using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
using Peak.Can.Basic;
using TPCANHandle = System.Byte;

namespace CANComm
{
    public partial class ComCan : Form
    {
        bool CanalTxSet, SpeedTxSet, CanalRxSet, SpeedRxSet, buttonReadStatus;
        private delegate void ReadDelegateHandler();
        private TPCANHandle m_PcanHandle;
        private TPCANBaudrate usBaudRate;
        private TPCANType m_HwType;
        private System.Collections.ArrayList m_LastMsgsList;
        private ReadDelegateHandler m_ReadDelegateHandler;
        private AutoResetEvent m_ReceiveEvent;
        private Thread m_ReadThread;
        private TPCANHandle[] m_HandlesArray;
        public string[] TableMessage;
        public string[] TableID;
        public string PubMsgID;
        public string PubMsgLen;

        private class MessageStatus
        {
            private TPCANMsg m_Msg;
            private TPCANTimestamp m_TimeStamp;
            private TPCANTimestamp m_oldTimeStamp;
            private int m_iIndex;
            private int m_Count;
            private bool m_bShowPeriod;
            private bool m_bWasChanged;

            public MessageStatus(TPCANMsg canMsg, TPCANTimestamp canTimestamp, int listIndex)
            {
                m_Msg = canMsg;
                m_TimeStamp = canTimestamp;
                m_oldTimeStamp = canTimestamp;
                m_iIndex = listIndex;
                m_Count = 1;
                m_bShowPeriod = true;
                m_bWasChanged = false;
            }

            public void Update(TPCANMsg canMsg, TPCANTimestamp canTimestamp)
            {
                m_Msg = canMsg;
                m_oldTimeStamp = m_TimeStamp;
                m_TimeStamp = canTimestamp;
                m_bWasChanged = true;
                m_Count += 1;
            }

            public TPCANMsg CANMsg
            {
                get { return m_Msg; }
            }

            public TPCANTimestamp Timestamp
            {
                get { return m_TimeStamp; }
            }

            public int Position
            {
                get { return m_iIndex; }
            }

            public string TypeString
            {
                get { return GetMsgTypeString(); }
            }

            public string IdString
            {
                get { return GetIdString(); }
            }

            public string DataString
            {
                get { return GetDataString(); }
            }

            public int Count
            {
                get { return m_Count; }
            }

            public bool ShowingPeriod
            {
                get { return m_bShowPeriod; }
                set
                {
                    if (m_bShowPeriod ^ value)
                    {
                        m_bShowPeriod = value;
                        m_bWasChanged = true;
                    }
                }
            }

            public bool MarkedAsUpdated
            {
                get { return m_bWasChanged; }
                set { m_bWasChanged = value; }
            }

            public string TimeString
            {
                get { return GetTimeString(); }
            }

            private string GetTimeString()
            {
                double fTime;

                fTime = m_TimeStamp.millis + (m_TimeStamp.micros / 1000.0);
                if (m_bShowPeriod)
                    fTime -= (m_oldTimeStamp.millis + (m_oldTimeStamp.micros / 1000.0));
                return fTime.ToString("F1");
            }

            private string GetDataString()
            {
                string strTemp;

                strTemp = "";

                if ((m_Msg.MSGTYPE & TPCANMessageType.PCAN_MESSAGE_RTR) == TPCANMessageType.PCAN_MESSAGE_RTR)
                    return "Remote Request";
                else
                    for (int i = 0; i < m_Msg.LEN; i++)
                        strTemp += string.Format("{0:X2} ", m_Msg.DATA[i]);

                return strTemp;
            }

            private string GetIdString()
            {
                // We format the ID of the message and show it
                //
                if ((m_Msg.MSGTYPE & TPCANMessageType.PCAN_MESSAGE_EXTENDED) == TPCANMessageType.PCAN_MESSAGE_EXTENDED)
                    return string.Format("{0:X8}h", m_Msg.ID);
                else
                    return string.Format("{0:X3}h", m_Msg.ID);
            }

            private string GetMsgTypeString()
            {
                string strTemp;

                if ((m_Msg.MSGTYPE & TPCANMessageType.PCAN_MESSAGE_EXTENDED) == TPCANMessageType.PCAN_MESSAGE_EXTENDED)
                    strTemp = "EXTENDED";
                else
                    strTemp = "STANDARD";

                if ((m_Msg.MSGTYPE & TPCANMessageType.PCAN_MESSAGE_RTR) == TPCANMessageType.PCAN_MESSAGE_RTR)
                    strTemp += "/RTR";

                return strTemp;
            }

        }

        public ComCan()
        {
            InitializeComponent();
            comboBoxChanRx.Items.AddRange(new string[]{"PCAN CH1","PCAN CH2"});
            comboBoxChanTx.Items.AddRange(new string[] {"PCAN CH1", "PCAN CH2"});

            comboBoxSpeedRx.Items.AddRange(new string[] { "1 MB/s", "800 kB/s", "500 kB/s", "250 kB/s", "125 kB/s", "100 kB/s", "95.238 kB/s",
                                                          "83.333 kB/s", "50 kB/s", "47.619 kB/s", "33.333 kB/s", "20 kB/s", "10 kB/s", "5 kB/s" });
            comboBoxSpeedTx.Items.AddRange(new string[]{ "1 MB/s", "800 kB/s", "500 kB/s", "250 kB/s", "125 kB/s", "100 kB/s", "95.238 kB/s",
                                                          "83.333 kB/s", "50 kB/s", "47.619 kB/s", "33.333 kB/s", "20 kB/s", "10 kB/s", "5 kB/s" });

            buttonConnectRx.Enabled = false;
            buttonConnectTx.Enabled = false;
            buttonRead.Enabled = false;
            buttonWrite.Enabled = false;
        }

        private string GetFormattedError(TPCANStatus error)
        {
            StringBuilder strTemp;
            strTemp = new StringBuilder(256);
            if (PCANBasic.GetErrorText(error, 0, strTemp) != TPCANStatus.PCAN_ERROR_OK)
            {
                return string.Format("Anchor error occured. Error code's text ({0:X}) couldn't be retrieved", error);
            }
            else
            {
                return strTemp.ToString();
            }
        }

        private void comboBoxChanRx_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxChanRx.Text == "PCAN CH1")
            {
                m_PcanHandle = 0x41;
            }
            if (comboBoxChanRx.Text == "PCAN CH2")
            {
                m_PcanHandle = 0x42;
            }
            CanalRxSet = true;
            if (SpeedRxSet == true) buttonConnectRx.Enabled = true;
        }

        private void comboBoxChanTx_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxChanTx.Text == "PCAN CH1")
            {
                m_PcanHandle = 0x41;
            }
            if (comboBoxChanTx.Text == "PCAN CH2")
            {
                m_PcanHandle = 0x42;
            }
            CanalTxSet = true;
            if (SpeedTxSet == true) buttonConnectTx.Enabled = true;
        }

        private void comboBoxSpeedRx_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBoxSpeedRx.SelectedIndex)
            {
                case 0:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_1M;
                    break;
                case 1:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_800K;
                    break;
                case 2:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_500K;
                    break;
                case 3:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_250K;
                    break;
                case 4:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_125K;
                    break;
                case 5:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_100K;
                    break;
                case 6:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_95K;
                    break;
                case 7:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_83K;
                    break;
                case 8:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_50K;
                    break;
                case 9:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_47K;
                    break;
                case 10:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_33K;
                    break;
                case 11:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_20K;
                    break;
                case 12:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_10K;
                    break;
                case 13:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_5K;
                    break;
            }
            SpeedRxSet = true;
            if (CanalRxSet == true) buttonConnectRx.Enabled = true;
        }

        private void comboBoxSpeedTx_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBoxSpeedTx.SelectedIndex)
            {
                case 0:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_1M;
                    break;
                case 1:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_800K;
                    break;
                case 2:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_500K;
                    break;
                case 3:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_250K;
                    break;
                case 4:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_125K;
                    break;
                case 5:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_100K;
                    break;
                case 6:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_95K;
                    break;
                case 7:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_83K;
                    break;
                case 8:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_50K;
                    break;
                case 9:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_47K;
                    break;
                case 10:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_33K;
                    break;
                case 11:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_20K;
                    break;
                case 12:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_10K;
                    break;
                case 13:
                    usBaudRate = TPCANBaudrate.PCAN_BAUD_5K;
                    break;
            }
            SpeedTxSet = true;
            if (CanalTxSet == true) buttonConnectTx.Enabled = true;
        }

        private void ReadMessage()
        {
            TPCANMsg CANMsg;
            TPCANTimestamp CANTimeStamp;
            TPCANStatus stsResult;
            string ID;
            string Length;
            // We read at least one time the queue looking for messages.
            // If a message is found, we look again trying to find more.
            // If the queue is empty or an error occurr, we get out from
            // the dowhile statement.
            //			
            do
            {
                // We execute the "Read" function of the PCANBasic                
                //
                stsResult = PCANBasic.Read(m_PcanHandle, out CANMsg, out CANTimeStamp);

                // A message was received
                // We process the message(s)
                //
                if (stsResult == TPCANStatus.PCAN_ERROR_OK)
                {
                    ID = Convert.ToString(CANMsg.ID, 16) + "h";
                    textBoxRxId.Text = ID;
                    PubMsgID = ID;

                    Length = Convert.ToString(CANMsg.LEN, 16);
                    textBoxLenghtRx.Text = Length;
                    PubMsgLen = Length;

                    Rx0.Text = Convert.ToString(CANMsg.DATA[0], 16);
                    Rx1.Text = Convert.ToString(CANMsg.DATA[1], 16);
                    Rx2.Text = Convert.ToString(CANMsg.DATA[2], 16);
                    Rx3.Text = Convert.ToString(CANMsg.DATA[3], 16);
                    Rx4.Text = Convert.ToString(CANMsg.DATA[4], 16);
                    Rx5.Text = Convert.ToString(CANMsg.DATA[5], 16);
                    Rx6.Text = Convert.ToString(CANMsg.DATA[6], 16);
                    Rx7.Text = Convert.ToString(CANMsg.DATA[7], 16);

                    for (int i = 0; i < Convert.ToChar(Length); i++)
                    {
                        TableMessage[i] = Convert.ToString(CANMsg.DATA[i], 16);
                    }
                }
                DisplayMessage();
                    //ProcessMessage(CANMsg, CANTimeStamp);

            } while (!Convert.ToBoolean(stsResult & TPCANStatus.PCAN_ERROR_QRCVEMPTY));
        }

        private void DisplayMessage()
        {
            Rx0.Visible = false;
            Rx1.Visible = false;
            Rx2.Visible = false;
            Rx3.Visible = false;
            Rx4.Visible = false;
            Rx5.Visible = false;
            Rx6.Visible = false;
            Rx7.Visible = false;
            switch (textBoxLenghtRx.Text)
            {
                case "0":
                    break;
                case "1":
                    Rx0.Visible = true;
                    break;
                case "2":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    break;
                case "3":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    Rx2.Visible = true;
                    break;
                case "4":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    Rx2.Visible = true;
                    Rx3.Visible = true;
                    break;
                case "5":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    Rx2.Visible = true;
                    Rx3.Visible = true;
                    Rx4.Visible = true;
                    break;
                case "6":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    Rx2.Visible = true;
                    Rx3.Visible = true;
                    Rx4.Visible = true;
                    Rx5.Visible = true;
                    break;
                case "7":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    Rx2.Visible = true;
                    Rx3.Visible = true;
                    Rx4.Visible = true;
                    Rx5.Visible = true;
                    Rx6.Visible = true;
                    break;
                case "8":
                    Rx0.Visible = true;
                    Rx1.Visible = true;
                    Rx2.Visible = true;
                    Rx3.Visible = true;
                    Rx4.Visible = true;
                    Rx5.Visible = true;
                    Rx6.Visible = true;
                    Rx7.Visible = true;
                    break;
            }
        }

        private void buttonConnectRx_Click(object sender, EventArgs e)
        {
            TPCANStatus stsResult;
            string IOConnect = "0100";
            string INTConnect = "3";

            if (buttonConnectRx.Text == "Connect")
            {
                stsResult = PCANBasic.Initialize(m_PcanHandle, usBaudRate, TPCANType.PCAN_TYPE_ISA, Convert.ToUInt32(IOConnect, 16), Convert.ToUInt16(INTConnect));
                if (stsResult != TPCANStatus.PCAN_ERROR_OK)
                {
                    MessageBox.Show(GetFormattedError(stsResult));
                }
                else
                buttonRead.Enabled = true;
                tmrRead.Enabled = true;
                buttonConnectRx.Text = "Disconnect";
            }
            else
            {
                PCANBasic.Uninitialize(m_PcanHandle);
                tmrRead.Enabled = false;
                if (m_ReadThread != null)
                {
                    m_ReadThread.Abort();
                    m_ReadThread.Join();
                    m_ReadThread = null;
                }
                else
                buttonRead.Enabled = false;
                buttonConnectRx.Text = "Connect";
                buttonRead.Text = "Lecture";
            }            
        }

        private void buttonConnectTx_Click(object sender, EventArgs e)
        {
            TPCANStatus stsResult;
            if (buttonConnectTx.Text == "Connect")
            {
                stsResult = PCANBasic.Initialize(m_PcanHandle, usBaudRate, TPCANType.PCAN_TYPE_ISA, 0x00000100, 0x0003);
                if (stsResult != TPCANStatus.PCAN_ERROR_OK)
                {
                    MessageBox.Show(GetFormattedError(stsResult));
                }
                buttonWrite.Enabled = true;
                buttonConnectTx.Text = "Disconnect";
            }
            else
            {
                PCANBasic.Uninitialize(m_PcanHandle);
                tmrRead.Enabled = false;
                if (m_ReadThread != null)
                {
                    m_ReadThread.Abort();
                    m_ReadThread.Join();
                    m_ReadThread = null;
                }
                buttonWrite.Enabled = false;
                buttonConnectTx.Text = "Connect";
            }
        }

        private void buttonWrite_Click(object sender, EventArgs e)
        {
            TPCANMsg CANMsg;
            TPCANStatus stsResult;

            CANMsg = new TPCANMsg();
            CANMsg.DATA = new byte[8];
            CANMsg.ID = Convert.ToUInt32(textBoxIDTx.Text, 16);
            CANMsg.LEN = Convert.ToByte(textBoxLenghtTx.Text);
            CANMsg.MSGTYPE = TPCANMessageType.PCAN_MESSAGE_STANDARD;

            for (int i = 0; i < CANMsg.LEN; i++)
            {
                if (i == 0) {CANMsg.DATA[0] = Convert.ToByte(Tx0.Text, 16);}
                if (i == 1) {CANMsg.DATA[1] = Convert.ToByte(Tx1.Text, 16);}
                if (i == 2) {CANMsg.DATA[2] = Convert.ToByte(Tx2.Text, 16);}
                if (i == 3) {CANMsg.DATA[3] = Convert.ToByte(Tx3.Text, 16);}
                if (i == 4) {CANMsg.DATA[4] = Convert.ToByte(Tx4.Text, 16);}
                if (i == 5) {CANMsg.DATA[5] = Convert.ToByte(Tx5.Text, 16);}
                if (i == 6) {CANMsg.DATA[6] = Convert.ToByte(Tx6.Text, 16);}
                if (i == 7) {CANMsg.DATA[7] = Convert.ToByte(Tx7.Text, 16);}
            }
            stsResult = PCANBasic.Write(m_PcanHandle, ref CANMsg);
            if (stsResult == TPCANStatus.PCAN_ERROR_OK) {}
            else
                MessageBox.Show(GetFormattedError(stsResult));
        }

        private void tmrRead_Tick(object sender, EventArgs e)
        {
           if (buttonReadStatus == true)
           {
            ReadMessage();
           }
        }

        private void buttonRead_Click(object sender, EventArgs e)
        {
            if (buttonRead.Text == "Lecture")
            {
                buttonReadStatus = true;
                buttonRead.Text = "Stop read";
            }
            else
            {
                buttonReadStatus = false;
                buttonRead.Text = "Lecture";
            }
        }

        private void buttonHist_Click(object sender, EventArgs e)
        {
            CANComm.Resources.HistCAN FormHistory;
            FormHistory = new Resources.HistCAN();
            FormHistory.Show();      
        }
    }
}

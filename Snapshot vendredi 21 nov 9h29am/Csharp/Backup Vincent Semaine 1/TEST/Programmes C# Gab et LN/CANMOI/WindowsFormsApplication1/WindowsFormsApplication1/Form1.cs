using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Peak.Can.Basic;


namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {

        TPCANType Type;
        byte Chanel = PCANBasic.PCAN_PCIBUS1;
        TPCANBaudrate  BAUDRATE = TPCANBaudrate.PCAN_BAUD_250K;
        byte Chanel1 = PCANBasic.PCAN_PCIBUS1;
        TPCANBaudrate BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_250K;
       
     
       TPCANMsg  MessageRX;
       TPCANMsg MessageTX;
     
      

        string[] Chan = { "BUS1", "BUS2", "BUS3", "BUS4", "BUS5" ,"BUS6", "BUS7", "BUS8" };
        string[] Baud = { "5K", "10K", "20k", "33K", "47K", "50K", "83k", "95k", "100K","125K","250K","500K","800K","1M" };
         
        public Form1()
        {
            InitializeComponent();
            comboBoxCanalRX.Items.AddRange(Chan);
            comboBoxCanalTX.Items.AddRange(Chan);
            comboBoxVitesseRX.Items.AddRange(Baud);
            comboBoxVitesseTX.Items.AddRange(Baud);
                
        }

        private void ConnecterRXBTN_Click(object sender, EventArgs e)
        {

            PCANBasic.Initialize(Chanel, BAUDRATE);
          
           
        }

        private void buttonLireRX_Click(object sender, EventArgs e)
        {


            PCANBasic.Read(Chanel, out MessageRX );

            textBoxIDRX.Text =  Convert.ToString(MessageRX.ID);
            textBoxLONGEURRX.Text = Convert.ToString(MessageRX.LEN);
            textBoxD0RX.Text = Convert.ToString(MessageRX.DATA[0]);
            textBoxD1RX.Text = Convert.ToString(MessageRX.DATA[1]);
            textBoxD2RX.Text = Convert.ToString(MessageRX.DATA[2]);
            textBoxD3RX.Text = Convert.ToString(MessageRX.DATA[3]);
            textBoxD4RX.Text = Convert.ToString(MessageRX.DATA[4]);
            textBoxD5RX.Text = Convert.ToString(MessageRX.DATA[5]);
            textBoxD6RX.Text = Convert.ToString(MessageRX.DATA[6]);
            textBoxD7RX.Text = Convert.ToString(MessageRX.DATA[7]); 

            



        }

        private void buttonConnecterTX_Click(object sender, EventArgs e)
        {

            PCANBasic.Initialize(Chanel1, BAUDRATE1);
            DEBUG.Text = Convert.ToString(BAUDRATE1);

        }

        private void buttonLireTX_Click(object sender, EventArgs e)
        {
           // PCANBasic.Read(Chanel, out MessageRX);

            PCANBasic.Write( Chanel1,  ref MessageTX );

            MessageTX.ID = Convert.ToUInt16( textBoxIDTX.Text) ;
           MessageTX.LEN = Convert.ToByte(textBoxLongeurTX.Text);
            
          MessageTX.DATA[0] =  Convert.ToByte(textBoxDOTX.Text);
          MessageTX.DATA[1] = Convert.ToByte(textBoxD1TX.Text);
          MessageTX.DATA[2] = Convert.ToByte(textBoxD2TX.Text);
          MessageTX.DATA[3] = Convert.ToByte(textBoxD3TX.Text);
          MessageTX.DATA[4] = Convert.ToByte(textBoxD4TX.Text);
          MessageTX.DATA[5] = Convert.ToByte(textBoxD5TX.Text);
          MessageTX.DATA[6] = Convert.ToByte(textBoxD6TX.Text);
          MessageTX.DATA[7] = Convert.ToByte(textBoxD7TX.Text);
        }

        private void comboBoxCanalRX_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBoxCanalRX.SelectedIndex)
            { 
                case 0:
                   Chanel =  PCANBasic.PCAN_PCIBUS1;
                break;
                case 1:
                Chanel = PCANBasic.PCAN_PCIBUS2;
                break;
                case 2:
                Chanel = PCANBasic.PCAN_PCIBUS3;
                break;
                case 3:
                Chanel = PCANBasic.PCAN_PCIBUS4;
                break;
                case 4:
                Chanel = PCANBasic.PCAN_PCIBUS5;
                break;
                case 5:
                Chanel = PCANBasic.PCAN_PCIBUS6;
                break;
                case 6:
                Chanel = PCANBasic.PCAN_PCIBUS7;
                break;
                case 7:
                Chanel = PCANBasic.PCAN_PCIBUS8;
                break;
            
            }


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBoxCanalRX.SelectedIndex = 0;
            comboBoxVitesseRX.SelectedIndex = 0;
            comboBoxCanalTX.SelectedIndex = 0;
            comboBoxVitesseTX.SelectedIndex = 0;
        }

        private void comboBoxVitesseRX_SelectedIndexChanged(object sender, EventArgs e)
        {

            switch (comboBoxVitesseRX.SelectedIndex)
            {
                case 0:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_5K;
                    break;
                case 1:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_10K;
                    break;
                case 2:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_20K;
                    break;
                case 3:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_33K;
                    break;
                case 4:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_47K;
                    break;
                case 5:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_50K;
                    break;
                case 6:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_83K;
                    break;
                case 7:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_95K;
                    break;

                case 8:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_100K;
                    break;
                case 9:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_125K;
                    break;
                case 10:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_250K;
                    break;
                case 11:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_500K;
                    break;
                case 12:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_800K;
                    break;
                case 13:
                    BAUDRATE = TPCANBaudrate.PCAN_BAUD_1M;
                    break;

            }

        }

        private void DEBUG_Click(object sender, EventArgs e)
        {

        }

        private void comboBoxCanalTX_SelectedIndexChanged(object sender, EventArgs e)
        {

            switch (comboBoxCanalTX.SelectedIndex)
            {
                case 0:
                    Chanel1 = PCANBasic.PCAN_PCIBUS1;
                    break;
                case 1:
                    Chanel1 = PCANBasic.PCAN_PCIBUS2;
                    break;
                case 2:
                    Chanel1= PCANBasic.PCAN_PCIBUS3;
                    break;
                case 3:
                    Chanel1 = PCANBasic.PCAN_PCIBUS4;
                    break;
                case 4:
                    Chanel1 = PCANBasic.PCAN_PCIBUS5;
                    break;
                case 5:
                    Chanel1 = PCANBasic.PCAN_PCIBUS6;
                    break;
                case 6:
                    Chanel1 = PCANBasic.PCAN_PCIBUS7;
                    break;
                case 7:
                    Chanel1 = PCANBasic.PCAN_PCIBUS8;
                    break;

            }


        }

        private void comboBoxVitesseTX_SelectedIndexChanged(object sender, EventArgs e)
        {

            switch (comboBoxVitesseTX.SelectedIndex)
            {
                case 0:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_5K;
                    break;
                case 1:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_10K;
                    break;
                case 2:
                    BAUDRATE1= TPCANBaudrate.PCAN_BAUD_20K;
                    break;
                case 3:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_33K;
                    break;
                case 4:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_47K;
                    break;
                case 5:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_50K;
                    break;
                case 6:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_83K;
                    break;
                case 7:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_95K;
                    break;

                case 8:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_100K;
                    break;
                case 9:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_125K;
                    break;
                case 10:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_250K;
                    break;
                case 11:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_500K;
                    break;
                case 12:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_800K;
                    break;
                case 13:
                    BAUDRATE1 = TPCANBaudrate.PCAN_BAUD_1M;
                    break;

            }
        }



    }
}

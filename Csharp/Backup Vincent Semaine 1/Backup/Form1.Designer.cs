namespace ICDIBasic
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnHwRefresh = new System.Windows.Forms.Button();
            this.cbbChannel = new System.Windows.Forms.ComboBox();
            this.cbbHwType = new System.Windows.Forms.ComboBox();
            this.cbbInterrupt = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.cbbIO = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.cbbBaudrates = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnInit = new System.Windows.Forms.Button();
            this.btnRelease = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.btnFilterQuery = new System.Windows.Forms.Button();
            this.chbFilterExt = new System.Windows.Forms.CheckBox();
            this.nudIdTo = new System.Windows.Forms.NumericUpDown();
            this.nudIdFrom = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.rdbFilterOpen = new System.Windows.Forms.RadioButton();
            this.rdbFilterCustom = new System.Windows.Forms.RadioButton();
            this.rdbFilterClose = new System.Windows.Forms.RadioButton();
            this.btnFilterApply = new System.Windows.Forms.Button();
            this.btnParameterSet = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnParameterGet = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.nudDeviceId = new System.Windows.Forms.NumericUpDown();
            this.label9 = new System.Windows.Forms.Label();
            this.cbbParameter = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.rdbParamActive = new System.Windows.Forms.RadioButton();
            this.rdbParamInactive = new System.Windows.Forms.RadioButton();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.btnReset = new System.Windows.Forms.Button();
            this.btnStatus = new System.Windows.Forms.Button();
            this.btnGetVersions = new System.Windows.Forms.Button();
            this.lbxInfo = new System.Windows.Forms.ListBox();
            this.btnInfoClear = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.chbShowPeriod = new System.Windows.Forms.CheckBox();
            this.rdbManual = new System.Windows.Forms.RadioButton();
            this.rdbEvent = new System.Windows.Forms.RadioButton();
            this.lstMessages = new System.Windows.Forms.ListView();
            this.clhType = new System.Windows.Forms.ColumnHeader();
            this.clhID = new System.Windows.Forms.ColumnHeader();
            this.clhLength = new System.Windows.Forms.ColumnHeader();
            this.clhData = new System.Windows.Forms.ColumnHeader();
            this.clhCount = new System.Windows.Forms.ColumnHeader();
            this.clhRcvTime = new System.Windows.Forms.ColumnHeader();
            this.btnMsgClear = new System.Windows.Forms.Button();
            this.rdbTimer = new System.Windows.Forms.RadioButton();
            this.btnRead = new System.Windows.Forms.Button();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.chbRemote = new System.Windows.Forms.CheckBox();
            this.chbExtended = new System.Windows.Forms.CheckBox();
            this.label11 = new System.Windows.Forms.Label();
            this.btnWrite = new System.Windows.Forms.Button();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.txtID = new System.Windows.Forms.TextBox();
            this.txtData7 = new System.Windows.Forms.TextBox();
            this.txtData6 = new System.Windows.Forms.TextBox();
            this.txtData5 = new System.Windows.Forms.TextBox();
            this.txtData4 = new System.Windows.Forms.TextBox();
            this.txtData3 = new System.Windows.Forms.TextBox();
            this.txtData2 = new System.Windows.Forms.TextBox();
            this.txtData1 = new System.Windows.Forms.TextBox();
            this.txtData0 = new System.Windows.Forms.TextBox();
            this.nudLength = new System.Windows.Forms.NumericUpDown();
            this.tmrRead = new System.Windows.Forms.Timer(this.components);
            this.tmrDisplay = new System.Windows.Forms.Timer(this.components);
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudIdTo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudIdFrom)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudDeviceId)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudLength)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.btnHwRefresh);
            this.groupBox1.Controls.Add(this.cbbChannel);
            this.groupBox1.Controls.Add(this.cbbHwType);
            this.groupBox1.Controls.Add(this.cbbInterrupt);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.cbbIO);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.cbbBaudrates);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.btnInit);
            this.groupBox1.Controls.Add(this.btnRelease);
            this.groupBox1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.groupBox1.Location = new System.Drawing.Point(8, 8);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(734, 65);
            this.groupBox1.TabIndex = 42;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = " Connection ";
            // 
            // btnHwRefresh
            // 
            this.btnHwRefresh.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnHwRefresh.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnHwRefresh.Location = new System.Drawing.Point(133, 30);
            this.btnHwRefresh.Name = "btnHwRefresh";
            this.btnHwRefresh.Size = new System.Drawing.Size(65, 23);
            this.btnHwRefresh.TabIndex = 45;
            this.btnHwRefresh.Text = "Refresh";
            this.btnHwRefresh.Click += new System.EventHandler(this.btnHwRefresh_Click);
            // 
            // cbbChannel
            // 
            this.cbbChannel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbChannel.Font = new System.Drawing.Font("Consolas", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbbChannel.Items.AddRange(new object[] {
            "None",
            "DNG-Channel 1",
            "ISA-Channel 1",
            "ISA-Channel 2",
            "ISA-Channel 3",
            "ISA-Channel 4",
            "ISA-Channel 5",
            "ISA-Channel 6",
            "ISA-Channel 7",
            "ISA-Channel 8",
            "PCC-Channel 1",
            "PCC-Channel 2",
            "PCI-Channel 1",
            "PCI-Channel 2",
            "PCI-Channel 3",
            "PCI-Channel 4",
            "PCI-Channel 5",
            "PCI-Channel 6",
            "PCI-Channel 7",
            "PCI-Channel 8",
            "USB-Channel 1",
            "USB-Channel 2",
            "USB-Channel 3",
            "USB-Channel 4",
            "USB-Channel 5",
            "USB-Channel 6",
            "USB-Channel 7",
            "USB-Channel 8"});
            this.cbbChannel.Location = new System.Drawing.Point(8, 31);
            this.cbbChannel.Name = "cbbChannel";
            this.cbbChannel.Size = new System.Drawing.Size(119, 21);
            this.cbbChannel.TabIndex = 32;
            this.cbbChannel.SelectedIndexChanged += new System.EventHandler(this.cbbChannel_SelectedIndexChanged);
            // 
            // cbbHwType
            // 
            this.cbbHwType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbHwType.Items.AddRange(new object[] {
            "ISA-82C200",
            "ISA-SJA1000",
            "ISA-PHYTEC",
            "DNG-82C200",
            "DNG-82C200 EPP",
            "DNG-SJA1000",
            "DNG-SJA1000 EPP"});
            this.cbbHwType.Location = new System.Drawing.Point(326, 31);
            this.cbbHwType.Name = "cbbHwType";
            this.cbbHwType.Size = new System.Drawing.Size(120, 21);
            this.cbbHwType.TabIndex = 37;
            this.cbbHwType.SelectedIndexChanged += new System.EventHandler(this.cbbHwType_SelectedIndexChanged);
            // 
            // cbbInterrupt
            // 
            this.cbbInterrupt.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbInterrupt.Items.AddRange(new object[] {
            "3",
            "4",
            "5",
            "7",
            "9",
            "10",
            "11",
            "12",
            "15"});
            this.cbbInterrupt.Location = new System.Drawing.Point(513, 31);
            this.cbbInterrupt.Name = "cbbInterrupt";
            this.cbbInterrupt.Size = new System.Drawing.Size(55, 21);
            this.cbbInterrupt.TabIndex = 39;
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(515, 15);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 23);
            this.label5.TabIndex = 44;
            this.label5.Text = "Interrupt:";
            // 
            // cbbIO
            // 
            this.cbbIO.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbIO.Items.AddRange(new object[] {
            "0100",
            "0120",
            "0140",
            "0200",
            "0220",
            "0240",
            "0260",
            "0278",
            "0280",
            "02A0",
            "02C0",
            "02E0",
            "02E8",
            "02F8",
            "0300",
            "0320",
            "0340",
            "0360",
            "0378",
            "0380",
            "03BC",
            "03E0",
            "03E8",
            "03F8"});
            this.cbbIO.Location = new System.Drawing.Point(452, 31);
            this.cbbIO.Name = "cbbIO";
            this.cbbIO.Size = new System.Drawing.Size(55, 21);
            this.cbbIO.TabIndex = 38;
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(452, 15);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(55, 23);
            this.label4.TabIndex = 43;
            this.label4.Text = "I/O Port:";
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(327, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(90, 23);
            this.label3.TabIndex = 42;
            this.label3.Text = "Hardware Type:";
            // 
            // cbbBaudrates
            // 
            this.cbbBaudrates.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbBaudrates.Items.AddRange(new object[] {
            "1 MBit/sec",
            "800 kBit/s",
            "500 kBit/sec",
            "250 kBit/sec",
            "125 kBit/sec",
            "100 kBit/sec",
            "95,238 kBit/s",
            "83,333 kBit/s",
            "50 kBit/sec",
            "47,619 kBit/s",
            "33,333 kBit/s",
            "20 kBit/sec",
            "10 kBit/sec",
            "5 kBit/sec"});
            this.cbbBaudrates.Location = new System.Drawing.Point(204, 31);
            this.cbbBaudrates.Name = "cbbBaudrates";
            this.cbbBaudrates.Size = new System.Drawing.Size(116, 21);
            this.cbbBaudrates.TabIndex = 36;
            this.cbbBaudrates.SelectedIndexChanged += new System.EventHandler(this.cbbBaudrates_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(204, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 23);
            this.label2.TabIndex = 41;
            this.label2.Text = "Baudrate:";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(7, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 23);
            this.label1.TabIndex = 40;
            this.label1.Text = "Hardware:";
            // 
            // btnInit
            // 
            this.btnInit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnInit.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnInit.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnInit.Location = new System.Drawing.Point(592, 30);
            this.btnInit.Name = "btnInit";
            this.btnInit.Size = new System.Drawing.Size(65, 23);
            this.btnInit.TabIndex = 34;
            this.btnInit.Text = "Initialize";
            this.btnInit.Click += new System.EventHandler(this.btnInit_Click);
            // 
            // btnRelease
            // 
            this.btnRelease.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnRelease.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnRelease.Enabled = false;
            this.btnRelease.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnRelease.Location = new System.Drawing.Point(663, 30);
            this.btnRelease.Name = "btnRelease";
            this.btnRelease.Size = new System.Drawing.Size(65, 23);
            this.btnRelease.TabIndex = 35;
            this.btnRelease.Text = "Release";
            this.btnRelease.Click += new System.EventHandler(this.btnRelease_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox3.Controls.Add(this.btnFilterQuery);
            this.groupBox3.Controls.Add(this.chbFilterExt);
            this.groupBox3.Controls.Add(this.nudIdTo);
            this.groupBox3.Controls.Add(this.nudIdFrom);
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.rdbFilterOpen);
            this.groupBox3.Controls.Add(this.rdbFilterCustom);
            this.groupBox3.Controls.Add(this.rdbFilterClose);
            this.groupBox3.Controls.Add(this.btnFilterApply);
            this.groupBox3.Location = new System.Drawing.Point(8, 79);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(734, 58);
            this.groupBox3.TabIndex = 44;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = " Message Filtering ";
            // 
            // btnFilterQuery
            // 
            this.btnFilterQuery.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnFilterQuery.Enabled = false;
            this.btnFilterQuery.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnFilterQuery.Location = new System.Drawing.Point(663, 26);
            this.btnFilterQuery.Name = "btnFilterQuery";
            this.btnFilterQuery.Size = new System.Drawing.Size(65, 23);
            this.btnFilterQuery.TabIndex = 55;
            this.btnFilterQuery.Text = "Query";
            this.btnFilterQuery.UseVisualStyleBackColor = true;
            this.btnFilterQuery.Click += new System.EventHandler(this.btnFilterQuery_Click);
            // 
            // chbFilterExt
            // 
            this.chbFilterExt.AutoSize = true;
            this.chbFilterExt.Location = new System.Drawing.Point(10, 33);
            this.chbFilterExt.Name = "chbFilterExt";
            this.chbFilterExt.Size = new System.Drawing.Size(103, 17);
            this.chbFilterExt.TabIndex = 44;
            this.chbFilterExt.Text = "Extended Frame";
            this.chbFilterExt.UseVisualStyleBackColor = true;
            this.chbFilterExt.CheckedChanged += new System.EventHandler(this.chbFilterExt_CheckedChanged);
            // 
            // nudIdTo
            // 
            this.nudIdTo.Hexadecimal = true;
            this.nudIdTo.Location = new System.Drawing.Point(438, 29);
            this.nudIdTo.Maximum = new decimal(new int[] {
            2047,
            0,
            0,
            0});
            this.nudIdTo.Name = "nudIdTo";
            this.nudIdTo.Size = new System.Drawing.Size(69, 20);
            this.nudIdTo.TabIndex = 6;
            this.nudIdTo.Value = new decimal(new int[] {
            2047,
            0,
            0,
            0});
            // 
            // nudIdFrom
            // 
            this.nudIdFrom.Hexadecimal = true;
            this.nudIdFrom.Location = new System.Drawing.Point(363, 29);
            this.nudIdFrom.Maximum = new decimal(new int[] {
            2047,
            0,
            0,
            0});
            this.nudIdFrom.Name = "nudIdFrom";
            this.nudIdFrom.Size = new System.Drawing.Size(69, 20);
            this.nudIdFrom.TabIndex = 5;
            // 
            // label8
            // 
            this.label8.Location = new System.Drawing.Point(436, 10);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(28, 23);
            this.label8.TabIndex = 43;
            this.label8.Text = "To:";
            // 
            // label7
            // 
            this.label7.Location = new System.Drawing.Point(361, 12);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(38, 23);
            this.label7.TabIndex = 42;
            this.label7.Text = "From:";
            // 
            // rdbFilterOpen
            // 
            this.rdbFilterOpen.Checked = true;
            this.rdbFilterOpen.Location = new System.Drawing.Point(120, 32);
            this.rdbFilterOpen.Name = "rdbFilterOpen";
            this.rdbFilterOpen.Size = new System.Drawing.Size(53, 17);
            this.rdbFilterOpen.TabIndex = 2;
            this.rdbFilterOpen.TabStop = true;
            this.rdbFilterOpen.Text = "Open";
            this.rdbFilterOpen.UseVisualStyleBackColor = true;
            // 
            // rdbFilterCustom
            // 
            this.rdbFilterCustom.Location = new System.Drawing.Point(238, 32);
            this.rdbFilterCustom.Name = "rdbFilterCustom";
            this.rdbFilterCustom.Size = new System.Drawing.Size(104, 17);
            this.rdbFilterCustom.TabIndex = 1;
            this.rdbFilterCustom.Text = "Custom (expand)";
            this.rdbFilterCustom.UseVisualStyleBackColor = true;
            // 
            // rdbFilterClose
            // 
            this.rdbFilterClose.Location = new System.Drawing.Point(177, 32);
            this.rdbFilterClose.Name = "rdbFilterClose";
            this.rdbFilterClose.Size = new System.Drawing.Size(58, 17);
            this.rdbFilterClose.TabIndex = 0;
            this.rdbFilterClose.Text = "Close";
            this.rdbFilterClose.UseVisualStyleBackColor = true;
            // 
            // btnFilterApply
            // 
            this.btnFilterApply.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnFilterApply.Enabled = false;
            this.btnFilterApply.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnFilterApply.Location = new System.Drawing.Point(592, 26);
            this.btnFilterApply.Name = "btnFilterApply";
            this.btnFilterApply.Size = new System.Drawing.Size(65, 23);
            this.btnFilterApply.TabIndex = 44;
            this.btnFilterApply.Text = "Apply";
            this.btnFilterApply.UseVisualStyleBackColor = true;
            this.btnFilterApply.Click += new System.EventHandler(this.btnFilterApply_Click);
            // 
            // btnParameterSet
            // 
            this.btnParameterSet.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnParameterSet.Enabled = false;
            this.btnParameterSet.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnParameterSet.Location = new System.Drawing.Point(592, 26);
            this.btnParameterSet.Name = "btnParameterSet";
            this.btnParameterSet.Size = new System.Drawing.Size(65, 23);
            this.btnParameterSet.TabIndex = 46;
            this.btnParameterSet.Text = "Set";
            this.btnParameterSet.UseVisualStyleBackColor = true;
            this.btnParameterSet.Click += new System.EventHandler(this.btnParameterSet_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox2.Controls.Add(this.btnParameterGet);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.nudDeviceId);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.cbbParameter);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.rdbParamActive);
            this.groupBox2.Controls.Add(this.rdbParamInactive);
            this.groupBox2.Controls.Add(this.btnParameterSet);
            this.groupBox2.Location = new System.Drawing.Point(8, 143);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(734, 58);
            this.groupBox2.TabIndex = 45;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = " Configuration Parameters ";
            // 
            // btnParameterGet
            // 
            this.btnParameterGet.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnParameterGet.Enabled = false;
            this.btnParameterGet.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnParameterGet.Location = new System.Drawing.Point(663, 26);
            this.btnParameterGet.Name = "btnParameterGet";
            this.btnParameterGet.Size = new System.Drawing.Size(65, 23);
            this.btnParameterGet.TabIndex = 54;
            this.btnParameterGet.Text = "Get";
            this.btnParameterGet.UseVisualStyleBackColor = true;
            this.btnParameterGet.Click += new System.EventHandler(this.btnParameterGet_Click);
            // 
            // label10
            // 
            this.label10.Location = new System.Drawing.Point(241, 11);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(59, 23);
            this.label10.TabIndex = 46;
            this.label10.Text = "Activation:";
            // 
            // nudDeviceId
            // 
            this.nudDeviceId.Enabled = false;
            this.nudDeviceId.Location = new System.Drawing.Point(408, 29);
            this.nudDeviceId.Maximum = new decimal(new int[] {
            -1,
            0,
            0,
            0});
            this.nudDeviceId.Name = "nudDeviceId";
            this.nudDeviceId.Size = new System.Drawing.Size(99, 20);
            this.nudDeviceId.TabIndex = 6;
            // 
            // label9
            // 
            this.label9.Location = new System.Drawing.Point(405, 12);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(59, 23);
            this.label9.TabIndex = 45;
            this.label9.Text = "Device ID:";
            // 
            // cbbParameter
            // 
            this.cbbParameter.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbParameter.FormattingEnabled = true;
            this.cbbParameter.Items.AddRange(new object[] {
            "USB\'s Device Number",
            "USB/PC-Card\'s 5V Power",
            "Auto-reset on BUS-OFF",
            "CAN Listen-Only",
            "Debug\'s Log"});
            this.cbbParameter.Location = new System.Drawing.Point(10, 31);
            this.cbbParameter.Name = "cbbParameter";
            this.cbbParameter.Size = new System.Drawing.Size(217, 21);
            this.cbbParameter.TabIndex = 44;
            this.cbbParameter.SelectedIndexChanged += new System.EventHandler(this.cbbParameter_SelectedIndexChanged);
            // 
            // label6
            // 
            this.label6.Location = new System.Drawing.Point(7, 14);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(64, 23);
            this.label6.TabIndex = 43;
            this.label6.Text = "Parameter:";
            // 
            // rdbParamActive
            // 
            this.rdbParamActive.Checked = true;
            this.rdbParamActive.Location = new System.Drawing.Point(238, 32);
            this.rdbParamActive.Name = "rdbParamActive";
            this.rdbParamActive.Size = new System.Drawing.Size(56, 17);
            this.rdbParamActive.TabIndex = 2;
            this.rdbParamActive.TabStop = true;
            this.rdbParamActive.Text = "Active";
            this.rdbParamActive.UseVisualStyleBackColor = true;
            // 
            // rdbParamInactive
            // 
            this.rdbParamInactive.Location = new System.Drawing.Point(300, 32);
            this.rdbParamInactive.Name = "rdbParamInactive";
            this.rdbParamInactive.Size = new System.Drawing.Size(67, 17);
            this.rdbParamInactive.TabIndex = 0;
            this.rdbParamInactive.Text = "Inactive";
            this.rdbParamInactive.UseVisualStyleBackColor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox4.Controls.Add(this.btnReset);
            this.groupBox4.Controls.Add(this.btnStatus);
            this.groupBox4.Controls.Add(this.btnGetVersions);
            this.groupBox4.Controls.Add(this.lbxInfo);
            this.groupBox4.Controls.Add(this.btnInfoClear);
            this.groupBox4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.groupBox4.Location = new System.Drawing.Point(8, 425);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(734, 135);
            this.groupBox4.TabIndex = 47;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Information";
            // 
            // btnReset
            // 
            this.btnReset.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnReset.Enabled = false;
            this.btnReset.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnReset.Location = new System.Drawing.Point(663, 48);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(65, 23);
            this.btnReset.TabIndex = 58;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // btnStatus
            // 
            this.btnStatus.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnStatus.Enabled = false;
            this.btnStatus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnStatus.Location = new System.Drawing.Point(592, 48);
            this.btnStatus.Name = "btnStatus";
            this.btnStatus.Size = new System.Drawing.Size(65, 23);
            this.btnStatus.TabIndex = 57;
            this.btnStatus.Text = "Status";
            this.btnStatus.UseVisualStyleBackColor = true;
            this.btnStatus.Click += new System.EventHandler(this.btnStatus_Click);
            // 
            // btnGetVersions
            // 
            this.btnGetVersions.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnGetVersions.Enabled = false;
            this.btnGetVersions.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnGetVersions.Location = new System.Drawing.Point(592, 19);
            this.btnGetVersions.Name = "btnGetVersions";
            this.btnGetVersions.Size = new System.Drawing.Size(65, 23);
            this.btnGetVersions.TabIndex = 53;
            this.btnGetVersions.Text = "Versions";
            this.btnGetVersions.UseVisualStyleBackColor = true;
            this.btnGetVersions.Click += new System.EventHandler(this.btnGetVersions_Click);
            // 
            // lbxInfo
            // 
            this.lbxInfo.FormattingEnabled = true;
            this.lbxInfo.Items.AddRange(new object[] {
            "Select a Hardware and a configuration for it. Then click \"Initialize\" button",
            "When activated, the Debug-Log file will be found in the same directory as this ap" +
                "plication"});
            this.lbxInfo.Location = new System.Drawing.Point(10, 19);
            this.lbxInfo.Name = "lbxInfo";
            this.lbxInfo.ScrollAlwaysVisible = true;
            this.lbxInfo.Size = new System.Drawing.Size(558, 108);
            this.lbxInfo.TabIndex = 56;
            this.lbxInfo.DoubleClick += new System.EventHandler(this.lbxInfo_DoubleClick);
            // 
            // btnInfoClear
            // 
            this.btnInfoClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnInfoClear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnInfoClear.Location = new System.Drawing.Point(663, 19);
            this.btnInfoClear.Name = "btnInfoClear";
            this.btnInfoClear.Size = new System.Drawing.Size(65, 23);
            this.btnInfoClear.TabIndex = 52;
            this.btnInfoClear.Text = "Clear";
            this.btnInfoClear.UseVisualStyleBackColor = true;
            this.btnInfoClear.Click += new System.EventHandler(this.btnInfoClear_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox5.Controls.Add(this.chbShowPeriod);
            this.groupBox5.Controls.Add(this.rdbManual);
            this.groupBox5.Controls.Add(this.rdbEvent);
            this.groupBox5.Controls.Add(this.lstMessages);
            this.groupBox5.Controls.Add(this.btnMsgClear);
            this.groupBox5.Controls.Add(this.rdbTimer);
            this.groupBox5.Controls.Add(this.btnRead);
            this.groupBox5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.groupBox5.Location = new System.Drawing.Point(8, 207);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(734, 140);
            this.groupBox5.TabIndex = 48;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = " Messages Reading ";
            // 
            // chbShowPeriod
            // 
            this.chbShowPeriod.AutoSize = true;
            this.chbShowPeriod.Checked = true;
            this.chbShowPeriod.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chbShowPeriod.Location = new System.Drawing.Point(374, 15);
            this.chbShowPeriod.Name = "chbShowPeriod";
            this.chbShowPeriod.Size = new System.Drawing.Size(123, 17);
            this.chbShowPeriod.TabIndex = 75;
            this.chbShowPeriod.Text = "Timestamp as period";
            this.chbShowPeriod.UseVisualStyleBackColor = true;
            this.chbShowPeriod.CheckedChanged += new System.EventHandler(this.chbShowPeriod_CheckedChanged);
            // 
            // rdbManual
            // 
            this.rdbManual.AutoSize = true;
            this.rdbManual.Location = new System.Drawing.Point(276, 14);
            this.rdbManual.Name = "rdbManual";
            this.rdbManual.Size = new System.Drawing.Size(89, 17);
            this.rdbManual.TabIndex = 74;
            this.rdbManual.Text = "Manual Read";
            this.rdbManual.UseVisualStyleBackColor = true;
            this.rdbManual.CheckedChanged += new System.EventHandler(this.rdbTimer_CheckedChanged);
            // 
            // rdbEvent
            // 
            this.rdbEvent.AutoSize = true;
            this.rdbEvent.Location = new System.Drawing.Point(131, 14);
            this.rdbEvent.Name = "rdbEvent";
            this.rdbEvent.Size = new System.Drawing.Size(139, 17);
            this.rdbEvent.TabIndex = 73;
            this.rdbEvent.Text = "Reading using an Event";
            this.rdbEvent.UseVisualStyleBackColor = true;
            this.rdbEvent.CheckedChanged += new System.EventHandler(this.rdbTimer_CheckedChanged);
            // 
            // lstMessages
            // 
            this.lstMessages.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.clhType,
            this.clhID,
            this.clhLength,
            this.clhData,
            this.clhCount,
            this.clhRcvTime});
            this.lstMessages.FullRowSelect = true;
            this.lstMessages.Location = new System.Drawing.Point(8, 37);
            this.lstMessages.MultiSelect = false;
            this.lstMessages.Name = "lstMessages";
            this.lstMessages.Size = new System.Drawing.Size(560, 96);
            this.lstMessages.TabIndex = 28;
            this.lstMessages.UseCompatibleStateImageBehavior = false;
            this.lstMessages.View = System.Windows.Forms.View.Details;
            this.lstMessages.DoubleClick += new System.EventHandler(this.lstMessages_DoubleClick);
            // 
            // clhType
            // 
            this.clhType.Text = "Type";
            this.clhType.Width = 69;
            // 
            // clhID
            // 
            this.clhID.Text = "ID";
            this.clhID.Width = 90;
            // 
            // clhLength
            // 
            this.clhLength.Text = "Length";
            this.clhLength.Width = 50;
            // 
            // clhData
            // 
            this.clhData.Text = "Data";
            this.clhData.Width = 160;
            // 
            // clhCount
            // 
            this.clhCount.Text = "Count";
            this.clhCount.Width = 49;
            // 
            // clhRcvTime
            // 
            this.clhRcvTime.Text = "Rcv Time";
            this.clhRcvTime.Width = 97;
            // 
            // btnMsgClear
            // 
            this.btnMsgClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnMsgClear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnMsgClear.Location = new System.Drawing.Point(663, 37);
            this.btnMsgClear.Name = "btnMsgClear";
            this.btnMsgClear.Size = new System.Drawing.Size(65, 23);
            this.btnMsgClear.TabIndex = 50;
            this.btnMsgClear.Text = "Clear";
            this.btnMsgClear.UseVisualStyleBackColor = true;
            this.btnMsgClear.Click += new System.EventHandler(this.btnMsgClear_Click);
            // 
            // rdbTimer
            // 
            this.rdbTimer.AutoSize = true;
            this.rdbTimer.Checked = true;
            this.rdbTimer.Location = new System.Drawing.Point(8, 14);
            this.rdbTimer.Name = "rdbTimer";
            this.rdbTimer.Size = new System.Drawing.Size(117, 17);
            this.rdbTimer.TabIndex = 72;
            this.rdbTimer.TabStop = true;
            this.rdbTimer.Text = "Read using a Timer";
            this.rdbTimer.UseVisualStyleBackColor = true;
            this.rdbTimer.CheckedChanged += new System.EventHandler(this.rdbTimer_CheckedChanged);
            // 
            // btnRead
            // 
            this.btnRead.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnRead.Enabled = false;
            this.btnRead.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnRead.Location = new System.Drawing.Point(592, 37);
            this.btnRead.Name = "btnRead";
            this.btnRead.Size = new System.Drawing.Size(65, 23);
            this.btnRead.TabIndex = 49;
            this.btnRead.Text = "Read";
            this.btnRead.UseVisualStyleBackColor = true;
            this.btnRead.Click += new System.EventHandler(this.btnRead_Click);
            // 
            // groupBox6
            // 
            this.groupBox6.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox6.Controls.Add(this.chbRemote);
            this.groupBox6.Controls.Add(this.chbExtended);
            this.groupBox6.Controls.Add(this.label11);
            this.groupBox6.Controls.Add(this.btnWrite);
            this.groupBox6.Controls.Add(this.label12);
            this.groupBox6.Controls.Add(this.label13);
            this.groupBox6.Controls.Add(this.txtID);
            this.groupBox6.Controls.Add(this.txtData7);
            this.groupBox6.Controls.Add(this.txtData6);
            this.groupBox6.Controls.Add(this.txtData5);
            this.groupBox6.Controls.Add(this.txtData4);
            this.groupBox6.Controls.Add(this.txtData3);
            this.groupBox6.Controls.Add(this.txtData2);
            this.groupBox6.Controls.Add(this.txtData1);
            this.groupBox6.Controls.Add(this.txtData0);
            this.groupBox6.Controls.Add(this.nudLength);
            this.groupBox6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.groupBox6.Location = new System.Drawing.Point(8, 353);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(734, 66);
            this.groupBox6.TabIndex = 51;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Write Messages";
            // 
            // chbRemote
            // 
            this.chbRemote.Cursor = System.Windows.Forms.Cursors.Default;
            this.chbRemote.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.chbRemote.Location = new System.Drawing.Point(270, 32);
            this.chbRemote.Name = "chbRemote";
            this.chbRemote.Size = new System.Drawing.Size(44, 24);
            this.chbRemote.TabIndex = 33;
            this.chbRemote.Text = "RTR";
            this.chbRemote.CheckedChanged += new System.EventHandler(this.chbRemote_CheckedChanged);
            // 
            // chbExtended
            // 
            this.chbExtended.Cursor = System.Windows.Forms.Cursors.Default;
            this.chbExtended.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.chbExtended.Location = new System.Drawing.Point(94, 32);
            this.chbExtended.Name = "chbExtended";
            this.chbExtended.Size = new System.Drawing.Size(62, 24);
            this.chbExtended.TabIndex = 34;
            this.chbExtended.Text = "Extended";
            this.chbExtended.CheckedChanged += new System.EventHandler(this.chbExtended_CheckedChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(267, 17);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(60, 13);
            this.label11.TabIndex = 32;
            this.label11.Text = "Data (0..7):";
            // 
            // btnWrite
            // 
            this.btnWrite.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnWrite.Cursor = System.Windows.Forms.Cursors.Default;
            this.btnWrite.Enabled = false;
            this.btnWrite.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.btnWrite.Location = new System.Drawing.Point(663, 32);
            this.btnWrite.Name = "btnWrite";
            this.btnWrite.Size = new System.Drawing.Size(65, 23);
            this.btnWrite.TabIndex = 36;
            this.btnWrite.Text = "Write";
            this.btnWrite.Click += new System.EventHandler(this.btnWrite_Click);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(174, 17);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(43, 13);
            this.label12.TabIndex = 31;
            this.label12.Text = "Length:";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(7, 17);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(49, 13);
            this.label13.TabIndex = 30;
            this.label13.Text = "ID (Hex):";
            // 
            // txtID
            // 
            this.txtID.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtID.Location = new System.Drawing.Point(8, 34);
            this.txtID.MaxLength = 3;
            this.txtID.Name = "txtID";
            this.txtID.Size = new System.Drawing.Size(80, 20);
            this.txtID.TabIndex = 20;
            this.txtID.Text = "0";
            this.txtID.Leave += new System.EventHandler(this.txtID_Leave);
            this.txtID.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData7
            // 
            this.txtData7.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData7.Location = new System.Drawing.Point(544, 34);
            this.txtData7.MaxLength = 2;
            this.txtData7.Name = "txtData7";
            this.txtData7.Size = new System.Drawing.Size(24, 20);
            this.txtData7.TabIndex = 29;
            this.txtData7.Text = "00";
            this.txtData7.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData7.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData7.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData6
            // 
            this.txtData6.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData6.Location = new System.Drawing.Point(512, 34);
            this.txtData6.MaxLength = 2;
            this.txtData6.Name = "txtData6";
            this.txtData6.Size = new System.Drawing.Size(24, 20);
            this.txtData6.TabIndex = 28;
            this.txtData6.Text = "00";
            this.txtData6.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData6.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData6.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData5
            // 
            this.txtData5.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData5.Location = new System.Drawing.Point(480, 34);
            this.txtData5.MaxLength = 2;
            this.txtData5.Name = "txtData5";
            this.txtData5.Size = new System.Drawing.Size(24, 20);
            this.txtData5.TabIndex = 27;
            this.txtData5.Text = "00";
            this.txtData5.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData5.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData5.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData4
            // 
            this.txtData4.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData4.Location = new System.Drawing.Point(448, 34);
            this.txtData4.MaxLength = 2;
            this.txtData4.Name = "txtData4";
            this.txtData4.Size = new System.Drawing.Size(24, 20);
            this.txtData4.TabIndex = 26;
            this.txtData4.Text = "00";
            this.txtData4.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData4.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData4.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData3
            // 
            this.txtData3.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData3.Location = new System.Drawing.Point(416, 34);
            this.txtData3.MaxLength = 2;
            this.txtData3.Name = "txtData3";
            this.txtData3.Size = new System.Drawing.Size(24, 20);
            this.txtData3.TabIndex = 25;
            this.txtData3.Text = "00";
            this.txtData3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData3.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData3.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData2
            // 
            this.txtData2.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData2.Location = new System.Drawing.Point(384, 34);
            this.txtData2.MaxLength = 2;
            this.txtData2.Name = "txtData2";
            this.txtData2.Size = new System.Drawing.Size(24, 20);
            this.txtData2.TabIndex = 24;
            this.txtData2.Text = "00";
            this.txtData2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData2.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData2.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData1
            // 
            this.txtData1.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData1.Location = new System.Drawing.Point(352, 34);
            this.txtData1.MaxLength = 2;
            this.txtData1.Name = "txtData1";
            this.txtData1.Size = new System.Drawing.Size(24, 20);
            this.txtData1.TabIndex = 23;
            this.txtData1.Text = "00";
            this.txtData1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData1.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // txtData0
            // 
            this.txtData0.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtData0.Location = new System.Drawing.Point(320, 34);
            this.txtData0.MaxLength = 2;
            this.txtData0.Name = "txtData0";
            this.txtData0.Size = new System.Drawing.Size(24, 20);
            this.txtData0.TabIndex = 22;
            this.txtData0.Text = "00";
            this.txtData0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.txtData0.Leave += new System.EventHandler(this.txtData0_Leave);
            this.txtData0.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtID_KeyPress);
            // 
            // nudLength
            // 
            this.nudLength.BackColor = System.Drawing.Color.White;
            this.nudLength.Location = new System.Drawing.Point(177, 34);
            this.nudLength.Maximum = new decimal(new int[] {
            8,
            0,
            0,
            0});
            this.nudLength.Name = "nudLength";
            this.nudLength.ReadOnly = true;
            this.nudLength.Size = new System.Drawing.Size(50, 20);
            this.nudLength.TabIndex = 21;
            this.nudLength.Value = new decimal(new int[] {
            8,
            0,
            0,
            0});
            // 
            // tmrRead
            // 
            this.tmrRead.Interval = 50;
            this.tmrRead.Tick += new System.EventHandler(this.tmrRead_Tick);
            // 
            // tmrDisplay
            // 
            this.tmrDisplay.Tick += new System.EventHandler(this.tmrDisplay_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(754, 572);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "PCAN-Basic Example";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudIdTo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudIdFrom)).EndInit();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudDeviceId)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudLength)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox cbbChannel;
        private System.Windows.Forms.ComboBox cbbHwType;
        private System.Windows.Forms.ComboBox cbbInterrupt;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox cbbIO;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cbbBaudrates;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnRelease;
        private System.Windows.Forms.Button btnInit;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.NumericUpDown nudIdFrom;
        private System.Windows.Forms.RadioButton rdbFilterOpen;
        private System.Windows.Forms.RadioButton rdbFilterCustom;
        private System.Windows.Forms.RadioButton rdbFilterClose;
        private System.Windows.Forms.Button btnFilterApply;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown nudIdTo;
        private System.Windows.Forms.CheckBox chbFilterExt;
        private System.Windows.Forms.Button btnParameterSet;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.RadioButton rdbParamActive;
        private System.Windows.Forms.RadioButton rdbParamInactive;
        private System.Windows.Forms.ComboBox cbbParameter;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.NumericUpDown nudDeviceId;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.RadioButton rdbEvent;
        private System.Windows.Forms.ListView lstMessages;
        private System.Windows.Forms.ColumnHeader clhType;
        private System.Windows.Forms.ColumnHeader clhID;
        private System.Windows.Forms.ColumnHeader clhLength;
        private System.Windows.Forms.ColumnHeader clhData;
        private System.Windows.Forms.ColumnHeader clhCount;
        private System.Windows.Forms.ColumnHeader clhRcvTime;
        private System.Windows.Forms.RadioButton rdbTimer;
        private System.Windows.Forms.RadioButton rdbManual;
        private System.Windows.Forms.Button btnRead;
        private System.Windows.Forms.Button btnMsgClear;
        private System.Windows.Forms.CheckBox chbShowPeriod;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.CheckBox chbRemote;
        private System.Windows.Forms.CheckBox chbExtended;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox txtID;
        private System.Windows.Forms.TextBox txtData7;
        private System.Windows.Forms.TextBox txtData6;
        private System.Windows.Forms.TextBox txtData5;
        private System.Windows.Forms.TextBox txtData4;
        private System.Windows.Forms.TextBox txtData3;
        private System.Windows.Forms.TextBox txtData2;
        private System.Windows.Forms.TextBox txtData1;
        private System.Windows.Forms.TextBox txtData0;
        private System.Windows.Forms.NumericUpDown nudLength;
        private System.Windows.Forms.Button btnWrite;
        private System.Windows.Forms.Button btnInfoClear;
        private System.Windows.Forms.Button btnGetVersions;
        private System.Windows.Forms.Button btnParameterGet;
        private System.Windows.Forms.Button btnFilterQuery;
        private System.Windows.Forms.ListBox lbxInfo;
        private System.Windows.Forms.Timer tmrRead;
        private System.Windows.Forms.Button btnHwRefresh;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.Button btnStatus;
        private System.Windows.Forms.Timer tmrDisplay;
    }
}


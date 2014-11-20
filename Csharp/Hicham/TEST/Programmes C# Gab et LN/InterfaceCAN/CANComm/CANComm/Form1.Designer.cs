namespace CANComm
{
    partial class ComCan
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.buttonConnectRx = new System.Windows.Forms.Button();
            this.buttonRead = new System.Windows.Forms.Button();
            this.Rx0 = new System.Windows.Forms.TextBox();
            this.Rx2 = new System.Windows.Forms.TextBox();
            this.Rx4 = new System.Windows.Forms.TextBox();
            this.Rx6 = new System.Windows.Forms.TextBox();
            this.Rx1 = new System.Windows.Forms.TextBox();
            this.Rx3 = new System.Windows.Forms.TextBox();
            this.Rx5 = new System.Windows.Forms.TextBox();
            this.Rx7 = new System.Windows.Forms.TextBox();
            this.textBoxLenghtRx = new System.Windows.Forms.TextBox();
            this.labelIDRx = new System.Windows.Forms.Label();
            this.labelLongueurRx = new System.Windows.Forms.Label();
            this.groupBoxRx = new System.Windows.Forms.GroupBox();
            this.buttonHist = new System.Windows.Forms.Button();
            this.textBoxRxId = new System.Windows.Forms.TextBox();
            this.comboBoxChanRx = new System.Windows.Forms.ComboBox();
            this.labelVitesseRx = new System.Windows.Forms.Label();
            this.labelCanalRx = new System.Windows.Forms.Label();
            this.comboBoxSpeedRx = new System.Windows.Forms.ComboBox();
            this.groupBoxTx = new System.Windows.Forms.GroupBox();
            this.comboBoxChanTx = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.comboBoxSpeedTx = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.Tx7 = new System.Windows.Forms.TextBox();
            this.Tx6 = new System.Windows.Forms.TextBox();
            this.textBoxIDTx = new System.Windows.Forms.TextBox();
            this.textBoxLenghtTx = new System.Windows.Forms.TextBox();
            this.buttonConnectTx = new System.Windows.Forms.Button();
            this.Tx5 = new System.Windows.Forms.TextBox();
            this.buttonWrite = new System.Windows.Forms.Button();
            this.Tx0 = new System.Windows.Forms.TextBox();
            this.Tx4 = new System.Windows.Forms.TextBox();
            this.Tx1 = new System.Windows.Forms.TextBox();
            this.Tx3 = new System.Windows.Forms.TextBox();
            this.Tx2 = new System.Windows.Forms.TextBox();
            this.tmrRead = new System.Windows.Forms.Timer(this.components);
            this.tmrDisplay = new System.Windows.Forms.Timer(this.components);
            this.groupBoxRx.SuspendLayout();
            this.groupBoxTx.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonConnectRx
            // 
            this.buttonConnectRx.Location = new System.Drawing.Point(353, 48);
            this.buttonConnectRx.Name = "buttonConnectRx";
            this.buttonConnectRx.Size = new System.Drawing.Size(75, 23);
            this.buttonConnectRx.TabIndex = 1;
            this.buttonConnectRx.Text = "Connect";
            this.buttonConnectRx.UseVisualStyleBackColor = true;
            this.buttonConnectRx.Click += new System.EventHandler(this.buttonConnectRx_Click);
            // 
            // buttonRead
            // 
            this.buttonRead.Location = new System.Drawing.Point(353, 98);
            this.buttonRead.Name = "buttonRead";
            this.buttonRead.Size = new System.Drawing.Size(75, 23);
            this.buttonRead.TabIndex = 1;
            this.buttonRead.Text = "Lecture";
            this.buttonRead.UseVisualStyleBackColor = true;
            this.buttonRead.Click += new System.EventHandler(this.buttonRead_Click);
            // 
            // Rx0
            // 
            this.Rx0.Location = new System.Drawing.Point(21, 170);
            this.Rx0.Name = "Rx0";
            this.Rx0.ReadOnly = true;
            this.Rx0.Size = new System.Drawing.Size(42, 20);
            this.Rx0.TabIndex = 2;
            // 
            // Rx2
            // 
            this.Rx2.Location = new System.Drawing.Point(127, 170);
            this.Rx2.Name = "Rx2";
            this.Rx2.ReadOnly = true;
            this.Rx2.Size = new System.Drawing.Size(42, 20);
            this.Rx2.TabIndex = 2;
            // 
            // Rx4
            // 
            this.Rx4.Location = new System.Drawing.Point(233, 170);
            this.Rx4.Name = "Rx4";
            this.Rx4.ReadOnly = true;
            this.Rx4.Size = new System.Drawing.Size(42, 20);
            this.Rx4.TabIndex = 2;
            // 
            // Rx6
            // 
            this.Rx6.Location = new System.Drawing.Point(339, 170);
            this.Rx6.Name = "Rx6";
            this.Rx6.ReadOnly = true;
            this.Rx6.Size = new System.Drawing.Size(42, 20);
            this.Rx6.TabIndex = 2;
            // 
            // Rx1
            // 
            this.Rx1.Location = new System.Drawing.Point(74, 170);
            this.Rx1.Name = "Rx1";
            this.Rx1.ReadOnly = true;
            this.Rx1.Size = new System.Drawing.Size(42, 20);
            this.Rx1.TabIndex = 2;
            // 
            // Rx3
            // 
            this.Rx3.Location = new System.Drawing.Point(180, 170);
            this.Rx3.Name = "Rx3";
            this.Rx3.ReadOnly = true;
            this.Rx3.Size = new System.Drawing.Size(42, 20);
            this.Rx3.TabIndex = 2;
            // 
            // Rx5
            // 
            this.Rx5.Location = new System.Drawing.Point(286, 170);
            this.Rx5.Name = "Rx5";
            this.Rx5.ReadOnly = true;
            this.Rx5.Size = new System.Drawing.Size(42, 20);
            this.Rx5.TabIndex = 2;
            // 
            // Rx7
            // 
            this.Rx7.Location = new System.Drawing.Point(392, 170);
            this.Rx7.Name = "Rx7";
            this.Rx7.ReadOnly = true;
            this.Rx7.Size = new System.Drawing.Size(42, 20);
            this.Rx7.TabIndex = 2;
            // 
            // textBoxLenghtRx
            // 
            this.textBoxLenghtRx.Location = new System.Drawing.Point(82, 126);
            this.textBoxLenghtRx.Name = "textBoxLenghtRx";
            this.textBoxLenghtRx.Size = new System.Drawing.Size(100, 20);
            this.textBoxLenghtRx.TabIndex = 2;
            // 
            // labelIDRx
            // 
            this.labelIDRx.AutoSize = true;
            this.labelIDRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelIDRx.Location = new System.Drawing.Point(24, 103);
            this.labelIDRx.Name = "labelIDRx";
            this.labelIDRx.Size = new System.Drawing.Size(21, 13);
            this.labelIDRx.TabIndex = 4;
            this.labelIDRx.Text = "ID:";
            // 
            // labelLongueurRx
            // 
            this.labelLongueurRx.AutoSize = true;
            this.labelLongueurRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelLongueurRx.Location = new System.Drawing.Point(24, 129);
            this.labelLongueurRx.Name = "labelLongueurRx";
            this.labelLongueurRx.Size = new System.Drawing.Size(55, 13);
            this.labelLongueurRx.TabIndex = 4;
            this.labelLongueurRx.Text = "Longueur:";
            // 
            // groupBoxRx
            // 
            this.groupBoxRx.Controls.Add(this.buttonHist);
            this.groupBoxRx.Controls.Add(this.textBoxRxId);
            this.groupBoxRx.Controls.Add(this.comboBoxChanRx);
            this.groupBoxRx.Controls.Add(this.labelVitesseRx);
            this.groupBoxRx.Controls.Add(this.labelLongueurRx);
            this.groupBoxRx.Controls.Add(this.labelCanalRx);
            this.groupBoxRx.Controls.Add(this.comboBoxSpeedRx);
            this.groupBoxRx.Controls.Add(this.labelIDRx);
            this.groupBoxRx.Controls.Add(this.Rx7);
            this.groupBoxRx.Controls.Add(this.Rx6);
            this.groupBoxRx.Controls.Add(this.textBoxLenghtRx);
            this.groupBoxRx.Controls.Add(this.buttonConnectRx);
            this.groupBoxRx.Controls.Add(this.Rx5);
            this.groupBoxRx.Controls.Add(this.buttonRead);
            this.groupBoxRx.Controls.Add(this.Rx0);
            this.groupBoxRx.Controls.Add(this.Rx4);
            this.groupBoxRx.Controls.Add(this.Rx1);
            this.groupBoxRx.Controls.Add(this.Rx3);
            this.groupBoxRx.Controls.Add(this.Rx2);
            this.groupBoxRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBoxRx.Location = new System.Drawing.Point(12, 12);
            this.groupBoxRx.Name = "groupBoxRx";
            this.groupBoxRx.Size = new System.Drawing.Size(455, 208);
            this.groupBoxRx.TabIndex = 5;
            this.groupBoxRx.TabStop = false;
            this.groupBoxRx.Text = "Réception";
            // 
            // buttonHist
            // 
            this.buttonHist.Location = new System.Drawing.Point(247, 98);
            this.buttonHist.Name = "buttonHist";
            this.buttonHist.Size = new System.Drawing.Size(75, 23);
            this.buttonHist.TabIndex = 24;
            this.buttonHist.Text = "Historique";
            this.buttonHist.UseVisualStyleBackColor = true;
            this.buttonHist.Click += new System.EventHandler(this.buttonHist_Click);
            // 
            // textBoxRxId
            // 
            this.textBoxRxId.Location = new System.Drawing.Point(82, 96);
            this.textBoxRxId.Name = "textBoxRxId";
            this.textBoxRxId.Size = new System.Drawing.Size(100, 20);
            this.textBoxRxId.TabIndex = 23;
            // 
            // comboBoxChanRx
            // 
            this.comboBoxChanRx.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxChanRx.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBoxChanRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBoxChanRx.FormattingEnabled = true;
            this.comboBoxChanRx.Location = new System.Drawing.Point(29, 50);
            this.comboBoxChanRx.Name = "comboBoxChanRx";
            this.comboBoxChanRx.Size = new System.Drawing.Size(153, 21);
            this.comboBoxChanRx.TabIndex = 0;
            this.comboBoxChanRx.SelectedIndexChanged += new System.EventHandler(this.comboBoxChanRx_SelectedIndexChanged);
            // 
            // labelVitesseRx
            // 
            this.labelVitesseRx.AutoSize = true;
            this.labelVitesseRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelVitesseRx.Location = new System.Drawing.Point(188, 32);
            this.labelVitesseRx.Name = "labelVitesseRx";
            this.labelVitesseRx.Size = new System.Drawing.Size(41, 13);
            this.labelVitesseRx.TabIndex = 4;
            this.labelVitesseRx.Text = "Vitesse";
            // 
            // labelCanalRx
            // 
            this.labelCanalRx.AutoSize = true;
            this.labelCanalRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelCanalRx.Location = new System.Drawing.Point(26, 34);
            this.labelCanalRx.Name = "labelCanalRx";
            this.labelCanalRx.Size = new System.Drawing.Size(34, 13);
            this.labelCanalRx.TabIndex = 4;
            this.labelCanalRx.Text = "Canal";
            // 
            // comboBoxSpeedRx
            // 
            this.comboBoxSpeedRx.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxSpeedRx.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBoxSpeedRx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBoxSpeedRx.FormattingEnabled = true;
            this.comboBoxSpeedRx.Location = new System.Drawing.Point(191, 48);
            this.comboBoxSpeedRx.Name = "comboBoxSpeedRx";
            this.comboBoxSpeedRx.Size = new System.Drawing.Size(131, 21);
            this.comboBoxSpeedRx.TabIndex = 0;
            this.comboBoxSpeedRx.SelectedIndexChanged += new System.EventHandler(this.comboBoxSpeedRx_SelectedIndexChanged);
            // 
            // groupBoxTx
            // 
            this.groupBoxTx.Controls.Add(this.comboBoxChanTx);
            this.groupBoxTx.Controls.Add(this.label1);
            this.groupBoxTx.Controls.Add(this.label2);
            this.groupBoxTx.Controls.Add(this.label3);
            this.groupBoxTx.Controls.Add(this.comboBoxSpeedTx);
            this.groupBoxTx.Controls.Add(this.label4);
            this.groupBoxTx.Controls.Add(this.Tx7);
            this.groupBoxTx.Controls.Add(this.Tx6);
            this.groupBoxTx.Controls.Add(this.textBoxIDTx);
            this.groupBoxTx.Controls.Add(this.textBoxLenghtTx);
            this.groupBoxTx.Controls.Add(this.buttonConnectTx);
            this.groupBoxTx.Controls.Add(this.Tx5);
            this.groupBoxTx.Controls.Add(this.buttonWrite);
            this.groupBoxTx.Controls.Add(this.Tx0);
            this.groupBoxTx.Controls.Add(this.Tx4);
            this.groupBoxTx.Controls.Add(this.Tx1);
            this.groupBoxTx.Controls.Add(this.Tx3);
            this.groupBoxTx.Controls.Add(this.Tx2);
            this.groupBoxTx.Location = new System.Drawing.Point(12, 226);
            this.groupBoxTx.Name = "groupBoxTx";
            this.groupBoxTx.Size = new System.Drawing.Size(455, 208);
            this.groupBoxTx.TabIndex = 5;
            this.groupBoxTx.TabStop = false;
            this.groupBoxTx.Text = "Transmission";
            // 
            // comboBoxChanTx
            // 
            this.comboBoxChanTx.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxChanTx.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBoxChanTx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBoxChanTx.FormattingEnabled = true;
            this.comboBoxChanTx.Location = new System.Drawing.Point(29, 52);
            this.comboBoxChanTx.Name = "comboBoxChanTx";
            this.comboBoxChanTx.Size = new System.Drawing.Size(153, 21);
            this.comboBoxChanTx.TabIndex = 5;
            this.comboBoxChanTx.SelectedIndexChanged += new System.EventHandler(this.comboBoxChanTx_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(188, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 20;
            this.label1.Text = "Vitesse";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(24, 131);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 19;
            this.label2.Text = "Longueur:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(26, 36);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 13);
            this.label3.TabIndex = 22;
            this.label3.Text = "Canal";
            // 
            // comboBoxSpeedTx
            // 
            this.comboBoxSpeedTx.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxSpeedTx.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.comboBoxSpeedTx.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBoxSpeedTx.FormattingEnabled = true;
            this.comboBoxSpeedTx.Location = new System.Drawing.Point(191, 50);
            this.comboBoxSpeedTx.Name = "comboBoxSpeedTx";
            this.comboBoxSpeedTx.Size = new System.Drawing.Size(131, 21);
            this.comboBoxSpeedTx.TabIndex = 6;
            this.comboBoxSpeedTx.SelectedIndexChanged += new System.EventHandler(this.comboBoxSpeedTx_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(24, 105);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(21, 13);
            this.label4.TabIndex = 21;
            this.label4.Text = "ID:";
            // 
            // Tx7
            // 
            this.Tx7.Location = new System.Drawing.Point(392, 172);
            this.Tx7.Name = "Tx7";
            this.Tx7.Size = new System.Drawing.Size(42, 20);
            this.Tx7.TabIndex = 16;
            // 
            // Tx6
            // 
            this.Tx6.Location = new System.Drawing.Point(339, 172);
            this.Tx6.Name = "Tx6";
            this.Tx6.Size = new System.Drawing.Size(42, 20);
            this.Tx6.TabIndex = 17;
            // 
            // textBoxIDTx
            // 
            this.textBoxIDTx.Location = new System.Drawing.Point(82, 102);
            this.textBoxIDTx.Name = "textBoxIDTx";
            this.textBoxIDTx.Size = new System.Drawing.Size(100, 20);
            this.textBoxIDTx.TabIndex = 18;
            // 
            // textBoxLenghtTx
            // 
            this.textBoxLenghtTx.Location = new System.Drawing.Point(82, 128);
            this.textBoxLenghtTx.Name = "textBoxLenghtTx";
            this.textBoxLenghtTx.Size = new System.Drawing.Size(100, 20);
            this.textBoxLenghtTx.TabIndex = 18;
            // 
            // buttonConnectTx
            // 
            this.buttonConnectTx.Location = new System.Drawing.Point(353, 50);
            this.buttonConnectTx.Name = "buttonConnectTx";
            this.buttonConnectTx.Size = new System.Drawing.Size(75, 23);
            this.buttonConnectTx.TabIndex = 9;
            this.buttonConnectTx.Text = "Connect";
            this.buttonConnectTx.UseVisualStyleBackColor = true;
            this.buttonConnectTx.Click += new System.EventHandler(this.buttonConnectTx_Click);
            // 
            // Tx5
            // 
            this.Tx5.Location = new System.Drawing.Point(286, 172);
            this.Tx5.Name = "Tx5";
            this.Tx5.Size = new System.Drawing.Size(42, 20);
            this.Tx5.TabIndex = 11;
            // 
            // buttonWrite
            // 
            this.buttonWrite.Location = new System.Drawing.Point(353, 100);
            this.buttonWrite.Name = "buttonWrite";
            this.buttonWrite.Size = new System.Drawing.Size(75, 23);
            this.buttonWrite.TabIndex = 8;
            this.buttonWrite.Text = "Écriture";
            this.buttonWrite.UseVisualStyleBackColor = true;
            this.buttonWrite.Click += new System.EventHandler(this.buttonWrite_Click);
            // 
            // Tx0
            // 
            this.Tx0.Location = new System.Drawing.Point(21, 172);
            this.Tx0.Name = "Tx0";
            this.Tx0.Size = new System.Drawing.Size(42, 20);
            this.Tx0.TabIndex = 15;
            // 
            // Tx4
            // 
            this.Tx4.Location = new System.Drawing.Point(233, 172);
            this.Tx4.Name = "Tx4";
            this.Tx4.Size = new System.Drawing.Size(42, 20);
            this.Tx4.TabIndex = 14;
            // 
            // Tx1
            // 
            this.Tx1.Location = new System.Drawing.Point(74, 172);
            this.Tx1.Name = "Tx1";
            this.Tx1.Size = new System.Drawing.Size(42, 20);
            this.Tx1.TabIndex = 13;
            // 
            // Tx3
            // 
            this.Tx3.Location = new System.Drawing.Point(180, 172);
            this.Tx3.Name = "Tx3";
            this.Tx3.Size = new System.Drawing.Size(42, 20);
            this.Tx3.TabIndex = 10;
            // 
            // Tx2
            // 
            this.Tx2.Location = new System.Drawing.Point(127, 172);
            this.Tx2.Name = "Tx2";
            this.Tx2.Size = new System.Drawing.Size(42, 20);
            this.Tx2.TabIndex = 12;
            // 
            // tmrRead
            // 
            this.tmrRead.Interval = 50;
            this.tmrRead.Tick += new System.EventHandler(this.tmrRead_Tick);
            // 
            // ComCan
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Violet;
            this.ClientSize = new System.Drawing.Size(479, 449);
            this.Controls.Add(this.groupBoxRx);
            this.Controls.Add(this.groupBoxTx);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ComCan";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.Text = "ComCan";
            this.groupBoxRx.ResumeLayout(false);
            this.groupBoxRx.PerformLayout();
            this.groupBoxTx.ResumeLayout(false);
            this.groupBoxTx.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonConnectRx;
        private System.Windows.Forms.Button buttonRead;
        private System.Windows.Forms.TextBox Rx0;
        private System.Windows.Forms.TextBox Rx2;
        private System.Windows.Forms.TextBox Rx4;
        private System.Windows.Forms.TextBox Rx6;
        private System.Windows.Forms.TextBox Rx1;
        private System.Windows.Forms.TextBox Rx3;
        private System.Windows.Forms.TextBox Rx5;
        private System.Windows.Forms.TextBox Rx7;
        private System.Windows.Forms.TextBox textBoxLenghtRx;
        private System.Windows.Forms.Label labelIDRx;
        private System.Windows.Forms.Label labelLongueurRx;
        private System.Windows.Forms.GroupBox groupBoxRx;
        private System.Windows.Forms.GroupBox groupBoxTx;
        private System.Windows.Forms.ComboBox comboBoxChanRx;
        private System.Windows.Forms.Label labelVitesseRx;
        private System.Windows.Forms.Label labelCanalRx;
        private System.Windows.Forms.ComboBox comboBoxSpeedRx;
        private System.Windows.Forms.ComboBox comboBoxChanTx;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox comboBoxSpeedTx;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox Tx7;
        private System.Windows.Forms.TextBox Tx6;
        private System.Windows.Forms.TextBox textBoxIDTx;
        private System.Windows.Forms.TextBox textBoxLenghtTx;
        private System.Windows.Forms.Button buttonConnectTx;
        private System.Windows.Forms.TextBox Tx5;
        private System.Windows.Forms.Button buttonWrite;
        private System.Windows.Forms.TextBox Tx0;
        private System.Windows.Forms.TextBox Tx4;
        private System.Windows.Forms.TextBox Tx1;
        private System.Windows.Forms.TextBox Tx3;
        private System.Windows.Forms.TextBox Tx2;
        private System.Windows.Forms.Timer tmrRead;
        private System.Windows.Forms.Timer tmrDisplay;
        private System.Windows.Forms.TextBox textBoxRxId;
        private System.Windows.Forms.Button buttonHist;
    }
}


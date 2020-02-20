namespace Ysdk_CSharp
{
    partial class Client
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.cmb_barcode = new System.Windows.Forms.ComboBox();
            this.txt_IP = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_SearchCards = new System.Windows.Forms.Button();
            this.btn_bright = new System.Windows.Forms.Button();
            this.btn_volumn = new System.Windows.Forms.Button();
            this.btn_checktime = new System.Windows.Forms.Button();
            this.btn_firmware = new System.Windows.Forms.Button();
            this.btn_onoff = new System.Windows.Forms.Button();
            this.btn_program = new System.Windows.Forms.Button();
            this.btn_DArea = new System.Windows.Forms.Button();
            this.num_volume = new System.Windows.Forms.NumericUpDown();
            this.btn_Screen = new System.Windows.Forms.Button();
            this.btn_capture = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_volume)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.cmb_barcode);
            this.groupBox1.Controls.Add(this.txt_IP);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.btn_SearchCards);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(524, 81);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "查找控制器";
            // 
            // cmb_barcode
            // 
            this.cmb_barcode.FormattingEnabled = true;
            this.cmb_barcode.Location = new System.Drawing.Point(177, 34);
            this.cmb_barcode.Name = "cmb_barcode";
            this.cmb_barcode.Size = new System.Drawing.Size(141, 25);
            this.cmb_barcode.TabIndex = 4;
            this.cmb_barcode.SelectedIndexChanged += new System.EventHandler(this.cmb_barcode_SelectedIndexChanged);
            // 
            // txt_IP
            // 
            this.txt_IP.Location = new System.Drawing.Point(399, 32);
            this.txt_IP.Name = "txt_IP";
            this.txt_IP.ReadOnly = true;
            this.txt_IP.Size = new System.Drawing.Size(110, 23);
            this.txt_IP.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(340, 35);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 17);
            this.label2.TabIndex = 2;
            this.label2.Text = "控制器IP";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(117, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "设备列表";
            // 
            // btn_SearchCards
            // 
            this.btn_SearchCards.Location = new System.Drawing.Point(19, 35);
            this.btn_SearchCards.Name = "btn_SearchCards";
            this.btn_SearchCards.Size = new System.Drawing.Size(75, 23);
            this.btn_SearchCards.TabIndex = 0;
            this.btn_SearchCards.Text = "搜索";
            this.btn_SearchCards.UseVisualStyleBackColor = true;
            this.btn_SearchCards.Click += new System.EventHandler(this.btn_SearchCards_Click);
            // 
            // btn_bright
            // 
            this.btn_bright.Enabled = false;
            this.btn_bright.Location = new System.Drawing.Point(396, 115);
            this.btn_bright.Name = "btn_bright";
            this.btn_bright.Size = new System.Drawing.Size(75, 23);
            this.btn_bright.TabIndex = 12;
            this.btn_bright.Text = "亮度";
            this.btn_bright.UseVisualStyleBackColor = true;
            this.btn_bright.Click += new System.EventHandler(this.btn_bright_Click);
            // 
            // btn_volumn
            // 
            this.btn_volumn.Enabled = false;
            this.btn_volumn.Location = new System.Drawing.Point(50, 158);
            this.btn_volumn.Name = "btn_volumn";
            this.btn_volumn.Size = new System.Drawing.Size(75, 23);
            this.btn_volumn.TabIndex = 11;
            this.btn_volumn.Text = "音量";
            this.btn_volumn.UseVisualStyleBackColor = true;
            this.btn_volumn.Click += new System.EventHandler(this.btn_volumn_Click);
            // 
            // btn_checktime
            // 
            this.btn_checktime.Enabled = false;
            this.btn_checktime.Location = new System.Drawing.Point(281, 115);
            this.btn_checktime.Name = "btn_checktime";
            this.btn_checktime.Size = new System.Drawing.Size(75, 23);
            this.btn_checktime.TabIndex = 10;
            this.btn_checktime.Text = "校时";
            this.btn_checktime.UseVisualStyleBackColor = true;
            this.btn_checktime.Click += new System.EventHandler(this.btn_checktime_Click);
            // 
            // btn_firmware
            // 
            this.btn_firmware.Enabled = false;
            this.btn_firmware.Location = new System.Drawing.Point(166, 115);
            this.btn_firmware.Name = "btn_firmware";
            this.btn_firmware.Size = new System.Drawing.Size(75, 23);
            this.btn_firmware.TabIndex = 9;
            this.btn_firmware.Text = "固件";
            this.btn_firmware.UseVisualStyleBackColor = true;
            this.btn_firmware.Click += new System.EventHandler(this.btn_firmware_Click);
            // 
            // btn_onoff
            // 
            this.btn_onoff.Enabled = false;
            this.btn_onoff.Location = new System.Drawing.Point(51, 115);
            this.btn_onoff.Name = "btn_onoff";
            this.btn_onoff.Size = new System.Drawing.Size(75, 23);
            this.btn_onoff.TabIndex = 8;
            this.btn_onoff.Text = "开关机";
            this.btn_onoff.UseVisualStyleBackColor = true;
            this.btn_onoff.Click += new System.EventHandler(this.btn_onoff_Click);
            // 
            // btn_program
            // 
            this.btn_program.Enabled = false;
            this.btn_program.Location = new System.Drawing.Point(105, 208);
            this.btn_program.Name = "btn_program";
            this.btn_program.Size = new System.Drawing.Size(75, 23);
            this.btn_program.TabIndex = 13;
            this.btn_program.Text = "节目";
            this.btn_program.UseVisualStyleBackColor = true;
            this.btn_program.Click += new System.EventHandler(this.btn_program_Click);
            // 
            // btn_DArea
            // 
            this.btn_DArea.Enabled = false;
            this.btn_DArea.Location = new System.Drawing.Point(312, 208);
            this.btn_DArea.Name = "btn_DArea";
            this.btn_DArea.Size = new System.Drawing.Size(75, 23);
            this.btn_DArea.TabIndex = 14;
            this.btn_DArea.Text = "动态区";
            this.btn_DArea.UseVisualStyleBackColor = true;
            this.btn_DArea.Click += new System.EventHandler(this.btn_DArea_Click);
            // 
            // num_volume
            // 
            this.num_volume.Location = new System.Drawing.Point(132, 159);
            this.num_volume.Name = "num_volume";
            this.num_volume.Size = new System.Drawing.Size(46, 23);
            this.num_volume.TabIndex = 15;
            // 
            // btn_Screen
            // 
            this.btn_Screen.Enabled = false;
            this.btn_Screen.Location = new System.Drawing.Point(245, 157);
            this.btn_Screen.Name = "btn_Screen";
            this.btn_Screen.Size = new System.Drawing.Size(75, 23);
            this.btn_Screen.TabIndex = 16;
            this.btn_Screen.Text = "屏参";
            this.btn_Screen.UseVisualStyleBackColor = true;
            this.btn_Screen.Click += new System.EventHandler(this.btn_Screen_Click);
            // 
            // btn_capture
            // 
            this.btn_capture.Enabled = false;
            this.btn_capture.Location = new System.Drawing.Point(355, 158);
            this.btn_capture.Name = "btn_capture";
            this.btn_capture.Size = new System.Drawing.Size(75, 23);
            this.btn_capture.TabIndex = 17;
            this.btn_capture.Text = "截屏";
            this.btn_capture.UseVisualStyleBackColor = true;
            this.btn_capture.Click += new System.EventHandler(this.btn_capture_Click);
            // 
            // Client
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(548, 248);
            this.Controls.Add(this.btn_capture);
            this.Controls.Add(this.btn_Screen);
            this.Controls.Add(this.num_volume);
            this.Controls.Add(this.btn_DArea);
            this.Controls.Add(this.btn_program);
            this.Controls.Add(this.btn_bright);
            this.Controls.Add(this.btn_volumn);
            this.Controls.Add(this.btn_checktime);
            this.Controls.Add(this.btn_firmware);
            this.Controls.Add(this.btn_onoff);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Client";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Client";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_volume)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox cmb_barcode;
        private System.Windows.Forms.TextBox txt_IP;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_SearchCards;
        private System.Windows.Forms.Button btn_bright;
        private System.Windows.Forms.Button btn_volumn;
        private System.Windows.Forms.Button btn_checktime;
        private System.Windows.Forms.Button btn_firmware;
        private System.Windows.Forms.Button btn_onoff;
        private System.Windows.Forms.Button btn_program;
        private System.Windows.Forms.Button btn_DArea;
        private System.Windows.Forms.NumericUpDown num_volume;
        private System.Windows.Forms.Button btn_Screen;
        private System.Windows.Forms.Button btn_capture;
    }
}
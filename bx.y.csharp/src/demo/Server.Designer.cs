namespace Ysdk_CSharp
{
    partial class Server
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
            this.num_volume = new System.Windows.Forms.NumericUpDown();
            this.btn_DArea = new System.Windows.Forms.Button();
            this.btn_program = new System.Windows.Forms.Button();
            this.btn_bright = new System.Windows.Forms.Button();
            this.btn_volumn = new System.Windows.Forms.Button();
            this.btn_checktime = new System.Windows.Forms.Button();
            this.btn_firmware = new System.Windows.Forms.Button();
            this.btn_onoff = new System.Windows.Forms.Button();
            this.cmb_barcode = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btn_search = new System.Windows.Forms.Button();
            this.btn_stop_server = new System.Windows.Forms.Button();
            this.btn_start_server = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.num_volume)).BeginInit();
            this.SuspendLayout();
            // 
            // num_volume
            // 
            this.num_volume.Location = new System.Drawing.Point(120, 178);
            this.num_volume.Name = "num_volume";
            this.num_volume.Size = new System.Drawing.Size(46, 23);
            this.num_volume.TabIndex = 23;
            // 
            // btn_DArea
            // 
            this.btn_DArea.Enabled = false;
            this.btn_DArea.Location = new System.Drawing.Point(300, 227);
            this.btn_DArea.Name = "btn_DArea";
            this.btn_DArea.Size = new System.Drawing.Size(75, 23);
            this.btn_DArea.TabIndex = 22;
            this.btn_DArea.Text = "动态区";
            this.btn_DArea.UseVisualStyleBackColor = true;
            this.btn_DArea.Click += new System.EventHandler(this.btn_DArea_Click);
            // 
            // btn_program
            // 
            this.btn_program.Enabled = false;
            this.btn_program.Location = new System.Drawing.Point(93, 227);
            this.btn_program.Name = "btn_program";
            this.btn_program.Size = new System.Drawing.Size(75, 23);
            this.btn_program.TabIndex = 21;
            this.btn_program.Text = "节目";
            this.btn_program.UseVisualStyleBackColor = true;
            this.btn_program.Click += new System.EventHandler(this.btn_program_Click);
            // 
            // btn_bright
            // 
            this.btn_bright.Enabled = false;
            this.btn_bright.Location = new System.Drawing.Point(384, 134);
            this.btn_bright.Name = "btn_bright";
            this.btn_bright.Size = new System.Drawing.Size(75, 23);
            this.btn_bright.TabIndex = 20;
            this.btn_bright.Text = "亮度";
            this.btn_bright.UseVisualStyleBackColor = true;
            this.btn_bright.Click += new System.EventHandler(this.btn_bright_Click);
            // 
            // btn_volumn
            // 
            this.btn_volumn.Enabled = false;
            this.btn_volumn.Location = new System.Drawing.Point(38, 177);
            this.btn_volumn.Name = "btn_volumn";
            this.btn_volumn.Size = new System.Drawing.Size(75, 23);
            this.btn_volumn.TabIndex = 19;
            this.btn_volumn.Text = "音量";
            this.btn_volumn.UseVisualStyleBackColor = true;
            this.btn_volumn.Click += new System.EventHandler(this.btn_volumn_Click);
            // 
            // btn_checktime
            // 
            this.btn_checktime.Enabled = false;
            this.btn_checktime.Location = new System.Drawing.Point(269, 134);
            this.btn_checktime.Name = "btn_checktime";
            this.btn_checktime.Size = new System.Drawing.Size(75, 23);
            this.btn_checktime.TabIndex = 18;
            this.btn_checktime.Text = "校时";
            this.btn_checktime.UseVisualStyleBackColor = true;
            this.btn_checktime.Click += new System.EventHandler(this.btn_checktime_Click);
            // 
            // btn_firmware
            // 
            this.btn_firmware.Enabled = false;
            this.btn_firmware.Location = new System.Drawing.Point(154, 134);
            this.btn_firmware.Name = "btn_firmware";
            this.btn_firmware.Size = new System.Drawing.Size(75, 23);
            this.btn_firmware.TabIndex = 17;
            this.btn_firmware.Text = "固件";
            this.btn_firmware.UseVisualStyleBackColor = true;
            this.btn_firmware.Click += new System.EventHandler(this.btn_firmware_Click);
            // 
            // btn_onoff
            // 
            this.btn_onoff.Enabled = false;
            this.btn_onoff.Location = new System.Drawing.Point(39, 134);
            this.btn_onoff.Name = "btn_onoff";
            this.btn_onoff.Size = new System.Drawing.Size(75, 23);
            this.btn_onoff.TabIndex = 16;
            this.btn_onoff.Text = "开关机";
            this.btn_onoff.UseVisualStyleBackColor = true;
            this.btn_onoff.Click += new System.EventHandler(this.btn_onoff_Click);
            // 
            // cmb_barcode
            // 
            this.cmb_barcode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_barcode.FormattingEnabled = true;
            this.cmb_barcode.Location = new System.Drawing.Point(269, 65);
            this.cmb_barcode.Name = "cmb_barcode";
            this.cmb_barcode.Size = new System.Drawing.Size(171, 25);
            this.cmb_barcode.TabIndex = 30;
            this.cmb_barcode.SelectedIndexChanged += new System.EventHandler(this.cmb_barcode_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(209, 69);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 17);
            this.label2.TabIndex = 29;
            this.label2.Text = "设备列表";
            // 
            // btn_search
            // 
            this.btn_search.Enabled = false;
            this.btn_search.Location = new System.Drawing.Point(107, 64);
            this.btn_search.Name = "btn_search";
            this.btn_search.Size = new System.Drawing.Size(75, 23);
            this.btn_search.TabIndex = 28;
            this.btn_search.Text = "搜索";
            this.btn_search.UseVisualStyleBackColor = true;
            this.btn_search.Click += new System.EventHandler(this.btn_search_Click);
            // 
            // btn_stop_server
            // 
            this.btn_stop_server.Enabled = false;
            this.btn_stop_server.Location = new System.Drawing.Point(365, 23);
            this.btn_stop_server.Name = "btn_stop_server";
            this.btn_stop_server.Size = new System.Drawing.Size(75, 23);
            this.btn_stop_server.TabIndex = 27;
            this.btn_stop_server.Text = "关闭服务器";
            this.btn_stop_server.UseVisualStyleBackColor = true;
            this.btn_stop_server.Click += new System.EventHandler(this.btn_stop_server_Click);
            // 
            // btn_start_server
            // 
            this.btn_start_server.Location = new System.Drawing.Point(248, 23);
            this.btn_start_server.Name = "btn_start_server";
            this.btn_start_server.Size = new System.Drawing.Size(75, 23);
            this.btn_start_server.TabIndex = 26;
            this.btn_start_server.Text = "启动服务器";
            this.btn_start_server.UseVisualStyleBackColor = true;
            this.btn_start_server.Click += new System.EventHandler(this.btn_start_server_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(107, 25);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 23);
            this.textBox1.TabIndex = 25;
            this.textBox1.Text = "6005";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(36, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(68, 17);
            this.label1.TabIndex = 24;
            this.label1.Text = "服务器端口";
            // 
            // Server
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(514, 273);
            this.Controls.Add(this.cmb_barcode);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btn_search);
            this.Controls.Add(this.btn_stop_server);
            this.Controls.Add(this.btn_start_server);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.num_volume);
            this.Controls.Add(this.btn_DArea);
            this.Controls.Add(this.btn_program);
            this.Controls.Add(this.btn_bright);
            this.Controls.Add(this.btn_volumn);
            this.Controls.Add(this.btn_checktime);
            this.Controls.Add(this.btn_firmware);
            this.Controls.Add(this.btn_onoff);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Server";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Server";
            ((System.ComponentModel.ISupportInitialize)(this.num_volume)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown num_volume;
        private System.Windows.Forms.Button btn_DArea;
        private System.Windows.Forms.Button btn_program;
        private System.Windows.Forms.Button btn_bright;
        private System.Windows.Forms.Button btn_volumn;
        private System.Windows.Forms.Button btn_checktime;
        private System.Windows.Forms.Button btn_firmware;
        private System.Windows.Forms.Button btn_onoff;
        private System.Windows.Forms.ComboBox cmb_barcode;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btn_search;
        private System.Windows.Forms.Button btn_stop_server;
        private System.Windows.Forms.Button btn_start_server;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label1;
    }
}
namespace Ysdk_CSharp
{
    partial class VidioArea
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
            this.num_height = new System.Windows.Forms.NumericUpDown();
            this.num_width = new System.Windows.Forms.NumericUpDown();
            this.num_Y = new System.Windows.Forms.NumericUpDown();
            this.num_X = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.trackBar2 = new System.Windows.Forms.TrackBar();
            this.label7 = new System.Windows.Forms.Label();
            this.cmb_scale_mode = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.btn_NO = new System.Windows.Forms.Button();
            this.btn_OK = new System.Windows.Forms.Button();
            this.btn_del = new System.Windows.Forms.Button();
            this.btn_addvidio = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.num_play_time = new System.Windows.Forms.NumericUpDown();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.cmb_source = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cmb_volume_mode = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.cmb_video_type = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.cmb_ratation_mode = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.num_height)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_width)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Y)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_X)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_play_time)).BeginInit();
            this.SuspendLayout();
            // 
            // num_height
            // 
            this.num_height.Location = new System.Drawing.Point(428, 11);
            this.num_height.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_height.Name = "num_height";
            this.num_height.Size = new System.Drawing.Size(50, 23);
            this.num_height.TabIndex = 21;
            // 
            // num_width
            // 
            this.num_width.Location = new System.Drawing.Point(324, 12);
            this.num_width.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_width.Name = "num_width";
            this.num_width.Size = new System.Drawing.Size(50, 23);
            this.num_width.TabIndex = 22;
            // 
            // num_Y
            // 
            this.num_Y.Location = new System.Drawing.Point(203, 11);
            this.num_Y.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_Y.Name = "num_Y";
            this.num_Y.Size = new System.Drawing.Size(50, 23);
            this.num_Y.TabIndex = 25;
            // 
            // num_X
            // 
            this.num_X.Location = new System.Drawing.Point(94, 12);
            this.num_X.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_X.Name = "num_X";
            this.num_X.Size = new System.Drawing.Size(50, 23);
            this.num_X.TabIndex = 18;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(399, 13);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(32, 17);
            this.label6.TabIndex = 24;
            this.label6.Text = "高度";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(286, 13);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(32, 17);
            this.label5.TabIndex = 23;
            this.label5.Text = "宽度";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(187, 13);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(15, 17);
            this.label4.TabIndex = 20;
            this.label4.Text = "Y";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(72, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(16, 17);
            this.label3.TabIndex = 19;
            this.label3.Text = "X";
            // 
            // trackBar2
            // 
            this.trackBar2.Location = new System.Drawing.Point(365, 100);
            this.trackBar2.Maximum = 100;
            this.trackBar2.Name = "trackBar2";
            this.trackBar2.Size = new System.Drawing.Size(160, 45);
            this.trackBar2.TabIndex = 32;
            this.trackBar2.TickStyle = System.Windows.Forms.TickStyle.None;
            this.trackBar2.Value = 100;
            this.trackBar2.Scroll += new System.EventHandler(this.trackBar2_Scroll);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(365, 80);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(32, 17);
            this.label7.TabIndex = 31;
            this.label7.Text = "音量";
            // 
            // cmb_scale_mode
            // 
            this.cmb_scale_mode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_scale_mode.FormattingEnabled = true;
            this.cmb_scale_mode.Items.AddRange(new object[] {
            " 按原始比例进行缩放",
            " 按窗口比例进行缩放"});
            this.cmb_scale_mode.Location = new System.Drawing.Point(366, 44);
            this.cmb_scale_mode.Name = "cmb_scale_mode";
            this.cmb_scale_mode.Size = new System.Drawing.Size(146, 25);
            this.cmb_scale_mode.TabIndex = 30;
            this.cmb_scale_mode.SelectedIndexChanged += new System.EventHandler(this.cmb_scale_mode_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(365, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 17);
            this.label1.TabIndex = 29;
            this.label1.Text = "缩放模式";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 17;
            this.listBox1.Location = new System.Drawing.Point(104, 22);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(255, 123);
            this.listBox1.TabIndex = 37;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // btn_NO
            // 
            this.btn_NO.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btn_NO.Location = new System.Drawing.Point(289, 292);
            this.btn_NO.Name = "btn_NO";
            this.btn_NO.Size = new System.Drawing.Size(75, 23);
            this.btn_NO.TabIndex = 36;
            this.btn_NO.Text = "取消";
            this.btn_NO.UseVisualStyleBackColor = true;
            this.btn_NO.Click += new System.EventHandler(this.btn_NO_Click);
            // 
            // btn_OK
            // 
            this.btn_OK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btn_OK.Location = new System.Drawing.Point(109, 292);
            this.btn_OK.Name = "btn_OK";
            this.btn_OK.Size = new System.Drawing.Size(75, 23);
            this.btn_OK.TabIndex = 35;
            this.btn_OK.Text = "确定";
            this.btn_OK.UseVisualStyleBackColor = true;
            this.btn_OK.Click += new System.EventHandler(this.btn_OK_Click);
            // 
            // btn_del
            // 
            this.btn_del.Location = new System.Drawing.Point(13, 101);
            this.btn_del.Name = "btn_del";
            this.btn_del.Size = new System.Drawing.Size(75, 23);
            this.btn_del.TabIndex = 34;
            this.btn_del.Text = "移除";
            this.btn_del.UseVisualStyleBackColor = true;
            this.btn_del.Click += new System.EventHandler(this.btn_del_Click);
            // 
            // btn_addvidio
            // 
            this.btn_addvidio.Location = new System.Drawing.Point(13, 39);
            this.btn_addvidio.Name = "btn_addvidio";
            this.btn_addvidio.Size = new System.Drawing.Size(75, 23);
            this.btn_addvidio.TabIndex = 33;
            this.btn_addvidio.Text = "添加视频";
            this.btn_addvidio.UseVisualStyleBackColor = true;
            this.btn_addvidio.Click += new System.EventHandler(this.btn_addvidio_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.num_play_time);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.label10);
            this.groupBox1.Controls.Add(this.listBox1);
            this.groupBox1.Controls.Add(this.cmb_source);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.cmb_scale_mode);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.btn_del);
            this.groupBox1.Controls.Add(this.trackBar2);
            this.groupBox1.Controls.Add(this.btn_addvidio);
            this.groupBox1.Location = new System.Drawing.Point(12, 99);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(533, 174);
            this.groupBox1.TabIndex = 38;
            this.groupBox1.TabStop = false;
            // 
            // num_play_time
            // 
            this.num_play_time.Location = new System.Drawing.Point(462, 143);
            this.num_play_time.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_play_time.Name = "num_play_time";
            this.num_play_time.Size = new System.Drawing.Size(50, 23);
            this.num_play_time.TabIndex = 47;
            this.num_play_time.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.num_play_time.ValueChanged += new System.EventHandler(this.num_play_time_ValueChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(459, 123);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(56, 17);
            this.label11.TabIndex = 48;
            this.label11.Text = "播放时间";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(372, 121);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(44, 17);
            this.label10.TabIndex = 45;
            this.label10.Text = "视频源";
            // 
            // cmb_source
            // 
            this.cmb_source.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_source.FormattingEnabled = true;
            this.cmb_source.Items.AddRange(new object[] {
            "CVBS",
            "HDMI"});
            this.cmb_source.Location = new System.Drawing.Point(368, 141);
            this.cmb_source.Name = "cmb_source";
            this.cmb_source.Size = new System.Drawing.Size(71, 25);
            this.cmb_source.TabIndex = 46;
            this.cmb_source.SelectedIndexChanged += new System.EventHandler(this.cmb_source_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(98, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 17);
            this.label2.TabIndex = 39;
            this.label2.Text = "是否禁音";
            // 
            // cmb_volume_mode
            // 
            this.cmb_volume_mode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_volume_mode.FormattingEnabled = true;
            this.cmb_volume_mode.Items.AddRange(new object[] {
            "非静音",
            "静音"});
            this.cmb_volume_mode.Location = new System.Drawing.Point(94, 68);
            this.cmb_volume_mode.Name = "cmb_volume_mode";
            this.cmb_volume_mode.Size = new System.Drawing.Size(71, 25);
            this.cmb_volume_mode.TabIndex = 40;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(189, 48);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(56, 17);
            this.label8.TabIndex = 41;
            this.label8.Text = "视频类型";
            // 
            // cmb_video_type
            // 
            this.cmb_video_type.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_video_type.FormattingEnabled = true;
            this.cmb_video_type.Items.AddRange(new object[] {
            "本地视频或网络流媒体",
            "外部输入视频"});
            this.cmb_video_type.Location = new System.Drawing.Point(185, 68);
            this.cmb_video_type.Name = "cmb_video_type";
            this.cmb_video_type.Size = new System.Drawing.Size(143, 25);
            this.cmb_video_type.TabIndex = 42;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(347, 48);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(92, 17);
            this.label9.TabIndex = 43;
            this.label9.Text = "逆时针旋转角度";
            // 
            // cmb_ratation_mode
            // 
            this.cmb_ratation_mode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_ratation_mode.FormattingEnabled = true;
            this.cmb_ratation_mode.Items.AddRange(new object[] {
            "0",
            "90",
            "180",
            "270"});
            this.cmb_ratation_mode.Location = new System.Drawing.Point(343, 68);
            this.cmb_ratation_mode.Name = "cmb_ratation_mode";
            this.cmb_ratation_mode.Size = new System.Drawing.Size(96, 25);
            this.cmb_ratation_mode.TabIndex = 44;
            // 
            // VidioArea
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(557, 324);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.cmb_ratation_mode);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.cmb_video_type);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.cmb_volume_mode);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btn_NO);
            this.Controls.Add(this.btn_OK);
            this.Controls.Add(this.num_height);
            this.Controls.Add(this.num_width);
            this.Controls.Add(this.num_Y);
            this.Controls.Add(this.num_X);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "VidioArea";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "VidioArea";
            ((System.ComponentModel.ISupportInitialize)(this.num_height)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_width)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Y)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_X)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar2)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.num_play_time)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown num_height;
        private System.Windows.Forms.NumericUpDown num_width;
        private System.Windows.Forms.NumericUpDown num_Y;
        private System.Windows.Forms.NumericUpDown num_X;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TrackBar trackBar2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox cmb_scale_mode;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button btn_NO;
        private System.Windows.Forms.Button btn_OK;
        private System.Windows.Forms.Button btn_del;
        private System.Windows.Forms.Button btn_addvidio;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cmb_volume_mode;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox cmb_video_type;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox cmb_ratation_mode;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox cmb_source;
        private System.Windows.Forms.NumericUpDown num_play_time;
        private System.Windows.Forms.Label label11;
    }
}
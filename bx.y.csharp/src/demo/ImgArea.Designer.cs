namespace Ysdk_CSharp
{
    partial class ImgArea
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
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.btn_NO = new System.Windows.Forms.Button();
            this.btn_OK = new System.Windows.Forms.Button();
            this.btn_del = new System.Windows.Forms.Button();
            this.btn_addFile = new System.Windows.Forms.Button();
            this.num_stay_time = new System.Windows.Forms.NumericUpDown();
            this.num_display_speed = new System.Windows.Forms.NumericUpDown();
            this.label14 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.cmb_display_effects = new System.Windows.Forms.ComboBox();
            this.label11 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.num_height)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_width)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Y)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_X)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_stay_time)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_display_speed)).BeginInit();
            this.SuspendLayout();
            // 
            // num_height
            // 
            this.num_height.Location = new System.Drawing.Point(388, 11);
            this.num_height.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_height.Name = "num_height";
            this.num_height.Size = new System.Drawing.Size(50, 23);
            this.num_height.TabIndex = 13;
            // 
            // num_width
            // 
            this.num_width.Location = new System.Drawing.Point(284, 12);
            this.num_width.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_width.Name = "num_width";
            this.num_width.Size = new System.Drawing.Size(50, 23);
            this.num_width.TabIndex = 14;
            // 
            // num_Y
            // 
            this.num_Y.Location = new System.Drawing.Point(163, 11);
            this.num_Y.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_Y.Name = "num_Y";
            this.num_Y.Size = new System.Drawing.Size(50, 23);
            this.num_Y.TabIndex = 17;
            // 
            // num_X
            // 
            this.num_X.Location = new System.Drawing.Point(54, 12);
            this.num_X.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.num_X.Name = "num_X";
            this.num_X.Size = new System.Drawing.Size(50, 23);
            this.num_X.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(359, 13);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(32, 17);
            this.label6.TabIndex = 16;
            this.label6.Text = "高度";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(246, 13);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(32, 17);
            this.label5.TabIndex = 15;
            this.label5.Text = "宽度";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(147, 13);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(15, 17);
            this.label4.TabIndex = 12;
            this.label4.Text = "Y";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(32, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(16, 17);
            this.label3.TabIndex = 11;
            this.label3.Text = "X";
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(187, 41);
            this.trackBar1.Maximum = 255;
            this.trackBar1.Minimum = 1;
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Size = new System.Drawing.Size(204, 45);
            this.trackBar1.TabIndex = 9;
            this.trackBar1.TickStyle = System.Windows.Forms.TickStyle.None;
            this.trackBar1.Value = 255;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(116, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(68, 17);
            this.label2.TabIndex = 8;
            this.label2.Text = "窗口透明度";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 17;
            this.listBox1.Location = new System.Drawing.Point(119, 75);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(257, 157);
            this.listBox1.TabIndex = 29;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // btn_NO
            // 
            this.btn_NO.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btn_NO.Location = new System.Drawing.Point(301, 263);
            this.btn_NO.Name = "btn_NO";
            this.btn_NO.Size = new System.Drawing.Size(75, 23);
            this.btn_NO.TabIndex = 28;
            this.btn_NO.Text = "取消";
            this.btn_NO.UseVisualStyleBackColor = true;
            this.btn_NO.Click += new System.EventHandler(this.btn_NO_Click);
            // 
            // btn_OK
            // 
            this.btn_OK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btn_OK.Location = new System.Drawing.Point(120, 263);
            this.btn_OK.Name = "btn_OK";
            this.btn_OK.Size = new System.Drawing.Size(75, 23);
            this.btn_OK.TabIndex = 27;
            this.btn_OK.Text = "确定";
            this.btn_OK.UseVisualStyleBackColor = true;
            this.btn_OK.Click += new System.EventHandler(this.btn_OK_Click);
            // 
            // btn_del
            // 
            this.btn_del.Location = new System.Drawing.Point(24, 188);
            this.btn_del.Name = "btn_del";
            this.btn_del.Size = new System.Drawing.Size(75, 23);
            this.btn_del.TabIndex = 26;
            this.btn_del.Text = "移除";
            this.btn_del.UseVisualStyleBackColor = true;
            this.btn_del.Click += new System.EventHandler(this.btn_del_Click);
            // 
            // btn_addFile
            // 
            this.btn_addFile.Location = new System.Drawing.Point(24, 94);
            this.btn_addFile.Name = "btn_addFile";
            this.btn_addFile.Size = new System.Drawing.Size(75, 23);
            this.btn_addFile.TabIndex = 25;
            this.btn_addFile.Text = "添加图片";
            this.btn_addFile.UseVisualStyleBackColor = true;
            this.btn_addFile.Click += new System.EventHandler(this.btn_addFile_Click);
            // 
            // num_stay_time
            // 
            this.num_stay_time.Location = new System.Drawing.Point(443, 171);
            this.num_stay_time.Maximum = new decimal(new int[] {
            128,
            0,
            0,
            0});
            this.num_stay_time.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.num_stay_time.Name = "num_stay_time";
            this.num_stay_time.Size = new System.Drawing.Size(57, 23);
            this.num_stay_time.TabIndex = 120;
            this.num_stay_time.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.num_stay_time.ValueChanged += new System.EventHandler(this.num_stay_time_ValueChanged);
            // 
            // num_display_speed
            // 
            this.num_display_speed.Location = new System.Drawing.Point(443, 136);
            this.num_display_speed.Maximum = new decimal(new int[] {
            16,
            0,
            0,
            0});
            this.num_display_speed.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.num_display_speed.Name = "num_display_speed";
            this.num_display_speed.Size = new System.Drawing.Size(75, 23);
            this.num_display_speed.TabIndex = 119;
            this.num_display_speed.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.num_display_speed.ValueChanged += new System.EventHandler(this.num_display_speed_ValueChanged);
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(498, 177);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(20, 17);
            this.label14.TabIndex = 118;
            this.label14.Text = "秒";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(384, 173);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(56, 17);
            this.label13.TabIndex = 117;
            this.label13.Text = "停留时间";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(383, 138);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(56, 17);
            this.label12.TabIndex = 116;
            this.label12.Text = "运行速度";
            // 
            // cmb_display_effects
            // 
            this.cmb_display_effects.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_display_effects.FormattingEnabled = true;
            this.cmb_display_effects.Items.AddRange(new object[] {
            "快速打出\t\t",
            "随机\t\t\t",
            "静止显示\t\t",
            "向上推入\t\t",
            "向下推入\t\t",
            "向左推入\t\t",
            "向右推入\t\t",
            "从上移入\t\t",
            "从下移入",
            "从左移入\t\t\t",
            "从右移入\t\t\t",
            "向上堆积\t\t",
            "向下堆积\t\t",
            "向左堆积\t\t",
            "向右堆积\t\t",
            "向上拉幕\t\t",
            "向下拉幕\t\t",
            "向左拉幕\t\t",
            "向右拉幕\t\t",
            "左上角拉幕\t\t",
            "右上角拉幕\t\t",
            "左下角拉幕\t\t",
            "右下角拉幕\t\t",
            "四周往中心拉幕\t",
            "从四角拉幕进入\t",
            "从四角拉幕退出\t",
            "左右交叉拉幕\t",
            "上下交叉拉幕\t",
            "垂直百叶\t\t",
            "水平百叶\t\t",
            "上下闭合\t\t",
            "上下对开\t\t",
            "左右开幕\t\t",
            "左右闭合\t\t",
            "中心放大\t\t",
            "马赛克\t\t\t",
            "淡入淡出\t\t",
            "条式擦除\t",
            "中心往四周拉幕（矩形） \t",
            "中心缩小\t",
            "中心缩小（拖尾\t",
            "向左拉伸\t",
            "向右拉伸 \t",
            "平滑向上推入 \t",
            "平滑向下推入 ",
            "平滑向左推入 ",
            "平滑向右推入",
            "平滑向下移入 ",
            "平滑向上移入 ",
            "平滑向右移入 ",
            "平滑向左移入 "});
            this.cmb_display_effects.Location = new System.Drawing.Point(443, 103);
            this.cmb_display_effects.Name = "cmb_display_effects";
            this.cmb_display_effects.Size = new System.Drawing.Size(75, 25);
            this.cmb_display_effects.TabIndex = 115;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(384, 107);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(56, 17);
            this.label11.TabIndex = 114;
            this.label11.Text = "显示特技";
            // 
            // ImgArea
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(543, 303);
            this.Controls.Add(this.num_stay_time);
            this.Controls.Add(this.num_display_speed);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.cmb_display_effects);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.btn_NO);
            this.Controls.Add(this.btn_OK);
            this.Controls.Add(this.btn_del);
            this.Controls.Add(this.btn_addFile);
            this.Controls.Add(this.num_height);
            this.Controls.Add(this.num_width);
            this.Controls.Add(this.num_Y);
            this.Controls.Add(this.num_X);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.trackBar1);
            this.Controls.Add(this.label2);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ImgArea";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "ImgArea";
            ((System.ComponentModel.ISupportInitialize)(this.num_height)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_width)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_Y)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_X)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_stay_time)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.num_display_speed)).EndInit();
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
        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button btn_NO;
        private System.Windows.Forms.Button btn_OK;
        private System.Windows.Forms.Button btn_del;
        private System.Windows.Forms.Button btn_addFile;
        private System.Windows.Forms.NumericUpDown num_stay_time;
        private System.Windows.Forms.NumericUpDown num_display_speed;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.ComboBox cmb_display_effects;
        private System.Windows.Forms.Label label11;
    }
}
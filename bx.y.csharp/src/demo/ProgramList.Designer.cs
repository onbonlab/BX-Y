namespace Ysdk_CSharp
{
    partial class ProgramList
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
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btn_LocalTempDir = new System.Windows.Forms.Button();
            this.txt_LocalTempDir = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btn_SendProgram = new System.Windows.Forms.Button();
            this.btn_delProgram = new System.Windows.Forms.Button();
            this.btn_AddProgram = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button5 = new System.Windows.Forms.Button();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btn_LocalTempDir);
            this.groupBox2.Controls.Add(this.txt_LocalTempDir);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Location = new System.Drawing.Point(2, 196);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(518, 61);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "本地文件夹";
            // 
            // btn_LocalTempDir
            // 
            this.btn_LocalTempDir.Location = new System.Drawing.Point(445, 28);
            this.btn_LocalTempDir.Name = "btn_LocalTempDir";
            this.btn_LocalTempDir.Size = new System.Drawing.Size(57, 23);
            this.btn_LocalTempDir.TabIndex = 7;
            this.btn_LocalTempDir.Text = "浏览";
            this.btn_LocalTempDir.UseVisualStyleBackColor = true;
            this.btn_LocalTempDir.Click += new System.EventHandler(this.btn_LocalTempDir_Click);
            // 
            // txt_LocalTempDir
            // 
            this.txt_LocalTempDir.Enabled = false;
            this.txt_LocalTempDir.Location = new System.Drawing.Point(227, 28);
            this.txt_LocalTempDir.Name = "txt_LocalTempDir";
            this.txt_LocalTempDir.Size = new System.Drawing.Size(211, 23);
            this.txt_LocalTempDir.TabIndex = 6;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 31);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(215, 17);
            this.label2.TabIndex = 5;
            this.label2.Text = "本地临时存放节目或任务文件的文件夹:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btn_SendProgram);
            this.groupBox1.Controls.Add(this.btn_delProgram);
            this.groupBox1.Controls.Add(this.btn_AddProgram);
            this.groupBox1.Controls.Add(this.listBox1);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(2, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(518, 188);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "节目";
            // 
            // btn_SendProgram
            // 
            this.btn_SendProgram.Location = new System.Drawing.Point(348, 136);
            this.btn_SendProgram.Name = "btn_SendProgram";
            this.btn_SendProgram.Size = new System.Drawing.Size(75, 23);
            this.btn_SendProgram.TabIndex = 5;
            this.btn_SendProgram.Text = "发送节目";
            this.btn_SendProgram.UseVisualStyleBackColor = true;
            this.btn_SendProgram.Click += new System.EventHandler(this.btn_SendProgram_Click);
            // 
            // btn_delProgram
            // 
            this.btn_delProgram.Location = new System.Drawing.Point(70, 136);
            this.btn_delProgram.Name = "btn_delProgram";
            this.btn_delProgram.Size = new System.Drawing.Size(75, 23);
            this.btn_delProgram.TabIndex = 4;
            this.btn_delProgram.Text = "删除节目";
            this.btn_delProgram.UseVisualStyleBackColor = true;
            this.btn_delProgram.Click += new System.EventHandler(this.btn_delProgram_Click);
            // 
            // btn_AddProgram
            // 
            this.btn_AddProgram.Location = new System.Drawing.Point(70, 48);
            this.btn_AddProgram.Name = "btn_AddProgram";
            this.btn_AddProgram.Size = new System.Drawing.Size(75, 23);
            this.btn_AddProgram.TabIndex = 2;
            this.btn_AddProgram.Text = "添加节目";
            this.btn_AddProgram.UseVisualStyleBackColor = true;
            this.btn_AddProgram.Click += new System.EventHandler(this.btn_AddProgram_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 17;
            this.listBox1.Location = new System.Drawing.Point(151, 36);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(120, 123);
            this.listBox1.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(186, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "播放列表";
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(287, 4);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(75, 23);
            this.button5.TabIndex = 5;
            this.button5.Text = "发送节目";
            this.button5.UseVisualStyleBackColor = true;
            // 
            // ProgramList
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(527, 266);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.button5);
            this.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ProgramList";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "ProgramList";
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btn_LocalTempDir;
        private System.Windows.Forms.TextBox txt_LocalTempDir;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btn_SendProgram;
        private System.Windows.Forms.Button btn_delProgram;
        private System.Windows.Forms.Button btn_AddProgram;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button5;
    }
}
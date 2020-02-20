namespace Ysdk_CSharp
{
    partial class Capture
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
            this.txt_programName = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.txt_ScreenH = new System.Windows.Forms.TextBox();
            this.txt_ScreenW = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Btn_GetScreen = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txt_programName
            // 
            this.txt_programName.Location = new System.Drawing.Point(70, 48);
            this.txt_programName.Name = "txt_programName";
            this.txt_programName.Size = new System.Drawing.Size(100, 21);
            this.txt_programName.TabIndex = 45;
            this.txt_programName.Text = "D:\\\\1.bmp\r\n";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(12, 51);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(53, 12);
            this.label10.TabIndex = 44;
            this.label10.Text = "保存路径";
            // 
            // txt_ScreenH
            // 
            this.txt_ScreenH.Location = new System.Drawing.Point(246, 21);
            this.txt_ScreenH.Name = "txt_ScreenH";
            this.txt_ScreenH.ReadOnly = true;
            this.txt_ScreenH.Size = new System.Drawing.Size(100, 21);
            this.txt_ScreenH.TabIndex = 43;
            // 
            // txt_ScreenW
            // 
            this.txt_ScreenW.Location = new System.Drawing.Point(70, 21);
            this.txt_ScreenW.Name = "txt_ScreenW";
            this.txt_ScreenW.ReadOnly = true;
            this.txt_ScreenW.Size = new System.Drawing.Size(100, 21);
            this.txt_ScreenW.TabIndex = 42;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(199, 24);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 41;
            this.label2.Text = "高度";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 40;
            this.label1.Text = "宽度";
            // 
            // Btn_GetScreen
            // 
            this.Btn_GetScreen.Location = new System.Drawing.Point(221, 65);
            this.Btn_GetScreen.Name = "Btn_GetScreen";
            this.Btn_GetScreen.Size = new System.Drawing.Size(75, 23);
            this.Btn_GetScreen.TabIndex = 46;
            this.Btn_GetScreen.Text = "截屏";
            this.Btn_GetScreen.UseVisualStyleBackColor = true;
            this.Btn_GetScreen.Click += new System.EventHandler(this.Btn_GetScreen_Click);
            // 
            // Capture
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(354, 100);
            this.Controls.Add(this.Btn_GetScreen);
            this.Controls.Add(this.txt_programName);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.txt_ScreenH);
            this.Controls.Add(this.txt_ScreenW);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Capture";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Capture";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txt_programName;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox txt_ScreenH;
        private System.Windows.Forms.TextBox txt_ScreenW;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Btn_GetScreen;
    }
}
namespace Ysdk_CSharp
{
    partial class Screen
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
            this.cmb_ScreenType = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txt_ScreenH = new System.Windows.Forms.TextBox();
            this.txt_ScreenW = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_Screen = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // cmb_ScreenType
            // 
            this.cmb_ScreenType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmb_ScreenType.Enabled = false;
            this.cmb_ScreenType.FormattingEnabled = true;
            this.cmb_ScreenType.Items.AddRange(new object[] {
            "BX-Y04",
            "BX-Y08",
            "BX-Y2",
            "BX-Y2L",
            "BX-Y3"});
            this.cmb_ScreenType.Location = new System.Drawing.Point(79, 51);
            this.cmb_ScreenType.Name = "cmb_ScreenType";
            this.cmb_ScreenType.Size = new System.Drawing.Size(98, 20);
            this.cmb_ScreenType.TabIndex = 43;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(17, 54);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(53, 12);
            this.label9.TabIndex = 42;
            this.label9.Text = "屏幕型号";
            // 
            // txt_ScreenH
            // 
            this.txt_ScreenH.Location = new System.Drawing.Point(245, 25);
            this.txt_ScreenH.Name = "txt_ScreenH";
            this.txt_ScreenH.ReadOnly = true;
            this.txt_ScreenH.Size = new System.Drawing.Size(100, 21);
            this.txt_ScreenH.TabIndex = 41;
            // 
            // txt_ScreenW
            // 
            this.txt_ScreenW.Location = new System.Drawing.Point(77, 25);
            this.txt_ScreenW.Name = "txt_ScreenW";
            this.txt_ScreenW.ReadOnly = true;
            this.txt_ScreenW.Size = new System.Drawing.Size(100, 21);
            this.txt_ScreenW.TabIndex = 40;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(198, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 39;
            this.label2.Text = "高度";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(30, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 38;
            this.label1.Text = "宽度";
            // 
            // btn_Screen
            // 
            this.btn_Screen.Location = new System.Drawing.Point(245, 54);
            this.btn_Screen.Name = "btn_Screen";
            this.btn_Screen.Size = new System.Drawing.Size(75, 23);
            this.btn_Screen.TabIndex = 44;
            this.btn_Screen.Text = "设置";
            this.btn_Screen.UseVisualStyleBackColor = true;
            this.btn_Screen.Click += new System.EventHandler(this.btn_Screen_Click);
            // 
            // Screen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(371, 90);
            this.Controls.Add(this.btn_Screen);
            this.Controls.Add(this.cmb_ScreenType);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txt_ScreenH);
            this.Controls.Add(this.txt_ScreenW);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Screen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Screen";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cmb_ScreenType;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txt_ScreenH;
        private System.Windows.Forms.TextBox txt_ScreenW;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_Screen;
    }
}
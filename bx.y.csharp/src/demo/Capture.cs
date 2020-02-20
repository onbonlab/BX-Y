using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Ysdk_CSharp
{
    public partial class Capture : Form
    {
        public Capture()
        {
            InitializeComponent();
            txt_ScreenW.Text = Variable.p_width.ToString();
            txt_ScreenH.Text = Variable.p_height.ToString();
        }

        private void Btn_GetScreen_Click(object sender, EventArgs e)
        {
            int w =int.Parse(txt_ScreenW.Text);
            int h = int.Parse(txt_ScreenH.Text);
            int err = LedYNetSdk.get_screen_capture(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, txt_programName.Text, w, h);
            if (err == 0) { MessageBox.Show("成功"); }
            else { MessageBox.Show("失败：" + err); }
        }
    }
}

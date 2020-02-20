using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Ysdk_CSharp
{
    public partial class Bright : Form
    {
        public Bright()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)//调亮
        {
            if (radioButton1.Checked == true)
            {
                int err = LedYNetSdk.set_screen_brightness(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, int.Parse(textBox1.Text));
            }
            else
            {
                ushort[] brightness = new ushort[48];
                brightness[0] = Convert.ToUInt16(textBox2.Text);
                brightness[1] = Convert.ToUInt16(textBox3.Text);
                brightness[2] = Convert.ToUInt16(textBox4.Text);
                brightness[3] = Convert.ToUInt16(textBox5.Text);
                brightness[4] = Convert.ToUInt16(textBox6.Text);
                brightness[5] = Convert.ToUInt16(textBox7.Text);
                brightness[6] = Convert.ToUInt16(textBox8.Text);
                brightness[7] = Convert.ToUInt16(textBox9.Text);
                brightness[8] = Convert.ToUInt16(textBox10.Text);
                brightness[9] = Convert.ToUInt16(textBox11.Text);
                brightness[10] = Convert.ToUInt16(textBox12.Text);
                brightness[11] = Convert.ToUInt16(textBox13.Text);
                brightness[12] = Convert.ToUInt16(textBox14.Text);
                brightness[13] = Convert.ToUInt16(textBox15.Text);
                brightness[14] = Convert.ToUInt16(textBox16.Text);
                brightness[15] = Convert.ToUInt16(textBox17.Text);
                brightness[16] = Convert.ToUInt16(textBox18.Text);
                brightness[17] = Convert.ToUInt16(textBox19.Text);
                brightness[18] = Convert.ToUInt16(textBox20.Text);
                brightness[19] = Convert.ToUInt16(textBox21.Text);
                brightness[20] = Convert.ToUInt16(textBox22.Text);
                brightness[21] = Convert.ToUInt16(textBox23.Text);
                brightness[22] = Convert.ToUInt16(textBox24.Text);
                brightness[23] = Convert.ToUInt16(textBox25.Text);
                brightness[24] = Convert.ToUInt16(textBox26.Text);
                brightness[25] = Convert.ToUInt16(textBox27.Text);
                brightness[26] = Convert.ToUInt16(textBox28.Text);
                brightness[27] = Convert.ToUInt16(textBox29.Text);
                brightness[28] = Convert.ToUInt16(textBox30.Text);
                brightness[29] = Convert.ToUInt16(textBox31.Text);
                brightness[30] = Convert.ToUInt16(textBox32.Text);
                brightness[31] = Convert.ToUInt16(textBox33.Text);
                brightness[32] = Convert.ToUInt16(textBox34.Text);
                brightness[33] = Convert.ToUInt16(textBox35.Text);
                brightness[34] = Convert.ToUInt16(textBox36.Text);
                brightness[35] = Convert.ToUInt16(textBox37.Text);
                brightness[36] = Convert.ToUInt16(textBox38.Text);
                brightness[37] = Convert.ToUInt16(textBox39.Text);
                brightness[38] = Convert.ToUInt16(textBox40.Text);
                brightness[39] = Convert.ToUInt16(textBox41.Text);
                brightness[40] = Convert.ToUInt16(textBox42.Text);
                brightness[41] = Convert.ToUInt16(textBox43.Text);
                brightness[42] = Convert.ToUInt16(textBox44.Text);
                brightness[43] = Convert.ToUInt16(textBox45.Text);
                brightness[44] = Convert.ToUInt16(textBox46.Text);
                brightness[45] = Convert.ToUInt16(textBox47.Text);
                brightness[46] = Convert.ToUInt16(textBox48.Text);
                brightness[47] = Convert.ToByte(textBox49.Text);
                int err = LedYNetSdk.set_screen_cus_brightness(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, brightness, 48);
            }
        }

        private void Bright_Load(object sender, EventArgs e)
        {
            if (Variable.p_brigtness_mode==0) { radioButton1.Checked = true; }
            else{radioButton2.Checked = true;}
        }
    }
}

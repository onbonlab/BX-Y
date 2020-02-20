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
    public partial class OnOff : Form
    {
        public OnOff()
        {
            InitializeComponent();
            radio_ON.Checked = true;
        }

        private void radio_ON_CheckedChanged(object sender, EventArgs e)
        {
            if (radio_ON.Checked)
            {
                int err = LedYNetSdk.set_screen_turnonoff(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, 1);
                if (err != 0)
                {
                    //LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
                groupBox2.Enabled = false;
            }
        }

        private void radio_OFF_CheckedChanged(object sender, EventArgs e)
        {
            if (radio_OFF.Checked)
            {
                int err = LedYNetSdk.set_screen_turnonoff(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, 0);
                if (err != 0)
                {
                    //LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
                groupBox2.Enabled = false;
            }
        }

        private void radio_TimeOnOff_CheckedChanged(object sender, EventArgs e)
        {
            if (radio_TimeOnOff.Checked)
            {
                groupBox2.Enabled = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (checkBox1.Checked || checkBox2.Checked || checkBox3.Checked || checkBox4.Checked)
            {
                IntPtr trunonoff = LedYNetSdk.create_turnonoff();
                if (checkBox1.Checked)
                {
                    LedYNetSdk.add_turnonoff(trunonoff, 1, DateTime.Parse(dateTimePicker1.Text).TimeOfDay.ToString());
                    LedYNetSdk.add_turnonoff(trunonoff, 0, DateTime.Parse(dateTimePicker2.Text).TimeOfDay.ToString());
                }
                if (checkBox2.Checked)
                {
                    LedYNetSdk.add_turnonoff(trunonoff, 1, DateTime.Parse(dateTimePicker3.Text).TimeOfDay.ToString());
                    LedYNetSdk.add_turnonoff(trunonoff, 0, DateTime.Parse(dateTimePicker4.Text).TimeOfDay.ToString());
                }
                if (checkBox3.Checked)
                {
                    LedYNetSdk.add_turnonoff(trunonoff, 1, DateTime.Parse(dateTimePicker5.Text).TimeOfDay.ToString());
                    LedYNetSdk.add_turnonoff(trunonoff, 0, DateTime.Parse(dateTimePicker6.Text).TimeOfDay.ToString());
                }
                if (checkBox4.Checked)
                {
                    LedYNetSdk.add_turnonoff(trunonoff, 1, DateTime.Parse(dateTimePicker7.Text).TimeOfDay.ToString());
                    LedYNetSdk.add_turnonoff(trunonoff, 0, DateTime.Parse(dateTimePicker8.Text).TimeOfDay.ToString());
                }
                int err = LedYNetSdk.set_screen_cus_turnonoff(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, trunonoff);
                LedYNetSdk.delete_turnonoff(trunonoff);
            }
            else { MessageBox.Show("未设置时间！！！"); }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked) 
            {
                dateTimePicker1.Enabled = true;
                dateTimePicker2.Enabled = true;
            }
            else
            {
                dateTimePicker1.Enabled = false;
                dateTimePicker2.Enabled = false;
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                dateTimePicker3.Enabled = true;
                dateTimePicker4.Enabled = true;
            }
            else
            {
                dateTimePicker3.Enabled = false;
                dateTimePicker4.Enabled = false;
            }
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox3.Checked)
            {
                dateTimePicker5.Enabled = true;
                dateTimePicker6.Enabled = true;
            }
            else
            {
                dateTimePicker5.Enabled = false;
                dateTimePicker6.Enabled = false;
            }
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked)
            {
                dateTimePicker7.Enabled = true;
                dateTimePicker8.Enabled = true;
            }
            else
            {
                dateTimePicker7.Enabled = false;
                dateTimePicker8.Enabled = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int err = LedYNetSdk.cancel_screen_cus_turnonoff(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str);
        }
    }
}

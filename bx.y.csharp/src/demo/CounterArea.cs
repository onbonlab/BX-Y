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
    public partial class CounterArea : Form
    {
        public LedYSDK.PicArea picArea = new LedYSDK.PicArea();
        public CounterArea()
        {
            InitializeComponent();
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_positive_te.SelectedIndex = 0;
            cmbD_font.SelectedIndex = 0;
            cmb_font.SelectedIndex = 0;
            num_X.Maximum = Variable.p_width;
            num_DX.Maximum = Variable.p_width;
            num_SX.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_DY.Maximum = Variable.p_height;
            num_SY.Maximum = Variable.p_height;
            num_width.Maximum = Variable.p_width;
            num_height.Maximum = Variable.p_height;
        }

        private void btn_OK_Click(object sender, EventArgs e)
        {
            if (check_day.Checked || check_hour.Checked || check_min.Checked || check_sec.Checked)
            {
            LedYSDK.Counter_Area Counter_Area;
            Counter_Area.bg_color = Variable.ToHexColor(btn_bg_color.BackColor);
            Counter_Area.time_equation = txt_time_equation.Text;
            Counter_Area.positive_te = cmb_positive_te.Items[cmb_positive_te.SelectedIndex].ToString();
            Counter_Area.target_date = dateTimePicker1.Text;
            Counter_Area.target_time = dateTimePicker2.Text;
            Counter_Area.content = "";
            if (check_day.Checked) { Counter_Area.content += "dd天"; }
            if (check_hour.Checked) { Counter_Area.content += "hh时"; }
            if (check_min.Checked) { Counter_Area.content += "mm分"; }
            if (check_sec.Checked) { Counter_Area.content += "ss秒"; }
            Counter_Area.font_color = Variable.ToHexColor(btnD_font_color.BackColor);
            Counter_Area.font_name = cmbD_font.Items[cmbD_font.SelectedIndex].ToString();
            Counter_Area.font_size = (int)numD_fontSize.Value;
            Counter_Area.content_x = (int)num_DX.Value;
            Counter_Area.content_y = (int)num_DY.Value;
            if (checkD_bold.Checked && checkD_italic.Checked)
            {
                Counter_Area.font_attributes = "bold&italic";
            }
            else if (checkD_bold.Checked)
            {
                Counter_Area.font_attributes = "bold";
            }
            else if (checkD_italic.Checked)
            {
                Counter_Area.font_attributes = "italic";
            }
            else
            {
                Counter_Area.font_attributes = "normal";
            }
            Counter_Area.add_enable = "yes";


            Counter_Area.t_write = checkText.Checked;
            Counter_Area.t_bg_color = "0xff000000";
            Counter_Area.t_time_equation = "00:00:00";
            Counter_Area.t_positive_te = cmb_positive_te.Items[cmb_positive_te.SelectedIndex].ToString();
            Counter_Area.t_content = txt_str.Text;
            Counter_Area.t_font_color = Variable.ToHexColor(btn_font_color.BackColor);
            Counter_Area.t_font_name = cmb_font.Items[cmb_font.SelectedIndex].ToString();
            Counter_Area.t_font_size = (int)num_fontSize.Value;
            Counter_Area.t_x = (int)num_SX.Value;
            Counter_Area.t_y = (int)num_SY.Value;
            if (check_bold.Checked && check_italic.Checked)
            {
                Counter_Area.t_font_attributes = "bold&italic";
            }
            else if (check_bold.Checked)
            {
                Counter_Area.t_font_attributes = "bold";
            }
            else if (check_italic.Checked)
            {
                Counter_Area.t_font_attributes = "italic";
            }
            else
            {
                Counter_Area.t_font_attributes = "normal";
            }

            picArea.thing = 6;
            picArea.m_x = (int)num_X.Value;
            picArea.m_y = (int)num_Y.Value;
            picArea.m_w = (int)num_width.Value;
            picArea.m_h = (int)num_height.Value;
            picArea.m_Transparent = (int)trackBar1.Value;
            picArea.m_Counter_Area = Counter_Area;
            this.Close();
            }
            else { MessageBox.Show("未选中"); }
        }

        private void btn_NO_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnD_font_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btnD_font_color.BackColor = col.Color;
            }
        }

        private void btn_bg_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btn_bg_color.BackColor = col.Color;
            }
        }

        private void btn_font_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btn_font_color.BackColor = col.Color;
            }
        }
    }
}

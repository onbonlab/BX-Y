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
    public partial class ClockAreas : Form
    {
        public LedYSDK.PicArea picArea = new LedYSDK.PicArea();
        public ClockAreas()
        {
            InitializeComponent();
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_positive_te.SelectedIndex = 0;
            cmb_font.SelectedIndex = 0;
            num_X.Maximum = Variable.p_width;
            num_SX.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_SY.Maximum = Variable.p_height;
            num_width.Maximum = Variable.p_width;
            num_height.Maximum = Variable.p_height;
        }

        private void btn_NO_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btn_OK_Click(object sender, EventArgs e)
        {
            if (txt_img.Text == "") { MessageBox.Show("未选中"); }
            else
            {
                LedYSDK.Clock_Area Clock_Area;
                Clock_Area.time_equation = txt_time_equation.Text;
                Clock_Area.positive_te = cmb_positive_te.Items[cmb_positive_te.SelectedIndex].ToString();
                Clock_Area.hour_color = Variable.ToHexColor(btn_hour_color.BackColor);
                Clock_Area.minute_color = Variable.ToHexColor(btn_minute_color.BackColor);
                Clock_Area.second_color = Variable.ToHexColor(btn_second_color.BackColor);
                Clock_Area.bg_image = txt_img.Text;

                Clock_Area.t_write = checkText.Checked;
                Clock_Area.t_bg_color = Variable.ToHexColor(btn_bg_color.BackColor);
                Clock_Area.t_time_equation = "00:00:00";
                Clock_Area.t_positive_te = cmb_positive_te.Items[cmb_positive_te.SelectedIndex].ToString();
                Clock_Area.t_content = txt_str.Text;
                Clock_Area.t_font_color = Variable.ToHexColor(btn_font_color.BackColor);
                Clock_Area.t_font_name = cmb_font.Items[cmb_font.SelectedIndex].ToString();
                Clock_Area.t_font_size = (int)num_fontSize.Value;
                Clock_Area.t_x = (int)num_SX.Value;
                Clock_Area.t_y = (int)num_SY.Value;
                if (check_bold.Checked && check_italic.Checked)
                {
                    Clock_Area.t_font_attributes = "bold&italic";
                }
                else if (check_bold.Checked)
                {
                    Clock_Area.t_font_attributes = "bold";
                }
                else if (check_italic.Checked)
                {
                    Clock_Area.t_font_attributes = "italic";
                }
                else
                {
                    Clock_Area.t_font_attributes = "normal";
                }

                picArea.thing = 4;
                picArea.m_x = (int)num_X.Value;
                picArea.m_y = (int)num_Y.Value;
                picArea.m_w = (int)num_width.Value;
                picArea.m_h = (int)num_height.Value;
                picArea.m_Transparent = (int)trackBar1.Value;
                picArea.m_Clock_Area = Clock_Area;
                this.Close();
            }
        }

        private void btn_addFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "所有支持文件|*.bmp;*.jpg;*.png;*.gif";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                txt_img.Text = openFileDialog1.FileName;
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

        private void btn_hour_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btn_hour_color.BackColor = col.Color;
            }
        }

        private void btn_minute_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btn_minute_color.BackColor = col.Color;
            }
        }

        private void btn_second_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btn_second_color.BackColor = col.Color;
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

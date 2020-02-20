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
    public partial class LunArea : Form
    {
        public LedYSDK.PicArea picArea = new LedYSDK.PicArea();
        public List<LedYSDK.Lun> pic = new List<LedYSDK.Lun>();
        public LunArea()
        {
            InitializeComponent();
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_positive_te.SelectedIndex = 0;
            cmbD_font.SelectedIndex = 0;
            cmbT_font.SelectedIndex = 0;
            cmbW_font.SelectedIndex = 0;
            cmb_font.SelectedIndex = 0;
            num_X.Maximum = Variable.p_width;
            num_DX.Maximum = Variable.p_width;
            num_TX.Maximum = Variable.p_width;
            num_WX.Maximum = Variable.p_width;
            num_SX.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_DY.Maximum = Variable.p_height;
            num_TY.Maximum = Variable.p_height;
            num_WY.Maximum = Variable.p_height;
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
            if (checkday.Checked || checkTime.Checked || checkWeek.Checked || checkText.Checked)
            {
                LedYSDK.Lun_Area Lun_Area;
                if (checkday.Checked)
                {
                    LedYSDK.Lun Lun;
                    Lun.mode = "heavenlystem";
                    Lun.font_color = Variable.ToHexColor(btnD_font_color.BackColor);
                    Lun.font_name = cmbD_font.Items[cmbD_font.SelectedIndex].ToString();
                    Lun.font_size = (int)numD_fontSize.Value;
                    Lun.x = (int)num_DX.Value;
                    Lun.y = (int)num_DY.Value;
                    if (checkD_bold.Checked && checkD_italic.Checked)
                    {
                        Lun.font_attributes = "bold&italic";
                    }
                    else if (checkD_bold.Checked)
                    {
                        Lun.font_attributes = "bold";
                    }
                    else if (checkD_italic.Checked)
                    {
                        Lun.font_attributes = "italic";
                    }
                    else
                    {
                        Lun.font_attributes = "normal";
                    }
                    Lun.text_content = "";
                    pic.Add(Lun);
                }
                if (checkTime.Checked)
                {
                    LedYSDK.Lun Lun;
                    Lun.mode = "lunarcalendar";
                    Lun.font_color = Variable.ToHexColor(btnT_font_color.BackColor);
                    Lun.font_name = cmbT_font.Items[cmbT_font.SelectedIndex].ToString();
                    Lun.font_size = (int)numT_fontSize.Value;
                    Lun.x = (int)num_TX.Value;
                    Lun.y = (int)num_TY.Value;
                    if (checkT_bold.Checked && checkT_italic.Checked)
                    {
                        Lun.font_attributes = "bold&italic";
                    }
                    else if (checkT_bold.Checked)
                    {
                        Lun.font_attributes = "bold";
                    }
                    else if (checkT_italic.Checked)
                    {
                        Lun.font_attributes = "italic";
                    }
                    else
                    {
                        Lun.font_attributes = "normal";
                    }
                    Lun.text_content = "";
                    pic.Add(Lun);
                }
                if (checkWeek.Checked)
                {
                    LedYSDK.Lun Lun;
                    Lun.mode = "solarterms";
                    Lun.font_color = Variable.ToHexColor(btnW_font_color.BackColor);
                    Lun.font_name = cmbW_font.Items[cmbW_font.SelectedIndex].ToString();
                    Lun.font_size = (int)numW_fontSize.Value;
                    Lun.x = (int)num_WX.Value;
                    Lun.y = (int)num_WY.Value;
                    if (checkW_bold.Checked && checkW_italic.Checked)
                    {
                        Lun.font_attributes = "bold&italic";
                    }
                    else if (checkW_bold.Checked)
                    {
                        Lun.font_attributes = "bold";
                    }
                    else if (checkW_italic.Checked)
                    {
                        Lun.font_attributes = "italic";
                    }
                    else
                    {
                        Lun.font_attributes = "normal";
                    }
                    Lun.text_content = "";
                    pic.Add(Lun);
                }
                if (checkText.Checked)
                {
                    LedYSDK.Lun Lun;
                    Lun.mode = "text";
                    Lun.font_color = Variable.ToHexColor(btn_font_color.BackColor);
                    Lun.font_name = cmb_font.Items[cmb_font.SelectedIndex].ToString();
                    Lun.font_size = (int)num_fontSize.Value;
                    Lun.x = (int)num_SX.Value;
                    Lun.y = (int)num_SY.Value;
                    if (check_bold.Checked && check_italic.Checked)
                    {
                        Lun.font_attributes = "bold&italic";
                    }
                    else if (check_bold.Checked)
                    {
                        Lun.font_attributes = "bold";
                    }
                    else if (check_italic.Checked)
                    {
                        Lun.font_attributes = "italic";
                    }
                    else
                    {
                        Lun.font_attributes = "normal";
                    }
                    Lun.text_content = txt_str.Text;
                    pic.Add(Lun);
                }
                Lun_Area.bg_color = Variable.ToHexColor(btn_bg_color.BackColor);
                Lun_Area.time_equation = txt_time_equation.Text;
                Lun_Area.positive_te = cmb_positive_te.Items[cmb_positive_te.SelectedIndex].ToString();
                Lun_Area.m_Lun = pic.ToArray();

                picArea.thing = 5;
                picArea.m_x = (int)num_X.Value;
                picArea.m_y = (int)num_Y.Value;
                picArea.m_w = (int)num_width.Value;
                picArea.m_h = (int)num_height.Value;
                picArea.m_Transparent = (int)trackBar1.Value;
                picArea.m_Lun_Area = Lun_Area;
                this.Close();
            }
            else { MessageBox.Show("未选中"); }
        }

        private void btn_bg_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btn_bg_color.BackColor = col.Color;
            }
        }

        private void btnD_font_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btnD_font_color.BackColor = col.Color;
            }
        }

        private void btnT_font_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btnT_font_color.BackColor = col.Color;
            }
        }

        private void btnW_font_color_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                btnW_font_color.BackColor = col.Color;
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

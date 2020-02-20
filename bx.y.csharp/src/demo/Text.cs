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
    public partial class Text : Form
    {
        public LedYSDK.PicArea picArea = new LedYSDK.PicArea();
        public List<LedYSDK.text> pic = new List<LedYSDK.text>();
        public Text()
        {
            InitializeComponent();
            num_X.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_width.Maximum = Variable.p_width;
            num_height.Maximum = Variable.p_height;
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_display_effects.SelectedIndex = 0;
            cmb_unitType.SelectedIndex = 1;

            cmb_font.SelectedIndex = 0;
        }

        private void btn_addstr_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text != "")
            {
                listBox1.Items.Add(richTextBox1.Text);
                LedYSDK.text picUnit;
                picUnit.display_speed = 1;
                picUnit.stay_time = 1;
                picUnit.font_name = cmb_font.Items[cmb_font.SelectedIndex].ToString();
                picUnit.font_size = (int)num_fontSize.Value;
                if (check_bold.Checked && check_italic.Checked)
                {
                    picUnit.font_attributes = "bold&italic";
                }
                else if (check_bold.Checked)
                {
                    picUnit.font_attributes = "bold";
                }
                else if (check_italic.Checked)
                {
                    picUnit.font_attributes = "italic";
                }
                else
                {
                    picUnit.font_attributes = "normal";
                }
                picUnit.font_alignment = "";
                picUnit.font_color = Variable.ToHexColor(btn_font_color.BackColor);
                picUnit.bg_color = Variable.ToHexColor(btn_bg_color.BackColor);
                picUnit.text_content = richTextBox1.Text;
                picUnit.last_move_width = 0;
                pic.Add(picUnit);
            }
            else { MessageBox.Show("未添加显示数据"); }
        }

        private void btn_addFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Multiselect = true;
            openFileDialog1.Filter = "所有支持文件|*.bmp;*.jpg;*.png;*.gif";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                foreach (string s in openFileDialog1.FileNames)
                {
                    listBox2.Items.Add(s);
                    LedYSDK.text picUnit;
                    picUnit.display_speed = 1;
                    picUnit.stay_time = 1;
                    picUnit.font_name = "";
                    picUnit.font_size = 0;
                    picUnit.font_attributes = "";
                    picUnit.font_alignment = "";
                    picUnit.font_color = "";
                    picUnit.bg_color = "";
                    picUnit.text_content = s;
                    picUnit.last_move_width = (int)num_width.Value;
                    pic.Add(picUnit);
                }
                listBox2.SelectedIndex = listBox1.Items.Count - 1;
            }
        }

        private void cmb_unitType_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmb_unitType.SelectedIndex == 0)
            {
                pic.Clear();
                listBox2.Items.Clear();
                listBox2.Refresh();
                groupBox3.Enabled = true;
                groupBox2.Enabled = false;
            }
            else
            {
                pic.Clear();
                listBox1.Items.Clear();
                listBox1.Refresh();
                groupBox3.Enabled = false;
                groupBox2.Enabled = true;
            }
        }

        private void btn_OK_Click(object sender, EventArgs e)
        {
            if (pic.Count > 0)
            {
                LedYSDK.Text_Area Text_Area;
                switch (cmb_display_effects.SelectedIndex)
                {
                    case 0:
                        Text_Area.display_effects = 0;
                        break;
                    case 1:
                        Text_Area.display_effects = 50;
                        break;
                    case 2:
                        Text_Area.display_effects = 51;
                        break;
                    case 3:
                        Text_Area.display_effects = 52;
                        break;
                    case 4:
                        Text_Area.display_effects = 53;
                        break;
                    case 5:
                        Text_Area.display_effects = 54;
                        break;
                    case 6:
                        Text_Area.display_effects = 55;
                        break;
                    case 7:
                        Text_Area.display_effects = 56;
                        break;
                    case 8:
                        Text_Area.display_effects = 57;
                        break;
                    default:
                        Text_Area.display_effects = 0;
                        break;
                }
                Text_Area.unit_type = cmb_unitType.SelectedIndex;
                if (cmb_unitType.SelectedIndex == 0) 
                {
                    if (pic.Count > 1)
                    {
                        for (int i = 0; i < (pic.Count - 1); i++)
                        {
                            LedYSDK.text text = pic[i];
                            text.last_move_width = 0;
                            pic[i] = text;
                        }
                    }
                }
                Text_Area.m_text = pic.ToArray();

                picArea.thing = 2;
                picArea.m_x = (int)num_X.Value;
                picArea.m_y = (int)num_Y.Value;
                picArea.m_w = (int)num_width.Value;
                picArea.m_h = (int)num_height.Value;
                picArea.m_Transparent = (int)trackBar1.Value;
                picArea.m_Text_Area = Text_Area;
                this.Close();
            }
            else { MessageBox.Show("未添加数据"); }
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

        private void btn_NO_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}

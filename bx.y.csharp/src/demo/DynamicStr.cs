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
    public partial class DynamicStr : Form
    {
        public LedYSDK.DynamicArea S_DynamicArea = new LedYSDK.DynamicArea();
        public List<LedYSDK.DynamicAreaFile> S_DynamicAreaFile = new List<LedYSDK.DynamicAreaFile>();
        public DynamicStr()
        {
            InitializeComponent();
            cmb_runmode.SelectedIndex = 0;
            com_align_h.SelectedIndex = 0;
            com_align_v.SelectedIndex = 0;
            comboBox3.SelectedIndex = 0;
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_font.SelectedIndex = 0;
            num_X.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_width.Maximum = Variable.p_width;
            num_height.Maximum = Variable.p_height;
            cmb_DynamiAreaID.SelectedIndex = 0;
        }

        private void btn_addSTR_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text != "")
            {
                listBox1.Items.Add(richTextBox1.Text);
                LedYSDK.DynamicAreaFile DynamicAreaFile;
                DynamicAreaFile.m_dynamic_type = 1;
                DynamicAreaFile.m_display_effects = comboBox3.SelectedIndex;
                DynamicAreaFile.m_display_speed = (int)num_display_speed.Value;
                DynamicAreaFile.m_stay_time = (int)num_stay_time.Value;

                byte[] b = System.Text.Encoding.UTF8.GetBytes(richTextBox1.Text);
                DynamicAreaFile.m_file_path = Convert.ToBase64String(b);

                DynamicAreaFile.m_gif_flag = 0;
                DynamicAreaFile.m_bg_color = Variable.ToHexColor(btn_bg_color.BackColor);
                DynamicAreaFile.m_font_size = (int)num_fontSize.Value;
                DynamicAreaFile.m_font_name = cmb_font.Items[cmb_font.SelectedIndex].ToString();
                DynamicAreaFile.m_font_color = Variable.ToHexColor(btn_font_color.BackColor);
                if (check_bold.Checked && check_italic.Checked)
                {
                    DynamicAreaFile.m_font_attributes = "bold&italic";
                }
                else if (check_bold.Checked)
                {
                    DynamicAreaFile.m_font_attributes = "bold";
                }
                else if (check_italic.Checked)
                {
                    DynamicAreaFile.m_font_attributes = "italic";
                }
                else
                {
                    DynamicAreaFile.m_font_attributes = "normal";
                }
                DynamicAreaFile.m_align_h = com_align_h.SelectedIndex.ToString();
                DynamicAreaFile.m_align_v = com_align_v.SelectedIndex.ToString();
                DynamicAreaFile.m_volumn = 0;
                DynamicAreaFile.m_scale_mode = 0;
                DynamicAreaFile.m_rolation_mode = 0;

                S_DynamicAreaFile.Add(DynamicAreaFile);
            }
            else { MessageBox.Show("未添加显示数据"); }
        }

        private void btn_del_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                S_DynamicAreaFile.RemoveAt(index);
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
            }
        }

        private void btn_OK_Click(object sender, EventArgs e)
        {
            S_DynamicArea.m_dynamic_id = cmb_DynamiAreaID.SelectedIndex;
            S_DynamicArea.m_x = (int)num_X.Value;
            S_DynamicArea.m_y = (int)num_Y.Value;
            S_DynamicArea.m_w = (int)num_width.Value;
            S_DynamicArea.m_h = (int)num_height.Value;
            if (checkBox1.Checked)
            {
                S_DynamicArea.m_relative_program = textBox5.Text;
            }
            else
            {
                S_DynamicArea.m_relative_program = "-1";
            }
            S_DynamicArea.m_run_mode = cmb_runmode.SelectedIndex;
            S_DynamicArea.m_update_frequency = "";
            S_DynamicArea.m_transparency = (int)trackBar1.Value;
            S_DynamicArea.m_DynamicAreaFile = S_DynamicAreaFile.ToArray();
            this.Close();
        }

        private void btn_CLOSE_Click(object sender, EventArgs e)
        {
            this.Close();
            this.Dispose();
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

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
    public partial class DynamicList : Form
    {
        public List<LedYSDK.DynamicArea> S_DynamicAreaFile = new List<LedYSDK.DynamicArea>();
        public List<LedYSDK.DynamicArea> S_DynamicAreaStr = new List<LedYSDK.DynamicArea>();
        public DynamicList()
        {
            InitializeComponent();
            radioButton1.Checked = true;
        }

        private void btn_AddFile_Click(object sender, EventArgs e)
        {
            DynamicFile F_DynamicFile = new DynamicFile();
            DialogResult ret = F_DynamicFile.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_DynamicAreaFile.Add(F_DynamicFile.S_DynamicArea);
                int num = F_DynamicFile.S_DynamicArea.m_dynamic_id;
                listBox1.Items.Add("动态区:" + num);
            }
        }

        private void btn_SendFile_Click(object sender, EventArgs e)
        {
            if (listBox1.Items.Count > 0)
            {
                int err = 0;
                IntPtr playlist = LedYNetSdk.create_playlist(Variable.p_width, Variable.p_height, Variable.p_screen_type);
                string name = "program_0";
                IntPtr program = LedYNetSdk.create_program(name,"0xff000000");
                for (int i = 0; i < S_DynamicAreaFile.Count; i++)
                {
                    LedYSDK.DynamicArea DynamicArea = S_DynamicAreaFile[i];
                    IntPtr dynamic_area = LedYNetSdk.create_dynamic();
                    for (int j = 0; j < DynamicArea.m_DynamicAreaFile.Length; j++)
                    {
                        LedYSDK.DynamicAreaFile DynamicAreaFile = DynamicArea.m_DynamicAreaFile[j];
                        err = LedYNetSdk.add_dynamic_unit(dynamic_area, DynamicAreaFile.m_dynamic_type, DynamicAreaFile.m_display_effects, DynamicAreaFile.m_display_speed, DynamicAreaFile.m_stay_time,
                            DynamicAreaFile.m_file_path, DynamicAreaFile.m_gif_flag, DynamicAreaFile.m_bg_color, DynamicAreaFile.m_font_size, DynamicAreaFile.m_font_name, DynamicAreaFile.m_font_color, DynamicAreaFile.m_font_attributes,
                            DynamicAreaFile.m_align_h, DynamicAreaFile.m_align_v, DynamicAreaFile.m_volumn, DynamicAreaFile.m_scale_mode, DynamicAreaFile.m_rolation_mode);
                    }
                    err = LedYNetSdk.add_dynamic(program, dynamic_area, DynamicArea.m_dynamic_id, DynamicArea.m_x, DynamicArea.m_y, DynamicArea.m_w, DynamicArea.m_h, DynamicArea.m_relative_program,
                        DynamicArea.m_run_mode, DynamicArea.m_update_frequency, DynamicArea.m_transparency);
                    LedYNetSdk.delete_dynamic(dynamic_area);
                }
                //星期
                #region
                int index;
                bool flag;
                byte BIT = 0;
                if (checkMon.Checked == true)
                {
                    index = 1;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 1;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkTues.Checked == true)
                {
                    index = 2;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 2;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkWed.Checked == true)
                {
                    index = 3;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 3;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkThur.Checked == true)
                {
                    index = 4;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 4;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkFri.Checked == true)
                {
                    index = 5;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 5;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkSat.Checked == true)
                {
                    index = 6;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 6;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkSun.Checked == true)
                {
                    index = 7;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 7;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                int m_play_week = BIT;
                #endregion
                err = LedYNetSdk.add_program_in_playlist(playlist, program, 1, 10, "", "", "", "", m_play_week);
                err = LedYNetSdk.update_dynamic(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, playlist, -1, 0, 0);

                LedYNetSdk.cancel_send_program(playlist);
                LedYNetSdk.delete_playlist(playlist);
            }
        }
        byte set_bit(byte data, int index, bool flag)
        {
            if (index > 8 || index < 1)
                throw new ArgumentOutOfRangeException();
            int v = index < 2 ? index : (2 << (index - 2));
            return flag ? (byte)(data | v) : (byte)(data & ~v);
        }

        private void btn_AddStr_Click(object sender, EventArgs e)
        {
            DynamicStr F_DynamicStr = new DynamicStr();
            DialogResult ret = F_DynamicStr.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_DynamicAreaStr.Add(F_DynamicStr.S_DynamicArea);
                int num = F_DynamicStr.S_DynamicArea.m_dynamic_id;
                listBox2.Items.Add("动态区:" + num);
            }
        }

        private void btn_SendStr_Click(object sender, EventArgs e)
        {
            if (listBox2.Items.Count > 0)
            {
                int err = 0;
                IntPtr playlist = LedYNetSdk.create_playlist(Variable.p_width, Variable.p_height, Variable.p_screen_type);
                string name = "program_0";
                IntPtr program = LedYNetSdk.create_program(name,"0xff000000");
                for (int i = 0; i < S_DynamicAreaStr.Count; i++)
                {
                    LedYSDK.DynamicArea DynamicArea = S_DynamicAreaStr[i];
                    IntPtr dynamic_area = LedYNetSdk.create_dynamic();
                    for (int j = 0; j < DynamicArea.m_DynamicAreaFile.Length; j++)
                    {
                        LedYSDK.DynamicAreaFile DynamicAreaFile = DynamicArea.m_DynamicAreaFile[j];
                        err = LedYNetSdk.add_dynamic_unit(dynamic_area, DynamicAreaFile.m_dynamic_type, DynamicAreaFile.m_display_effects, DynamicAreaFile.m_display_speed, DynamicAreaFile.m_stay_time,
                            DynamicAreaFile.m_file_path, DynamicAreaFile.m_gif_flag, DynamicAreaFile.m_bg_color, DynamicAreaFile.m_font_size, DynamicAreaFile.m_font_name, DynamicAreaFile.m_font_color, DynamicAreaFile.m_font_attributes,
                            DynamicAreaFile.m_align_h, DynamicAreaFile.m_align_v, DynamicAreaFile.m_volumn, DynamicAreaFile.m_scale_mode, DynamicAreaFile.m_rolation_mode);
                    }
                    err = LedYNetSdk.add_dynamic(program, dynamic_area, DynamicArea.m_dynamic_id, DynamicArea.m_x, DynamicArea.m_y, DynamicArea.m_w, DynamicArea.m_h, DynamicArea.m_relative_program,
                        DynamicArea.m_run_mode, DynamicArea.m_update_frequency, DynamicArea.m_transparency);
                    LedYNetSdk.delete_dynamic(dynamic_area);

                }
                //星期
                #region
                int index;
                bool flag;
                byte BIT = 0;
                if (checkMon.Checked == true)
                {
                    index = 1;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 1;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkTues.Checked == true)
                {
                    index = 2;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 2;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkWed.Checked == true)
                {
                    index = 3;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 3;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkThur.Checked == true)
                {
                    index = 4;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 4;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkFri.Checked == true)
                {
                    index = 5;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 5;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkSat.Checked == true)
                {
                    index = 6;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 6;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                if (checkSun.Checked == true)
                {
                    index = 7;
                    flag = true;
                    BIT = set_bit(BIT, index, flag);
                }
                else
                {
                    index = 7;
                    flag = false;
                    BIT = set_bit(BIT, index, flag);
                }
                int m_play_week = BIT;
                #endregion
                err = LedYNetSdk.add_program_in_playlist(playlist, program, 1, 10, "", "", "", "", m_play_week);
                err = LedYNetSdk.update_dynamic_small(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, playlist, -1, 0, 0);

                LedYNetSdk.cancel_send_program(playlist);
                LedYNetSdk.delete_playlist(playlist);
            }
        }

        private void btn_delfile_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                S_DynamicAreaFile.RemoveAt(index);
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
            }
        }

        private void btn_delTxt_Click(object sender, EventArgs e)
        {
            int index = listBox2.SelectedIndex;
            if (index != -1)
            {
                S_DynamicAreaStr.RemoveAt(index);
                //移出选择的项
                listBox2.Items.Remove(listBox2.SelectedItem);
            }
        }

        private void btn_DelArea_Click(object sender, EventArgs e)
        {
            int err = LedYNetSdk.clear_dynamic(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str);
            if (err == 0) { MessageBox.Show("删除成功"); }
            else { MessageBox.Show("删除失败，错误码："+err); }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (timer1.Interval == (int)numericUpDown1.Value * 1000) 
            {
                if (listBox2.Items.Count > 0)
                {
                    send_number++;
                    int err = 0;
                    IntPtr playlist = LedYNetSdk.create_playlist(Variable.p_width, Variable.p_height, Variable.p_screen_type);
                    string name = "program_0";
                    IntPtr program = LedYNetSdk.create_program(name,"0xff000000");
                    for (int i = 0; i < S_DynamicAreaStr.Count; i++)
                    {
                        LedYSDK.DynamicArea DynamicArea = S_DynamicAreaStr[i];
                        IntPtr dynamic_area = LedYNetSdk.create_dynamic();
                        for (int j = 0; j < DynamicArea.m_DynamicAreaFile.Length; j++)
                        {
                            Random random = new Random();
                            byte[] b = System.Text.Encoding.UTF8.GetBytes(random.Next(10, 1000).ToString());
                            string m_file_path = Convert.ToBase64String(b);
                            LedYSDK.DynamicAreaFile DynamicAreaFile = DynamicArea.m_DynamicAreaFile[j];
                            err = LedYNetSdk.add_dynamic_unit(dynamic_area, DynamicAreaFile.m_dynamic_type, DynamicAreaFile.m_display_effects, DynamicAreaFile.m_display_speed, DynamicAreaFile.m_stay_time,
                                m_file_path, DynamicAreaFile.m_gif_flag, DynamicAreaFile.m_bg_color, DynamicAreaFile.m_font_size, DynamicAreaFile.m_font_name, DynamicAreaFile.m_font_color, DynamicAreaFile.m_font_attributes,
                                DynamicAreaFile.m_align_h, DynamicAreaFile.m_align_v, DynamicAreaFile.m_volumn, DynamicAreaFile.m_scale_mode, DynamicAreaFile.m_rolation_mode);
                        }
                        err = LedYNetSdk.add_dynamic(program, dynamic_area, DynamicArea.m_dynamic_id, DynamicArea.m_x, DynamicArea.m_y, DynamicArea.m_w, DynamicArea.m_h, DynamicArea.m_relative_program,
                            DynamicArea.m_run_mode, DynamicArea.m_update_frequency, DynamicArea.m_transparency);
                        LedYNetSdk.delete_dynamic(dynamic_area);

                    }
                    //星期
                    #region
                    int index;
                    bool flag;
                    byte BIT = 0;
                    if (checkMon.Checked == true)
                    {
                        index = 1;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 1;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    if (checkTues.Checked == true)
                    {
                        index = 2;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 2;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    if (checkWed.Checked == true)
                    {
                        index = 3;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 3;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    if (checkThur.Checked == true)
                    {
                        index = 4;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 4;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    if (checkFri.Checked == true)
                    {
                        index = 5;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 5;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    if (checkSat.Checked == true)
                    {
                        index = 6;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 6;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    if (checkSun.Checked == true)
                    {
                        index = 7;
                        flag = true;
                        BIT = set_bit(BIT, index, flag);
                    }
                    else
                    {
                        index = 7;
                        flag = false;
                        BIT = set_bit(BIT, index, flag);
                    }
                    int m_play_week = BIT;
                    #endregion
                    err = LedYNetSdk.add_program_in_playlist(playlist, program, 1, 10, "", "", "", "", m_play_week);
                    err = LedYNetSdk.update_dynamic_unit_small(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, playlist);
                    if (err != 0) { err_number++; richTextBox1.Text = "更新失败：" + err; }
                    else { richTextBox1.Text = "更新成功"; }
                    LedYNetSdk.cancel_send_program(playlist);
                    LedYNetSdk.delete_playlist(playlist);
                    numericUpDown2.Value = send_number;
                    numericUpDown3.Value = err_number;
                }
            }
        }
        int send_number = 0;
        int err_number = 0;
        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Interval = (int)numericUpDown1.Value * 1000;
            timer1.Enabled = true;
            button1.Enabled = false;
            button2.Enabled = true;
            numericUpDown1.Enabled = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
            button1.Enabled = true;
            button2.Enabled = false;
            numericUpDown1.Enabled = true;
        }

    }
}

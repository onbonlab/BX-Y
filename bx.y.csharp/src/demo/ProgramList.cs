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
    public partial class ProgramList : Form
    {
        public List<LedYSDK.Program> S_Program = new List<LedYSDK.Program>();
        public ProgramList()
        {
            InitializeComponent();
            string str = Application.StartupPath;
            txt_LocalTempDir.Text = str;
        }

        private void btn_LocalTempDir_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                txt_LocalTempDir.Text = dialog.SelectedPath;
            }
        }

        private void btn_AddProgram_Click(object sender, EventArgs e)
        {
            ProgramArea F_ProgramArea = new ProgramArea();
            DialogResult ret = F_ProgramArea.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_Program.Add(F_ProgramArea.S_Program);
                Variable.num_program = S_Program.Count;
                listBox1.Items.Add(F_ProgramArea.S_Program.ProgramNmae);
            }
        }

        private void btn_SendProgram_Click(object sender, EventArgs e)
        {
            int err = 0;
            IntPtr playlist = LedYNetSdk.create_playlist(Variable.p_width, Variable.p_height, Variable.p_screen_type);
            for (int i = 0; i < S_Program.Count; i++)
            {
                LedYSDK.Program m_Program = S_Program[i];
                string name = "program_0";
                IntPtr program = LedYNetSdk.create_program(name,"0xff000000");
                for (int j = 0; j < m_Program.m_PicArea.Length; j++)
                {
                    switch (m_Program.m_PicArea[j].thing)
                    {
                        case 0:
                            {
                                //图片
                                IntPtr pic_area = LedYNetSdk.create_pic();
                                for (int n = 0; n < m_Program.m_PicArea[j].m_ImgText.Length; n++)
                                {
                                    LedYSDK.ImgText ImgText = m_Program.m_PicArea[j].m_ImgText[n];
                                    err = LedYNetSdk.add_pic_unit(pic_area, ImgText.stay_time, ImgText.display_effects, ImgText.display_speed, ImgText.FileName);
                                }
                                err = LedYNetSdk.add_pic(program, pic_area, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent);
                                break;
                            }
                        case 1:
                            {
                                //视频
                                IntPtr video_area = LedYNetSdk.create_video();
                                for (int n = 0; n < m_Program.m_PicArea[j].m_Video.Length; n++)
                                {
                                    LedYSDK.Video Video = m_Program.m_PicArea[j].m_Video[n];
                                    err = LedYNetSdk.add_video_unit(video_area, Video.volume, Video.scale_mode, Video.source, Video.play_time, Video.FileName,"");
                                }
                                string clone_str = "";
                                err = LedYNetSdk.add_video(program, video_area, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h,
                                    m_Program.m_PicArea[j].volume_mode, m_Program.m_PicArea[j].video_type, m_Program.m_PicArea[j].ratation_mode, clone_str,"");
                                break;
                            }
                        case 2:
                            {
                                LedYSDK.Text_Area Text_Area=m_Program.m_PicArea[j].m_Text_Area;
                                IntPtr area_tree = LedYNetSdk.create_text();
                                for (int n = 0; n < Text_Area.m_text.Length; n++) 
                                {
                                    if (Text_Area.unit_type == 0)
                                    {
                                        err = LedYNetSdk.add_text_unit_img(area_tree, Text_Area.m_text[n].stay_time, Text_Area.m_text[n].display_speed, Text_Area.m_text[n].last_move_width, Text_Area.m_text[n].text_content);
                                    }
                                    else
                                    {
                                        err = LedYNetSdk.add_text_unit_text(area_tree, Text_Area.m_text[n].stay_time, Text_Area.m_text[n].display_speed, Text_Area.m_text[n].font_name, Text_Area.m_text[n].font_size,
                                            Text_Area.m_text[n].font_attributes, Text_Area.m_text[n].font_alignment, Text_Area.m_text[n].font_color, Text_Area.m_text[n].bg_color, Text_Area.m_text[n].text_content);//
                                    }
                                }
                                err = LedYNetSdk.add_text(program, area_tree, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent, Text_Area.display_effects, Text_Area.unit_type);
                                break;
                            }
                        case 3:
                            {
                                //时间
                                IntPtr time_area = LedYNetSdk.create_time();
                                for (int n = 0; n < m_Program.m_PicArea[j].m_Time_Area.m_time.Length; n++)
                                {
                                    LedYSDK.time time = m_Program.m_PicArea[j].m_Time_Area.m_time[n];
                                    err = LedYNetSdk.add_time_unit(time_area, time.content, time.font_color, time.font_name, time.font_size, time.x, time.y, time.font_attributes);
                                }
                                err = LedYNetSdk.add_time(program, time_area, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h,m_Program.m_PicArea[j].m_Transparent,
                                     m_Program.m_PicArea[j].m_Time_Area.bg_color, m_Program.m_PicArea[j].m_Time_Area.time_equation, m_Program.m_PicArea[j].m_Time_Area.positive_te);
                                break;
                            }
                        case 4:
                            {
                                //表盘
                                IntPtr clock_area = LedYNetSdk.create_clock();
                                LedYSDK.Clock_Area Clock_Area = m_Program.m_PicArea[j].m_Clock_Area;
                                err = LedYNetSdk.add_clock(program,clock_area, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent,
                                    Clock_Area.time_equation, Clock_Area.positive_te, Clock_Area.hour_color, Clock_Area.minute_color, Clock_Area.second_color, Clock_Area.bg_image);
                                //文字
                                if (Clock_Area.t_write) 
                                {
                                    IntPtr time_area = LedYNetSdk.create_time();
                                    err = LedYNetSdk.add_time_unit(time_area, Clock_Area.t_content, Clock_Area.t_font_color, Clock_Area.t_font_name, Clock_Area.t_font_size, Clock_Area.t_x, Clock_Area.t_y, Clock_Area.t_font_attributes);
                                    err = LedYNetSdk.add_time(program, time_area, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent,
                                        Clock_Area.t_bg_color, Clock_Area.t_time_equation, Clock_Area.t_positive_te);
                                }
                                break;
                            }
                        case 5:
                            {
                                //农历
                                IntPtr calendar_area = LedYNetSdk.create_calendar();
                                for (int n = 0; n < m_Program.m_PicArea[j].m_Lun_Area.m_Lun.Length; n++)
                                {
                                    LedYSDK.Lun Lun = m_Program.m_PicArea[j].m_Lun_Area.m_Lun[n];
                                    err = LedYNetSdk.add_calendar_unit(calendar_area, Lun.mode, Lun.font_color, Lun.font_name, Lun.font_size, Lun.x, Lun.y, Lun.font_attributes, Lun.text_content);
                                }
                                err = LedYNetSdk.add_calendar(program, calendar_area,  m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent,
                                    m_Program.m_PicArea[j].m_Lun_Area.bg_color, m_Program.m_PicArea[j].m_Lun_Area.time_equation, m_Program.m_PicArea[j].m_Lun_Area.positive_te);
                                break;
                            }
                        case 6:
                            {
                                LedYSDK.Counter_Area Counter_Area = m_Program.m_PicArea[j].m_Counter_Area;
                                err = LedYNetSdk.add_count(program, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent,
                                    Counter_Area.bg_color, Counter_Area.time_equation, Counter_Area.positive_te, Counter_Area.target_date, Counter_Area.target_time, Counter_Area.content,
                                    Counter_Area.font_color, Counter_Area.font_name, Counter_Area.font_size, Counter_Area.content_x, Counter_Area.content_y, Counter_Area.font_attributes, Counter_Area.add_enable);
                                //文字
                                if (Counter_Area.t_write)
                                {
                                    IntPtr time_area = LedYNetSdk.create_time();
                                    err = LedYNetSdk.add_time_unit(time_area, Counter_Area.t_content, Counter_Area.t_font_color, Counter_Area.t_font_name, Counter_Area.t_font_size, Counter_Area.t_x, Counter_Area.t_y, Counter_Area.t_font_attributes);
                                    err = LedYNetSdk.add_time(program, time_area, m_Program.m_PicArea[j].m_x, m_Program.m_PicArea[j].m_y, m_Program.m_PicArea[j].m_w, m_Program.m_PicArea[j].m_h, m_Program.m_PicArea[j].m_Transparent,
                                        Counter_Area.t_bg_color, Counter_Area.t_time_equation, Counter_Area.t_positive_te);
                                }
                                break;
                            }
                    }
                }

                err = LedYNetSdk.add_program_in_playlist(playlist, program, m_Program.m_play_mode, m_Program.m_play_time, m_Program.m_aging_start_time, m_Program.m_aging_stop_time,
                    m_Program.m_period_ontime, m_Program.m_period_offtime, m_Program.m_play_week);
               
            }
            int send_style = 0;
            var szLocalTempDir = txt_LocalTempDir.Text;
            long free_size = 0; long total_size = 0;
            err = LedYNetSdk.send_program(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, szLocalTempDir, playlist, send_style, ref free_size, ref total_size);

            LedYNetSdk.cancel_send_program(playlist);
            LedYNetSdk.delete_playlist(playlist);
            if (err == 0) { MessageBox.Show("更新节目成功！"); }
            else { MessageBox.Show("更新节目失败！" + err); }
        }

        private void btn_delProgram_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                S_Program.RemoveAt(index);
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
            }
            else { MessageBox.Show("请选择节目!"); }
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace Ysdk_CSharp
{
    public class LedYSDK
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct Program
        {
            public string ProgramNmae;//节目名
            public int m_play_mode;//播放模式
            public int m_play_time;//播放时长
            public string m_aging_start_time;//开始日期
            public string m_aging_stop_time;//结束日期
            public string m_period_ontime;//开始时间
            public string m_period_offtime;//结束时间
            public int m_play_week;//星期
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public PicArea[] m_PicArea;
        }
        public struct PicArea
        {
            public int thing;//区域类型 0图文 1视频 2字幕 3时间 4表盘 5农历 6计时
            public int m_x;//x
            public int m_y;//y
            public int m_w;//宽
            public int m_h;//高

            public int m_Transparent;//窗口透明

            public int volume_mode;
            public int video_type;
            public int ratation_mode;

            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public ImgText[] m_ImgText;//文件
            public Video[] m_Video;//视频
            public Text_Area m_Text_Area;//字幕
            public Time_Area m_Time_Area;//时间
            public Clock_Area m_Clock_Area;//表盘
            public Lun_Area m_Lun_Area;//农历
            public Counter_Area m_Counter_Area;//计时
        }
        //图文
        public struct ImgText
        {
            public string FileName;//路径
            public int display_effects;//特效
            public int display_speed;//运行时间
            public int stay_time;//停留时间
        };

        //字幕
        public struct Text_Area
        {
            public int display_effects;
            public int unit_type;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public text[] m_text;

        }
        public struct text
        {
            public int display_speed;//运行时间
            public int stay_time;//停留时间
            public string font_name;
            public int font_size;
            public string font_attributes;
            public string font_alignment;
            public string font_color;
            public string bg_color;
            public string text_content;
            public int last_move_width;
        }
        //视频
        public struct Video
        {
            public string FileName;//路径
            public int scale_mode;//缩放模式
            public int volume;//音量
            public int source;//
            public int play_time;//
        }
        //时间
        public struct Time_Area
        {
            public string bg_color;
            public string time_equation;
            public string positive_te;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public time[] m_time;

        }
        public struct time
        {
            public string content;
            public string font_color;
            public string font_name;
            public int font_size;
            public int x;
            public int y;
            public string font_attributes;
        }
        //表盘
        public struct Clock_Area
        {
            public string time_equation;
            public string positive_te;
            public string hour_color;
            public string minute_color;
            public string second_color;
            public string bg_image;

            public bool t_write;
            public string t_bg_color;
            public string t_time_equation;
            public string t_positive_te;
            public string t_content;
            public string t_font_color;
            public string t_font_name;
            public int t_font_size;
            public int t_x;
            public int t_y;
            public string t_font_attributes;
        }
        //农历
        public struct Lun_Area
        {
            public string bg_color;
            public string time_equation;
            public string positive_te;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public Lun[] m_Lun;
        }
        public struct Lun
        {
            public string mode;
            public string font_color;
            public string font_name;
            public int font_size;
            public int x;
            public int y;
            public string font_attributes;
            public string text_content;
        }
        //计时
        public struct Counter_Area
        {
            public string bg_color;
            public string time_equation;
            public string positive_te;
            public string target_date;
            public string target_time;
            public string content;
            public string font_color;
            public string font_name;
            public int font_size;
            public int content_x;
            public int content_y;
            public string font_attributes;
            public string add_enable;

            public bool t_write;
            public string t_bg_color;
            public string t_time_equation;
            public string t_positive_te;
            public string t_content;
            public string t_font_color;
            public string t_font_name;
            public int t_font_size;
            public int t_x;
            public int t_y;
            public string t_font_attributes;
        }

        public struct DynamicArea
        {
            public int m_dynamic_id;//
            public int m_x;//x
            public int m_y;//y
            public int m_w;//宽
            public int m_h;//高
            public string m_relative_program;//关联的节目
            public int m_run_mode;//动态区运行方式
            public string m_update_frequency;//
            public int m_transparency;//背景透明
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public DynamicAreaFile[] m_DynamicAreaFile;//文件

        }
        public struct DynamicAreaFile 
        {
            public int m_dynamic_type;
            public int m_display_effects;
            public int m_display_speed;
            public int m_stay_time;
            public string m_file_path;
            public int m_gif_flag;
            public string m_bg_color;
            public int m_font_size;
            public string m_font_name;
            public string m_font_color;
            public string m_font_attributes;
            public string m_align_h;
            public string m_align_v;
            public int m_volumn;
            public int m_scale_mode;
            public int m_rolation_mode;
        }
    }
}

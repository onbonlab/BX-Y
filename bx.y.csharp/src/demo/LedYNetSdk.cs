﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace Ysdk_CSharp
{
    public class LedYNetSdk
    {
        /// <summary>
        /// 初始化
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int init_sdk();
        /// <summary>
        /// 释放动态库
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int release_sdk();
        
        /// <summary>
        /// 发送节目到显示屏
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="tmp_path">播放列表路径</param>
        /// <param name="playlist">播放列表</param>
        /// <param name="send_style">固定值为0 不能改变</param>
        /// <param name="free_size">剩余空间  目前无效</param>
        /// <param name="total_size">总容量  目前无效</param>
        /// <returns>返回值 0成功</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int send_program(byte[] ip, ushort port, string user_name, string user_pwd, string tmp_path, IntPtr playlist, int send_style, ref Int64 free_size, ref Int64 total_size);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="playlist">播放列表句柄</param>
        /// <param name="total">总进度</param>
        /// <param name="cur">当前进度</param>
        /// <param name="rate">速度</param>
        /// <param name="remainsec">剩余时间</param>
        /// <param name="taskcount"></param>
        /// <param name="completecount">固定值为0 不能改变</param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void query_rate(IntPtr playlist, ref Int64 total, ref Int64 cur, ref int rate, ref int remainsec, ref int taskcount, ref int completecount);
        /// <summary>
        /// 取消节目单
        /// </summary>
        /// <param name="playlist">播放列表句柄</param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void cancel_send_program(IntPtr playlist);
        /// <summary>
        /// 视频md5验证
        /// </summary>
        /// <param name="playlist">播放列表句柄</param>
        /// <param name="md5">md5值</param>
        /// <param name="file_path">视频绝对路径</param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void add_video_md5(IntPtr playlist, string md5, string file_path);
        /// <summary>
        /// 删除素材
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int clear_material(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 清除所有节目
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int clear_all_program(byte[] ip, ushort port, string user_name, string user_pwd);

        #region insert list
        /// <summary>
        /// 插入数据
        /// </summary>
        /// <param name="playlist">播放列表句柄</param>
        /// <param name="insert_list_count"></param>
        /// <param name="insert_list_duration"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void add_insert_list(IntPtr playlist, int insert_list_count, int insert_list_duration);
        /// <summary>
        /// 停止播放插入数据
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int stop_play_insert_list(byte[] ip, ushort port, string user_name, string user_pwd);
        #endregion

        #region Program
        /// <summary>
        /// 停止播放节目
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int stop_play_program(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 创建播放列表
        /// </summary>
        /// <param name="w">屏幕宽度</param>
        /// <param name="h">屏幕高度</param>
        /// <param name="device_type">控制卡型号BX-Y04/8280 BX-Y08/8536 BX-Y2/8792 BX-Y2L/9304 BX-Y3/9048</param>
        /// <returns>播放列表句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_playlist(int w, int h, int device_type);
        /// <summary>
        /// 销毁播放列表
        /// </summary>
        /// <param name="playlist">播放列表句柄</param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_playlist(IntPtr playlist);
        /// <summary>
        /// 创建节目句柄
        /// </summary>
        /// <param name="name">节目名</param>
        /// <returns>节目句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_program(string name,string bg_color);
        /// <summary>
        /// 创建视频区句柄
        /// </summary>
        /// <returns>视频区句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_video();
        /// <summary>
        /// 创建图文句柄
        /// </summary>
        /// <returns>图文句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_pic();
        /// <summary>
        /// 创建字幕句柄
        /// </summary>
        /// <returns>字幕句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_text();
        /// <summary>
        /// 创建炫彩字分区
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_colortext();
        /// <summary>
        /// 创建时间句柄
        /// </summary>
        /// <returns>时间句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_time();
        /// <summary>
        /// 创建农历分区句柄。
        /// </summary>
        /// <returns>农历分区句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_calendar();
        /// <summary>
        /// 创建表盘分区句柄。
        /// </summary>
        /// <returns>表盘分区句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_clock();
        /// <summary>
        /// 创建传感器分区
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_sensor();
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_db();
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_audio();
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_broder();
        /// <summary>
        /// 创建动态区句柄
        /// </summary>
        /// <returns>动态区句柄</returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_dynamic();
        //销毁动态区句柄
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_dynamic(IntPtr area_tree);
        //
        /// <summary>
        /// 把视频区添加到节目
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree">视频区句柄</param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="volume_mode">是否静音：‘Unmute’/0 - 非静音；‘Mute’/1 - 静音</param>
        /// <param name="video_type">‘local’/0 - 本地视频或网络流媒体   ‘capture’/1 - 外部输入视频(Y 系列暂不支持)</param>
        /// <param name="ratation_mode">逆时针旋转角度：仅支持 0/90/180/270 四种，默认 0</param>
        /// <param name="clone_str"></param>
        /// <param name="crop_type">HDMI输出指定位置 可以给空字符串</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_video(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int volume_mode, int video_type, int ratation_mode, string clone_str, string crop_type);
        //
        /// <summary>
        /// 把图文区域添加到节目
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree">图文区句柄</param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度  1-255</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_pic(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int transparency);
        //
        /// <summary>
        /// 把动态区添加到节目
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree">动态区句柄</param>
        /// <param name="dynamic_id">动态区编号0-49</param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="relative_program">关联的节目，即所要关联的节目序号(节目列表中的 order 字段("0","1",...))</param>
        /// <param name="run_mode">动态区运行方式，0全局播放动态区/1全局动态区节目/2全局动态区节目/3绑定播放动态区，关联节目开始播放时播放动态区，直到关联节目播放完毕/4绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后本轮不再显示/5绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后静止显示该动态区的最后一个unit/6绑定播放动态区，关联节目播放完后播放动态区</param>
        /// <param name="update_frequency">放空""即可 </param>
        /// <param name="transparency">透明度  1-255</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_dynamic(IntPtr tree, IntPtr area_tree, int dynamic_id, int x, int y, int w, int h, string relative_program, int run_mode, string update_frequency, int transparency);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree"></param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度  1-255</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_broder(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int transparency);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree"></param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_colorful_subtitle(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree"></param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度  1-255</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_db(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int transparency);
        /// <summary>
        /// 节⽬添加⽂本
        /// </summary>
        /// <param name="tree">节目句柄</param>
        /// <param name="area_tree">字幕句柄</param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度  1-255</param>
        /// <param name="display_effects">播放特</param>
        /// <param name="unit_type"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_text(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);
        //
        /// <summary>
        /// 添加视频数据
        /// </summary>
        /// <param name="area_tree">视频分区句柄 </param>
        /// <param name="volume">音量</param>
        /// <param name="scale_mode">缩放模式0-按原始比例进行缩放，1-按窗口比例进行缩放</param>
        /// <param name="source">输⼊视频源（包括"CVBS/0"、“HDMI/1”，此属性只对外部输⼊视频类型有效） 0</param>
        /// <param name="play_time">播放时间</param>
        /// <param name="path">视频绝对路径</param>
        /// <param name="crop_type">HDMI输出指定位置 可以给空字符串</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_video_unit(IntPtr area_tree, int volume, int scale_mode, int source, int play_time, string path, string crop_type);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="area_tree"></param>
        /// <param name="duration"></param>
        /// <param name="broder_w"></param>
        /// <param name="texture_w"></param>
        /// <param name="stunt_type"></param>
        /// <param name="stunt_speed"></param>
        /// <param name="flicker_grade"></param>
        /// <param name="src_path"></param>
        /// <param name="flicker_path"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_broder_unit(IntPtr area_tree, int duration, int broder_w, int texture_w, int stunt_type, int stunt_speed, int flicker_grade, string src_path, string flicker_path);
        //
        /// <summary>
        /// 添加图文数据
        /// </summary>
        /// <param name="area_tree">图⽚分区句柄 </param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="path">图片文件全路径</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_pic_unit(IntPtr area_tree, int stay_time, int display_effects, int display_speed, string path);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="area_tree"></param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="last_move_width"></param>
        /// <param name="path"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_text_unit_img(IntPtr area_tree, int stay_time, int display_speed, int last_move_width, string path);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="area_tree"></param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="font_attributes">字体属性（包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进⾏组合）</param>
        /// <param name="font_alignment"></param>
        /// <param name="font_color">字体颜⾊ </param>
        /// <param name="bg_color">背景颜色</param>
        /// <param name="content">显⽰内容 </param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_text_unit_text(IntPtr area_tree, int stay_time, int display_speed, string font_name, int font_size, string font_attributes, string font_alignment, string font_color, string bg_color, string content);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="area_tree"></param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="path"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_colorful_hollowunit(IntPtr area_tree, int display_effects, int display_speed, int stay_time, string path);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="area_tree"></param>
        /// <param name="path"></param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="wave_effects">特技编号</param>
        /// <param name="wave_count"></param>
        /// <param name="wave_speed">特技运行速度</param>
        /// <param name="wave_amplitude"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_colorful_fontunit(IntPtr area_tree, string path, int display_effects, int display_speed, int stay_time, int wave_effects, int wave_count, int wave_speed, int wave_amplitude);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="db_tree"></param>
        /// <param name="db_type"></param>
        /// <param name="db_ip"></param>
        /// <param name="db_port"></param>
        /// <param name="user_name"></param>
        /// <param name="user_pwd"></param>
        /// <param name="db_name"></param>
        /// <param name="update_time"></param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="bg_odd_color"></param>
        /// <param name="bg_even_color"></param>
        /// <param name="text_odd_color"></param>
        /// <param name="text_even_color"></param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="font_bold"></param>
        /// <param name="font_italic"></param>
        /// <param name="font_underline"></param>
        /// <param name="font_strikeout"></param>
        /// <param name="font_noAntialias"></param>
        /// <param name="align_h_type"></param>
        /// <param name="align_v_type"></param>
        /// <param name="auto_lf"></param>
        /// <param name="head_type"></param>
        /// <param name="row_to_column"></param>
        /// <param name="linear"></param>
        /// <param name="line_w"></param>
        /// <param name="paint_table"></param>
        /// <param name="line_color"></param>
        /// <param name="row_count"></param>
        /// <param name="column_count"></param>
        /// <param name="row_h"></param>
        /// <param name="column_w"></param>
        /// <param name="cmd_data"></param>
        /// <param name="cmd_fieldname"></param>
        /// <param name="bg_img"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_db_unit(IntPtr db_tree, string db_type, string db_ip, ushort db_port, string user_name, string user_pwd, string db_name, int update_time, int stay_time, int display_effects, int display_speed, string bg_odd_color, string bg_even_color, string text_odd_color, string text_even_color, string font_name, int font_size, int font_bold, int font_italic, int font_underline, int font_strikeout, int font_noAntialias, string align_h_type, string align_v_type, string auto_lf, string head_type, string row_to_column, int linear, int line_w, int paint_table, string line_color, int row_count, int column_count, int row_h, int column_w, string cmd_data, string cmd_fieldname, string bg_img);
        //
        /// <summary>
        /// 添加时间区到节目
        /// </summary>
        /// <param name="tree">节⽬句柄 </param>
        /// <param name="area_tree">时间分区句柄 </param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度 </param>
        /// <param name="bg_color">背景颜色</param>
        /// <param name="time_equation">时差，格式“hh:mm:ss” </param>
        /// <param name="positive_te">正，负时差：”true“，”false“"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_time(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int transparency, string bg_color, string time_equation, string positive_te);
        /// <summary>
        /// 添加时间数据
        /// </summary>
        /// <param name="time_tree">时间分区句柄 </param>
        /// <param name="content">显⽰内容 </param>
        /// <param name="font_color">字体颜⾊ </param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="x">x坐标(相对窗⼝)</param>
        /// <param name="y">y坐标(相对窗⼝)</param>
        /// <param name="font_attributes">字体属性（包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进⾏组合）</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_time_unit(IntPtr time_tree, string content, string font_color, string font_name, int font_size, int x, int y, string font_attributes);
        /// <summary>
        /// 节⽬添加农历分区，
        /// </summary>
        /// <param name="tree">节⽬句柄 </param>
        /// <param name="area_tree">农历区句柄 </param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度 </param>
        /// <param name="bg_color">背景颜⾊ </param>
        /// <param name="time_equation">时差，格式“hh:mm:ss” </param>
        /// <param name="positive_te">正，负时差：”true“，”false“</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_calendar(IntPtr tree, IntPtr area_tree, int x, int y, int w, int h, int transparency, string bg_color, string time_equation, string positive_te);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="program">节⽬句柄</param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度 </param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="font_attributes">字体属性（包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进⾏组合）</param>
        /// <param name="font_color">字体颜⾊</param>
        /// <param name="thresh_fontcolor"></param>
        /// <param name="bg_color">背景颜⾊</param>
        /// <param name="content_sensor"></param>
        /// <param name="content_x">x坐标(相对窗⼝)</param>
        /// <param name="content_y">y坐标(相对窗⼝)</param>
        /// <param name="unit_type"></param>
        /// <param name="significant_digits"></param>
        /// <param name="unit_coefficient"></param>
        /// <param name="correction"></param>
        /// <param name="thresh_mode"></param>
        /// <param name="thresh"></param>
        /// <param name="sensor_addr"></param>
        /// <param name="fun_seq"></param>
        /// <param name="update_time"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_sensor(IntPtr program, int x, int y, int w, int h, int transparency,
            string font_name, int font_size, string font_attributes, string font_color, string thresh_fontcolor, string bg_color,
            string content_sensor, int content_x, int content_y, int unit_type, int significant_digits, float unit_coefficient,
            float correction, string thresh_mode, int thresh, string sensor_addr, string fun_seq,
            int update_time);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="program"></param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度  1-255</param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_density"></param>
        /// <param name="display_size"></param>
        /// <param name="direction"></param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="animation_color"></param>
        /// <param name="taper"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_animation(IntPtr program, int x, int y, int w, int h, int transparency, int display_effects, int display_density, int display_size,
            string direction, int display_speed, string animation_color, int taper);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="tree"></param>
        /// <param name="area_tree"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_audio(IntPtr tree, IntPtr area_tree);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="area_tree"></param>
        /// <param name="volume"></param>
        /// <param name="path"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_audio_unit(IntPtr area_tree, int volume, string path);
        /// <summary>
        /// 农历分区添加天⼲、地⽀、节⽓、固定⽂本
        /// </summary>
        /// <param name="calendar_tree">农历分区句柄 </param>
        /// <param name="mode">显⽰类型包括"heavenlystem"(天⼲)、“lunarcalendar”(农历)、“solarterms”(节⽓)、“text”(固定⽂ 本) </param>
        /// <param name="font_color">字体颜⾊ </param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="x">x坐标(相对窗⼝)</param>
        /// <param name="y">y坐标(相对窗⼝)</param>
        /// <param name="font_attributes">字体属性（包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进⾏组合）</param>
        /// <param name="text_content">mode为"text"时的⽂本内容</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_calendar_unit(IntPtr calendar_tree, string mode, string font_color, string font_name, int font_size, int x, int y, string font_attributes, string text_content);
        /// <summary>
        /// 节⽬添加表盘分区
        /// </summary>
        /// <param name="tree">节⽬句柄</param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度 </param>
        /// <param name="time_equation">时差，格式“hh:mm:ss” </param>
        /// <param name="positive_te">正，负时差：”true“，”false“</param>
        /// <param name="hour_color">时针颜⾊ </param>
        /// <param name="minute_color">分针颜⾊ </param>
        /// <param name="second_color">秒针颜⾊ </param>
        /// <param name="bg_image">背景图⽚路径</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_clock(IntPtr tree, IntPtr clock_area, int x, int y, int w, int h, int transparency, string time_equation, string positive_te, string hour_color, string minute_color, string second_color, string bg_image);
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_clock_hour(IntPtr clock_area, string src_path, string h_color, int h_length, int h_width);
        
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_clock_minute(IntPtr clock_area, string src_path, string m_color, int m_length, int m_width);
        
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_clock_second(IntPtr clock_area, string src_path, string s_color, int s_length, int s_width);
        /// <summary>
        /// 节⽬添加计时分区
        /// </summary>
        /// <param name="tree"></param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="transparency">透明度 </param>
        /// <param name="bg_color">背景颜⾊</param>
        /// <param name="time_equation">时差，格式“hh:mm:ss” </param>
        /// <param name="positive_te">正，负时差：”true“，”false“ </param>
        /// <param name="target_date">⽬标⽇期,格式“yyyy-MM-dd” </param>
        /// <param name="target_time">⽬标时间,格式“hh:mm:ss” </param>
        /// <param name="content">显⽰内容 </param>
        /// <param name="font_color">字体颜⾊ </param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="content_x">x坐标(相对窗⼝) </param>
        /// <param name="content_y">y坐标(相对窗⼝) </param>
        /// <param name="font_attributes">字体属性（包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进⾏组合）</param>
        /// <param name="add_enable"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_count(IntPtr tree, int x, int y, int w, int h, int transparency, string bg_color, string time_equation, string positive_te, string target_date, string target_time, string content, string font_color, string font_name, int font_size, int content_x, int content_y, string font_attributes, string add_enable);
        //
        /// <summary>
        /// 添加动态区图文数据
        /// </summary>
        /// <param name="dynamic_area">动态区句柄</param>
        /// <param name="dynamic_type">动态单元类型 图片 0  txt 1</param>
        /// <param name="display_effects">特技类型</param>
        /// <param name="display_speed">特技速度</param>
        /// <param name="stay_time">特技停留时间</param>
        /// <param name="file_path">元素路径：文本类的支持txt（utf-8）格式，字符串要使用Base64编码格式</param>
        /// <param name="gif_flag">0非GIF；1GIF类型（暂不支持动态播放，作为普通图片播放）</param>
        /// <param name="bg_color">背景颜色</param>
        /// <param name="font_size">字体大小</param>
        /// <param name="font_name">字体</param>
        /// <param name="font_color">字体颜色</param>
        /// <param name="font_attributes">包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进行组合</param>
        /// <param name="align_h">水平对齐方式0居左/1居右/2居中</param>
        /// <param name="align_v">垂直对齐方式0居上/1居下/2居中</param>
        //以下三个为视频属性，暂不支持视频
        /// <param name="volumn">音量</param>
        /// <param name="scale_mode">缩放模式，窗口比例0/原始比例1</param>
        /// <param name="rolation_mode">旋转角度</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_dynamic_unit(IntPtr dynamic_area, int dynamic_type, int display_effects, int display_speed, int stay_time, string file_path, int gif_flag, string bg_color, int font_size, string font_name, string font_color, string font_attributes, string align_h, string align_v, int volumn, int scale_mode, int rolation_mode);
        //
        /// <summary>
        /// 把节目添加到节目单
        /// </summary>
        /// <param name="playlist">播放列表</param>
        /// <param name="program">节目句柄</param>
        /// <param name="play_mode">播放模式，0 – 定长播放，1 – 定次播放</param>
        /// <param name="play_time">播放时长或者播放次数</param>
        /// <param name="aging_start_time">播放时效的开始日期</param>
        /// <param name="aging_end_time">播放时效结束日期</param>
        /// <param name="period_ontime">播放时段开始时间</param>
        /// <param name="period_offtime">放时段结束时间</param>
        /// <param name="play_week">bit0 ～ bit6 依次表示星期一至星期天，0—表示该天节目不能播放，1—表示该天节目可以播放</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_program_in_playlist(IntPtr playlist, IntPtr program, int play_mode, int play_time, string aging_start_time, string aging_end_time, string period_ontime, string period_offtime, int play_week);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="playlist"></param>
        /// <param name="play_mode"></param>
        /// <param name="startH"></param>
        /// <param name="startM"></param>
        /// <param name="startS"></param>
        /// <param name="endH"></param>
        /// <param name="endM"></param>
        /// <param name="endS"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_playlist_style(IntPtr playlist, int play_mode, int startH, int startM, int startS, int endH, int endM, int endS);
        #endregion

        #region Bulletin
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="bulletin_list"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int play_bulletin(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr bulletin_list);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="names"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int query_bulletin(byte[] ip, ushort port, string user_name, string user_pwd, string names);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="name"></param>
        /// <param name="layout"></param>
        /// <param name="transparency">透明度  1-255</param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_color">字体颜⾊ </param>
        /// <param name="bg_color">背景颜色</param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="aging_start_time"></param>
        /// <param name="aging_end_time"></param>
        /// <param name="period_ontime"></param>
        /// <param name="period_offtime"></param>
        /// <param name="content">显⽰内容 </param>
        /// <param name="font_align"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_bulletin(int x, int y, int w, int h, string name, int layout, int transparency, int font_size, string font_name, string font_color, string bg_color, int display_effects, int display_speed, int stay_time, string aging_start_time, string aging_end_time, string period_ontime, string period_offtime, string content, string font_align);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="names"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int delete_bulletin(byte[] ip, ushort port, string user_name, string user_pwd, string names);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int stop_play_bulletin(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="file_path"></param>
        /// <param name="bulletin"></param>
        /// <param name="x">坐标起始X</param>
        /// <param name="y">坐标起始Y</param>
        /// <param name="w">区域宽度</param>
        /// <param name="h">区域高度</param>
        /// <param name="name"></param>
        /// <param name="layout"></param>
        /// <param name="transparency">透明度  1-255</param>
        /// <param name="font_size">字体⼤⼩ </param>
        /// <param name="font_name">字体名称 </param>
        /// <param name="font_color">字体颜⾊ </param>
        /// <param name="bg_color">背景颜色</param>
        /// <param name="display_effects">特技编号</param>
        /// <param name="display_speed">特技运行速度</param>
        /// <param name="stay_time">停留时间 </param>
        /// <param name="aging_start_time"></param>
        /// <param name="aging_end_time"></param>
        /// <param name="period_ontime"></param>
        /// <param name="period_offtime"></param>
        /// <param name="content">显⽰内容 </param>
        /// <param name="font_align"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int add_bulletin(string file_path, IntPtr bulletin, int x, int y, int w, int h, string name, int layout, int transparency, int font_size, string font_name, string font_color, string bg_color, int display_effects, int display_speed, int stay_time, string aging_start_time, string aging_end_time, string period_ontime, string period_offtime, string content, string font_align);
        #endregion

        #region UDP
        /// <summary>
        /// 搜索局域⽹下的控制卡
        /// </summary>
        /// <param name="datas">控制卡的结构体数组</param>
        /// <param name="data_count">控制卡的数量</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int search_card(IntPtr datas, ref int data_count); 
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct card
        {
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public byte[] ip;//控制卡的地址    
            string barcode;//控制卡的条形码 
        }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_radio();
        /// <summary>
        /// 
        /// </summary>
        /// <param name="radios"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int search_cardSend(IntPtr radios);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="radios"></param>
        /// <param name="datas"></param>
        /// <param name="data_count"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int search_cardRecv(IntPtr radios, byte[] datas, ref int data_count);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="radios"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void destroy_radio(IntPtr radios);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="ip"></param>
        /// <param name="submark"></param>
        /// <param name="gateway"></param>
        /// <param name="dns_server"></param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_ip(string barcode, string pid, byte[] ip, byte[] submark, byte[] gateway, byte[] dns_server, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="ip"></param>
        /// <param name="submark"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_shadow_net_ip(string barcode, string pid, byte[] ip, byte[] submark);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="ip"></param>
        /// <param name="submark"></param>
        /// <param name="gateway"></param>
        /// <param name="dns_server"></param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_wifi_ip(string barcode, string pid, byte[] ip, byte[] submark, byte[] gateway, byte[] dns_server, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_auto_ip(string barcode, string pid, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_auto_wifi_ip(string barcode, string pid, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 设置MAC地址
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="mac">MAC地址</param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_mac(string barcode, string pid, string mac, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="mac">MAC地址</param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_wifi_mac(string barcode, string pid, string mac, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="install_address"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_install_address(string barcode, string pid, string install_address);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="user_id"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_web_user_id(string barcode, string pid, string user_id);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="wifis"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_ssid_list(string barcode, string pid, byte[] wifis);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="wifi_name">wifi名</param>
        /// <param name="wifi_pwd">WiFi密码</param>
        /// <param name="wifi_ip">wifiIP</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_ap_property(string barcode, string pid, string wifi_name, string wifi_pwd, byte[] wifi_ip);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="wifi_name">wifi名</param>
        /// <param name="wifi_pwd">WiFi密码</param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int connect_wifi(string barcode, string pid, string wifi_name, string wifi_pwd, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int disconnect_wifi(string barcode, string pid);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode"></param>
        /// <param name="pid"></param>
        /// <param name="wifi_status"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int query_wifi_status(string barcode, string pid, byte[] wifi_status);
        #endregion
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="pid"></param>
        /// <param name="device_type"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int check_screen_info(byte[] ip, ushort port, string user_name, string user_pwd, string pid, ushort device_type);
        /// <summary>
        /// 锁定节目
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="programLock">锁定：1  解锁：0</param>
        /// <param name="programName">节目名</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int lock_program(byte[] ip, ushort port, string user_name, string user_pwd, int programLock, string programName);
        /// <summary>
        /// 取得屏幕参数
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="datas">缓存空间</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_parameters(byte[] ip, ushort port, string user_name, string user_pwd, byte[] datas);
        /// <summary>
        /// 校正时间
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int check_time(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 格式化
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int reboot(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int restart_app(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 锁定屏幕
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="screenLock">锁定：1  解锁：0</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int lock_screen(byte[] ip, ushort port, string user_name, string user_pwd, int screenLock);
        /// <summary>
        /// 设置系统⾳量
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="volumn">⾳量值(0-100)</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_volumn(byte[] ip, ushort port, string user_name, string user_pwd, int volumn);
        //
        /// <summary>
        /// 手动调亮 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="brightness">亮度1-255</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_brightness(byte[] ip, ushort port, string user_name, string user_pwd, int brightness);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="brightness"></param>
        /// <param name="data_count"></param>
        /// <param name="sensor_brightness"></param>
        /// <param name="sensor_data_count"></param>
        /// <param name="sensor_addr"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_auto_brightness(byte[] ip, ushort port, string user_name, string user_pwd, ushort[] brightness, int data_count, ushort[] sensor_brightness, int sensor_data_count, string sensor_addr);
        /// <summary>
        /// 定时调亮，
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="brightness">48组亮度值 00:00:00-00:29:59 00:30:00-00:59:59.....23:30:00-23:59:59</param>
        /// <param name="data_count">固定值48 不能改变</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_cus_brightness(byte[] ip, ushort port, string user_name, string user_pwd, ushort[] brightness, int data_count);
        /// <summary>
        /// 设置开关机
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="turnonoff">开关机状态( 1:开机 0:关机)</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_turnonoff(byte[] ip, ushort port, string user_name, string user_pwd, int turnonoff);
        /// <summary>
        /// 定时开关机
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="trunonoff">开关机句柄</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_cus_turnonoff(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr trunonoff);
        /// <summary>
        /// 取消定时开关机
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int cancel_screen_cus_turnonoff(byte[] ip, ushort port, string user_name, string user_pwd);

        #region customer turn onoff
        /// <summary>
        /// 创建开关机句柄
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_turnonoff();
        /// <summary>
        /// 销毁开关机句柄
        /// </summary>
        /// <param name="trunonoff"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_turnonoff(IntPtr trunonoff);
        /// <summary>
        /// 设置开关机
        /// </summary>
        /// <param name="trunonoff">开关机句柄 </param>
        /// <param name="action">开关机( 1:开机 0:关机) </param>
        /// <param name="name">时间</param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void add_turnonoff(IntPtr trunonoff, int action, string name);
        #endregion
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="ppp_apn"></param>
        /// <param name="ppp_number"></param>
        /// <param name="ppp_username"></param>
        /// <param name="ppp_password"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_apn(byte[] ip, ushort port, string user_name, string user_pwd, string ppp_apn, string ppp_number, string ppp_username, string ppp_password);
        /// <summary>
        /// 设置logo信息
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="logoFlag"></param>
        /// <param name="w">宽度</param>
        /// <param name="h">高度</param>
        /// <param name="path"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_logo(byte[] ip, ushort port, string user_name, string user_pwd, int logoFlag, int w, int h, string path);
        /// <summary>
        /// 设置屏幕参数
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="w">屏宽 </param>
        /// <param name="h">屏⾼</param>
        /// <param name="screenrotation"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_size(byte[] ip, ushort port, string user_name, string user_pwd, int w, int h, int screenrotation);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="w"></param>
        /// <param name="h"></param>
        /// <param name="fold_type"></param>
        /// <param name="fold_count"></param>
        /// <param name="fold_h"></param>
        /// <param name="h_len"></param>
        /// <param name="fold_w"></param>
        /// <param name="w_len"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_fold_screen_size(byte[] ip, ushort port, string user_name, string user_pwd, int w, int h, int fold_type, int fold_count, int[] fold_h, int h_len, int[] fold_w, int w_len);
        /// <summary>
        /// 设置屏幕条码
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="barcode">条码</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_barcode(byte[] ip, ushort port, string user_name, string user_pwd, string barcode);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="flag"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_ip_flag(byte[] ip, ushort port, string user_name, string user_pwd, int flag);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="flag"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_led_flag(byte[] ip, ushort port, string user_name, string user_pwd, int flag);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="output_type"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_output_type(byte[] ip, ushort port, string user_name, string user_pwd, int output_type);
        /// <summary>
        /// 设置屏幕名
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="controller_name">屏幕名</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_name(byte[] ip, ushort port, string user_name, string user_pwd, string controller_name);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="timezoneflag"></param>
        /// <param name="timezone"></param>
        /// <param name="timezone_server"></param>
        /// <param name="timezone_interval"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_timezone(byte[] ip, ushort port, string user_name, string user_pwd, int timezoneflag, string timezone, string timezone_server, int timezone_interval);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="diskList"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_disk_list(byte[] ip, ushort port, string user_name, string user_pwd, byte[] diskList);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="curDisk"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_cur_disk(byte[] ip, ushort port, string user_name, string user_pwd, byte[] curDisk);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="storage_media"></param>
        /// <param name="totalsize"></param>
        /// <param name="freesize"></param>
        /// <param name="usedsize"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_disk_info(byte[] ip, ushort port, string user_name, string user_pwd, string storage_media, ref Int64 totalsize, ref Int64 freesize, ref Int64 usedsize);
        //
        /// <summary>
        /// 设置存储介质
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="storage_media">控制器存储节目的介质 sd usb1 emmc</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_storage_media(byte[] ip, ushort port, string user_name, string user_pwd, string storage_media);
        /// <summary>
        /// 查询固件版本
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="firmware_version">程序版本号 </param>
        /// <param name="app_version">APP版本号 </param>
        /// <param name="fpga_version">升级⽂件路径</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_firmware_version(byte[] ip, ushort port, string user_name, string user_pwd, byte[] firmware_version, byte[] app_version, byte[] fpga_version);
        /// <summary>
        /// 更新固件
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="firmware_path">升级⽂件路径</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int update_firmware(byte[] ip, ushort port, string user_name, string user_pwd, string firmware_path);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int net_getcode(byte[] ip, ushort port);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr net_login(byte[] ip, ushort port, string user_name, string user_pwd);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="post"></param>
        /// <param name="cmd"></param>
        /// <param name="data"></param>
        /// <param name="len"></param>
        /// <param name="recv_data"></param>
        /// <param name="recv_cmd"></param>
        /// <param name="recv_status"></param>
        /// <param name="recv_len"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_xser_cmd(IntPtr post, int cmd, string data, int len, byte[] recv_data, ref int recv_cmd, ref int recv_status, ref int recv_len);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="post"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int net_logout(IntPtr post);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="screen_onoff"></param>
        /// <param name="brigtness"></param>
        /// <param name="brigtness_mode"></param>
        /// <param name="volume"></param>
        /// <param name="screen_lockunlock"></param>
        /// <param name="program_lockunlock"></param>
        /// <param name="screen_time"></param>
        /// <param name="screen_addr"></param>
        /// <param name="screen_customer_onoff"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_status(byte[] ip, ushort port, string user_name, string user_pwd, ref int screen_onoff, ref int brigtness, ref int brigtness_mode, ref int volume, ref int screen_lockunlock, ref int program_lockunlock, byte[] screen_time, byte[] screen_addr, byte[] screen_customer_onoff);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="screen_w"></param>
        /// <param name="screen_h"></param>
        /// <param name="fold_type"></param>
        /// <param name="screen_type"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_send_program_info(byte[] ip, ushort port, string user_name, string user_pwd, ref int screen_w, ref int screen_h, ref int fold_type, ref ushort screen_type);
        /// <summary>
        /// 获取屏幕条码
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="barcode">条码</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_barcode(byte[] ip, ushort port, string user_name, string user_pwd, byte[] barcode);
        /// <summary>
        /// 获取屏幕mac
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="mac">MAC</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_mac(byte[] ip, ushort port, string user_name, string user_pwd, byte[] mac);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="dest_path"></param>
        /// <param name="capture_w"></param>
        /// <param name="capture_h"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_screen_capture(byte[] ip, ushort port, string user_name, string user_pwd, string dest_path, int capture_w, int capture_h);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="src_path"></param>
        /// <param name="dest_path"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int download_file(byte[] ip, ushort port, string user_name, string user_pwd, string src_path, string dest_path);

        #region Font
        #region customer font
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_font();
        /// <summary>
        /// 添加字库
        /// </summary>
        /// <param name="font"></param>
        /// <param name="font_file"></param>
        /// <param name="font_name">字体名称 </param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void add_font(IntPtr font, string font_file, string font_name);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="font"></param>
        /// <param name="font_name">字体名称 </param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_add_font(IntPtr font, string font_name);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="font"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_create_font(IntPtr font);
        #endregion
        /// <summary>
        /// 查询字库
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="system_font"></param>
        /// <param name="custom_font"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int query_font(byte[] ip, ushort port, string user_name, string user_pwd, byte[] system_font, byte[] custom_font);
        /// <summary>
        /// 安装字库
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="font"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int install_font(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr font);
        /// <summary>
        /// 删除字库
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="font"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int delete_font(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr font);
        #endregion

        #region sensor
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern IntPtr create_manage_sensor();
        /// <summary>
        /// 
        /// </summary>
        /// <param name="sensor"></param>
        /// <param name="unit_type"></param>
        /// <param name="significant_digits"></param>
        /// <param name="unit_coefficient"></param>
        /// <param name="correction"></param>
        /// <param name="thresh_mode"></param>
        /// <param name="thresh"></param>
        /// <param name="sensor_addr"></param>
        /// <param name="fun_seq"></param>
        /// <param name="relay_type"></param>
        /// <param name="relay_switch"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void add_manage_sensor(IntPtr sensor, int unit_type,
    int significant_digits, float unit_coefficient, float correction, string thresh_mode, int thresh, string sensor_addr,
    string fun_seq, int relay_type, int relay_switch);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="sensor"></param>
        /// <param name="sensor_index"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_add_sensor(IntPtr sensor, int sensor_index);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="sensor"></param>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern void delete_create_sensor(IntPtr sensor);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="sensor_bus"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_sensor_bus(byte[] ip, ushort port, string user_name, string user_pwd, byte[] sensor_bus);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="datas"></param>
        /// <param name="datas_count"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int get_sensor(byte[] ip, ushort port, string user_name, string user_pwd, byte[] datas, ref int datas_count);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="sensor_bus"></param>
        /// <param name="min_waitTime"></param>
        /// <param name="max_waitTime"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int query_seeksensor(byte[] ip, ushort port, string user_name, string user_pwd, string sensor_bus, ref int min_waitTime, ref int max_waitTime);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="setOrCancel"></param>
        /// <param name="update_time"></param>
        /// <param name="sensors"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_relay_switch(byte[] ip, ushort port, string user_name, string user_pwd, int setOrCancel, int update_time, IntPtr sensors);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="relay_addr"></param>
        /// <param name="relay_type"></param>
        /// <param name="relay_switch"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screenonoff_switch(byte[] ip, ushort port, string user_name, string user_pwd, string relay_addr, int relay_type, int relay_switch);
        #endregion

        #region Dynamic
        //
        /// <summary>
        /// 更新动态区图文
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="dynamic_playlist">播放列表</param>
        /// <param name="immediately_play">指定一个关联了普通节目的动态区 ID（必须是 dynamics 参数中存在的 id）</param>
        /// <param name="conver">是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目</param>
        /// <param name="onlyUpdate">是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int update_dynamic(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr dynamic_playlist, int immediately_play, int conver, int onlyUpdate);
        //
        /// <summary>
        /// 添加动态区字符串
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="dynamic_playlist">播放列表</param>
        /// <param name="immediately_play">指定一个关联了普通节目的动态区 ID（必须是 dynamics 参数中存在的 id）</param>
        /// <param name="conver">是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目</param>
        /// <param name="onlyUpdate">是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int update_dynamic_small(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr dynamic_playlist, int immediately_play, int conver, int onlyUpdate);
        //
        /// <summary>
        /// 替换素材，可用于更新已有动态区图文
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="dynamic_playlist">播放列表句柄</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int update_dynamic_unit(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr dynamic_playlist);
        /// <summary>
        /// 替换素材，可用于更新已有动态区字符串
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <param name="dynamic_playlist">播放列表句柄</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int update_dynamic_unit_small(byte[] ip, ushort port, string user_name, string user_pwd, IntPtr dynamic_playlist);
        /// <summary>
        /// 清除显示屏动态区
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="user_name">登录名 "guest"</param>
        /// <param name="user_pwd">登录密码 "guest"</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int clear_dynamic(byte[] ip, ushort port, string user_name, string user_pwd);
        #endregion

        #region Server Mode
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <param name="server_mode"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int set_screen_server(string barcode, string pid, byte[] ip, ushort port, int server_mode);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <param name="pid">PID</param>
        /// <param name="server_mode"></param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int enable_screen_server(string barcode, string pid, int server_mode);
        /// <summary>
        /// 启动服务器
        /// </summary>
        /// <param name="port">服务器端口</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int Start_Native_Server(ushort port);
        /// <summary>
        /// 停止服务器
        /// </summary>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int Stop_Server();
        /// <summary>
        /// 通过PID获取服务器模式下控制卡使用端口
        /// </summary>
        /// <param name="pid">PID码</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int Get_Port_Pid(string pid);
        /// <summary>
        /// 通过条码获取服务器模式下控制卡使用端口
        /// </summary>
        /// <param name="barcode">条码</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int Get_Port_Barcode(string barcode);
        /// <summary>
        /// 获取服务器模式下在线的控制器条形码列表
        /// </summary>
        /// <param name="datas">缓存空间 </param>
        /// <param name="data_count">控制卡的数量</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int Get_CardList(byte[] datas, ref int data_count);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ip">控制卡IP</param>
        /// <param name="port">端口</param>
        /// <returns></returns>
        [DllImport("YQNetCom.dll", CharSet = CharSet.Unicode)]
        public static extern int Refresh_CardInfo(byte[] ip, ushort port);
        #endregion


        //网络
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct BroadCast2
        {
            public int is_dhcp;
            public int wifi_is_dhcp;
            public int output_type;
            public int port;
            public int screen_w;
            public int screen_h;
            public int screen_volume;
            public int screen_brigtness;
            public int screen_brigtness_mode;
            public int screen_rotation;
            public ushort screen_type;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]
            public byte[] storagemedia;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 34)]
            public byte[] barcode;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] source_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] sub_mark;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] gateway;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] mac;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] local_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 66)]
            public byte[] pid;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
            public byte[] local_net;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] ap_wifi_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] wifi_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] wifi_sub_mark;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] wifi_gateway;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] dns_server;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] network_device;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
            public byte[] controller_name;
        }
        //屏参
        [StructLayout(LayoutKind.Sequential, Pack = 1)]
        public struct ControllerInfo
        {
            public int is_dhcp;
            public int wifi_is_dhcp;
            public int output_type;
            public int port;
            public int screen_w;
            public int screen_h;
            public int screen_volume;
            public int screen_brigtness;
            public int screen_brigtness_mode;
            public int fold_type;
            public int fold_count;
            public int logic_width;
            public int logic_height;
            public int screen_rotation;
            public int flag;
        	public ushort screen_type;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]
            public byte[] storagemedia;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 34)]
            public byte[] barcode;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] source_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] sub_mark;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] gateway;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] mac;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] local_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 66)]
            public byte[] pid;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
            public byte[] local_net;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] ap_wifi_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] wifi_ip;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] wifi_sub_mark;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] wifi_gateway;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] dns_server;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40)]
            public byte[] network_device;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
            public byte[] controller_name;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
            public byte[] fold_width;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
            public byte[] fold_height;
        }

    }
}

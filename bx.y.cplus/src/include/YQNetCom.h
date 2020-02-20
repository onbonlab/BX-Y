/************************************************************************
 * file:	YQNetCom.h
 * brief:	Header file of Network communication library in network part
 * author:	niu.zhimin
 * date:	2017-11-01
 ***********************************************************************/
#ifndef _YQNETCOM_H
#define _YQNETCOM_H
#ifdef _WIN32
#ifdef YQNETCOM_EXPORTS
#define LEDNETSDK_API extern "C" __declspec(dllexport)
#else
#define LEDNETSDK_API extern "C" __declspec(dllimport)
#endif
#define _TEXT_CHAR	wchar_t
//#define _JAVA
// #ifdef _JAVA
// #define _CALL_STD __cdecl
// #else
#define _CALL_STD __stdcall
//#endif
#else
#define LEDNETSDK_API extern "C"
#define _TEXT_CHAR	char
#define _CALL_STD  
#endif

typedef struct card
{
	char ip[20];//控制器地址
	char barcode[17];//控制器条形码
}card_unit;
typedef struct _CARD_SERVER
{
	char barcode[17];//控制器条形
}server_card;

typedef struct ControllerData
{
	int is_dhcp;
	int wifi_is_dhcp;
	int output_type;
	int port;
	int screen_w;
	int screen_h;
	int screen_volume;
	int screen_brigtness;
	int screen_brigtness_mode;
	int screen_rotation;
	unsigned short screen_type;
	_TEXT_CHAR storagemedia[10];
	_TEXT_CHAR barcode[17];
	_TEXT_CHAR ip[20];
	_TEXT_CHAR source_ip[20];
	_TEXT_CHAR sub_mark[20];
	_TEXT_CHAR gateway[20];
	_TEXT_CHAR mac[20];
	_TEXT_CHAR local_ip[20];
	_TEXT_CHAR pid[33];
	_TEXT_CHAR local_net[64];
	_TEXT_CHAR ap_wifi_ip[20];
	_TEXT_CHAR wifi_ip[20];
	_TEXT_CHAR wifi_sub_mark[20];
	_TEXT_CHAR wifi_gateway[20];
	_TEXT_CHAR dns_server[20];
	_TEXT_CHAR network_device[20];
	_TEXT_CHAR controller_name[128];
}BroadCast2;

typedef struct ControllerInfo
{
	int is_dhcp;
	int wifi_is_dhcp;
	int output_type;
	int port;
	int screen_w;
	int screen_h;
	int screen_volume;
	int screen_brigtness;
	int screen_brigtness_mode;
	int fold_type;
	int fold_count;
	int logic_width;
	int logic_height;
	int screen_rotation;
	int timezone_flag;
	unsigned short screen_type;
	_TEXT_CHAR storagemedia[10];
	_TEXT_CHAR barcode[17];
	_TEXT_CHAR ip[20];
	_TEXT_CHAR source_ip[20];
	_TEXT_CHAR sub_mark[20];
	_TEXT_CHAR gateway[20];
	_TEXT_CHAR mac[20];
	_TEXT_CHAR local_ip[20];
	_TEXT_CHAR pid[33];
	_TEXT_CHAR local_net[64];
	_TEXT_CHAR ap_wifi_ip[20];
	_TEXT_CHAR wifi_ip[20];
	_TEXT_CHAR wifi_sub_mark[20];
	_TEXT_CHAR wifi_gateway[20];
	_TEXT_CHAR dns_server[20];
	_TEXT_CHAR network_device[20];
	_TEXT_CHAR controller_name[128];
	_TEXT_CHAR fold_width[128];
	_TEXT_CHAR fold_height[128];
	_TEXT_CHAR timezone[128];
	_TEXT_CHAR timezone_server[128];
}controllerInfo;



#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
LEDNETSDK_API int _CALL_STD init_sdk();

LEDNETSDK_API int _CALL_STD release_sdk();
#endif

LEDNETSDK_API int _CALL_STD search_card(unsigned char* cards, int* card_count);

LEDNETSDK_API unsigned long _CALL_STD create_radio();
LEDNETSDK_API int _CALL_STD search_cardSend(unsigned long radio);
LEDNETSDK_API int _CALL_STD search_cardRecv(unsigned long radio,unsigned char* cards, int* card_count);
LEDNETSDK_API void _CALL_STD destroy_radio(unsigned long radio);

// 函数：	set_screen_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* ip：控制器ip
//			char* submark：网关
//			char* gateway：子网掩码
//			char* dns_server: 域名服务器地址
// 说明：	设置控制器IP地址
LEDNETSDK_API int _CALL_STD set_screen_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);
/*
//函数：	set_screen_ip_dwhand
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器ip
//			char* submark：网关
//			char* gateway：子网掩码
//			char* dns_server: 域名服务器地址
// 说明：	TCP设置控制器IP地址
*/
LEDNETSDK_API int _CALL_STD set_screen_ip_dwhand(unsigned long dwhand, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD set_screen_shadow_net_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark);

// 函数：	set_screen_wifi_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* ip：控制器ip
//			char* submark：网关
//			char* gateway：子网掩码
//			char* dns_server: 域名服务器地址
// 说明：	设置控制器IP地址
LEDNETSDK_API int _CALL_STD set_screen_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* ip, char* submark, char* gateway, char* dns_server, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_auto_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
// 说明：	设置控制器自动获取IP地址
LEDNETSDK_API int _CALL_STD set_screen_auto_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_auto_wifi_ip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
// 说明：	设置控制器自动获取IP地址
LEDNETSDK_API int _CALL_STD set_screen_auto_wifi_ip(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_mac
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* mac：控制器mac
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD set_screen_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_wifi_mac
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* mac：控制器mac
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD set_screen_wifi_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac, int* min_waitTime, int* max_waitTime);

// 函数：	set_screen_server
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			int server_mode：server(1)：普通服务器模式；cloud(2) ：云平台服务器模式；off(0)：关闭服务器模式；
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD set_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, char* server_ip, unsigned short port, int server_mode);

// 函数：	enable_screen_server
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			int server_mode：server(1)：普通服务器模式；cloud(2) ：云平台服务器模式；off(0)：关闭服务器模式；
// 说明：	设置控制器MAC地址
LEDNETSDK_API int _CALL_STD enable_screen_server(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, int server_mode);

// 函数：	set_screen_install_address
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			_TEXT_CHAR* install_address：控制器安装地址
// 说明：	设置控制器IP地址
LEDNETSDK_API int _CALL_STD set_screen_install_address(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* install_address);

LEDNETSDK_API int _CALL_STD set_web_user_id(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* user_id);

LEDNETSDK_API int _CALL_STD send_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* tmp_path, unsigned long playlist, int send_style, long long  * free_size, long long * total_size);
LEDNETSDK_API int _CALL_STD send_program_dwhand(unsigned long dwhand, char* ip, _TEXT_CHAR* tmp_path, unsigned long playlist, int send_style, long long  * free_size, long long * total_size);

LEDNETSDK_API void _CALL_STD query_rate(unsigned long playlist, long long * total,long long * cur,int* rate,int* remainsec,int* taskcount,int* completecount);

LEDNETSDK_API void _CALL_STD cancel_send_program(unsigned long playlist);

LEDNETSDK_API void _CALL_STD add_video_md5(unsigned long playlist, _TEXT_CHAR* md5, _TEXT_CHAR* file_path);

LEDNETSDK_API int _CALL_STD clear_material(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_material_dwhand(unsigned long dwhand);

LEDNETSDK_API int _CALL_STD clear_all_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_all_program_dwhand(unsigned long dwhand);

// 函数：	enable_uploaddownload
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：通讯IP
//			unsigned short port：通讯端口
//			_TEXT_CHAR* user_name：登陆用户名
//			_TEXT_CHAR* user_pwd：登陆密码
//			int enable_state：开启还是关闭
//			int upload_download：上传还是下载
// 说明：	开启/关闭文件上传/下载
LEDNETSDK_API int _CALL_STD enable_uploaddownload(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int enable_state, int upload_download);
LEDNETSDK_API int _CALL_STD enable_uploaddownload_dwhand(unsigned long dwhand, int enable_state, int upload_download);

#pragma region insert list
LEDNETSDK_API void _CALL_STD add_insert_list(unsigned long playlist, int insert_list_count, int insert_list_duration);
#pragma endregion insert list

#pragma region program
LEDNETSDK_API unsigned long _CALL_STD create_playlist(int w, int h, int device_type);

LEDNETSDK_API void _CALL_STD delete_playlist(unsigned long playlist);

LEDNETSDK_API void _CALL_STD delete_dynamic(unsigned long dynamic_area);

LEDNETSDK_API unsigned long _CALL_STD create_program(_TEXT_CHAR* name, _TEXT_CHAR* bg_color);

LEDNETSDK_API unsigned long _CALL_STD create_video();

LEDNETSDK_API unsigned long _CALL_STD create_pic();

LEDNETSDK_API unsigned long _CALL_STD create_text();

LEDNETSDK_API unsigned long _CALL_STD create_colortext();

LEDNETSDK_API unsigned long _CALL_STD create_time();

LEDNETSDK_API unsigned long _CALL_STD create_calendar();

LEDNETSDK_API unsigned long _CALL_STD create_sensor();

LEDNETSDK_API unsigned long _CALL_STD create_db();

LEDNETSDK_API unsigned long _CALL_STD create_db_unit();

LEDNETSDK_API unsigned long _CALL_STD create_audio();

LEDNETSDK_API unsigned long _CALL_STD create_broder();

LEDNETSDK_API unsigned long _CALL_STD create_dynamic();

LEDNETSDK_API unsigned long _CALL_STD create_clock();

LEDNETSDK_API int _CALL_STD add_video(unsigned long program, unsigned long video_area, int x, int y, int w, int h, int volume_mode, int video_type, int ratation_mode, _TEXT_CHAR* clone_str, _TEXT_CHAR* crop_type);

LEDNETSDK_API int _CALL_STD add_pic(unsigned long program, unsigned long pic_area, int x, int y, int w, int h, int transparency);

LEDNETSDK_API int _CALL_STD add_broder(unsigned long program, unsigned long broder_area, int x, int y, int w, int h, int transparency);

// 函数：	add_dynamic
// 返回值：	
// 参数：	
//			IntPtr tree：动态区节目节点句柄
//			IntPtr area_tree：动态区区域节点句柄
//			int x/y/w/h:动态区区域坐标和宽高
//			int relative_program:关联的节目，即所要关联的节目序号(节目列表中的 order 字段("0","1",...))
//		int run_mode:动态区运行方式，0全局播放动态区/1全局动态区节目/2全局动态区节目/3绑定播放动态区，关联节目开始播放时播放动态区，直到关联节目播放完毕/4绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后本轮不再显示/5绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后静止显示该动态区的最后一个unit/6绑定播放动态区，关联节目播放完后播放动态区
//			update_frequency：放空""即可 
//			transparency:透明度
// 说明：	添加动态区
LEDNETSDK_API int _CALL_STD add_dynamic(unsigned long program, unsigned long dynamic_area, int dynamic_id, int x, int y, int w, int h, _TEXT_CHAR* relative_program, int run_mode, _TEXT_CHAR* update_frequency, int transparency);

LEDNETSDK_API int _CALL_STD add_colorful_subtitle(unsigned long program, unsigned long colorful_subtitle_area, int x, int y, int w, int h);

LEDNETSDK_API int _CALL_STD add_db(unsigned long program, unsigned long db_area, int x, int y, int w, int h, int transparency);

LEDNETSDK_API int _CALL_STD add_text(unsigned long program, unsigned long text_area, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);

LEDNETSDK_API int _CALL_STD add_clock(unsigned long program, unsigned long clock_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* hour_color, _TEXT_CHAR* minute_color, _TEXT_CHAR* second_color, _TEXT_CHAR* bg_image);

LEDNETSDK_API int _CALL_STD add_clock_hour(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* h_color, int h_length, int h_width);

LEDNETSDK_API int _CALL_STD add_clock_minute(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* m_color, int m_length, int m_width);

LEDNETSDK_API int _CALL_STD add_clock_second(unsigned long clock_area, _TEXT_CHAR* src_path, _TEXT_CHAR* s_color, int s_length, int s_width);

LEDNETSDK_API int _CALL_STD add_count(unsigned long program, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te, _TEXT_CHAR* target_date, _TEXT_CHAR* target_time, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int content_x, int content_y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* add_enable);

LEDNETSDK_API int _CALL_STD add_time(unsigned long program, unsigned long time_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te);

LEDNETSDK_API int _CALL_STD add_calendar(unsigned long program, unsigned long calendar_area, int x, int y, int w, int h, int transparency, _TEXT_CHAR* bg_color, _TEXT_CHAR* time_equation, _TEXT_CHAR* positive_te);

LEDNETSDK_API int _CALL_STD add_sensor(unsigned long program, int x, int y, int w, int h, int transparency, 
	_TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_color, _TEXT_CHAR* thresh_fontcolor, _TEXT_CHAR* bg_color, 
	_TEXT_CHAR* content_sensor, int content_x, int content_y, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int update_time);

LEDNETSDK_API int _CALL_STD add_animation(unsigned long program, int x, int y, int w, int h, int transparency, int display_effects, int display_density, int display_size, _TEXT_CHAR* direction, int display_speed, _TEXT_CHAR* animation_color, int taper);

LEDNETSDK_API int _CALL_STD add_audio(unsigned long program, unsigned long audio_area);

LEDNETSDK_API int _CALL_STD add_video_unit(unsigned long video_area, int volume, int scale_mode, int source, int play_time, _TEXT_CHAR* src_path, _TEXT_CHAR* crop_type);

LEDNETSDK_API int _CALL_STD add_broder_unit(unsigned long broder_area, int duration, int broder_w, int texture_w, int stunt_type, int stunt_speed, int flicker_grade, _TEXT_CHAR* src_path, _TEXT_CHAR* flicker_path);

LEDNETSDK_API int _CALL_STD add_pic_unit(unsigned long pic_area, int stay_time, int display_effects, int display_speed, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD add_text_unit_img(unsigned long text_area, int stay_time, int display_speed, int last_move_width, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD add_text_unit_text(unsigned long text_area, int stay_time, int display_speed, _TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_alignment, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);

LEDNETSDK_API int _CALL_STD add_colorful_hollowunit(unsigned long colorful_subtitle_area, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* hollow_file);

LEDNETSDK_API int _CALL_STD add_colorful_fontunit(unsigned long colorful_subtitle_area, _TEXT_CHAR* file, int display_effects, int display_speed, int stay_time, int wave_effects, int wave_count, int wave_speed, int wave_amplitude);

LEDNETSDK_API int _CALL_STD add_time_unit(unsigned long time_area, _TEXT_CHAR* content, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes);

LEDNETSDK_API int _CALL_STD add_calendar_unit(unsigned long calendar_area, _TEXT_CHAR* mode, _TEXT_CHAR* font_color, _TEXT_CHAR* font_name, int font_size, int x, int y, _TEXT_CHAR* font_attributes, _TEXT_CHAR* text_content);

//LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, _TEXT_CHAR* db_type, _TEXT_CHAR* db_ip,  unsigned short db_port,  _TEXT_CHAR* user_name,  _TEXT_CHAR* user_pwd,  _TEXT_CHAR* db_name, int update_time, int stay_time, int display_effects, int display_speed,  _TEXT_CHAR* bg_odd_color,  _TEXT_CHAR* bg_even_color, _TEXT_CHAR* text_odd_color, _TEXT_CHAR* text_even_color,  _TEXT_CHAR* font_name, int font_size, int font_bold, int font_italic, int font_underline, int font_strikeout, int font_noAntialias, _TEXT_CHAR* align_h_type, _TEXT_CHAR* align_v_type, _TEXT_CHAR* auto_lf , _TEXT_CHAR* headtype, _TEXT_CHAR* row_to_column, int linear, int line_w, int paint_table, _TEXT_CHAR* line_color, int row_count, int column_count, int row_h, int column_w, _TEXT_CHAR* cmd_data, _TEXT_CHAR* cmd_fieldname , _TEXT_CHAR* bg_img);
LEDNETSDK_API int _CALL_STD add_db_unit(unsigned long db_area, unsigned long dbUnit, struct DatabaseUnitInfo* dbUnitInfo);

LEDNETSDK_API int _CALL_STD add_db_unit_specifyrow(unsigned long dbUnit, struct SpecifyRow* specifyRow);

LEDNETSDK_API int _CALL_STD add_db_unit_specifycolumn(unsigned long dbUnit, struct SpecifyColumn* specifyColumn);

LEDNETSDK_API int _CALL_STD add_db_unit_specifycell(unsigned long dbUnit, struct SpecifyCell* specifyCell);

LEDNETSDK_API int _CALL_STD add_audio_unit(unsigned long audio_area, int volume, _TEXT_CHAR* src_path);

// 函数：	add_dynamic_unit
// 返回值：	
// 参数：	
//			dynamic_area：动态区区域节点句柄
//			int dynamic_type:动态单元类型
//			int display_effects:特技类型
//			int display_speed：特技速度
//			int stay_time:特技停留时间
//			file_path:元素路径：文本类的支持txt格式
//			gif_flag:0非GIF；1GIF类型（暂不支持动态播放，作为普通图片播放）
//			bg_color：背景颜色
//			font_size：字体大小
//			font_color:字体颜色
//			font_attributes：包括“bold”、“italic”、“normal”，其中“bold”和“italic”可以通过“&”进行组合
//			font_name：字体
//			align_h:水平对齐方式0居左/1居右/2居中
//			align_v:垂直对齐方式0居上/1居下/2居中
//以下三个为视频属性，暂不支持视频
//			volumn：音量
//			scale_mode：缩放模式，窗口比例0/原始比例1
//			rolation_mode：旋转角度
LEDNETSDK_API int _CALL_STD add_dynamic_unit(unsigned long dynamic_area, int dynamic_type, int display_effects, int display_speed, int stay_time,_TEXT_CHAR* file_path, int gif_flag, _TEXT_CHAR* bg_color, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* font_attributes, _TEXT_CHAR* align_h, _TEXT_CHAR* align_v, int volumn, int scale_mode, int rolation_mode);

LEDNETSDK_API int _CALL_STD add_program_in_playlist(unsigned long playlist, unsigned long program, int play_mode, int play_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, int play_week);

/*
设置是否同步播放
*/
LEDNETSDK_API int _CALL_STD set_playlist_style(unsigned long playlist, int sync_display, int startH, int startM, int startS, int endH, int endM, int endS);
#pragma endregion program

#pragma region bulletin
LEDNETSDK_API int _CALL_STD play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long bulletin_list);
LEDNETSDK_API int _CALL_STD play_bulletin_dwhand(unsigned long dwhand,char* ip, unsigned short port, unsigned long bulletin_list);

// 函数：	query_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* names：当前控制器上所有公告名称，多个使用分号隔开
// 说明：	查询公告
LEDNETSDK_API int _CALL_STD query_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd,  _TEXT_CHAR* names);
LEDNETSDK_API int _CALL_STD query_bulletin_dwhand(unsigned long dwhand,  _TEXT_CHAR* names);

LEDNETSDK_API int _CALL_STD create_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
LEDNETSDK_API int _CALL_STD create_bulletin_dwhand(unsigned long dwhand, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);

// 函数：	delete_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* names：指定删除的公告名称，多个使用分号隔开
// 说明：	删除指定公告
LEDNETSDK_API int _CALL_STD delete_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd,  _TEXT_CHAR* names);
LEDNETSDK_API int _CALL_STD delete_bulletin_dwhand(unsigned long dwhand,  _TEXT_CHAR* names);

LEDNETSDK_API int _CALL_STD stop_play_bulletin(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD stop_play_bulletin_dwhand(unsigned long dwhand);

// 函数：	add_bulletin
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	添加公告并且生存xml文件，并且记录到play_list类中；方便在上传文件的时候使用文件md5及路径
LEDNETSDK_API int _CALL_STD add_bulletin(_TEXT_CHAR* tmp_path, unsigned long playlist, int x, int y, int w, int h, _TEXT_CHAR* name, int layout, int transparency, int font_size, _TEXT_CHAR* font_name, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, int display_effects, int display_speed, int stay_time, _TEXT_CHAR* aging_start_time, _TEXT_CHAR* aging_end_time, _TEXT_CHAR* period_ontime, _TEXT_CHAR* period_offtime, _TEXT_CHAR* content, _TEXT_CHAR* font_align);
#pragma endregion bulletin

LEDNETSDK_API int _CALL_STD change_password(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pwd);
LEDNETSDK_API int _CALL_STD change_password_dwhand(unsigned long dwhand, _TEXT_CHAR* pwd);

LEDNETSDK_API int _CALL_STD reset_password(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD reset_password_dwhand(unsigned long dwhand, _TEXT_CHAR* user_name);

LEDNETSDK_API int _CALL_STD check_screen_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* pid, unsigned short device_type);
LEDNETSDK_API int _CALL_STD check_screen_info_dwhand(unsigned long dwhand, _TEXT_CHAR* pid, unsigned short device_type);

// 函数：	play_program
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			_TEXT_CHAR* path：播放节目路径
// 说明：	播放指定节目
LEDNETSDK_API int _CALL_STD play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path);
LEDNETSDK_API int _CALL_STD play_program_dwhand(unsigned long dwhand, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD stop_play_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD stop_play_program_dwhand(unsigned long dwhand);

LEDNETSDK_API int _CALL_STD lock_program(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, _TEXT_CHAR* program_name);
LEDNETSDK_API int _CALL_STD lock_program_dwhand(unsigned long dwhand, int flag, _TEXT_CHAR* program_name);

LEDNETSDK_API int _CALL_STD get_screen_parameters(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned char* cards);
LEDNETSDK_API int _CALL_STD get_screen_parameters_dwhand(unsigned long dwhand, unsigned char* cards);

LEDNETSDK_API int _CALL_STD restart_boot(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD restart_boot_dwhand(unsigned long dwhand);

LEDNETSDK_API int _CALL_STD restart_app(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD restart_app_dwhand(unsigned long dwhand);

LEDNETSDK_API int _CALL_STD check_time(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD check_time_dwhand(unsigned long dwhand);

LEDNETSDK_API int _CALL_STD lock_screen(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int lock);
LEDNETSDK_API int _CALL_STD lock_screen_dwhand(unsigned long dwhand, int lock);

LEDNETSDK_API int _CALL_STD set_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int brightness);
LEDNETSDK_API int _CALL_STD set_screen_brightness_dwhand(unsigned long dwhand, int brightness);

LEDNETSDK_API int _CALL_STD set_screen_auto_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);
LEDNETSDK_API int _CALL_STD set_screen_auto_brightness_dwhand(unsigned long dwhand, unsigned short* brightness, int data_count, unsigned short* sensor_brightness, int sensor_data_count, _TEXT_CHAR* sensor_addr);

LEDNETSDK_API int _CALL_STD set_screen_cus_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned short* brightness, int data_count);
LEDNETSDK_API int _CALL_STD set_screen_cus_brightness_dwhand(unsigned long dwhand, unsigned short* brightness, int data_count);

LEDNETSDK_API int _CALL_STD set_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int volumn);
LEDNETSDK_API int _CALL_STD set_screen_volumn_dwhand(unsigned long dwhand, int volumn);

LEDNETSDK_API int _CALL_STD set_screen_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int turnonoff_status);
LEDNETSDK_API int _CALL_STD set_screen_turnonoff_dwhand(unsigned long dwhand, int turnonoff_status);

// 函数：	screen_cus_turnonoff
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			struct CustomerTurnOnOffScreenData* turnonoff：定时开关机结构体
//			int data_count：定时开关机结构体个数，如果传入为0时，表示取消定时开关机；否则表示设置定时开关机
// 说明：	定时开关机
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long turnonoff);
LEDNETSDK_API int _CALL_STD set_screen_cus_turnonoff_dwhand(unsigned long dwhand, unsigned long turnonoff);

LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD cancel_screen_cus_turnonoff_dwhand(unsigned long dwhand);

#pragma region customer turn onoff
LEDNETSDK_API unsigned long _CALL_STD create_turnonoff();

LEDNETSDK_API void _CALL_STD add_turnonoff(unsigned long turnonoff, int action, _TEXT_CHAR* time);

LEDNETSDK_API void _CALL_STD delete_turnonoff(unsigned long turnonoff);
#pragma endregion customer turn onoff

LEDNETSDK_API int _CALL_STD set_apn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);
LEDNETSDK_API int _CALL_STD set_apn_dwhand(unsigned long dwhand, _TEXT_CHAR* ppp_apn, _TEXT_CHAR* ppp_number, _TEXT_CHAR* ppp_username, _TEXT_CHAR* ppp_password);

LEDNETSDK_API int _CALL_STD set_screen_logo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag, int screen_w, int screen_h, _TEXT_CHAR* src_path);
LEDNETSDK_API int _CALL_STD set_screen_logo_dwhand(unsigned long dwhand,char* ip, unsigned short port, int flag, int screen_w, int screen_h, _TEXT_CHAR* src_path);

LEDNETSDK_API int _CALL_STD set_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int screenrotation);
LEDNETSDK_API int _CALL_STD set_screen_size_dwhand(unsigned long dwhand, int screen_w, int screen_h, int screenrotation);

LEDNETSDK_API int _CALL_STD set_fold_screen_size(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);
LEDNETSDK_API int _CALL_STD set_fold_screen_size_dwhand(unsigned long dwhand, int screen_w, int screen_h, int fold_type, int fold_count, int* fold_h, int h_len, int* fold_w, int w_len);

LEDNETSDK_API int _CALL_STD set_screen_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD set_screen_barcode_dwhand(unsigned long dwhand, _TEXT_CHAR* barcode);

LEDNETSDK_API int _CALL_STD set_screen_ip_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);
LEDNETSDK_API int _CALL_STD set_screen_ip_flag_dwhand(unsigned long dwhand, int flag);

LEDNETSDK_API int _CALL_STD set_screen_led_flag(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int flag);
LEDNETSDK_API int _CALL_STD set_screen_led_flag_dwhand(unsigned long dwhand, int flag);

LEDNETSDK_API int _CALL_STD set_screen_output_type(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int output_type);
LEDNETSDK_API int _CALL_STD set_screen_output_type_dwhand(unsigned long dwhand, int output_type);

LEDNETSDK_API int _CALL_STD set_screen_name(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_name);
LEDNETSDK_API int _CALL_STD set_screen_name_dwhand(unsigned long dwhand, _TEXT_CHAR* controller_name);

LEDNETSDK_API int _CALL_STD set_screen_timezone(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);
LEDNETSDK_API int _CALL_STD set_screen_timezone_dwhand(unsigned long dwhand, int timezoneflag, _TEXT_CHAR* timezone, _TEXT_CHAR* timezone_server, int timezone_interval);

LEDNETSDK_API int _CALL_STD set_screen_language(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* controller_language);
LEDNETSDK_API int _CALL_STD set_screen_language_dwhand(unsigned long dwhand, _TEXT_CHAR* controller_language);

LEDNETSDK_API int _CALL_STD get_screen_disk_list(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD get_screen_disk_list_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

LEDNETSDK_API int _CALL_STD get_screen_cur_disk(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD get_screen_cur_disk_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

LEDNETSDK_API int _CALL_STD get_screen_disk_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);
LEDNETSDK_API int _CALL_STD get_screen_disk_info_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media, long long *totalsize, long long *freesize, long long *usedsize);

LEDNETSDK_API int _CALL_STD set_screen_storage_media(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* storage_media);
LEDNETSDK_API int _CALL_STD set_screen_storage_media_dwhand(unsigned long dwhand, _TEXT_CHAR* storage_media);

LEDNETSDK_API int _CALL_STD get_screen_status(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff, _TEXT_CHAR* screen_language);
LEDNETSDK_API int _CALL_STD get_screen_status_dwhand(unsigned long dwhand, int* screen_onoff, int* brigtness, int* brigtness_mode, int* volume, int* screen_lockunlock, int* program_lockunlock, _TEXT_CHAR* screen_time, _TEXT_CHAR* screen_addr, _TEXT_CHAR* screen_customer_onoff, _TEXT_CHAR* screen_language);

LEDNETSDK_API int _CALL_STD get_screen_send_program_info(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);
LEDNETSDK_API int _CALL_STD get_screen_send_program_info_dwhand(unsigned long dwhand, int* screen_w, int* screen_h, int* fold_type, unsigned short* screen_type);

LEDNETSDK_API int _CALL_STD get_firmware_version(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);
LEDNETSDK_API int _CALL_STD get_firmware_version_dwhand(unsigned long dwhand, _TEXT_CHAR* firmware_version, _TEXT_CHAR* app_version, _TEXT_CHAR* fpga_version);

LEDNETSDK_API int _CALL_STD update_firmware(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path);
LEDNETSDK_API int _CALL_STD update_firmware_dwhand(unsigned long dwhand,char* ip, unsigned short port, _TEXT_CHAR* src_path);

LEDNETSDK_API unsigned int _CALL_STD net_getcode(char* ip, unsigned short port);

LEDNETSDK_API unsigned long _CALL_STD net_login(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD net_logout(unsigned long post);

LEDNETSDK_API int _CALL_STD set_xser_cmd(unsigned long post,int cmd,_TEXT_CHAR* content, int len, _TEXT_CHAR* recv_data, int* recv_cmd, int* recv_status, int* recv_len);

LEDNETSDK_API int _CALL_STD get_barcode(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD get_barcode_dwhand(unsigned long dwhand, _TEXT_CHAR* barcode);

LEDNETSDK_API int _CALL_STD get_screen_mac(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* mac);
LEDNETSDK_API int _CALL_STD get_screen_mac_dwhand(unsigned long dwhand, _TEXT_CHAR* mac);

LEDNETSDK_API int _CALL_STD get_screen_capture(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* file_path, int captureW, int captureH);
LEDNETSDK_API int _CALL_STD get_screen_capture_dwhand(unsigned long dwhand, _TEXT_CHAR* file_path, int captureW, int captureH);

LEDNETSDK_API int _CALL_STD download_file(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);
LEDNETSDK_API int _CALL_STD download_file_dwhand(unsigned long dwhand, _TEXT_CHAR* src_path, _TEXT_CHAR* dest_path);

#pragma region WIFI
LEDNETSDK_API int _CALL_STD  get_ssid_list(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* values);

LEDNETSDK_API int _CALL_STD  set_ap_property(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_name, _TEXT_CHAR* wifi_pwd, char* wifi_ip);

LEDNETSDK_API int _CALL_STD  connect_wifi(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_name, _TEXT_CHAR* wifi_pwd, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD  disconnect_wifi(_TEXT_CHAR* barcode, _TEXT_CHAR* pid);

LEDNETSDK_API int _CALL_STD  query_wifi_status(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* wifi_status);

// 函数：	set_wifi_screen_mac
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* pid：控制器唯一码
//			_TEXT_CHAR* barcode：控制器唯一码
//			char* mac：控制器mac
// 说明：	设置控制器WIFI MAC地址
LEDNETSDK_API int _CALL_STD set_wifi_screen_mac(_TEXT_CHAR* barcode, _TEXT_CHAR* pid, _TEXT_CHAR* mac);
#pragma endregion WIFI

#pragma region Font
// 函数：	query_font
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* fontfile：字库文件路径
//			_TEXT_CHAR* fontname：字库文件名
// 说明：	查询字库
LEDNETSDK_API int _CALL_STD query_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);
LEDNETSDK_API int _CALL_STD query_font_dwhand(unsigned long dwhand, _TEXT_CHAR* font_file, _TEXT_CHAR* font_name);

// 函数：	install_font
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned long font：字库文件路径和文件名
// 说明：	安装字库
LEDNETSDK_API int _CALL_STD install_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font);
LEDNETSDK_API int _CALL_STD install_font_dwhand(unsigned long dwhand, unsigned long font);

// 函数：	delete_font
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			_TEXT_CHAR* fontname：字库文件名
// 说明：	卸载字库
LEDNETSDK_API int _CALL_STD delete_font(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long font);
LEDNETSDK_API int _CALL_STD delete_font_dwhand(unsigned long dwhand, unsigned long font);

#pragma region customer font
LEDNETSDK_API unsigned long _CALL_STD create_font();

LEDNETSDK_API void _CALL_STD add_font(unsigned long font, _TEXT_CHAR* system_font, _TEXT_CHAR* custom_font);

LEDNETSDK_API void _CALL_STD delete_add_font(unsigned long font, _TEXT_CHAR* font_name);

LEDNETSDK_API void _CALL_STD delete_create_font(unsigned long font);
#pragma endregion customer font
#pragma endregion Font

#pragma region sensor manage
LEDNETSDK_API unsigned long _CALL_STD create_manage_sensor();

LEDNETSDK_API void _CALL_STD add_manage_sensor(unsigned long sensor, int unit_type,
	int significant_digits, float unit_coefficient, float correction, _TEXT_CHAR* thresh_mode, int thresh, _TEXT_CHAR* sensor_addr, 
	_TEXT_CHAR* fun_seq, int relay_type, int relay_switch);

LEDNETSDK_API void _CALL_STD delete_add_sensor(unsigned long sensor, int sensor_index);

LEDNETSDK_API void _CALL_STD delete_create_sensor(unsigned long sensor);

LEDNETSDK_API int _CALL_STD get_sensor_bus(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus);
LEDNETSDK_API int _CALL_STD get_sensor_bus_dwhand(unsigned long dwhand, _TEXT_CHAR* sensor_bus);

LEDNETSDK_API int _CALL_STD query_seeksensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);
LEDNETSDK_API int _CALL_STD query_seeksensor_dwhand(unsigned long dwhand, _TEXT_CHAR* sensor_bus, int* min_waitTime, int* max_waitTime);

LEDNETSDK_API int _CALL_STD get_sensor(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned char* sensors, int* sensors_count);
LEDNETSDK_API int _CALL_STD get_sensor_dwhand(unsigned long dwhand, unsigned char* sensors, int* sensors_count);

LEDNETSDK_API int _CALL_STD set_relay_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int setOrCancel, int update_time, unsigned long sensors);
LEDNETSDK_API int _CALL_STD set_relay_switch_dwhand(unsigned long dwhand, int setOrCancel, int update_time, unsigned long sensors);

LEDNETSDK_API int _CALL_STD set_screenonoff_switch(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
LEDNETSDK_API int _CALL_STD set_screenonoff_switch_dwhand(unsigned long dwhand, _TEXT_CHAR* relay_addr, int relay_type , int relay_switch);
#pragma endregion sensor

#pragma region dynamic
// 函数：	update_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
//			int immediately_play：指定一个关联了普通节目的动态区 ID（必须是 dynamics 参数中存在的 id）
//			int conver：是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目
//			int onlyUpdate：是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"
// 说明：	更新动态区
LEDNETSDK_API int _CALL_STD update_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, int immediately_play, int conver, int onlyUpdate);
LEDNETSDK_API int _CALL_STD update_dynamic_dwhand(unsigned long dwhand, unsigned long playlist, int immediately_play, int conver, int onlyUpdate);

// 函数：	update_dynamic_small
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
//			int immediately_play：指定一个关联了普通节目的动态区 ID（必须是 dynamics 参数中存在的 id）
//			int conver：是否覆盖普通节目，即是否只播放动态区，"0"：动态区和普通节目共存播放，"1"：停止播放普通节目，只播放动态区节目
//			int onlyUpdate：是否只更新动态区；只更新动态区"0"；清空原来的动态区后再更新动态区"1"
// 说明：	更新动态区内容少的
LEDNETSDK_API int _CALL_STD update_dynamic_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist, int immediately_play, int conver, int onlyUpdate);
LEDNETSDK_API int _CALL_STD update_dynamic_small_dwhand(unsigned long dwhand, unsigned long playlist, int immediately_play, int conver, int onlyUpdate);

// 函数：	update_dynamic_unit
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
// 说明：	更新动态区素材
LEDNETSDK_API int _CALL_STD update_dynamic_unit(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
LEDNETSDK_API int _CALL_STD update_dynamic_unit_dwhand(unsigned long dwhand, unsigned long playlist);

// 函数：	update_dynamic_unit_small
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
//			unsigned long playlist：动态区节目句柄
// 说明：	更新动态区素材，素材较小的时候使用
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, unsigned long playlist);
LEDNETSDK_API int _CALL_STD update_dynamic_unit_small_dwhand(unsigned long dwhand, unsigned long playlist);

// 函数：	clear_dynamic
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned short port：端口
//			_TEXT_CHAR* user_name：登录名
//			_TEXT_CHAR* user_pwd：登录密码
// 说明：	清空动态区
LEDNETSDK_API int _CALL_STD clear_dynamic(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd);
LEDNETSDK_API int _CALL_STD clear_dynamic_dwhand(unsigned long dwhand);
#pragma endregion dynamic

#pragma region proxy
LEDNETSDK_API int _CALL_STD Get_Port_Barcode(_TEXT_CHAR* pid);

LEDNETSDK_API int _CALL_STD Get_Port_Pid(_TEXT_CHAR* pid);

LEDNETSDK_API  void _CALL_STD Get_CardList(unsigned char* cards, int* card_count);

LEDNETSDK_API int _CALL_STD Start_Native_Server(int port);

LEDNETSDK_API int _CALL_STD Start_Proxy();

LEDNETSDK_API void _CALL_STD Stop_Server();
#pragma endregion proxy
LEDNETSDK_API int _CALL_STD SearchCards(card_unit *cards);

LEDNETSDK_API int _CALL_STD get_screeninfo(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_w, int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type);
LEDNETSDK_API int _CALL_STD get_screeninfo_dwhand(unsigned long dwhand, int* screen_w, int* screen_h, _TEXT_CHAR* controller_name,unsigned short *screen_type);

LEDNETSDK_API int _CALL_STD get_screen_volumn(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int *volumn);
LEDNETSDK_API int _CALL_STD get_screen_volumn_dwhand(unsigned long dwhand, int *volumn);

LEDNETSDK_API int _CALL_STD get_screen_brightness(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, short* brightness);
LEDNETSDK_API int _CALL_STD get_screen_brightness_dwhand(unsigned long dwhand, short* brightness);

LEDNETSDK_API int _CALL_STD get_screen_onoff(char* ip, unsigned short port, _TEXT_CHAR* user_name, _TEXT_CHAR* user_pwd, int* screen_onoff);
LEDNETSDK_API int _CALL_STD get_screen_onoff_dwhand(unsigned long dwhand, int* screen_onoff);

LEDNETSDK_API int _CALL_STD set_static_ip(_TEXT_CHAR* barcode,char* ip,char *submark,char *gateway);
LEDNETSDK_API int _CALL_STD set_auto_ip(_TEXT_CHAR* barcode);
LEDNETSDK_API int _CALL_STD get_netinfo(char *ip,_TEXT_CHAR* barcode,char* mask,char* gate,int *ipmode);
 #ifdef __cplusplus
}
#endif
#endif

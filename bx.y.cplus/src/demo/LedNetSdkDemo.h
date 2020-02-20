
// LedNetSdkDemo.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号



// CLedNetSdkDemoApp:
// 有关此类的实现，请参阅 LedNetSdkDemo.cpp
//

class CLedNetSdkDemoApp : public CWinApp
{
public:
	CLedNetSdkDemoApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
public:
	char ftp_server_ip[16];
	USHORT ftp_server_port;
	char ftp_server_user[64];
	char ftp_server_pwd[64];
	bool m_bServerRun;
};

extern CLedNetSdkDemoApp theApp;
//////////////////////////////////////////////////////////////////////////
//功能：  转换通用字符串为ansi字符串
//参数：
//        pwstr：源字符串
//        str：目标字符串
//Example:
//        
//////////////////////////////////////////////////////////////////////////

void Char2TCHAR(TCHAR *pwstr,const char *str);
void CString2Char(CString str, char ch[]);

CString GetErrText(int err);


#include <vector>
using namespace std;

struct PicUnit
{
	TCHAR szFile[MAX_PATH];
	int display_effects;
	int display_speed;
	int stay_time;
	bool bPic;
};
struct StrUnit
{
    int display_speed;//运行时间
    int stay_time;//停留时间
    TCHAR font_name[128];
    int font_size;
    TCHAR font_attributes[16];
    TCHAR font_alignment[16];
    UINT font_color;
    UINT bg_color;
    TCHAR text_content[MAX_PATH];
    int last_move_width;
};
struct VideoUnit
{
	TCHAR szVideoFile[MAX_PATH];
	UCHAR scale_mode;
	UCHAR volume;
};

class Area
{
public:
	Area(){}
	virtual ~Area(){};
public:
	int m_AreaType;
};
class VideoArea:public Area
{
public:
	VideoArea(int type){m_AreaType=type;}
	virtual ~VideoArea(){};
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_transparency;
	struct VideoUnit m_Videolist[256];
	int m_VideoCount;
};


class PicArea:public Area
{
public:
	PicArea(int type){m_AreaType=type;}
	virtual ~PicArea(){};
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_transparency;
	int m_window_type;
	bool  m_bBgTransparent;
	PicUnit m_Piclist[256];
	int m_PicCount;
};


class StrArea:public Area
{
public:
	StrArea(int type){m_AreaType=type;}
	virtual ~StrArea(){};
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_transparency;
	int m_window_type;
	bool  m_bBgTransparent;
    int display_effects;
    int unit_type;
	vector<StrUnit*> m_StrUnit;
	int m_StrCount;
};


class TimeArea:public Area
{
public:
	TimeArea(int type){m_AreaType=type;}
	virtual ~TimeArea(){};
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_transparency;
	int m_timediff_flag;
	int m_timediff_hour;
	int m_timediff_min;
	TCHAR m_font[128];
	int   m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;
	UCHAR m_align;
	bool m_multiline;
	bool m_day_enable;
	UINT m_daycolor;

	bool m_week_enable;
	UINT m_weekcolor;

	bool m_time_enable;
	UINT m_timecolor;

	bool m_text_enable;
	UINT m_textcolor;
	TCHAR m_statictext[256];
	int m_day_x;
	int m_day_y;
	int m_week_x;
	int m_week_y;
	int m_time_x;
	int m_time_y;
	int m_text_x;
	int m_text_y;
};

class LunarArea:public Area
{
public:
	LunarArea(int type){m_AreaType=type;}
	virtual ~LunarArea(){};
	int		m_x;
	int		m_y;
	int		m_w;
	int		m_h;
	int		m_transparency;
	_TEXT_CHAR m_font[32];
	int		m_fontsize;
	bool		m_bold;
	bool		m_italic;
	bool		m_underline;
	int  	m_align;
	bool		m_multiline;
	bool		m_year_enable;
	UINT		m_yearcolor;
	bool		m_day_enable;
	UINT		m_daycolor;
	bool		m_solarterms_enable;
	UINT		m_solartermscolor;
	bool		m_text_enable;
	UINT		m_textcolor;
	TCHAR		m_statictext[256];
	int m_heavenlystem_x;
	int m_heavenlystem_y;
	int m_lunarcalendar_x;
	int m_lunarcalendar_y;
	int m_solarterms_x;
	int m_solarterms_y;
	int m_text_x;
	int m_text_y;

};

class CounterArea:public Area
{
public:
	CounterArea(int type){m_AreaType=type;}
	virtual ~CounterArea(){};
	int m_x;
	int m_y;
	int m_w;
	int m_h;
	int m_transparency;
	TCHAR m_font[32];
	int   m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;
	UCHAR m_align;
	bool m_multiline;
	TCHAR m_target_date[32];
	TCHAR m_target_time[32];
	UINT m_counter_color;
	bool m_day_enable;
	TCHAR m_daytext[32];
	bool m_hour_enable;
	TCHAR m_hourtext[32];
	bool m_min_enable;
	TCHAR m_minutetext[32];
	bool m_sec_enable;
	TCHAR m_secondtext[32];
	bool m_add_enable;
	bool m_unit_enable;
	bool m_text_enable;
	UINT m_textcolor;
	TCHAR m_statictext[256];
	bool m_bTimeFlag;
	int m_time_x;
	int m_time_y;
	int m_text_x;
	int m_text_y;
};
class ClockArea:public Area
{
public:
	ClockArea(int type){m_AreaType=type;}
	virtual ~ClockArea(){};
	int		m_x;
	int		m_y;
	int		m_w;
	int		m_h;
	int		m_transparency;

	_TEXT_CHAR m_src_path[256];
	TCHAR   m_font[32];
	int     m_fontsize;
	bool    m_bold;
	bool    m_italic;
	bool    m_underline;

	bool		m_day_enable;
	UINT		m_daycolor;

	bool		m_week_enable;
	UINT		m_weekcolor;

	bool		m_text_enable;
	UINT		m_textcolor;
	TCHAR	m_statictext[256];

	UINT		m_hourhand_color;
	UINT		m_minhand_color;
	UINT		m_secondhand_color;

	UCHAR		m_timediff_flag;
	UCHAR		m_timediff_hour;
	UCHAR		m_timediff_min;


	UINT m_rightangle_color; // 3,6,9点颜色

	UINT m_hour_color; // 整点颜色

	UINT m_minute_color; //分点颜色

	UCHAR m_style;
	int m_text_x;
	int m_text_y;
};


class Program
{
public:
	virtual ~Program(){
		for (int i=0;i<m_Arealist.size();i++)
		{
			delete m_Arealist[i];
		}
	};
	short m_w;
	short m_h;
	int 	m_play_mode;
    int	m_play_time;
	bool			m_bDate;
	CTime			m_aging_start_time;
	CTime			m_aging_stop_time;
	bool			m_bTime;
	CTime			m_period_ontime;
	CTime			m_period_offtime;
	unsigned char	m_play_week;
	vector<Area*> m_Arealist;
};

struct DynamicAreaFile 
{
    int dynamic_type;
    int display_effects;
    int display_speed;
    int stay_time;
    TCHAR file_path[MAX_PATH];
    int gif_flag;
    TCHAR bg_color[MAX_PATH];
    int font_size;
    TCHAR font_name[MAX_PATH];
    TCHAR font_color[MAX_PATH];
    TCHAR font_attributes[MAX_PATH];
    TCHAR align_h[MAX_PATH];
    TCHAR align_v[MAX_PATH];
    int volumn;
    int scale_mode;
    int rolation_mode;
};
class DynamicArea:public Area
{
public:
	DynamicArea(int type){m_AreaType=type;}
	virtual ~DynamicArea(){};
    int m_dynamic_id;//
    int m_x;//x
    int m_y;//y
    int m_w;//宽
    int m_h;//高
    TCHAR m_relative_program[MAX_PATH];//关联的节目
    int m_run_mode;//动态区运行方式
    TCHAR m_update_frequency[MAX_PATH];//
    int m_transparency;//背景透明
	DynamicAreaFile m_DynamicAreaFile[256];
	int m_PicCount;
};

class ProgramDyanmic
{
public:
	virtual ~ProgramDyanmic(){
		for (int i=0;i<m_Arealist.size();i++)
		{
			delete m_Arealist[i];
		}
	};
	short m_w;
	short m_h;
	int 	m_play_mode;
    int	m_play_time;
	bool			m_bDate;
	CTime			m_aging_start_time;
	CTime			m_aging_stop_time;
	bool			m_bTime;
	CTime			m_period_ontime;
	CTime			m_period_offtime;
	unsigned char	m_play_week;
	vector<Area*> m_Arealist;
};
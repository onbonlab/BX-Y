// PlaylistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "PlaylistDlg.h"
#include "afxdialogex.h"
#include <sstream> 
#include "ProgramDlg.h"

// CPlaylistDlg 对话框
bool m_mediastatus=false;
IMPLEMENT_DYNAMIC(CPlaylistDlg, CDialogEx)

CPlaylistDlg::CPlaylistDlg(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlaylistDlg::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CPlaylistDlg::CPlaylistDlg(char *ip,_TEXT_CHAR* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlaylistDlg::IDD, pParent)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}
CPlaylistDlg::~CPlaylistDlg()
{
}

void CPlaylistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_TotalProgress);
	DDX_Control(pDX, IDC_PROGRESS2, m_CurProgress);
	DDX_Control(pDX, IDC_COMBO2, m_WorkDir);
	DDX_Control(pDX, IDC_LIST1, m_ctrlProgramList);
	DDX_Control(pDX, IDC_PROGRESS3, m_DownProgress);
}


BEGIN_MESSAGE_MAP(CPlaylistDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEND, &CPlaylistDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_BROWSE, &CPlaylistDlg::OnBnClickedBrowse)
	ON_BN_CLICKED(IDC_BUTTON31, &CPlaylistDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON3, &CPlaylistDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CPlaylistDlg::OnBnClickedButton6)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CPlaylistDlg::OnBnClickedButton1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON2, &CPlaylistDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CPlaylistDlg::OnCbnSelchangeCombo2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS2, &CPlaylistDlg::OnNMCustomdrawProgress2)
END_MESSAGE_MAP()

// CPlaylistDlg 消息处理程序

void color2TCHAR(unsigned int color,_TEXT_CHAR* Tcolor )
{
	CString strClr;
	strClr.Format(_T("0x%08X"),color);
	char day[17]={0};
	memset(day,0,sizeof(day));
	CString2Char(strClr,day);
	day[2]='F';
	day[3]='F';
	char temp='0';
	temp=day[4];
	day[4]=day[8];
	day[8]=temp;
	temp=day[5];
	day[5]=day[9];
	day[9]=temp;	
	Char2TCHAR(Tcolor,day);
}
void stringWidth(_TEXT_CHAR*font_name,int font_size,_TEXT_CHAR* content,bool m_italic,bool m_bold,bool m_underline,int start_x,int start_y,int Width,int Heigh,int* width,int *heigh)
{
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	Bitmap bmpTmp(Width,Heigh, PixelFormat32bppARGB);
	Graphics graphics(&bmpTmp);
	Gdiplus::FontFamily* pfontFamily=NULL; 
	Gdiplus::FontFamily tmpFamily(_T("宋体"));
	Gdiplus::FontFamily fontFamily(font_name);  
	if (fontFamily.GetLastStatus()==Ok)
	{
		pfontFamily=&fontFamily;
	}
	else
	{
		pfontFamily=&tmpFamily;
	}
	Gdiplus::Font font(pfontFamily,font_size, (m_italic?FontStyleItalic:0)|(m_bold?FontStyleBold:0)|(m_underline?FontStyleUnderline:0),UnitPoint); 
	StringFormat stringFormat;
	stringFormat.SetLineAlignment(StringAlignmentNear);
	stringFormat.SetFormatFlags(StringFormatFlagsNoWrap);
	Gdiplus::RectF boundingBox(0, 0, 0, 0); 
	RectF tRect(start_x,start_y,Width,Heigh);
	graphics.MeasureString(content, -1, &font, tRect, &stringFormat,&boundingBox);
	*width=boundingBox.Width-boundingBox.X;
	*heigh=boundingBox.Height-boundingBox.Y;
//	GdiplusShutdown(gdiplusToken);
}
void  alignmode(int area_w,int align,int length,int* x)
{
	if (align==0)
	{
		*x=0;
	}
	else if (align==1)
	{
		*x=(area_w-length)/2;
	}
	else
		*x=(area_w-length);
}
void fontAttributes(bool bold,bool italic,bool underline,_TEXT_CHAR* font_attributes)//字体属性 粗体 斜体 下划线
{
	if(bold)
	{
		wcscpy(font_attributes,_TEXT_T("bold"));
		if(italic)
		{
			wcscat(font_attributes,_TEXT_T("&italic"));
			if(underline)
				wcscat(font_attributes,_TEXT_T("&underline"));
		}
		else 
			wcscat(font_attributes,_TEXT_T("&underline"));
	}
	else if (italic)
	{
		wcscpy(font_attributes,_TEXT_T("italic"));
		if (underline)
		{
			wcscat(font_attributes,_TEXT_T("&underline"));
		}
	}
	else if (underline)
	{
		wcscpy(font_attributes,_TEXT_T("underline"));
	}
	else
		wcscpy(font_attributes,_TEXT_T("normal"));
}

void CPlaylistDlg::OnBnClickedSend()
{
	unsigned short port=80;
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	 _TEXT_CHAR controller_name[128]=_TEXT_T("");
	controllerInfo info;
	BYTE cards[1024*32]={0}; 
	 int result=-1;
	 if (card_mode==0)
	 {
		result=get_screen_parameters(card_ip,port,user_name,user_pwd,cards);
	 }
	 else
	 {
		port=Get_Port_Pid(card_PID);
		 _TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		 //result=get_screeninfo(card_ip,port,user_name,user_pwd,&screen_w,&screen_h,controller_name,&screen_type);
		result=get_screen_parameters(card_ip,port,user_name,user_pwd,cards);
	 }
		 memset(&info,0,sizeof(controllerInfo));
		 memcpy(&info,cards,sizeof(controllerInfo));
	if (result!=0)
	{
		AfxMessageBox(GetErrText(result));
	}
	unsigned long playlist=create_playlist(info.screen_w, info.screen_h,info.screen_type);
	for (int j=0;j<m_vecProgram.size();j++)
	{
		Program* p=m_vecProgram[j];
		_TEXT_CHAR* name=_TEXT_T("program_1");
		unsigned long program=create_program(name,_TEXT_T("0xff000000"));
		for (int i=0;i<p->m_Arealist.size();i++)
		{
			switch(p->m_Arealist[i]->m_AreaType)
			{
			case 1:
				{
					PicArea* n=(PicArea*)p->m_Arealist[i];
					DWORD pic_area=create_pic();	
					for (int t=0;t<n->m_PicCount;t++)
					{
						if (n->m_Piclist[t].bPic)
						{
							if (n->m_Piclist[t].display_effects==37 ||n->m_Piclist[t].display_effects==38)
							{
								n->m_Piclist[t].display_effects+=1;
							}
							if (n->m_Piclist[t].display_effects>=39 && n->m_Piclist[t].display_effects<=41)
							{
								n->m_Piclist[t].display_effects+=2;
							}
							if (n->m_Piclist[t].display_effects>=42 && n->m_Piclist[t].display_effects<=45)
							{
								n->m_Piclist[t].display_effects-=39;
							}
							if (n->m_Piclist[t].display_effects>=42 && n->m_Piclist[t].display_effects<=45)
							{
								n->m_Piclist[t].display_effects-=39;
							}
							if (n->m_Piclist[t].display_effects>=46 && n->m_Piclist[t].display_effects<=49)
							{
								n->m_Piclist[t].display_effects+=8;
							}
							if (n->m_Piclist[t].display_effects>=50 )
							{
								n->m_Piclist[t].display_effects+=78;
							}
							add_pic_unit(pic_area,n->m_Piclist[t].stay_time, n->m_Piclist[t].display_effects,n->m_Piclist[t].display_speed, n->m_Piclist[t].szFile);
							int pic_type=0,move_width=1;
							add_pic(program,pic_area,n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency);
						} 
					}
					break;
				} 
			case 2:
				{
					StrArea* n=(StrArea*)p->m_Arealist[i];
					DWORD pic_area=create_text();	
					for (int t=0;t<n->m_StrCount;t++)
					{
						StrUnit* m = n->m_StrUnit[t];
						if(n->unit_type==0)
						{
							add_text_unit_img(pic_area, m->stay_time, m->display_speed, m->last_move_width,m->text_content);
						}
						else
						{
							_TEXT_CHAR font_color[20]=_TEXT_T("");
							_TEXT_CHAR bg_color[20]=_TEXT_T("");
							color2TCHAR(m->font_color,font_color);
							color2TCHAR(m->bg_color,bg_color);
							add_text_unit_text(pic_area,m->stay_time,m->display_speed, m->font_name, m->font_size,
                                            m->font_attributes,m->font_alignment,font_color, bg_color, m->text_content);
						}
					}
					add_text(program,pic_area,n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,n->display_effects,n->unit_type);
					break;
				} 
			case 3:
				{
					TimeArea* n=(TimeArea*)p->m_Arealist[i];
					unsigned long time_area=create_time();
					_TEXT_CHAR font_attributes[20]=_TEXT_T("");
					fontAttributes(n->m_bold,n->m_italic,n->m_underline,font_attributes);
					int width=0,height=0,total_height=0;
					if (n->m_text_enable)
					{
						int length=0;
						_TEXT_CHAR textcolor[20]=_TEXT_T("");
						color2TCHAR(n->m_textcolor,textcolor);
						stringWidth(n->m_font,n->m_fontsize,n->m_statictext,n->m_italic,n->m_bold,n->m_underline,-1,-1,info.screen_w+10,info.screen_h+10,&length,&height);
						width=length;
						if (!(n->m_multiline))
						{
							n->m_text_x=0;
							n->m_text_y=height;
						}
						else
						{
							total_height=height;
							n->m_text_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_text_x));
						}
						add_time_unit(time_area,n->m_statictext,textcolor,n->m_font,n->m_fontsize,n->m_text_x,n->m_text_y,font_attributes);
					}
					_TEXT_CHAR content1[20]=_TEXT_T("");
					if (n->m_day_enable)
					{
						int length=0;
						wcscpy(content1,_TEXT_T("%Y年%m月%d日"));
						_TEXT_CHAR daycolor[20]=_TEXT_T("");
						color2TCHAR(n->m_daycolor,daycolor);
						stringWidth(n->m_font,n->m_fontsize,content1,n->m_italic,n->m_bold,n->m_underline,-1,-1,info.screen_w+10,info.screen_h+10,&length,&height);					
						if (!(n->m_multiline))
						{
							if(n->m_text_enable)
							{
								n->m_day_x=width;
								n->m_day_y=height;
							}
							else
							{
								n->m_day_x=-1;;
								n->m_day_y=height;
							}
							width+=length;
						}
						else
						{
							total_height+=height;
							n->m_day_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_day_x));
						}
						add_time_unit(time_area,content1,daycolor,n->m_font,n->m_fontsize,n->m_day_x,n->m_day_y,font_attributes);
					}
					_TEXT_CHAR content2[20]=_TEXT_T("");
					if (n->m_week_enable)
					{
						int length=0;
						wcscpy(content2,_TEXT_T("星期%w"));
						_TEXT_CHAR weekcolor[20]=_TEXT_T("");
						color2TCHAR(n->m_weekcolor,weekcolor);
						stringWidth(n->m_font,n->m_fontsize,content2,n->m_italic,n->m_bold,n->m_underline,-1,-1,info.screen_w+10,info.screen_h+10,&length,&height);
						if (!(n->m_multiline))
						{
							if (n->m_text_enable)
							{
								if (n->m_day_enable)
									n->m_week_y=n->m_day_y; 
								else
									n->m_week_y=height;
								n->m_week_x+=width;
							}
							else if (n->m_day_enable)
							{
								n->m_week_y=n->m_day_y;
								n->m_week_x+=width;
							}
							else
							{
								n->m_week_x=-1;
								n->m_week_y=height;
							}
							width+=length;
						}
						else
						{
							total_height+=height;
							n->m_week_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_week_x));
						}
						add_time_unit(time_area,content2,weekcolor,n->m_font,n->m_fontsize,n->m_week_x,n->m_week_y,font_attributes);
					}
					_TEXT_CHAR content3[20]=_TEXT_T("");
					if (n->m_time_enable)
					{
						int length=0;
						wcscpy(content3,_TEXT_T("%H时%M分%S秒"));
						_TEXT_CHAR timecolor[20]=_TEXT_T("");
						color2TCHAR(n->m_timecolor,timecolor);
						stringWidth(n->m_font,n->m_fontsize,content3,n->m_italic,n->m_bold,n->m_underline,-1,-1,info.screen_w+10,info.screen_h+10,&length,&height);
						if (!(n->m_multiline))
						{
							if (n->m_text_enable)
							{
								if (n->m_day_enable)
								{
									if (n->m_week_enable)
										n->m_time_y=n->m_day_y;
								}
								else if (n->m_week_enable)
									n->m_time_y=n->m_week_y;
								else
									n->m_time_y=height;		
								n->m_time_x+=width;
							}
							else if (n->m_day_enable)
							{
								n->m_time_y=n->m_day_y;
								n->m_time_x+=width;
							}
							else if (n->m_week_enable)
							{
								n->m_time_y=n->m_week_y;
								n->m_time_x+=width;
							}
							else
							{
								n->m_time_x=-1;
								n->m_time_y=height;
							}
						}
						else
						{
							total_height+=height;
							n->m_time_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_time_x));
						}
					    add_time_unit(time_area,content3,timecolor,n->m_font,n->m_fontsize,n->m_time_x,n->m_time_y,font_attributes);
					}
					_TEXT_CHAR positive_te[20]=_TEXT_T("");
					 if (n->m_timediff_flag=1)
							wcscpy(positive_te,_TEXT_T("+"));
					 else
						wcscpy(positive_te,_TEXT_T("-"));
					_TEXT_CHAR* bg_color=_TEXT_T("0xff000000");
					_TEXT_CHAR time_equation[10]=_TEXT_T("0");
					memset(time_equation,0,sizeof(time_equation));
					stringstream stream1,stream2;
					stream1<<n->m_timediff_hour;
					stream2<<n->m_timediff_min;
					string string_temp=stream1.str()+":"+stream2.str()+":"+"00"; 
					Char2TCHAR(time_equation,string_temp.c_str());
					add_time(program,time_area,n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,bg_color,time_equation,positive_te);
					break;
				} 
			case 4:
				{
					ClockArea* n=(ClockArea*)p->m_Arealist[i];
					_TEXT_CHAR positive_te[20]=_TEXT_T("");
					if (n->m_timediff_flag=1)
						wcscpy(positive_te,_TEXT_T("+"));
					else
						wcscpy(positive_te,_TEXT_T("-"));
					_TEXT_CHAR time_equation[10]=_TEXT_T("0");
					memset(time_equation,0,sizeof(time_equation));
					stringstream stream1,stream2;
					stream1<<n->m_timediff_hour;
					stream2<<n->m_timediff_min;
					string string_temp=stream1.str()+":"+stream2.str()+":"+"00"; 
					Char2TCHAR(time_equation,string_temp.c_str());	
					_TEXT_CHAR* bg_color=_TEXT_T("0xffffffff");	
					_TEXT_CHAR hour_color[20]=_TEXT_T("0xffffffff"),minute_color[20]=_TEXT_T("0xffffffff"),second_color[20]=_TEXT_T("0xffffffff");
					color2TCHAR(n->m_hourhand_color,hour_color);
					color2TCHAR(n->m_minhand_color,minute_color);
					color2TCHAR(n->m_secondhand_color,second_color);
					unsigned long clock_area = create_clock();
					DWORD dwArea=add_clock(program,clock_area,n->m_x+13,n->m_y+13, n->m_w, n->m_h, n->m_transparency,time_equation,positive_te,hour_color,minute_color,second_color,n->m_src_path);
					if (n->m_text_enable)
					{
						int length=0,height=0;
						_TEXT_CHAR textcolor[20]=_TEXT_T("0xffffffff");
						_TEXT_CHAR font_attributes[20]=_TEXT_T("normal");
						fontAttributes(n->m_bold,n->m_italic,n->m_underline,font_attributes);
						color2TCHAR(n->m_textcolor,textcolor);
						unsigned long time_area=create_time();
						color2TCHAR(n->m_textcolor,textcolor);
						stringWidth(n->m_font,n->m_fontsize,textcolor,n->m_italic,n->m_bold,n->m_underline,-1,-1,info.screen_w+10,info.screen_h+10,&length,&height);
						n->m_text_x=(n->m_w-length)/2;
						n->m_text_y=height;
						add_time_unit(time_area,n->m_statictext,textcolor,n->m_font,n->m_fontsize,n->m_text_x,n->m_text_y,font_attributes);
						add_time(program,time_area,n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,bg_color,time_equation,positive_te);
					}
					break;
				} 	
			case 5:
				{
					LunarArea* n=(LunarArea*)p->m_Arealist[i];
					unsigned long calendar_area= create_calendar();
					_TEXT_CHAR font_attributes[20]=_TEXT_T("normal");
					fontAttributes(n->m_bold,n->m_italic,n->m_underline,font_attributes);
					_TEXT_CHAR text_content[256]=_TEXT_T("");
					_TEXT_CHAR* bg_color=_TEXT_T("0xff000000");
					_TEXT_CHAR* time_equation=_TEXT_T("0:00:00");
					_TEXT_CHAR* positive_te=_TEXT_T("+");
					int width=0,height=0,total_height=0;
					if (n->m_text_enable)
					{
						int length=0;
						_TEXT_CHAR textcolor[20]=_TEXT_T("0xffffffff");
						color2TCHAR(n->m_textcolor,textcolor);
						stringWidth(n->m_font,n->m_fontsize,n->m_statictext,n->m_italic,n->m_bold,n->m_underline,0,0,n->m_w,n->m_h,&length,&height);
						width=length;
						if (!(n->m_multiline))
						{
							n->m_text_x=0;
							n->m_text_y=height;
						}
						else
						{
							total_height=height;
							n->m_text_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_text_x));
						}
						unsigned long time_area=create_time();
						add_time_unit(time_area,n->m_statictext,textcolor,n->m_font,n->m_fontsize,n->m_text_x,n->m_text_y,font_attributes);
						add_time(program,time_area,n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,bg_color,time_equation,positive_te);
					}
					_TEXT_CHAR mode2[20]=_TEXT_T("");
					if (n->m_year_enable)
					{
						int length=0;
						wcscpy(mode2,_TEXT_T("heavenlystem"));
						_TEXT_CHAR yearcolor[12]=_TEXT_T("0xFFFFFFFF");
						color2TCHAR(n->m_yearcolor,yearcolor);
						_TEXT_CHAR temp[12]=_TEXT_T("戊戌狗年");
						stringWidth(n->m_font,n->m_fontsize,temp,n->m_italic,n->m_bold,n->m_underline,0,0,n->m_w,n->m_h,&length,&height);
						if (!(n->m_multiline))
						{
							if(n->m_text_enable)
							{
								n->m_heavenlystem_x=width;
								n->m_heavenlystem_y=n->m_text_y;
							}
							else
							{
								n->m_heavenlystem_x=-1;;
								n->m_heavenlystem_y=height;
							}
					    	width+=length;
						}
						else
						{
							total_height+=height;
							n->m_heavenlystem_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_heavenlystem_x));
						}
						add_calendar_unit(calendar_area,mode2,yearcolor,n->m_font,n->m_fontsize,n->m_heavenlystem_x,n->m_heavenlystem_y,font_attributes,text_content);
					}
					_TEXT_CHAR mode1[20]=_TEXT_T("");
					if (n->m_day_enable)
					{
						int length=0;
						wcscpy(mode1,_TEXT_T("lunarcalendar"));

						_TEXT_CHAR daycolor[20]=_TEXT_T("0xFFFFFFFF");
						_TEXT_CHAR temp[12]=_TEXT_T("四月廿十");
						color2TCHAR(n->m_daycolor,daycolor);
						stringWidth(n->m_font,n->m_fontsize,temp,n->m_italic,n->m_bold,n->m_underline,0,0,n->m_w,n->m_h,&length,&height);
						if (!(n->m_multiline))
						{
							if (n->m_text_enable)
							{
								if (n->m_year_enable)
									n->m_lunarcalendar_y=n->m_text_y; 
								else
									n->m_lunarcalendar_y=height;
								n->m_lunarcalendar_x+=width;
							}
							else if (n->m_day_enable)
							{
								n->m_lunarcalendar_y=n->m_heavenlystem_y;
								n->m_lunarcalendar_x+=width;
							}
							else
							{
								n->m_lunarcalendar_x=-1;
								n->m_lunarcalendar_y=height;
							}
							width+=length;
						}
						else
						{
							total_height+=height;
							n->m_lunarcalendar_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_lunarcalendar_x));
						}
						add_calendar_unit(calendar_area,mode1,daycolor,n->m_font,n->m_fontsize,n->m_lunarcalendar_x,n->m_lunarcalendar_y,font_attributes,text_content);
					}
					_TEXT_CHAR mode3[20]=_TEXT_T("");
					if (n->m_solarterms_enable)
					{
						int length=0;
						wcscpy(mode3,_TEXT_T("solarterms"));
						_TEXT_CHAR temp[12]=_TEXT_T("距芒种01天");
						_TEXT_CHAR solartermscolor[20]=_TEXT_T("0xffffffff");
						color2TCHAR(n->m_solartermscolor,solartermscolor);
						stringWidth(n->m_font,n->m_fontsize,temp,n->m_italic,n->m_bold,n->m_underline,-1,-1,n->m_w,n->m_h,&length,&height);
						if (!(n->m_multiline))
						{
							if (n->m_text_enable)
							{
								if (n->m_year_enable)
								{
									if (n->m_day_enable)
										n->m_solarterms_y=n->m_solarterms_y;
								}
								else if (n->m_day_enable)
									n->m_solarterms_y=n->m_lunarcalendar_y;
								else
									n->m_solarterms_y=height;		
								n->m_solarterms_x+=width;
							}
							else if (n->m_year_enable)
							{
								n->m_solarterms_y=n->m_solarterms_y;
								n->m_solarterms_x+=width;
							}
							else if (n->m_day_enable)
							{
								n->m_solarterms_y=n->m_lunarcalendar_y;
								n->m_solarterms_x+=width;
							}
							else
							{
								n->m_solarterms_x=-1;
								n->m_solarterms_y=height;
							}
						}
						else
						{
							total_height+=height;
							n->m_solarterms_y=total_height;
							alignmode(n->m_w,n->m_align,length,&(n->m_solarterms_x));
						}
						add_calendar_unit(calendar_area,mode3,solartermscolor,n->m_font,n->m_fontsize,n->m_solarterms_x,n->m_solarterms_y,font_attributes,text_content);
					}
					add_calendar(program,calendar_area,n->m_x, n->m_y,n->m_w,n->m_h,n->m_transparency,bg_color,time_equation,positive_te);
					break;
				} 
			case 6:
				{
					CounterArea* n=(CounterArea*)p->m_Arealist[i];
					_TEXT_CHAR font_attributes[20]=_TEXT_T("");
					_TEXT_CHAR add_enable[20]=_TEXT_T("yes");
					fontAttributes(n->m_bold,n->m_italic,n->m_underline,font_attributes);
					_TEXT_CHAR content[128]=_TEXT_T("");
					if (n->m_day_enable)
					{
						wcscpy(content,_T("dd天"));
						if(n->m_hour_enable)
						{
							wcscat(content,_T("hh时"));
							if (n->m_min_enable)
							{
								wcscat(content,_T("mm分"));
								if (n->m_sec_enable)
								{
									wcscat(content,_T("ss秒"));
								}
							}
						}
						else if (n->m_min_enable)
						{
							wcscat(content,_T("mm分"));
							if (n->m_sec_enable)
							{
								wcscat(content,_T("ss秒"));
							}
						}
						else if (n->m_sec_enable)
						{
							wcscat(content,_T("ss秒"));
						}
						
					}
					else if (n->m_hour_enable)
					{
						wcscpy(content,_T("hh时"));
						if (n->m_min_enable)
						{
							wcscat(content,_T("mm分"));
							if (n->m_sec_enable)
							{
								wcscat(content,_T("ss秒"));
							}
						}
						else if (n->m_sec_enable)
						{
							wcscat(content,_T("ss秒"));
			    		}
					}
					else if (n->m_min_enable)
					{
						wcscpy(content,_T("mm分"));
						if (n->m_sec_enable)
						{
							wcscat(content,_T("ss秒"));
						}
					}
					else if (n->m_sec_enable)
					{
						wcscpy(content,_T("ss秒"));
					}
					_TEXT_CHAR* bg_color=_TEXT_T("0xffffffff");
					_TEXT_CHAR* time_equation=_TEXT_T("00:00:00");
					_TEXT_CHAR* positive_te=_TEXT_T("true");
					int Width=0;
					if (n->m_text_enable)
					{
						int length=0,height=0;
						_TEXT_CHAR textcolor[20]=_TEXT_T("0xffffffff");
						color2TCHAR(n->m_textcolor,textcolor);
						unsigned long time_area=create_time();
						color2TCHAR(n->m_textcolor,textcolor);
						stringWidth(n->m_font,n->m_fontsize,n->m_statictext,n->m_italic,n->m_bold,n->m_underline,0,0,n->m_w,n->m_h,&length,&height);
						add_time_unit(time_area,n->m_statictext,textcolor,n->m_font,n->m_fontsize,0,height,font_attributes);
						add_time(program,time_area,n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,bg_color,time_equation,positive_te);
						Width=length;
					}
					_TEXT_CHAR font_color[20]=_TEXT_T("0xffffffff");
					color2TCHAR(n->m_counter_color,font_color);
					_TEXT_CHAR targetType[10]=_TEXT_T("");
					_TEXT_CHAR time_equation1[10]=_TEXT_T("");
					if(n->m_bTimeFlag)
						wcscpy(targetType,_T("start"));//过去
					else
						wcscpy(targetType,_T("end"));//未来
					int height=0,length=0;
					stringWidth(n->m_font,n->m_fontsize,content,n->m_italic,n->m_bold,n->m_underline,-1,-1,info.screen_w+10,info.screen_h+10,&length,&height);
					n->m_time_x=Width;
					n->m_time_y=height;
					DWORD dwArea=add_count(program,n->m_x,n->m_y,n->m_w, n->m_h,n->m_transparency,bg_color,time_equation1,targetType,n->m_target_date,n->m_target_time,content,font_color,n->m_font,n->m_fontsize,n->m_time_x,n->m_time_y,font_attributes,add_enable);
					break;
				} 
			case 7:
				{
					VideoArea* n=(VideoArea*)p->m_Arealist[i];
					unsigned long video_area= create_video();
					int  source=0,play_time=1,volume_mode=0,video_type=0,ratation_mode=0;
					_TEXT_CHAR clone_str[20]=_TEXT_T("");
					for (int t=0;t<n->m_VideoCount;t++)
					{
						add_video_unit(video_area,n->m_Videolist[t].volume,n->m_Videolist[t].scale_mode,source,p->m_play_time, n->m_Videolist[t].szVideoFile,clone_str);
						add_video(program,video_area,n->m_x, n->m_y, n->m_w,  n->m_h, volume_mode, video_type, ratation_mode, clone_str,clone_str);
					}
					break;
				} 
			}
		}
		CString str1,str2,str3,str4;
		_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
		_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
		if (p->m_bDate)
		{
			str1=p->m_aging_start_time.Format("%Y-%m-%d");
			str2=p->m_aging_stop_time.Format("%Y-%m-%d");
			char start_time[20],stop_time[20];
			memset(start_time,0,sizeof(start_time));
			memset(stop_time,0,sizeof(stop_time));
			CString2Char(str1,start_time);
			Char2TCHAR(aging_start_time,start_time);
			CString2Char(str2,stop_time);
			Char2TCHAR(aging_end_time,stop_time);
		}
		if (p->m_bTime)
		{
			str3=p->m_period_ontime.Format("%H:%M:%S");
			str4=p->m_period_offtime.Format("%H:%M:%S");
			char ontime[20],offtime[20];
			memset(offtime,0,sizeof(offtime));
			memset(ontime,0,sizeof(ontime));
			CString2Char(str3,ontime);
			Char2TCHAR(period_ontime,ontime);
			CString2Char(str4,offtime);
			Char2TCHAR(period_offtime,offtime);
		}
		int play_time=1;
		add_program_in_playlist(playlist,program,p->m_play_mode,p->m_play_time,aging_start_time,aging_end_time, period_ontime,period_offtime,p->m_play_week);
	}
	CString szLocal;
	GetDlgItem(IDC_EDIT2)->GetWindowText(szLocal);
	if (szLocal.IsEmpty())
	{
		MessageBox(_T("本地路径不能为空"));
		return;
	}
	char temp[256]={0};
	CString2Char(szLocal,temp);
	_TEXT_CHAR  tmp_path[256]=_TEXT_T("");
	memset(tmp_path,0,sizeof(tmp_path));
	Char2TCHAR(tmp_path,temp);
	int err=0;
	DWORD dwSend=0;
	int media=m_WorkDir.GetCurSel();
	_TEXT_CHAR storage_media[10]={0};
	if (media==0)
	{
		memcpy(storage_media,_TEXT_T("sd"),10);
		m_mediastatus=true;
	}
	else if(media==1)
	{
		memcpy(storage_media,_TEXT_T("usb1"),10);
		m_mediastatus=true;
	}
	else
	{
		if (m_mediastatus)
		{
			memcpy(storage_media,_TEXT_T("emmc"),10);
		}	
	}
	/*if (card_mode==0)
	{
		result=set_screen_storage_media(card_ip,port,user_name,user_pwd,storage_media);
	}
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		result=set_screen_storage_media(card_ip,port,user_name,user_pwd,storage_media);
	}*/
	if (card_mode==0)
	{
		long long  free_size=0, total_size=0;
		int send_style=0;
	    err=send_program(card_ip,port,user_name,user_pwd,tmp_path,playlist,send_style,&free_size,&total_size);
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int send_style=0;
		long long free_size=0,total_size=0;
	   err=send_program(card_ip,port,user_name,user_pwd,tmp_path,playlist,send_style,&free_size,&total_size);

	}
	if (err==0)
	{
		m_hSend=playlist;
		SetTimer(100,50,NULL);
		GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	}
	else
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
}


BOOL CPlaylistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_WorkDir.SetCurSel(2);
	m_TotalProgress.SetRange(0,100);
	m_CurProgress.SetRange(0,100);

	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0;
	GetDlgItem(IDC_EDIT2)->SetWindowText(szFilePath);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPlaylistDlg::OnBnClickedBrowse()
{
	// 浏览节目文件夹
	BROWSEINFO bi;
	TCHAR Buffer[MAX_PATH];
	//初始化入口参数bi开始
	bi.hwndOwner = NULL;
	bi.pidlRoot =NULL;//初始化制定的root目录很不容易
	bi.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
	bi.lpszTitle =_T( "选择节目文件夹路径");
	bi.ulFlags = BIF_EDITBOX;//带编辑框的风格
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage=IDR_MAINFRAME;

	//初始化入口参数bi结束
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框

	if(pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);

		//取得文件夹路径到Buffer里

		CString program_dir = Buffer;//将路径保存在一个CString对象里

		GetDlgItem(IDC_EDIT2)->SetWindowText(program_dir);
	}
}


void CPlaylistDlg::OnBnClickedButton31()
{
	int w=0,h=0,err=0;
	unsigned short type=0;
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		_TEXT_CHAR controller_name[128]=_TEXT_T("");
		err= get_screeninfo(card_ip,port,user_name,user_pwd, &w,&h,controller_name,&type);
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR controller_name[128]=_TEXT_T("");
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err= get_screeninfo(card_ip,port,user_name,user_pwd, &w,&h,controller_name,&type);
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
	Program* p=new Program;
	p->m_w=w;
	p->m_h=h;
	p->m_play_mode=1;
	p->m_play_time=1;
	p->m_bDate=false;
	p->m_bTime=false;
	p->m_play_week=127;
	CProgramDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecProgram.push_back(p);
		CString str;
		str.Format(_T("%d"),m_vecProgram.size());
		m_ctrlProgramList.AddString(str);
	}
	else
	{
		delete p;
	}
}


void CPlaylistDlg::OnBnClickedButton3()
{
	int index=m_ctrlProgramList.GetCurSel();
	if (index>=0)
	{
		Program* p=m_vecProgram[index];
		CProgramDlg dlg(p);
		dlg.DoModal();
	}
}


void CPlaylistDlg::OnBnClickedButton6()
{
	int index=m_ctrlProgramList.GetCurSel();
	if (index>=0)
	{
		Program* p=m_vecProgram[index];
		delete p;
		m_vecProgram.erase(m_vecProgram.begin()+index);
		m_ctrlProgramList.DeleteString(index);
	}
}


void CPlaylistDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent==100)
	{
		int err=0;
		long long total=0,cur=0;
		int completecount=0;
		int remainsec=0;
		int rate=0,taskcount=0;
		if (card_mode==0)
		{
			query_rate(m_hSend, &total,&cur,&rate,&remainsec,&taskcount,&completecount);

		} 
		if (remainsec!=0)
		{
			m_TotalProgress.SetPos(total);
			m_CurProgress.SetPos(cur);
		}
		else
		{
			KillTimer(nIDEvent);
			if (remainsec==0)
			{
				AfxMessageBox(_T("发送完毕"));
				delete_playlist(m_hSend);
			} 
			else
			{
				AfxMessageBox(GetErrText(err));
			}
			GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CPlaylistDlg::OnBnClickedButton1()
{
	KillTimer(100);
	if (card_mode==0)
	{
		cancel_send_program(m_hSend);
	}
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		cancel_send_program(m_hSend);
	}
	GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}


void CPlaylistDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	for (int i=0;i<m_vecProgram.size();i++)
	{
		delete m_vecProgram[i];
	}
}


void CPlaylistDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CPlaylistDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}



void CPlaylistDlg::OnNMCustomdrawProgress2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

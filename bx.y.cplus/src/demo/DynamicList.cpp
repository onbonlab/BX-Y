// DynamicList.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "DynamicList.h"
#include "afxdialogex.h"
#include "DynamicFile.h"


// DynamicList 对话框

IMPLEMENT_DYNAMIC(DynamicList, CDialogEx)

DynamicList::DynamicList(char* ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(DynamicList::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}

DynamicList::DynamicList(char* ip,_TEXT_CHAR* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(DynamicList::IDD, pParent)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}
DynamicList::~DynamicList()
{
}

void DynamicList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dynamicList);
}


BEGIN_MESSAGE_MAP(DynamicList, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &DynamicList::OnBnClickedButton6)
	ON_BN_CLICKED(IDOK, &DynamicList::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DynamicList::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON7, &DynamicList::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_SEND, &DynamicList::OnBnClickedSend)
	ON_BN_CLICKED(IDC_BUTTON31, &DynamicList::OnBnClickedButton31)
END_MESSAGE_MAP()


// DynamicList 消息处理程序


void DynamicList::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_dynamicList.GetCurSel();
	if (index>=0)
	{
		DynamicArea* p=m_Area[index];
		delete p;
		m_Area.erase(m_Area.begin()+index);
		m_dynamicList.DeleteString(index);
	}
}


void DynamicList::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void DynamicList::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void DynamicList::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	if(card_mode==0)
	{
		unsigned short port=80;
		int err = clear_dynamic(card_ip,port,user_name,user_pwd);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}else{
		unsigned short port=Get_Port_Pid(card_PID);
		int err = clear_dynamic(card_ip,port,user_name,user_pwd);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
}


void DynamicList::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
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

		_TEXT_CHAR* name=_TEXT_T("program_1");
		unsigned long program=create_program(name,_TEXT_T("0xff000000"));
		for (int i=0;i<m_Area.size();i++)
		{
			DynamicArea* n=(DynamicArea*)m_Area[i];
			DWORD dynamic_area = create_dynamic();
			for (int t=0;t<n->m_PicCount;t++)
			{
				add_dynamic_unit(dynamic_area, n->m_DynamicAreaFile[t].dynamic_type, n->m_DynamicAreaFile[t].display_effects, n->m_DynamicAreaFile[t].display_speed, n->m_DynamicAreaFile[t].stay_time,
                n->m_DynamicAreaFile[t].file_path, n->m_DynamicAreaFile[t].gif_flag, n->m_DynamicAreaFile[t].bg_color, n->m_DynamicAreaFile[t].font_size,n->m_DynamicAreaFile[t].font_name,
				n->m_DynamicAreaFile[t].font_color, n->m_DynamicAreaFile[t].font_attributes,
                n->m_DynamicAreaFile[t].align_h, n->m_DynamicAreaFile[t].align_v, n->m_DynamicAreaFile[t].volumn, n->m_DynamicAreaFile[t].scale_mode, n->m_DynamicAreaFile[t].rolation_mode);
            }
            result = add_dynamic(program, dynamic_area, n->m_dynamic_id, n->m_x, n->m_y, n->m_w, n->m_h, n->m_relative_program,
                n->m_run_mode, n->m_update_frequency, n->m_transparency);
		   delete_dynamic(dynamic_area);
		}
		CString str1,str2,str3,str4;
		_TEXT_CHAR aging_start_time[20]=_TEXT_T(""),aging_end_time[20]=_TEXT_T("");
		_TEXT_CHAR period_ontime[20]=_TEXT_T(""),period_offtime[20]=_TEXT_T("");
		if (m_ProgramDyanmic->m_bDate)
		{
			str1=m_ProgramDyanmic->m_aging_start_time.Format("%Y-%m-%d");
			str2=m_ProgramDyanmic->m_aging_stop_time.Format("%Y-%m-%d");
			char start_time[20],stop_time[20];
			memset(start_time,0,sizeof(start_time));
			memset(stop_time,0,sizeof(stop_time));
			CString2Char(str1,start_time);
			Char2TCHAR(aging_start_time,start_time);
			CString2Char(str2,stop_time);
			Char2TCHAR(aging_end_time,stop_time);
		}
		if (m_ProgramDyanmic->m_bTime)
		{
			str3=m_ProgramDyanmic->m_period_ontime.Format("%H:%M:%S");
			str4=m_ProgramDyanmic->m_period_offtime.Format("%H:%M:%S");
			char ontime[20],offtime[20];
			memset(offtime,0,sizeof(offtime));
			memset(ontime,0,sizeof(ontime));
			CString2Char(str3,ontime);
			Char2TCHAR(period_ontime,ontime);
			CString2Char(str4,offtime);
			Char2TCHAR(period_offtime,offtime);
		}
		int play_time=1;
		add_program_in_playlist(playlist,program,m_ProgramDyanmic->m_play_mode,m_ProgramDyanmic->m_play_time,aging_start_time,aging_end_time, period_ontime,period_offtime,m_ProgramDyanmic->m_play_week);
	
	if (card_mode==0)
	{
		int send_style=0;
	    result=update_dynamic(card_ip,port,user_name,user_pwd,playlist,-1,0,0);
		if (result!=0)
		{
			AfxMessageBox(GetErrText(result));
		}
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int send_style=0;
		long long free_size=0,total_size=0;
	   result=update_dynamic(card_ip,port,user_name,user_pwd,playlist,-1,0,0);

	}
}


void DynamicList::OnBnClickedButton31()
{
	// TODO: 在此添加控件通知处理程序代码
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
		/*TCHAR barcode[17];
		memset(barcode,0,sizeof(barcode));
		Char2TCHAR(barcode,card_barcode);
		unsigned short port=Get_Port_Barcode(barcode);
		_TEXT_CHAR controller_name[128]=_TEXT_T("");
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err= get_screeninfo(card_ip,port,user_name,user_pwd, &w,&h,controller_name,&type);*/
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
	m_ProgramDyanmic=new ProgramDyanmic;
	m_ProgramDyanmic->m_w=w;
	m_ProgramDyanmic->m_h=h;
	m_ProgramDyanmic->m_play_mode=1;
	m_ProgramDyanmic->m_play_time=1;
	m_ProgramDyanmic->m_bDate=false;
	m_ProgramDyanmic->m_bTime=false;
	m_ProgramDyanmic->m_play_week=127;
	DynamicArea* p=new DynamicArea(0);
	p->m_w=w;
	p->m_h=h;
	p->m_dynamic_id=0;
    p->m_x=0;//x
    p->m_y=0;//y
	_tcscpy_s(p->m_relative_program,_TEXT_T("-1"));
    p->m_run_mode=0;//动态区运行方式
	_tcscpy_s(p->m_update_frequency,_TEXT_T(""));
    p->m_transparency=255;
	CDynamicFile dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_Area.push_back(p);
		CString str;
		str.Format(_T("%d"),m_Area.size());
		m_dynamicList.AddString(str);
	}
	else
	{
		delete p;
	}
}

// VolumeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "VolumeDlg.h"
#include "afxdialogex.h"


// CVolumeDlg 对话框

IMPLEMENT_DYNAMIC(CVolumeDlg, CDialogEx)

CVolumeDlg::CVolumeDlg(char* ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CVolumeDlg::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CVolumeDlg::CVolumeDlg( char *ip,_TEXT_CHAR* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CVolumeDlg::IDD, pParent)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}
CVolumeDlg::~CVolumeDlg()
{
}

void CVolumeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_VolumeSlider);
}


BEGIN_MESSAGE_MAP(CVolumeDlg, CDialogEx)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CVolumeDlg::OnNMReleasedcaptureSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CVolumeDlg::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// CVolumeDlg 消息处理程序




BOOL CVolumeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_VolumeSlider.SetRange(0,100);
	int volume=0;
	int err=0;
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err=get_screen_volumn(card_ip,port,user_name,user_pwd, &volume);
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err=get_screen_volumn(card_ip,port,user_name,user_pwd, &volume);
	}
	
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		m_VolumeSlider.SetPos(volume);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CVolumeDlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int volume=m_VolumeSlider.GetPos();
	int err=0;
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int err=set_screen_volumn(card_ip,port,user_name,user_pwd,volume);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int err=set_screen_volumn(card_ip,port,user_name,user_pwd,volume);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

	*pResult = 0;
}


void CVolumeDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

// BrightDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "BrightDlg.h"
#include "afxdialogex.h"


// CBrightDlg 对话框
UINT id_table[]=
{
	IDC_EDIT16,IDC_EDIT17,IDC_EDIT18,IDC_EDIT19,IDC_EDIT20,IDC_EDIT21,IDC_EDIT22,IDC_EDIT23,
	IDC_EDIT24,IDC_EDIT25,IDC_EDIT26,IDC_EDIT27,IDC_EDIT28,IDC_EDIT29,IDC_EDIT30,IDC_EDIT31,
	IDC_EDIT32,IDC_EDIT33,IDC_EDIT34,IDC_EDIT35,IDC_EDIT36,IDC_EDIT37,IDC_EDIT38,IDC_EDIT39,
	IDC_EDIT40,IDC_EDIT41,IDC_EDIT42,IDC_EDIT43,IDC_EDIT44,IDC_EDIT45,IDC_EDIT46,IDC_EDIT47,
	IDC_EDIT48,IDC_EDIT49,IDC_EDIT50,IDC_EDIT51,IDC_EDIT52,IDC_EDIT53,IDC_EDIT54,IDC_EDIT55,
	IDC_EDIT56,IDC_EDIT57,IDC_EDIT58,IDC_EDIT59,IDC_EDIT60,IDC_EDIT61,IDC_EDIT62,IDC_EDIT63,
};
IMPLEMENT_DYNAMIC(CBrightDlg, CDialogEx)

CBrightDlg::CBrightDlg( char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CBrightDlg::IDD, pParent)
	, m_Mode(0)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CBrightDlg::CBrightDlg( char *ip,_TEXT_CHAR* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CBrightDlg::IDD, pParent)
	, m_Mode(0)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}

CBrightDlg::~CBrightDlg()
{
}

void CBrightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX,IDC_RADIO1,m_Mode);
}


BEGIN_MESSAGE_MAP(CBrightDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADJUST_BRIGHT, &CBrightDlg::OnBnClickedAdjustBright)
	ON_BN_CLICKED(IDC_RADIO2, &CBrightDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CBrightDlg 消息处理程序


void CBrightDlg::OnBnClickedAdjustBright()
{

	int mode=0;

	unsigned short table[48];
	
	CButton* btn=(CButton*)GetDlgItem(IDC_RADIO1);
	if (!btn->GetCheck())
	{
		mode=1;
		for (int i=0;i<48;i++)
		{	
			CString str;
			GetDlgItem(id_table[i])->GetWindowText(str);
			table[i]=_tstoi(str);
		}
	}
	else
	{
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		table[0]=_tstoi(str);
	}
	if(card_mode==0)
	{
		int err=0;
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		if (mode==1)
		{
			int data_count=48;
			err=set_screen_cus_brightness(card_ip,port,user_name,user_pwd,table,data_count);
		}
		else
		{
			int brightness=table[0];
			err=set_screen_brightness(card_ip,port,user_name,user_pwd,brightness);
		}
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
	else
	{
		int err=0;
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		if (mode==1)
		{
			int data_count=48;
			err=set_screen_cus_brightness(card_ip,port,user_name,user_pwd,table,data_count);
		}
		else
		{
			int brightness=table[0];
			err=set_screen_brightness(card_ip,port,user_name,user_pwd,brightness);
		}
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
}

BOOL CBrightDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Mode=0;
	int mode=0;
	short table[48]={0};
	int err=0;
	if (card_mode==0)
	{
		int data_count=48;
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	    err=get_screen_brightness(card_ip,port,user_name,user_pwd,table);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	   int err=get_screen_brightness(card_ip,port,user_name,user_pwd,table);
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		m_Mode=mode;
		if (mode==1)
		{
			for (int i=0;i<48;i++)
			{	
				CString str;
				str.Format(_T("%d"),table[i]);
				GetDlgItem(id_table[i])->SetWindowText(str);
			}
		}
		else
		{
			CString str;
			str.Format(_T("%d"),table[0]);
			GetDlgItem(IDC_EDIT1)->SetWindowText(str);

			for (int i=0;i<48;i++)
			{	
				GetDlgItem(id_table[i])->SetWindowText(_T("50"));
			}
		}

	}
	this->UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CBrightDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}

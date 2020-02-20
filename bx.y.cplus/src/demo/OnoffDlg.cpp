// OnoffDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "OnoffDlg.h"
#include "afxdialogex.h"


// COnoffDlg 对话框

IMPLEMENT_DYNAMIC(COnoffDlg, CDialogEx)

COnoffDlg::COnoffDlg(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(COnoffDlg::IDD, pParent)
	, m_Onoff(0)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
COnoffDlg::COnoffDlg(char *ip,_TEXT_CHAR* pid,CWnd* pParent /*= NULL*/)
	: CDialogEx(COnoffDlg::IDD, pParent)
	, m_Onoff(0)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}
COnoffDlg::~COnoffDlg()
{
}

void COnoffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX,IDC_RADIO1,m_Onoff);
}


BEGIN_MESSAGE_MAP(COnoffDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &COnoffDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &COnoffDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &COnoffDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &COnoffDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK2, &COnoffDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &COnoffDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &COnoffDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &COnoffDlg::OnBnClickedCheck5)
END_MESSAGE_MAP()


// COnoffDlg 消息处理程序


BOOL COnoffDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	int onoff=0;
	int err=0;
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err=get_screen_onoff(card_ip,port,user_name,user_pwd,&onoff);
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
    	err=get_screen_onoff(card_ip,port,user_name,user_pwd,&onoff);
	}

	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		m_Onoff=onoff;
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void COnoffDlg::OnBnClickedButton2()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	_TEXT_CHAR *starttime1=_TEXT_T("");
	_TEXT_CHAR *endtime1=_TEXT_T("");
	unsigned long turnonoff= create_turnonoff();
	if (btn->GetCheck())
	{
		CString str;
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER1);
		CTime tm;
		pCtrl->GetTime(tm);
        str= tm.Format(("%H:%M:%S"));
		starttime1=str.GetBuffer();


		CString str1;
		CDateTimeCtrl* pCtrl1=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER2);
		pCtrl1->GetTime(tm);
        str1= tm.Format(("%H:%M:%S"));
		endtime1=str1.GetBuffer();
	

		int startaction1=1,endaction1=0;;
		add_turnonoff(turnonoff,startaction1,starttime1);
		add_turnonoff(turnonoff,endaction1,endtime1);
	}
	 _TEXT_CHAR* starttime2=_TEXT_T("");
	 _TEXT_CHAR* endtime2=_TEXT_T("");
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	if (btn->GetCheck())
	{
		CString str;
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER3);
		CTime tm;
		pCtrl->GetTime(tm);
        str= tm.Format(("%H:%M:%S"));
		starttime2=str.GetBuffer();

		CString str1;
		CDateTimeCtrl* pCtrl1=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER4);
		pCtrl1->GetTime(tm);
        str1= tm.Format(("%H:%M:%S"));
		endtime2=str1.GetBuffer(); 
		int startaction2=1,endaction2=0;
		add_turnonoff(turnonoff,startaction2,starttime2);
		add_turnonoff(turnonoff,endaction2,endtime2);
	}
	_TEXT_CHAR* starttime3=_TEXT_T("");
	_TEXT_CHAR* endtime3=_TEXT_T("");
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	if (btn->GetCheck())
	{
		CString str;
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER5);
		CTime tm;
		pCtrl->GetTime(tm);
        str= tm.Format(("%H:%M:%S"));
		starttime3=str.GetBuffer();

		CString str1;
		CDateTimeCtrl* pCtrl1=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER6);
		pCtrl1->GetTime(tm);
        str1= tm.Format(("%H:%M:%S"));
		endtime3=str1.GetBuffer();

		int startaction3=1,endaction3=0;
		add_turnonoff(turnonoff,startaction3,starttime3);
		add_turnonoff(turnonoff,endaction3,endtime3);
	}
		_TEXT_CHAR* starttime4=_TEXT_T("");
	_TEXT_CHAR* endtime4=_TEXT_T("");
	btn=(CButton*)GetDlgItem(IDC_CHECK5);
	if (btn->GetCheck())
	{
		CString str;
		CDateTimeCtrl* pCtrl=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER7);
		CTime tm;
		pCtrl->GetTime(tm);
        str= tm.Format(("%H:%M:%S"));
		starttime4=str.GetBuffer();

		CString str1;
		CDateTimeCtrl* pCtrl1=(CDateTimeCtrl*)GetDlgItem(IDC_DATETIMEPICKER8);
		pCtrl1->GetTime(tm);
        str1= tm.Format(("%H:%M:%S"));
		endtime4=str1.GetBuffer();
		int startaction4=1,endaction4=0;
		add_turnonoff(turnonoff,startaction4,starttime4);
		add_turnonoff(turnonoff,endaction4,endtime4);
	}
	if (card_mode==0)
	{
		int err=0;
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
        err=set_screen_cus_turnonoff(card_ip, port,user_name,user_pwd,turnonoff);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
    	int  err=set_screen_cus_turnonoff(card_ip, port,user_name,user_pwd,turnonoff);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
	delete_turnonoff(turnonoff);//销毁句柄
}
void COnoffDlg::OnBnClickedButton1()
{
	if (card_mode==0)
	{
		int err=0;
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err=cancel_screen_cus_turnonoff(card_ip,port,user_name,user_pwd);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int  err=cancel_screen_cus_turnonoff(card_ip, port,user_name,user_pwd);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
}

void COnoffDlg::OnBnClickedRadio1()
{
	CButton *btn=(CButton*)GetDlgItem(IDC_RADIO3);
	btn->SetCheck(0);
	btn=(CButton*)GetDlgItem(IDC_RADIO4);
	btn->SetCheck(0);
	if (card_mode==0)
	{
		int err=0;
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int turnonoff_status=0;
	    err=set_screen_turnonoff(card_ip,port,user_name,user_pwd,turnonoff_status);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int turnonoff_status=0;
		int err=set_screen_turnonoff(card_ip,port,user_name,user_pwd,turnonoff_status);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

}


void COnoffDlg::OnBnClickedRadio2()
{
	CButton *btn=(CButton*)GetDlgItem(IDC_RADIO3);
	btn->SetCheck(0);
	btn=(CButton*)GetDlgItem(IDC_RADIO4);
	btn->SetCheck(0);
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int turnonoff_status=1;
		int err=set_screen_turnonoff(card_ip,port,user_name,user_pwd,turnonoff_status);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		int turnonoff_status=1;
		int err=set_screen_turnonoff(card_ip,port,user_name,user_pwd,turnonoff_status);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

}


void COnoffDlg::OnBnClickedCheck2()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(FALSE);
	}
}


void COnoffDlg::OnBnClickedCheck3()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK3);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(FALSE);
	}
}


void COnoffDlg::OnBnClickedCheck4()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK4);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER5)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER6)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER5)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER6)->EnableWindow(FALSE);
	}
}


void COnoffDlg::OnBnClickedCheck5()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK5);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER7)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER8)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER7)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER8)->EnableWindow(FALSE);
	}
}

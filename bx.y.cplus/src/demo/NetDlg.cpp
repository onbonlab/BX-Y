// NetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "NetDlg.h"
#include "afxdialogex.h"


 //CNetDlg 对话框

IMPLEMENT_DYNAMIC(CNetDlg, CDialogEx)

CNetDlg::CNetDlg(card_unit* pUnit,CWnd* pParent /*=NULL*/)
	: CDialogEx(CNetDlg::IDD, pParent)
	, m_IpMode(0)
	,m_ClientMode(0)
{
	card_mode=0;
	m_pUnit=pUnit;
}
CNetDlg::CNetDlg(char *ip,int port,BroadCast2* pCard,CWnd* pParent /*= NULL*/)
	: CDialogEx(CNetDlg::IDD, pParent)
	, m_IpMode(0)
	,m_ClientMode(1)
{
	memset(m_serversip,0,sizeof(m_serversip));
	strcpy(m_serversip,ip);
	card_mode=1;
	m_serversport=port;
	m_pServerCard=pCard;
}
CNetDlg::~CNetDlg()
{
}

void CNetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX,IDC_RADIO1,m_IpMode);
	DDX_Radio(pDX,IDC_RADIO3,m_ClientMode);
}


BEGIN_MESSAGE_MAP(CNetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CNetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO2, &CNetDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CNetDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CNetDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CNetDlg 消息处理程序


void CNetDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(str);
	char ip[20]={0};
	CString2Char(str,ip);
	GetDlgItem(IDC_IPADDRESS2)->GetWindowText(str);
	char mask[20]={0};
	CString2Char(str,mask);
	GetDlgItem(IDC_IPADDRESS3)->GetWindowText(str);
	char gate[20]={0};
	CString2Char(str,gate);


	CButton* btn=(CButton*)GetDlgItem(IDC_RADIO1);
	if (btn->GetCheck())
	{
		_TEXT_CHAR barcode[17];
		memset(barcode,0,sizeof(barcode));
		Char2TCHAR(barcode,(char*)m_pUnit->barcode);
		int err=set_auto_ip(barcode);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
		else
		{
			char ip[20]={0};
			char mask[20]={0};
			char gate[20]={0};
			char a[10]={0};
			int ipmode=0;
			Sleep(1000);
			err= get_netinfo(ip,barcode,mask,gate,&ipmode);
			strcpy(m_pUnit->ip,ip);
			if (err==0)
			{	
				TCHAR tmp[20]={0};
				memset(tmp,0,sizeof(tmp));
				Char2TCHAR(tmp,ip);
				GetDlgItem(IDC_IPADDRESS1)->SetWindowText(tmp);
				memset(tmp,0,sizeof(tmp));
				Char2TCHAR(tmp,mask);
				GetDlgItem(IDC_IPADDRESS2)->SetWindowText(tmp);
				memset(tmp,0,sizeof(tmp));
				Char2TCHAR(tmp,gate);
				GetDlgItem(IDC_IPADDRESS3)->SetWindowText(tmp);

			}
		}
	}
	else
	{
		int err=0;
		_TEXT_CHAR barcode[17];
		memset(barcode,0,sizeof(barcode));
		Char2TCHAR(barcode,(char*)m_pUnit->barcode);
		err=set_static_ip(barcode,ip,mask,gate);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
		else
		{
			strcpy(m_pUnit->ip,ip);
		}
	}


}


BOOL CNetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("20000"));
	CString str;
	char serverip[20]={0};
	USHORT port=0;

	char ip[20]={0};
	char mask[20]={0};
	char gate[20]={0};
	int ipmode;
	unsigned char pid[33]={0};
	if(card_mode==0)
	{
		int err=0;
		char ip[20]={0};
		TCHAR barcode[17]={0};
		memset(barcode,0,sizeof(barcode));
		Char2TCHAR(barcode,m_pUnit->barcode);
		err= get_netinfo(ip,barcode,mask,gate,&ipmode);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
		else
		{
			m_IpMode=ipmode;
			TCHAR tmp[20]={0};
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,ip);
			GetDlgItem(IDC_IPADDRESS1)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,mask);
			GetDlgItem(IDC_IPADDRESS2)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,gate);
			GetDlgItem(IDC_IPADDRESS3)->SetWindowText(tmp);
		}
	}
	else if(card_mode==1)
	{
		int err=0;
		char ip[20]={0};
		err= get_netinfo(ip,m_pServerCard->barcode,mask,gate,&ipmode);
		if (err!=ERR_NO)
		{
			AfxMessageBox(GetErrText(err));
			return FALSE;
		}
		else
		{
			m_IpMode=ipmode;
			TCHAR tmp[20]={0};
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,ip);
			GetDlgItem(IDC_IPADDRESS1)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,mask);
			GetDlgItem(IDC_IPADDRESS2)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,gate);
			GetDlgItem(IDC_IPADDRESS3)->SetWindowText(tmp);
		}
		
		TCHAR tmp[20]={0};
		memset(tmp,0,sizeof(tmp));
		Char2TCHAR(tmp,m_serversip);
		GetDlgItem(IDC_IPADDRESS4)->SetWindowText(tmp);
		CString str;
		str.Format(_T("%d"),m_serversport);
		GetDlgItem(IDC_EDIT1)->SetWindowText(str);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}

		if (m_IpMode==0)
		{
			GetDlgItem(IDC_IPADDRESS1)->EnableWindow(FALSE);
			GetDlgItem(IDC_IPADDRESS2)->EnableWindow(FALSE);
			GetDlgItem(IDC_IPADDRESS3)->EnableWindow(FALSE);
		}
		if (m_ClientMode==0)
		{
			GetDlgItem(IDC_IPADDRESS4)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		}
		UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CNetDlg::OnBnClickedButton2()
{

		CButton* btn=(CButton*)GetDlgItem(IDC_RADIO4);
		if (btn->GetCheck())
		{
			CString str;
			GetDlgItem(IDC_IPADDRESS4)->GetWindowText(str);
			char server_ip[20]={0};
			CString2Char(str,server_ip);
			GetDlgItem(IDC_EDIT1)->GetWindowText(str);
			short port=_tstoi(str);
			int err=0;
			GetDlgItem(IDC_EDIT1)->GetWindowText(str);
			port=_tstoi(str);
			str.Format(_T("%d"),port);
			GetDlgItem(IDC_EDIT1)->SetWindowText(str);
			TCHAR barcode[17]=_TEXT_T("0");
			memset(barcode,0,sizeof(barcode));
			Char2TCHAR(barcode,m_pUnit->barcode);
			_TEXT_CHAR *pid=_TEXT_T("");
			err=set_screen_server(barcode,pid,server_ip,port,1);
			if (err!=0)
			{
				AfxMessageBox(GetErrText(err));
			}
		}

}




void CNetDlg::OnBnClickedRadio2()
{
	GetDlgItem(IDC_IPADDRESS1)->EnableWindow(TRUE);
	GetDlgItem(IDC_IPADDRESS2)->EnableWindow(TRUE);
	GetDlgItem(IDC_IPADDRESS3)->EnableWindow(TRUE);
}


void CNetDlg::OnBnClickedRadio1()
{
	GetDlgItem(IDC_IPADDRESS1)->EnableWindow(FALSE);
	GetDlgItem(IDC_IPADDRESS2)->EnableWindow(FALSE);
	GetDlgItem(IDC_IPADDRESS3)->EnableWindow(FALSE);
}


void CNetDlg::OnBnClickedRadio4()
{
	GetDlgItem(IDC_IPADDRESS4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
}

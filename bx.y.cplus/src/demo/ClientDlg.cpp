// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#include "ScreenProperty.h"
#include "NetDlg.h"
#include "VolumeDlg.h"
#include "BrightDlg.h"
#include "OnoffDlg.h"
#include "FirmwareDlg.h"
#include "PlaylistDlg.h"
#include "DynamicList.h"

// CClientDlg 对话框

IMPLEMENT_DYNAMIC(CClientDlg, CDialogEx)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO7, m_cmbClientCardList);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON28, &CClientDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON5, &CClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CClientDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &CClientDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON32, &CClientDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON10, &CClientDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CClientDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON7, &CClientDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON15, &CClientDlg::OnBnClickedButton15)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CClientDlg::OnCbnSelchangeCombo7)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CClientDlg 消息处理程序





void CClientDlg::OnCbnSelchangeCombo7()
{
	int index=m_cmbClientCardList.GetCurSel();
	TCHAR ip[20]={0};
	memset(ip,0,sizeof(ip));
	Char2TCHAR(ip,m_ClientList[index].ip);
	GetDlgItem(IDC_IPADDRESS3)->SetWindowText(ip);
}

void CClientDlg::OnBnClickedButton28()
{
	m_cmbClientCardList.ResetContent();
	m_ClientCount=SearchCards(m_ClientList);
	for (int i=0;i<m_ClientCount;i++)
	{
		char tmp[25]={0};
		memcpy(tmp,m_ClientList[i].barcode,sizeof(m_ClientList[i].barcode));
		TCHAR barcode[17]={0};
		memset(barcode,0,sizeof(barcode));
		Char2TCHAR(barcode,tmp);
		m_cmbClientCardList.AddString(barcode);
	}
	
	if (m_ClientCount>0)
	{
		m_cmbClientCardList.SetCurSel(0);
		OnCbnSelchangeCombo7();
		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}
}


void CClientDlg::OnBnClickedButton5()
{
	int t=m_cmbClientCardList.GetCurSel();
	CScreenProperty dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton8()
{
	CNetDlg dlg(m_ClientList+m_cmbClientCardList.GetCurSel());

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton11()
{
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	unsigned short port=80;
	int err=check_time(m_ClientList[m_cmbClientCardList.GetCurSel()].ip,port,user_name,user_pwd);
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}

}


void CClientDlg::OnBnClickedButton32()
{
	CVolumeDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton10()
{
	CBrightDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton9()
{
	COnoffDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton7()
{
	CFirmwareDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton2()
{
	CPlaylistDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton15()
{
	DynamicList dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}
BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	m_ClientList=new card_unit[1024];
	m_ClientCount=0;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
void CClientDlg::OnClose()
{

	if (m_ClientCount>0)
	{
    	delete[] m_ClientList;
	}
	CDialogEx::OnClose();
}

void CClientDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_IPADDRESS3)->GetWindowText(str);
	char ip[20]={0};
	CString2Char(str,ip);
	m_ClientCount=1;
	memset(m_ClientList[0].ip,0,sizeof(m_ClientList[0].ip));
	strcpy(m_ClientList[0].ip,ip);
	m_cmbClientCardList.AddString(_T(""));
	m_cmbClientCardList.SetCurSel(0);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
}

// StrPageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "StrPageDlg.h"
#include "afxdialogex.h"
#include <sstream>

// CStrPageDlg 对话框

IMPLEMENT_DYNAMIC(CStrPageDlg, CDialogEx)

CStrPageDlg::CStrPageDlg(StrUnit* pPage,CWnd* pParent /*=NULL*/)
	: CDialogEx(CStrPageDlg::IDD, pParent)
{
	m_pPage=pPage;
}

CStrPageDlg::~CStrPageDlg()
{
}

void CStrPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_btnTextColor);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btnBgColor);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_cmbFont);
}


BEGIN_MESSAGE_MAP(CStrPageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStrPageDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CStrPageDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CStrPageDlg 消息处理程序

wstring short2hexw(unsigned short v)
{
	wstringstream ss;
	ss.width(4);
	ss.fill(L'0');
	ss <<hex  << v;
	return L"0x"+ss.str();
}
void CStrPageDlg::OnBnClickedOk()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	m_pPage->font_size=_tstoi(str);
	
	GetDlgItem(IDC_MFCFONTCOMBO1)->GetWindowText(m_pPage->font_name,sizeof(m_pPage->font_name));

	m_pPage->bg_color=m_btnBgColor.GetColor();
	m_pPage->font_color=m_btnTextColor.GetColor();
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_pPage->text_content,sizeof(m_pPage->text_content));
	CDialogEx::OnOK();
}


BOOL CStrPageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;
	str.Format(_T("%d"),m_pPage->font_size);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_pPage->text_content);
	m_cmbFont.SelectFont(m_pPage->font_name);
	m_btnBgColor.SetColor(m_pPage->bg_color);
	m_btnTextColor.SetColor(m_pPage->font_color);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CStrPageDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

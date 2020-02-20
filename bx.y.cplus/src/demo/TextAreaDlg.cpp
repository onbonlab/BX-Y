// TextAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "TextAreaDlg.h"
#include "afxdialogex.h"
#include "StrPageDlg.h"

TCHAR* TXT_ShowMode[]=
{
	_T("快速打出		"),
	_T("随机			"),
	_T("静止显示		"),
	_T("向上推入		"),
	_T("向下推入		"),
	_T("向左推入		"),
	_T("向右推入		"),
	_T("向上连移		"),
	_T("向下连移		"),
	_T("向左连移		"),
	_T("向右连移		"),

};
extern TCHAR* PIC_ShowMode[];
// CTextAreaDlg 对话框

IMPLEMENT_DYNAMIC(CTextAreaDlg, CDialogEx)

CTextAreaDlg::CTextAreaDlg(StrArea* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextAreaDlg::IDD, pParent)
{
	m_pArea=p;
}

CTextAreaDlg::~CTextAreaDlg()
{
}

void CTextAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Control(pDX, IDC_COMBO1, m_cmbDisplayEffect);
	DDX_Control(pDX, IDC_LIST_UNIT, m_ctrlUnitList);
	DDX_Control(pDX, IDC_COMBO2, m_cmbunit_type);
}


BEGIN_MESSAGE_MAP(CTextAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTextAreaDlg::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST_UNIT, &CTextAreaDlg::OnLbnSelchangeListUnit)
	ON_BN_CLICKED(IDC_UNIT_REMOVE, &CTextAreaDlg::OnBnClickedUnitRemove)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CTextAreaDlg::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT31, &CTextAreaDlg::OnEnKillfocusEdit31)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CTextAreaDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON4, &CTextAreaDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTextAreaDlg 消息处理程序

void CTextAreaDlg::OnBnClickedUnitRemove()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit.erase(m_vecUnit.begin()+index);
		m_ctrlUnitList.DeleteString(index);
	}
}



void CTextAreaDlg::OnEnKillfocusEdit1()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		//m_vecUnit[index].display_speed=_tstoi(str);
	}
}


void CTextAreaDlg::OnEnKillfocusEdit31()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT31)->GetWindowText(str);
		//m_vecUnit[index].stay_time=_tstoi(str);
	}
}


void CTextAreaDlg::OnLbnSelchangeListUnit()
{
	/*int index=m_ctrlUnitList.GetCurSel();
	CString str;
	str.Format(_T("%d"),m_vecUnit[index].display_speed);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	str.Format(_T("%d"),m_vecUnit[index].stay_time);
	GetDlgItem(IDC_EDIT31)->SetWindowText(str);*/
}
void CTextAreaDlg::OnBnClickedOk()
{
	m_pArea->m_transparency=255-m_ctrlSlider.GetPos();
	CString str;
	GetDlgItem(IDC_AREA_X)->GetWindowText(str);
	m_pArea->m_x=_tstoi(str);

	GetDlgItem(IDC_AREA_Y)->GetWindowText(str);
	m_pArea->m_y=_tstoi(str);

	GetDlgItem(IDC_AREA_W)->GetWindowText(str);
	m_pArea->m_w=_tstoi(str);

	GetDlgItem(IDC_AREA_H)->GetWindowText(str);
	m_pArea->m_h=_tstoi(str);
	
	int index=m_cmbDisplayEffect.GetCurSel();
	if (index>=0)
	{
		switch(m_cmbDisplayEffect.GetCurSel())
		{
		case 0:m_pArea->display_effects=m_cmbDisplayEffect.GetCurSel();
			break;
		case 1:m_pArea->display_effects=50;
			break;
		case 2:m_pArea->display_effects=51;
			break;
		case 3:m_pArea->display_effects=52;
			break;
		case 4:m_pArea->display_effects=53;
			break;
		case 5:m_pArea->display_effects=54;
			break;
		case 6:m_pArea->display_effects=55;
			break;
		case 7:m_pArea->display_effects=56;
			break;
		case 8:m_pArea->display_effects=57;
			break;
		default:m_pArea->display_effects=0;
			break;
		}
	}
	m_pArea->unit_type=m_cmbunit_type.GetCurSel();
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	m_pArea->m_bBgTransparent=btn->GetCheck();

	for (int i=0;i<m_vecUnit.size();i++)
	{
		m_pArea->m_StrUnit.push_back(m_vecUnit[i]);
	}
	m_pArea->m_StrCount=m_vecUnit.size();
	CDialogEx::OnOK();
}


BOOL CTextAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	m_cmbDisplayEffect.AddString(_T("快速打出"));
	m_cmbDisplayEffect.AddString(_T("平滑向上推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向下推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向左推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向右推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向上移入"));
	m_cmbDisplayEffect.AddString(_T("平滑向下移入"));
	m_cmbDisplayEffect.AddString(_T("平滑向左移入"));
	m_cmbDisplayEffect.AddString(_T("平滑向右移入"));
	m_cmbDisplayEffect.SetCurSel(0);

	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(255-m_pArea->m_transparency);

	m_cmbunit_type.SetCurSel(1);

	CString str;
	str.Format(_T("%d"),m_pArea->m_x);
	GetDlgItem(IDC_AREA_X)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_y);
	GetDlgItem(IDC_AREA_Y)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_w);
	GetDlgItem(IDC_AREA_W)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_h);
	GetDlgItem(IDC_AREA_H)->SetWindowText(str);
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	btn->SetCheck(m_pArea->m_bBgTransparent);

	for (int i=0;i<m_pArea->m_StrCount;i++)
	{
		m_vecUnit.push_back(m_pArea->m_StrUnit[i]);
		//m_ctrlUnitList.AddString(m_sArea->m_StrUnit[i].szFile);
	}
	if (m_vecUnit.size()>0)
	{
		m_ctrlUnitList.SetCurSel(0);
		OnLbnSelchangeListUnit();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CTextAreaDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CTextAreaDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	StrUnit *page=new StrUnit;
	page->display_speed=16;
	page->stay_time=5;
	page->bg_color=RGB(0,0,0);
	_tcscpy_s(page->font_name,_T("宋体"));
	page->font_size=12;
	_tcscpy_s(page->font_attributes,_T("normal"));
	_tcscpy_s(page->font_alignment,_T(""));
	_tcscpy_s(page->text_content,_T(" "));
	page->font_color=RGB(0,255,0);
	page->last_move_width=0;


	CStrPageDlg dlg(page);
	if (dlg.DoModal()==IDOK)
	{
		m_vecUnit.push_back(page);
		CString str;
		str.Format(_T("%d"),m_vecUnit.size());
		int item=m_ctrlUnitList.AddString(str);
		m_ctrlUnitList.SetCurSel(item);
		//OnLbnSelchangeList1();
	}
}

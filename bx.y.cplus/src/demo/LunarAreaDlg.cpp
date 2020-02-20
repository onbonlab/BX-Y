// LunarAreaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "LunarAreaDlg.h"
#include "afxdialogex.h"


// CLunarAreaDlg �Ի���

IMPLEMENT_DYNAMIC(CLunarAreaDlg, CDialogEx)

CLunarAreaDlg::CLunarAreaDlg(LunarArea* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CLunarAreaDlg::IDD, pParent)
{
	m_pArea=p;
}

CLunarAreaDlg::~CLunarAreaDlg()
{
}

void CLunarAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_cmbFont);
	DDX_Radio(pDX,IDC_RADIO1,m_bMultiLine);
	DDX_Control(pDX, IDC_COMBO5, m_cmbAlign);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON4, m_btnText);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, m_btnTime);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_btnYear);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btnDate);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
}


BEGIN_MESSAGE_MAP(CLunarAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLunarAreaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK10, &CLunarAreaDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CLunarAreaDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK13, &CLunarAreaDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK1, &CLunarAreaDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON4, &CLunarAreaDlg::OnBnClickedMfccolorbutton4)
END_MESSAGE_MAP()


// CLunarAreaDlg ��Ϣ�������


void CLunarAreaDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
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


	m_pArea->m_multiline=m_bMultiLine;
	_tcscpy_s(m_pArea->m_font,m_cmbFont.GetSelFont()->m_strName);

	GetDlgItem(IDC_EDIT15)->GetWindowText(str);
	m_pArea->m_fontsize=_tstoi(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	m_pArea->m_bold=btn->GetCheck();
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	m_pArea->m_italic=btn->GetCheck();
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	m_pArea->m_underline=btn->GetCheck();

	m_pArea->m_align=m_cmbAlign.GetCurSel();

	btn=(CButton*)GetDlgItem(IDC_CHECK1);
	m_pArea->m_day_enable=btn->GetCheck();
	if (m_pArea->m_day_enable)
	{
		m_pArea->m_daycolor=m_btnYear.GetColor();
	} 

	btn=(CButton*)GetDlgItem(IDC_CHECK11);
	m_pArea->m_year_enable=btn->GetCheck();
	if (m_pArea->m_year_enable)
	{
		m_pArea->m_yearcolor=m_btnDate.GetColor();
	} 

	btn=(CButton*)GetDlgItem(IDC_CHECK13);
	m_pArea->m_solarterms_enable=btn->GetCheck();
	if (m_pArea->m_solarterms_enable)
	{
		m_pArea->m_solartermscolor=m_btnTime.GetColor();
	} 

	btn=(CButton*)GetDlgItem(IDC_CHECK10);
	m_pArea->m_text_enable=btn->GetCheck();
	if (m_pArea->m_text_enable)
	{
		GetDlgItem(IDC_EDIT1)->GetWindowText(m_pArea->m_statictext,sizeof(m_pArea->m_statictext));
		m_pArea->m_textcolor=m_btnText.GetColor();
	} 
	CDialogEx::OnOK();
}


BOOL CLunarAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(255-m_pArea->m_transparency);

	CString str;
	str.Format(_T("%d"),m_pArea->m_x);
	GetDlgItem(IDC_AREA_X)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_y);
	GetDlgItem(IDC_AREA_Y)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_w);
	GetDlgItem(IDC_AREA_W)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_h);
	GetDlgItem(IDC_AREA_H)->SetWindowText(str);


	m_bMultiLine=m_pArea->m_multiline;
	m_cmbFont.SelectFont(m_pArea->m_font);
	str.Format(_T("%d"),m_pArea->m_fontsize);
	GetDlgItem(IDC_EDIT15)->SetWindowText(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	btn->SetCheck(m_pArea->m_bold);
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	btn->SetCheck(m_pArea->m_italic);
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	btn->SetCheck(m_pArea->m_underline);

	m_cmbAlign.SetCurSel(m_pArea->m_align);

	btn=(CButton*)GetDlgItem(IDC_CHECK1);
	btn->SetCheck(m_pArea->m_day_enable);
	if (m_pArea->m_day_enable)
	{
		m_btnDate.SetColor(m_pArea->m_daycolor);
	} 
	else
	{
		m_btnDate.EnableWindow(FALSE);
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK11);
	btn->SetCheck(m_pArea->m_year_enable);
	if (m_pArea->m_year_enable)
	{
		m_btnYear.SetColor(m_pArea->m_yearcolor);
	} 
	else
	{
		m_btnYear.EnableWindow(FALSE);
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK13);
	btn->SetCheck(m_pArea->m_solarterms_enable);
	if (m_pArea->m_solarterms_enable)
	{
		m_btnTime.SetColor(m_pArea->m_solartermscolor);
	} 
	else
	{
		m_btnTime.EnableWindow(FALSE);
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK10);
	btn->SetCheck(m_pArea->m_text_enable);
	if (m_pArea->m_text_enable)
	{
		GetDlgItem(IDC_EDIT1)->SetWindowText(m_pArea->m_statictext);
		m_btnText.SetColor(m_pArea->m_textcolor);
	} 
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		m_btnText.EnableWindow(FALSE);
	}
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



void CLunarAreaDlg::OnBnClickedCheck1()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_MFCCOLORBUTTON2)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_MFCCOLORBUTTON2)->EnableWindow(FALSE);
	}

}


void CLunarAreaDlg::OnBnClickedCheck10()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK10);
	if (btn->GetCheck())
	{
			GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MFCCOLORBUTTON4)->EnableWindow(TRUE);
	} 
	else
	{
			GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MFCCOLORBUTTON4)->EnableWindow(FALSE);
	}
}


void CLunarAreaDlg::OnBnClickedCheck11()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK11);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_MFCCOLORBUTTON1)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_MFCCOLORBUTTON1)->EnableWindow(FALSE);
	}
}


void CLunarAreaDlg::OnBnClickedCheck13()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK13);
	if (btn->GetCheck())
	{
	
		GetDlgItem(IDC_MFCCOLORBUTTON3)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_MFCCOLORBUTTON3)->EnableWindow(FALSE);
	}
}


void CLunarAreaDlg::OnBnClickedMfccolorbutton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CLunarAreaDlg::OnEnChange4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CLunarAreaDlg::OnEnChange6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

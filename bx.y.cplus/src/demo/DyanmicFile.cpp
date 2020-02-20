// DyanmicFile.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "DyanmicFile.h"
#include "afxdialogex.h"
#include "ServerDlg.h"

extern TCHAR* PIC_ShowMode[];
DWORD g_hDynamicArea=0;
bool g_bRunDynamic=false;
HANDLE* g_thread_list=NULL;
int g_count;

// CDyanmicFile �Ի���

IMPLEMENT_DYNAMIC(CDyanmicFile, CDialogEx)

CDyanmicFile::CDyanmicFile(char* ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CDyanmicFile::IDD, pParent)
	, m_PlayRelation(0)
	, m_RunTime(0)
	, m_PageType(0)
	, m_X(0)
	, m_Y(0)
	, m_W(128)
	, m_H(96)
	, m_RelProgram(0)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}

CDyanmicFile::~CDyanmicFile()
{
}

void CDyanmicFile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_cmbRunMode);
	DDX_Control(pDX, IDC_COMBO8, m_cmbDisplayEffect);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Control(pDX, IDC_LIST1, m_PageList);
}


BEGIN_MESSAGE_MAP(CDyanmicFile, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CDyanmicFile::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDyanmicFile::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDyanmicFile::OnBnClickedButton5)
	ON_BN_CLICKED(IDOK, &CDyanmicFile::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDyanmicFile::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDyanmicFile::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CDyanmicFile ��Ϣ�������

BOOL CDyanmicFile::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cmbRunMode.AddString(_T("ѭ����ʾ"));
	m_cmbRunMode.AddString(_T("˳����ʾ,��ʾ�����һҳ��Ͳ�����ʾ"));
	m_cmbRunMode.AddString(_T("��ʾ��ɺ�ֹ��ʾ���һҳ����"));
	m_cmbRunMode.AddString(_T("ѭ����ʾ,�����趨ʱ���������δ����ʱɾ����̬����Ϣ"));
	m_cmbRunMode.AddString(_T("ѭ����ʾ,�����趨ʱ���������δ����ʱ����LOGOͼƬ"));

	for (int i=0;i<48;i++)
	{
		m_cmbDisplayEffect.AddString(PIC_ShowMode[i]);
	}

	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(0);

	CString str;

	for (int i=0;i<32;i++)
	{
		CString str;
		str.Format(_T("%d"),i);
		m_cmbAreaId.AddString(str);
	}
	m_cmbAreaId.SetCurSel(0);
	m_cmbRunMode.SetCurSel(0);

	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T("5"));
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDyanmicFile::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE,_T("bmp"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.bmp;*.jpg;*.png;*.gif)|*.bmp;*.jpg;*.png;*.gif||"));
	if(dlg.DoModal() == IDOK)
	{
		DynamicAreaFile unit;
		
		_tcscpy_s(unit.m_file_path,dlg.GetPathName());
		unit.m_display_effects=1;
		unit.m_display_speed=16;
		unit.m_stay_time=5;
		m_vecDynamicAreaFile.push_back(unit);
		int item=m_PageList.AddString(dlg.GetPathName());
		m_PageList.SetCurSel(item);
		OnLbnSelchangeList1();
	}
}


void CDyanmicFile::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDyanmicFile::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDyanmicFile::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CDyanmicFile::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CDyanmicFile::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

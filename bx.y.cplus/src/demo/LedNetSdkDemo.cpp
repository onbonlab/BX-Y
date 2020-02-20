
// LedNetSdkDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "LedNetSdkDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLedNetSdkDemoApp

BEGIN_MESSAGE_MAP(CLedNetSdkDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLedNetSdkDemoApp ����

CLedNetSdkDemoApp::CLedNetSdkDemoApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLedNetSdkDemoApp ����

CLedNetSdkDemoApp theApp;


// CLedNetSdkDemoApp ��ʼ��

BOOL CLedNetSdkDemoApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	strcpy(ftp_server_ip,"127.0.0.1");
	ftp_server_port=8888;
	strcpy(ftp_server_user,"guest");
	strcpy(ftp_server_pwd,"guest");
	m_bServerRun=false;
	CLedNetSdkDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

void CString2Char(CString str, char ch[])
{
#ifdef _UNICODE
	int i;
	char *tmpch;
	int wLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);//�õ�Char�ĳ���
	tmpch = new char[wLen + 1];                                             //��������ĵ�ַ��С
	WideCharToMultiByte(CP_ACP, 0, str, -1, tmpch, wLen, NULL, NULL);       //��CStringת����char*

	for(i = 0; tmpch[i] != '\0'; i++) ch[i] = tmpch[i];
	ch[i] = '\0';
	delete tmpch;
#else
	strcpy(ch,str.GetBuffer());
#endif
}

/*/////
pwstr ���뻺��
len   ���뻺�峤��
*/////
void Char2TCHAR(TCHAR *pwstr,const char *str)  
{  
#ifdef _UNICODE
	int widesize = ::MultiByteToWideChar(CP_ACP, 0, (const char *)str, -1, NULL, 0);  
	int convresult = ::MultiByteToWideChar(CP_UTF8, 0, (const char *)str, -1,pwstr, widesize);
#else
	strcpy(pwstr,str);
#endif
} 
CString GetErrText(int err)
{
	switch (err)
	{
	case ERR_OUTOFGROUP				:return _T("��������� ");
	case ERR_NOCMD					:return _T("��������� ");
	case ERR_BUSY					:return _T("������æ ");
	case ERR_MEMORYVOLUME			:return _T("�洢������Խ�� ");
	case ERR_CHECKSUM				:return _T("���ݰ� CRC У����� ");
	case ERR_FILENOTEXIST			:return _T("���ļ������� ");
	case ERR_FLASH					:return _T("Flash���ʴ��� ");
	case ERR_FILE_DOWNLOAD			:return _T("�ļ����ش��� ");
	case ERR_FILE_NAME				:return _T("�ļ������� ");
	case ERR_FILE_TYPE				:return _T("�ļ����ʹ��� ");
	case ERR_FILE_CRC16				:return _T("�ļ�У����� ");
	case ERR_FONT_NOT_EXIST			:return _T("�ֿ��ļ������� ");
	case ERR_FIRMWARE_TYPE			:return _T("Firmware ����������Ͳ�ƥ�� ");
	case ERR_DATE_TIME_FORMAT		:return _T("����ʱ���ʽ���� ");
	case ERR_FILE_EXIST				:return _T("���ļ��Ѵ��� ");
	case ERR_FILE_BLOCK_NUM			:return _T("�ļ� Block �Ŵ��� ");
	case ERR_CONTROLLER_TYPE		:return _T("���������Ͳ�ƥ�� ");
	case ERR_SCREEN_PARA			:return _T("����������Խ������ ");
	case ERR_CONTROLLER_ID			:return _T("��ȡ������ ID ���� ");
	case ERR_USER_SECRET			:return _T("ͨѶʱ�û�������� ");
	case ERR_OLD_SECRET				:return _T("�޸�����ʱ�������������� ");
	case ERR_PHY1_NO_SECRET			:return _T("ͨѶʱ�Լ��� 2 ��ʽ������ʾ����� PHY1 û���趨������");
	case ERR_PHY_USE_SECTET			:return _T("ͨѶʱ�Թ̶����� 1 ��ʽ������ʾ����� PHY1 û���趨������");
	case ERR_FILE_READ				:return _T("��ȡ�ļ�ʧ�� ");
	case ERR_XML_TOP				:return _T("��ȡ XML �ļ�����Ԫ��ʧ�� ");
	case ERR_DIR_NULL				:return _T("·������,��·�� ");
	case ERR_DIR_MK					:return _T("����·��ʧ�� ");
	case ERR_DIR_NOT_EXIST			:return _T("��·�������� ");
	case ERR_NOHEAD					:return _T("������ͷ�� ����ͷ����  ");
	case ERR_DISK_NAME				:return _T("���������ƴ��� ");
	case ERR_DISK_NOT_EXIST			:return _T("������������(���γ�����ж����)");
	case ERR_OPEN_FILE				:return _T("���ļ�ʧ�� ");
	case ERR_FILE_SEEK				:return _T("�ļ�ƫ�ƴ��� ");
	case ERR_CMD_UNFINISHED			:return _T("����δ��������� ,����ԭ����");
	case ERR_CMD_DBG				:return _T("������δ������ �������ڵ��Խ׶�");
	case ERR_CMD_NOT_SUPPORT		:return _T("�����֧�� ");
	case ERR_PERMISSIONS			:return _T("Ȩ�޲��� ");
	case ERR_UNLAWFUL_OPERATION		:return _T("�Ƿ����� ");
	case ERR_NO_RTC_CHIP			:return _T("�Ҳ��� RTC оƬ ");
	case ERR_APP_NUM				:return _T("�Ѿ���װ�� 5 �� app ��������ж��һ");
	case ERR_APP_NOT_EXIST			:return _T("������������� ");
	case ERR_APP_EXIST				:return _T("�Ѿ���װ������� ");
	case ERR_CMD_BUSY				:return _T("������æ (���������ʱ");
	case ERR_NO_LIST_PLAYING		:return _T("�����б�δ���� ");
	case ERR_NO_PROGRAM_PLAYING		:return _T("��ǰ�޽�Ŀ���� ");
	case ERR_APP_PATH				:return _T("·������ ");
	case ERR_MEMRY_USEOUT			:return _T("�������ڴ�ľ� ");
	case ERR_FTP_IP					:return _T("ftp �� ip ���ɴ� ");
	case ERR_USER_EXIST				:return _T("�Ѿ��д��û� ");
	case ERR_NOT_LOGIN				:return _T("δ��¼ ");
	case ERR_USER_NOT_EXIST			:return _T("�޴��û� ");
	case ERR_USER_PASSWORD			:return _T("������� ");
	case ERR_USER_ALREADY_LOGIN		:return _T("�Ѿ����û���¼ ");
	case ERR_PASSWORD_INCONSISTENT	:return _T("���벻һ�� ");
	case ERR_USER_NUM_MAX			:return _T("�û����� ");
	case ERR_USER_NAME_NULL			:return _T("�û���Ϊ�� ");
	case ERR_LOG_MODE				:return _T("�Ƿ���־ģʽ ");
	case ERR_READ_DIR				:return _T("��Ŀ¼ʧ�� ");
	case ERR_IP_FORMAT				:return _T("ip ��ʽ����");
	case ERR_NULL_TARGET			:return _T("FTP ����  Ŀ������Ϊ�� ");
	case ERR_NULL_PATH				:return _T("FTP ���� Ŀ��·��Ϊ�� ");
	case ERR_NULL_USER				:return _T("FTP ���� �û�Ϊ�� ");
	case ERR_NULL_IP				:return _T("FTP ���� �û�Ϊ�� ");
	case ERR_FONT_FORMAT			:return _T("�ֿ��ʽ���� ");
	case ERR_PROPERTY_NOT_EXIST		:return _T("���ʵ����Բ����� ");
	case ERR_PROPERTY_READONLY		:return _T("ֻ�����ԣ������޸�");
	
	case ERR_TIMEOUT				:return _T("ͨѶ��ʱ,�����������");
	case ERR_DiskSpace				:return _T("����������Ŀ¼�ռ䲻��");
	case ERR_Hand					:return _T("δ����ͨѶ����");
	case ERR_SCREENSIZE				:return _T("��Ļ���߲�����");
	case ERR_PATH					:return _T("������ļ�·��");
	case ERR_CMD					:return _T("���������");
	case ERR_PROPERTY				:return _T("�������������");
	case ERR_UPLOAD					:return _T("�ϴ�ʧ��");
	case ERR_TASKEXIST				:return _T("������зǿ�");
	case ERR_PARAM					:return _T("����������");
	case ERR_CANCEL					:return _T("���ͱ�ȡ��");
	case ERR_DOWNLOAD				:return _T("����������ʧ��");
	case ERR_PROGRAM_SIZE			:return _T("��Ŀ��С�����������������");
	case ERR_SENDHAND				:return _T("��Ч�ķ��;���������ѽ�����Ϊ��ʼ");
	case ERR_SENDCONNECT			:return _T("Ftp����ʧ��");
	default:return _T("δ֪����");
	}
	return 0;
}

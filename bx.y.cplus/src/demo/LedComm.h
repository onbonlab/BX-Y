#ifndef _LEDCOMMON_H

// ������
typedef enum SDK_ERR
{
	ERR_NO						=0x00,	//������ȷ��ɣ�û�д���

	ERR_OUTOFGROUP				=0x01,	//��������� 
	ERR_NOCMD					=0x02,	//��������� 
	ERR_BUSY					=0x03,	//������æ 
	ERR_MEMORYVOLUME			=0x04,	//�洢������Խ�� 
	ERR_CHECKSUM				=0x05,	//���ݰ� CRC У����� 
	ERR_FILENOTEXIST			=0x06,	//���ļ������� 
	ERR_FLASH					=0x07,	//Flash���ʴ��� 
	ERR_FILE_DOWNLOAD			=0x08,	//�ļ����ش��� 
	ERR_FILE_NAME				=0x09,	//�ļ������� 
	ERR_FILE_TYPE				=0x0a,	//�ļ����ʹ��� 
	ERR_FILE_CRC16				=0x0b,	//�ļ�У����� 
	ERR_FONT_NOT_EXIST			=0x0c,	//�ֿ��ļ������� 
	ERR_FIRMWARE_TYPE			=0x0d,	//Firmware ����������Ͳ�ƥ�� 
	ERR_DATE_TIME_FORMAT		=0x0e,	//����ʱ���ʽ���� 
	ERR_FILE_EXIST				=0x0f,	//���ļ��Ѵ��� 
	ERR_FILE_BLOCK_NUM			=0x10,	//�ļ� Block �Ŵ��� 
	ERR_CONTROLLER_TYPE			=0x11,	//���������Ͳ�ƥ�� 
	ERR_SCREEN_PARA				=0x12,	//����������Խ������ 
	ERR_CONTROLLER_ID			=0x13,	//��ȡ������ ID ���� 
	ERR_USER_SECRET				=0x14,	//ͨѶʱ�û�������� 
	ERR_OLD_SECRET				=0x15,	//�޸�����ʱ�������������� 
	ERR_PHY1_NO_SECRET			=0x16,	//ͨѶʱ�Լ��� 2 ��ʽ������ʾ����� PHY1 û���趨������
	ERR_PHY_USE_SECTET			=0x17,	//ͨѶʱ�Թ̶����� 1 ��ʽ������ʾ����� PHY1 û���趨������
	ERR_FILE_READ				=0x18,	//��ȡ�ļ�ʧ�� 
	ERR_XML_TOP					=0x19,	//��ȡ XML �ļ�����Ԫ��ʧ�� 
	ERR_DIR_NULL				=0x1a,	//·������,��·�� 
	ERR_DIR_MK					=0x1b,	//����·��ʧ�� 
	ERR_DIR_NOT_EXIST			=0x1c,	//��·�������� 
	ERR_NOHEAD					=0x1d,	//������ͷ�� ����ͷ����  
	ERR_DISK_NAME				=0x1e,	//���������ƴ��� 
	ERR_DISK_NOT_EXIST			=0x1f,	//������������(���γ�����ж����)
	ERR_OPEN_FILE				=0x20,	//���ļ�ʧ�� 
	ERR_FILE_SEEK				=0x21,	//�ļ�ƫ�ƴ��� 
	ERR_CMD_UNFINISHED			=0x22,	//����δ��������� ,����ԭ����
	ERR_CMD_DBG					=0x23,	//������δ������ �������ڵ��Խ׶�
	ERR_CMD_NOT_SUPPORT			=0x24,	//�����֧�� 
	ERR_PERMISSIONS				=0x25,	//Ȩ�޲��� 
	ERR_UNLAWFUL_OPERATION		=0x26,	//�Ƿ����� 
	ERR_NO_RTC_CHIP				=0x27,	//�Ҳ��� RTC оƬ 
	ERR_APP_NUM					=0x28,	//�Ѿ���װ�� 5 �� app ��������ж��һ
	ERR_APP_NOT_EXIST			=0x29,	//������������� 
	ERR_APP_EXIST				=0x2a,	//�Ѿ���װ������� 
	ERR_CMD_BUSY				=0x2b,	//������æ (���������ʱ
	ERR_NO_LIST_PLAYING			=0x2c,	//�����б�δ���� 
	ERR_NO_PROGRAM_PLAYING		=0x2d,	//��ǰ�޽�Ŀ���� 
	ERR_APP_PATH				=0x2e,	//·������ 
	ERR_MEMRY_USEOUT			=0x2f,	//�������ڴ�ľ� 
	ERR_FTP_IP					=0x30,	//ftp �� ip ���ɴ� 
	ERR_USER_EXIST				=0x31,	//�Ѿ��д��û� 
	ERR_NOT_LOGIN				=0x32,	//δ��¼ 
	ERR_USER_NOT_EXIST			=0x33,	//�޴��û� 
	ERR_USER_PASSWORD			=0x34,	//������� 
	ERR_USER_ALREADY_LOGIN		=0x35,	//�Ѿ����û���¼ 
	ERR_PASSWORD_INCONSISTENT	=0x36,	//���벻һ�� 
	ERR_USER_NUM_MAX			=0x37,	//�û����� 
	ERR_USER_NAME_NULL			=0x38,	//�û���Ϊ�� 
	ERR_LOG_MODE				=0x39,	//�Ƿ���־ģʽ 
	ERR_READ_DIR				=0x3a,	//��Ŀ¼ʧ�� 
	ERR_IP_FORMAT				=0x3b,	//ip ��ʽ����
	ERR_NULL_TARGET				=0x3c,	//FTP ����  Ŀ������Ϊ�� 
	ERR_NULL_PATH				=0x3d,	//FTP ���� Ŀ��·��Ϊ�� 
	ERR_NULL_USER				=0x3e,	//FTP ���� �û�Ϊ�� 
	ERR_NULL_IP					=0x3f,	//FTP ���� �û�Ϊ�� 
	ERR_FONT_FORMAT				=0x40,	//�ֿ��ʽ���� 
	ERR_PROPERTY_NOT_EXIST		=0x41,	//���ʵ����Բ����� 
	ERR_PROPERTY_READONLY		=0x42,	//ֻ�����ԣ������޸�
	ERR_NOSTORAGE				=0xFE,	//û�д洢����
	ERR_Unknow					=0x0100,//δ֪����
	ERR_TIMEOUT					=0x0101,//ͨѶ��ʱ,�����������
	ERR_DiskSpace				=0x0102,//����������Ŀ¼�ռ䲻��
	ERR_Hand					=0x0103,//δ����ͨѶ����
	ERR_SCREENSIZE				=0x0104,//��Ļ���߲�����
	ERR_PATH					=0x0105,//������ļ�·��
	ERR_CMD						=0x0106,//���������
	ERR_PROPERTY				=0x0107,//�������������
	ERR_UPLOAD					=0x0108,//�ϴ�ʧ��
	ERR_TASKEXIST				=0x0109,//������зǿ�
	ERR_PARAM					=0x010a,//����������
	ERR_CANCEL					=0x010b,//���ͱ�ȡ��
	ERR_DOWNLOAD				=0x010c,//����������ʧ��
	ERR_PROGRAM_SIZE			=0x010d,//��Ŀ��С�����������������
	ERR_SENDHAND				=0x010e,//��Ч�ķ��;���������ѽ�����Ϊ��ʼ
	ERR_SENDCONNECT				=0x010f,//��Ч�ķ��;���������ѽ�����Ϊ��ʼ
}sdk_err;


  
typedef enum ONBON_YQ_CARD_TYPE
{
	BX_Y0,
	BX_Y2,
	BX_Y2L,
	BX_Y3,
	
}onbon_yq_card_type;

//�ؼ�����
enum TransitionMode {
	eNone=0,					//���ٴ��		
	eRandom, 					//���			
	eStatic, 					//��ֹ��ʾ		
	ePushUp, 					//��������		
	ePushDown, 					//��������		
	ePushLeft, 					//��������		
	ePushRight, 				//��������		
	eSlideInFromTop, 			//��������		
	eSlideInFromBottom, 		//��������		
	eSlideInFromLeft,			//��������		
	eSlideInFromRight, 			//��������		
	eBuildUpFromUp, 			//���϶ѻ�		
	eBuildUpFromDown, 			//���¶ѻ�		
	eBuildUpFromLeft, 			//����ѻ�		
	eBuildUpFromRight,			//���Ҷѻ�		
	eRevealFromBottom, 			//������Ļ		
	eRevealFromUp, 				//������Ļ		
	eRevealFromRight,			//������Ļ		
	eRevealFromLeft, 			//������Ļ
	eRevealFromTopLeft, 		//���Ͻ���Ļ		
	eRevealFromTopRight,		//���Ͻ���Ļ		
	eRevealFromBottomLeft,		//���½���Ļ		
	eRevealFromBottomRight,		//���½���Ļ		
	eRevealInToCentre,			//������������Ļ	
	eFourCornerIn,				//���Ľ���Ļ����	
	eFourCornerOut,				//���Ľ���Ļ�˳�	
	eBarsFromBothSides,			//���ҽ�����Ļ	
	eBarsFromTopAndBottom, 		//���½�����Ļ			
	eBlindVertically,			//��ֱ��Ҷ		
	eBlindHorizontally,			//ˮƽ��Ҷ		
	eSlindInFromTopAndBottom,	//���±պ�		
	eRevealFromMiddle,			//���¶Կ�		
	eRevealOutFromMiddle,		//���ҿ�Ļ		
	eRevealInFromSides, 		//���ұպ�		
	eExpandOutFromCentre,		//���ķŴ�			
	eRandomSquaresAppear, 		//������	
	eFade,						//���뵭��		
	eExpandFromLeft, 			//��������		
	eBoxLineWipe,				//��в���		
	eWipeBox,					//���Ӳ���		
	eZoomOut,					//������С		
	eZoomOut_tail,				//������С			
	eLeftRollIn,				//�����			
	eRightRollIn, 				//�ҹ���		
	eContinuousPushUp,			//��������		
	eContinuousPushDown,		//��������		
	eContinuousPushLeft, 		//��������		
	eContinuousPushRight, 		//��������	

};


#endif
	




#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN           

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS     

#define _AFX_ALL_WARNINGS

#include <afxwin.h>         
#include <afxext.h>         


#include <afxdisp.h>       
#include <cstring>
#include <iostream>
using namespace  std;


#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>          
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             
#endif 

#ifdef _UNICODE  
typedef wstring tstring;
#define _TEXT_CHAR	wchar_t
#define _TEXT_T(x)	L ## x
#else  
typedef string tstring;
#define _TEXT_CHAR	char
#define _TEXT_T(x)	x	
#endif  
#include <afxcontrolbars.h>     
#include "..\\include\\\YQNetCom.h"
#include "LedComm.h"
#pragma comment( lib, "gdiplus.lib" )
#include "gdiplus.h"
using namespace Gdiplus;

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#endif

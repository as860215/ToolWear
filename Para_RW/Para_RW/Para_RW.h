
// Para_RW.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CPara_RWApp:
// �аѾ\��@�����O�� Para_RW.cpp
//

class CPara_RWApp : public CWinApp
{
public:
	CPara_RWApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CPara_RWApp theApp;
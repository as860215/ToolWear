// EZSocket2.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include "EZSocketNc.h"
#include "EZSocketNcDef.h"
#include "EZSocketNcErr.h"
#include "EZSocketNcStr.h"

extern "C" __declspec(dllexport) int __stdcall GetPLCMemory(int iPLCAddr)
{
	int iRet = -1;
	long lRet;
	DWORD dwLength = 1;
	LPCOLESTR lppcwszDevice;
	DWORD lpdwLength;
	CLSID clsid;
	LPCOLESTR lpcwszIPAddress = L"192.168.11.216";
	LONG lPort = 683;
	LONG plRet;
	LONG lSystemType = EZNC_SYS_MELDAS800M;
	LONG lMachine = 1;
	LONG lTimeOut = 100;  // (unit: 100 ms)
	DWORD* lppdwValue;
	DWORD lpdwDataType;
	DWORD lpdwValue;
	
	if (iPLCAddr == 1301) lppcwszDevice = L"M1301";
	if (iPLCAddr == 1302) lppcwszDevice = L"M1302";
	if (iPLCAddr == 1303) lppcwszDevice = L"M1303";
	if (iPLCAddr == 1304) lppcwszDevice = L"M1304";
	if (iPLCAddr == 1305) lppcwszDevice = L"M1305";
	if (iPLCAddr == 1306) lppcwszDevice = L"M1306";
	if (iPLCAddr == 1307) lppcwszDevice = L"M1307";
	if (iPLCAddr == 1308) lppcwszDevice = L"M1308";
	if (iPLCAddr == 1309) lppcwszDevice = L"M1309";
	if (iPLCAddr == 1310) lppcwszDevice = L"M1310";
	if (iPLCAddr == 1321) lppcwszDevice = L"M1321";
	if (iPLCAddr == 1322) lppcwszDevice = L"M1322";
	if (iPLCAddr == 1323) lppcwszDevice = L"M1323";
	if (iPLCAddr == 1324) lppcwszDevice = L"M1324";
	if (iPLCAddr == 1325) lppcwszDevice = L"M1325";
	if (iPLCAddr == 1326) lppcwszDevice = L"M1326";
	if (iPLCAddr == 1327) lppcwszDevice = L"M1327";
	if (iPLCAddr == 1328) lppcwszDevice = L"M1328";
	if (iPLCAddr == 1329) lppcwszDevice = L"M1329";
	if (iPLCAddr == 1330) lppcwszDevice = L"M1330";
	if (iPLCAddr == 1381) lppcwszDevice = L"M1381";

	lpdwDataType = EZNC_PLC_BIT;
	lRet = CoInitialize(NULL);
	IEZNcCommunication3* m_pezComm;
	IEZNcDevice* m_pezDevice;

	CLSIDFromProgID(L"EZSocketNc.EZNcCommunication",&clsid);
	lRet = CoCreateInstance(clsid,NULL,CLSCTX_INPROC_SERVER,IID_IEZNcCommunication3,(void**)&m_pezComm);
	lRet = m_pezComm->QueryInterface(IID_IEZNcDevice,(void**)&m_pezDevice);
	lRet = m_pezComm -> SetTCPIPProtocol(lpcwszIPAddress, lPort, &plRet);
	lRet = m_pezComm -> Open2(lSystemType, lMachine, lTimeOut, &plRet);
	if (lRet == 0)
	{

		lRet = m_pezComm -> SetHead(1, &plRet);
		lRet = m_pezDevice->SetDevice(dwLength, &lppcwszDevice, &lpdwDataType, &lpdwValue, &plRet);
		lRet = m_pezDevice->ReadDevice(&lpdwLength, &lppdwValue, &plRet);
		lRet = m_pezDevice->DeleteDeviceAll(&plRet);
		if (*lppdwValue == 0) iRet = 0;
		if (*lppdwValue == 1) iRet = 1;
		lpdwLength = NULL;
		CoTaskMemFree(lppdwValue);
		lppdwValue = NULL;
		m_pezComm -> Close(&lRet);
	}
	m_pezDevice -> Release();
	m_pezDevice = NULL;
	m_pezComm -> Release();
	m_pezComm = NULL;
	CoUninitialize( );

	return iRet;
}

extern "C" __declspec(dllexport) int __stdcall SetPLCMemory(int iPLCAddr, int iValue)
{
	int iRet = -1;
	long lRet;
	DWORD dwLength = 1;
	LPCOLESTR lppcwszDevice;
	CLSID clsid;
	LPCOLESTR lpcwszIPAddress = L"192.168.11.216";
	LONG lPort = 683;
	LONG plRet;
	LONG lSystemType = EZNC_SYS_MELDAS800M;
	LONG lMachine = 1;
	LONG lTimeOut = 100;  // (unit: 100 ms)
	//DWORD* lppdwValue;
	DWORD lpdwDataType;
	DWORD lpdwValue;
	
	if (iPLCAddr == 1301) lppcwszDevice = L"M1301";
	if (iPLCAddr == 1302) lppcwszDevice = L"M1302";
	if (iPLCAddr == 1303) lppcwszDevice = L"M1303";
	if (iPLCAddr == 1304) lppcwszDevice = L"M1304";
	if (iPLCAddr == 1305) lppcwszDevice = L"M1305";
	if (iPLCAddr == 1306) lppcwszDevice = L"M1306";
	if (iPLCAddr == 1307) lppcwszDevice = L"M1307";
	if (iPLCAddr == 1308) lppcwszDevice = L"M1308";
	if (iPLCAddr == 1309) lppcwszDevice = L"M1309";
	if (iPLCAddr == 1310) lppcwszDevice = L"M1310";
	if (iPLCAddr == 1321) lppcwszDevice = L"M1321";
	if (iPLCAddr == 1322) lppcwszDevice = L"M1322";
	if (iPLCAddr == 1323) lppcwszDevice = L"M1323";
	if (iPLCAddr == 1324) lppcwszDevice = L"M1324";
	if (iPLCAddr == 1325) lppcwszDevice = L"M1325";
	if (iPLCAddr == 1326) lppcwszDevice = L"M1326";
	if (iPLCAddr == 1327) lppcwszDevice = L"M1327";
	if (iPLCAddr == 1328) lppcwszDevice = L"M1328";
	if (iPLCAddr == 1329) lppcwszDevice = L"M1329";
	if (iPLCAddr == 1330) lppcwszDevice = L"M1330";
	if (iPLCAddr == 1381) lppcwszDevice = L"M1381";

	lpdwDataType = EZNC_PLC_BIT;
	lRet = CoInitialize(NULL);
	IEZNcCommunication3* m_pezComm;
	IEZNcDevice* m_pezDevice;

	CLSIDFromProgID(L"EZSocketNc.EZNcCommunication",&clsid);
	lRet = CoCreateInstance(clsid,NULL,CLSCTX_INPROC_SERVER,IID_IEZNcCommunication3,(void**)&m_pezComm);
	lRet = m_pezComm->QueryInterface(IID_IEZNcDevice,(void**)&m_pezDevice);
	lRet = m_pezComm -> SetTCPIPProtocol(lpcwszIPAddress, lPort, &plRet);
	lRet = m_pezComm -> Open2(lSystemType, lMachine, lTimeOut, &plRet);
	if (lRet == 0)
	{
		if (iValue == 0) lpdwValue = 0;
		if (iValue == 1) lpdwValue = 1;
		lRet = m_pezComm -> SetHead(1, &plRet);
		lRet = m_pezDevice->SetDevice(dwLength, &lppcwszDevice, &lpdwDataType, &lpdwValue, &plRet);
		lRet = m_pezDevice->WriteDevice(&plRet);
		if (lRet == 0) iRet = 1;
		lRet = m_pezDevice->DeleteDeviceAll(&plRet);

		if (iValue == 1)
		{
			Sleep(500);
			lpdwValue = 0;
			lRet = m_pezDevice->SetDevice(dwLength, &lppcwszDevice, &lpdwDataType, &lpdwValue, &plRet);
			lRet = m_pezDevice->WriteDevice(&plRet);
			lRet = m_pezDevice->DeleteDeviceAll(&plRet);
		}
		m_pezComm -> Close(&lRet);
	}
	m_pezDevice -> Release();
	m_pezDevice = NULL;
	m_pezComm -> Release();
	m_pezComm = NULL;
	CoUninitialize( );

	return iRet;
}


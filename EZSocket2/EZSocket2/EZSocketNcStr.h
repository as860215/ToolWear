/********************************************************************************/
/*																				*/
/*	<FILENAME>	EZSocketNcStr.h													*/
/*		EZSocketNcStr.h ｲﾝｸﾙｰﾄﾞﾌｧｲﾙ												*/
/*																				*/
/* Copyright (C) 2000-2014 MITSUBISHI Electric Corporation All Rights Reserved	*/
/********************************************************************************/
/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Sep 22 11:09:28 2008
 */
//@@MIDL_FILE_HEADING(  )

#ifndef __EZSocketNcStr_h__
#define __EZSocketNcStr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_EZSocketNcStr_0000 */
/* [local] */ 

typedef struct  EZNcStOpen
    {
    LONG lNetworkNumber;
    LONG lStationNumber;
    LONG lUnitNumber;
    LONG lConnectUnitNumber;
    LONG lIONumber;
    LONG lCpuType;
    LONG lUnitType;
    LONG lPacketType;
    LONG lProtocolType;
    LONG lPortNumber;
    LONG lBaudRate;
    LONG lDataBits;
    LONG lParity;
    LONG lStopBits;
    LONG lControl;
    /* [string] */ WCHAR __RPC_FAR *lpcwszHostAddress;
    LONG lCpuTimeOut;
    LONG lTimeOut;
    LONG lSumCheck;
    LONG lSourceNetworkNumber;
    LONG lSourceStationNumber;
    LONG lDestinationPortNumber;
    LONG lDestinationIONumber;
    LONG lConnectChannelNumber;
    LONG lMultiDropChannelNumber;
    LONG lThroughNetworkType;
    LONG lIntelligentPreferenceBit;
    LONG lDidPropertyBit;
    LONG lDsidPropertyBit;
    }	EZNCST_OPEN;



extern RPC_IF_HANDLE __MIDL_itf_EZSocketNcStr_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_EZSocketNcStr_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif

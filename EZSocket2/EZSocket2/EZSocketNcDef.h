/********************************************************************************/
/*																			    */
/*	<FILENAME>	EZSocketNcDef.h												    */
/*		Meldas用定義用ﾍｯﾀﾞﾌｧｲﾙ												    */
/*																			    */
/*																			    */
/* Copyright (C) 2000-2008 MITSUBISHI Electric Corporation All Rights Reserved	*/
/********************************************************************************/
//
/////////////////////////////////////////////////////////////////////////////
#ifndef __EZSOCKETNCDEF_H_
#define __EZSOCKETNCDEF_H_


#define EZ_TRUE					0x00000001
#define EZ_FALSE				0x00000000

#define EZNC_SYS_MAGICCARD64	0	// MELDASMAGIC Card64Ⅱ
#define EZNC_SYS_MAGICBOARD64	1	// MELDASMAGIC64
#define EZNC_SYS_MELDAS6X5L		2	// MELDAS600L(M6x5L)
#define EZNC_SYS_MELDAS6X5M		3	// MELDAS600M(M6x5M)
#define EZNC_SYS_MELDASC6C64	4	// MELDASC6C64
#define EZNC_SYS_MELDAS700L		5	// MELDAS700L
#define EZNC_SYS_MELDAS700M		6	// MELDAS700M
#define EZNC_SYS_MELDASC70		7	// MELDASC70
#define EZNC_SYS_MELDAS800L		8	// MELDAS800L
#define EZNC_SYS_MELDAS800M		9	// MELDAS800M

#define EZNC_PLCAXIS			255	// PLC軸指定

#define EZNC_MAINPRG			0	// ﾒｲﾝﾌﾟﾛｸﾞﾗﾑ
#define EZNC_SUBPRG				1	// ｻﾌﾞﾌﾟﾛｸﾞﾗﾑ

#define EZNC_MCODE1				0	// M指令1
#define EZNC_MCODE2				10	// M指令2
#define EZNC_MCODE3				20	// M指令3
#define EZNC_MCODE4				30	// M指令4
#define EZNC_SCODE1				1	// S指令1
#define EZNC_TCODE1				2	// T指令1
#define EZNC_BCODE1				3	// B指令1

#define EZNC_M					0	// M指令
#define EZNC_S					1	// S指令
#define EZNC_T					2	// T指令
#define EZNC_B					3	// B指令

#define EZNC_PRG_MAXNUM			0	// 登録可能な最大本数
#define EZNC_PRG_CURNUM			1	// 現在登録されている本数
#define EZNC_PRG_RESTNUM		2	// 登録可能な残本数
#define EZNC_PRG_CHARNUM		3	// 登録されている文字数
#define EZNC_PRG_RESTCHARNUM	4	// 登録可能な残文字数

#define EZNC_DISK_DIRTYPE		0x00010000	// ﾃﾞｨﾚｸﾄﾘ情報読み出し
#define EZNC_DISK_COMMENT		0x00000004	// ｺﾒﾝﾄ情報読み出し
#define EZNC_DISK_DATE			0x00000002	// 日付情報読み出し
#define EZNC_DISK_SIZE			0x00000001	// ｻｲｽﾞ情報読み出し

#define EZNC_COMMACT_TRUE		0x00000001	// 通信起動
#define EZNC_COMMACT_FALSE		0x00000000	// 通信停止

#define EZ_T_CHAR				VT_UI1		// VARIANT型ﾃﾞｰﾀﾀｲﾌﾟ(byte)
#define EZ_T_SHORT				VT_I2		//                  (short)
#define EZ_T_LONG				VT_I4		//                  (long)
#define EZ_T_DOUBLE				VT_R8		//	                (double)
#define EZ_T_STR				VT_BSTR		//                  (bstr)
#define EZ_T_DLONG				VT_BYREF	//					(void)

#define	M_ALM_ALL_ALARM			0x000		// アラーム種類の区別なし

#define	M_ALM_NC_ALARM			0x100		// NCアラーム
#define	M_ALM_STOP_CODE			0x200		// ストップコード
#define	M_ALM_PLC_ALARM			0x300		// PLCアラームメッセージ
#define	M_ALM_OPE_MSG			0x400		// オペレータメッセージ
#define	M_ALM_WARNING			0x500		// ワーニング


#define	M_ALM_NC_SYSTEM			0x101		// システムアラーム
#define	M_ALM_NC_SERVO			0x102		// サーボアラーム
#define	M_ALM_NC_MCP			0x103		// MCPアラーム
#define	M_ALM_NC_BASICPLC		0x104		// ベーシックPLCアラーム
#define	M_ALM_NC_USERPLC		0x105		// ユーザPLCアラーム
#define	M_ALM_NC_PROGRAM		0x106		// プログラムエラー
#define	M_ALM_NC_SERVO_WARNING	0x107		// サーボワーニング
#define	M_ALM_NC_MCP_WARNING	0x108		// MCPワーニング
#define	M_ALM_NC_SYSTEM_WARNING	0x109		// システムワーニング
#define	M_ALM_NC_OPERATION		0x10A		// オペレーションエラー
#define	M_ALM_OPE_ALARM			0x10B		// オペコンエラー

#define	EZNC_PLC_1SHOT			0x10
#define	EZNC_PLC_MODAL			0x20
#define	EZNC_PLC_BIT_FLG		0x01
#define	EZNC_PLC_BYTE_FLG		0x02
#define	EZNC_PLC_WORD_FLG		0x04
#define	EZNC_PLC_DWORD_FLG		0x08
#define	EZNC_PLC_BIT			(EZNC_PLC_BIT_FLG|EZNC_PLC_1SHOT)
#define	EZNC_PLC_BYTE			(EZNC_PLC_BYTE_FLG|EZNC_PLC_1SHOT)
#define	EZNC_PLC_WORD			(EZNC_PLC_WORD_FLG|EZNC_PLC_1SHOT)
#define	EZNC_PLC_DWORD			(EZNC_PLC_DWORD_FLG|EZNC_PLC_1SHOT)

//ファイルオープンモード
#define EZNC_FILE_INIT			0
#define EZNC_FILE_READ			1	//読み出しモード
#define EZNC_FILE_WRITE			2	//書き込みモード
#define EZNC_FILE_OVERWRITE 	3	//強制上書きモード

//ファイル書き込みモード
#define	EZNC_FILE_OPEN			1	//書き込みオープンモード
#define	EZNC_FILE_CREATE		2	//書き込み新規作成モード

#define	EZNC_FILE_MODE_UNNCPROGRAM	0		//OpenFile系でNCプログラム以外のオープンを示す。
#define	EZNC_FILE_MODE_NCPROGRAM	1		//OpenFile系でNCプログラムのオープンを示す。

#endif //__EZSOCKETNCDEF_H_

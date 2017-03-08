/************************************************

includeするヘッダファイルを管理するヘッダファイル
使いたいヘッダをincludeして、
ソースファイルとヘッダファイルをそれぞれ
Source Files と Header Filesに追加すればおｋ

************************************************/

#include <xc.h>
#define _XTAL_FREQ 32000000	// delay用に必要(クロック32MHzを指定)

#include "Interrupt_Timer0.h"	// タイマー０割り込み用ヘッダ
#include "skI2C.h"		// I2C用ヘッダ
#include "UART.h"		// UART用ヘッダ
#include "AD_converter.h"	// AD変換用ヘッダ
#include "Motor_Control.h"	// モータドライバ制御用ヘッダ
#include "UART.h"		// UART通信用ヘッダ


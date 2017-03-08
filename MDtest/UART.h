/*************************

URAT用ライブラリ関数プロトタイプ宣言

*************************/

#ifndef UART_H
#define UART_H

unsigned char RCV_Buff=0;   //データ格納変数
unsigned char UART_data;	    //受信データ

void UART_Init( void );					   //初期設定用関数
void UART_Interrupt( void );			   //UART受信用割り込み関数
void UART_Send(unsigned char send_data);   //送信用関数

#endif
/********************

モータドライバ用モータ制御関数
なるべくいじらないほうが良いかも

********************/

#include "GV.h"

//モータドライバを使用するためのレジスタ初期設定。
void FirstInit(void){
	OSCCON  = 0b01110000;	// 内部クロックは32ＭＨｚとする
	__delay_ms(10);			// 内部クロックの設定が終了まで待つ。10ms
	CM1CON0 = 0x00;			// コンパレータの設定
	CM1CON1 = 0x30;			// 同上
	TRISA   = 0b00000000;	// ポートの入出力の設定
	TRISB   = 0b00000000;	// 同上
	TRISC   = 0b00011000;	// 同上
	PORTA   = 0b00000000;	// 出力ピンの初期化(全てLOWにする)
	PORTB   = 0b00000000;	// 同上
	PORTC	= 0b00000000;	// 同上
}

void PWMInit(void)
{

//	CCPTMRS0 = (CCPTMRS0&0b11111100);
    CCPTMRS0 = 0b00000000;
	PR2 = 0xFF;
	T2CON	= 0b00000111;
	CCP1CON = 0b00001100;

//	PWM1CON = 0b00001111;
	PSTR1CON = 0b00000001;          // PWMはP1Aのみ
//	TRISB = (TRISB & 0b111101000);
//	TRISC = (TRISC & 0b111111011);
}

void PWMConfig(char turn,char pwm)
{
//turnのbit0下位2ビットが回転方向とか
//00:free
//01:forward
//10:reverse
//11:brake

//turnの上位2ビットがPWMの下位2ビット。
//pwmはpwmの上位8ビット。

	if(turn==0x03){
//		CCP1CON = 0b00001100;
		IN_PWM  = 0;
		IN_A    = 0;
		IN_B    = 0;
		EN      = 0;
		IN_PWM  = 0;
		IN_A    = 1;
		IN_B    = 1;
		EN      = 0;
		CCPR1L = 0x00;
	}
	else if(turn==0x01){
//        CCP1CON = 0b00001100;
        IN_PWM  = 0;//a
		IN_A    = 1;//b
		IN_B    = 0;//c
		EN      = 1;//d        
		CCPR1L = pwm;
	}
	else if(turn==0x02){
        IN_PWM  = 0;//a
		IN_A    = 0;//b
		IN_B    = 1;//c
		EN      = 1;//d        
		CCPR1L = pwm;
	}
	else{
//		CCP1CON = 0b00001100;
		IN_PWM  = 0;//a
		IN_A    = 0;//b
		IN_B    = 0;//c
		EN      = 0;//d
		CCPR1L = 0x00;
	}
}
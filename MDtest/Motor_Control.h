/*******************************

モータドライバ用モータ制御関数プロトタイプ宣言

*******************************/

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#define IN_PWM      RC2
#define IN_A        RB2
#define IN_B        RB1
#define EN          RB4
#define CS           
#define CS_RESO     130

void FirstInit(void);
void PWMConfig(char turn,char pwm);
void PWMInit(void);
char Get_CS(void);

/****************************************************************************************************************************************************

FirstInit()		ロボ研規格のBlueのドライバ用のGPIOとかの設定が入っている。main()のはじめに記述。
PWMConfig(*,*)	PWMConfig(aug1,aug2) と記述、aug1の下位2bitでモータの回転方向を決定　aug2は0~255(0xFF)までの値を取り、PWMのデューティが変わる
PWMInit()		ロボ研規格のBLueのドライバ用のPWM出力の設定が入っている。main()のはじめに記述。

******************************************************************************************************************************************************/

#endif
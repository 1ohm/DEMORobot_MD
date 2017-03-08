
#ifndef INTERRUPT_TIMER0_H
#define INTERRUPT_TIMER0_H  //多重読み込み防止の目印

#define TMR0VAL 131   //タイマー0　カウントレジスタの初期値
				      //プリスケーラレート64倍なので　
					  //(1 / 32M) * 4 * 64 [s]ごとに1カウントされる
					  //TMR0 > 255のときにTIMER0割り込みが発生するので	
					  //125 * 8[us] = 1[ms]ごとに割り込みが発生する。
			    	  //1[ms]ごとに発生が一番使いやすいと思うので、
					  //TMR0VALとOPTION_REGは変更しないことをお勧めする。
					  
void Timer0_Init( void );          //タイマ－０割り込みレジスタ初期設定関数					  
void Timer0_Interrupt( void );     //タイマー０割り込み

#endif // INTERRUPT_TIMER0_H

/////EOF/////
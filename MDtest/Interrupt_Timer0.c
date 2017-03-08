#include "GV.h"

void Timer0_Init( void )
{
	OPTION_REG = 0b00000101; //TIMER0レジスタの設定。プリスケーラレート 101 64倍
	GIE = 1; 			 	 //すべての割り込みを許可
	TMR0IE = 1; 			 //TIMER0割り込みを許可
	TMR0IF = 0; 			 //TIMER0割り込みフラグリセット	
}	

void Timer0_Interrupt( void )
{
     if(TMR0IF == 1){   //フラグON
		TMR0 = TMR0VAL; //カウントリセット
		TMR0IF = 0;	    //フラグリセット
	}					
}	
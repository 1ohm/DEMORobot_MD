////////////////////////////
//                        //
//Demmo MD test code      //
//      作成：SOEDA       //
//                        //
////////////////////////////

#include "GV.h"

// PIC16F1938 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), high trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


/*	メインの処理	*/
void main()
{
    FirstInit();	
	PWMInit();	
	ad_init();
    InitI2C_Slave(0x40);

    char speed;
    char cnt;

    for (cnt=0;cnt<3;cnt++){
        LATA3 = 1;
        __delay_ms(100);
        LATA3 = 0;
        __delay_ms(100);
    }

	/*******以下メインループ******/
	while(1)
	{
        snd_data[0] = rcv_data[0];
		speed = rcv_data[1];
		
		if(rcv_data[0] == 0x01){
			PWMConfig(0x01, speed);       //PWMConfig(0x　　01：前進　02：後進　03：ブレーキ 　　, デューティ比 )　　と設定
			LATA3 = 1;                   //デューティ比の値は0x00~0xFFの256段階。　参考までに、50%は0x80　70%は0xB2　75%は0xBF　80%は0xCC　
			LATA4 = 0;
		}
		else if(rcv_data[0] == 0x02){
			PWMConfig(0x02, speed);       //PWMConfig(0x　　01：前進　02：後進　03：ブレーキ 　　, デューティ比 )　　と設定
			LATA4 = 1;
			LATA3 = 0;
		}
        else if(rcv_data[0] == 0x03){
            PWMConfig(0x03, speed);
            LATA4 = 1;
            LATA3 = 1;
        }
		else{
			PWMConfig(0x00, 0x80);       //PWMConfig(0x　　01：前進　02：後進　03：ブレーキ 　　, デューティ比 )　　と設定
			LATA3 = 0;
			LATA4 = 0;
		}        
  	}	
}

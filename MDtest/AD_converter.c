#include "GV.h"


void ad_init(void) //初期化どのアナログピンを使用するかの指定。
{
	unsigned char AN_A,AN_B; //アナログ入力を行うピンを設定。
	
	AN_A = 0b001111; //アナログ入力を行うピンA（RA0-3、RA5）の指定。右から順にAN0,AN1,AN2,AN3一つ飛ばしてAN4
					 //サンプルではAは使わない。 基本、この値は初期設定して以後変更しない
					
	AN_B = 0x000000; //アナログ入力を行うピンB（RB0-5）の指定。右から順にAN12,AN10,AN8,AN9,AN11,AN13
					 //サンプルではAN8から読み込む。 基本、この値は初期設定して以後変更しない
	
	ANSELA = AN_A; //アナログ入力を行うピンA（RA0-3、RA5）の指定。右から順にAN0,AN1,AN2,AN3一つ飛ばしてAN4
	ANSELB = AN_B; //アナログ入力を行うピンB（RB0-5）の指定。右から順にAM12,AN10,AN8,AN9,AN11,AN13
	
	ADCON1 = 0b10010000; //0b1"110"0000の３ケタをいじってA/D変換を行う速度のクロックを設定 000:FOSC/2 001:FOSC/8 010:FOSC/32 100:FOSC/4 101:FOSC/16 110:FOSC/64
	__delay_ms(10);
}

unsigned char ad_get(unsigned char PIN)
{
	char conf;
	unsigned int temp;
	
	switch(PIN){
		case 0:	
				conf = 0b00000001; //0b0"01010"01の５ケタをいじって読み込むANピンを指定,AN0=00000,AN1=00001,AN2=00010...AN8=01000...AN13=01101
				break;
		case 1:	
				conf = 0b00000101; 
				break;
		case 2:	
				conf = 0b00001001; 
				break;
		case 3:	
				conf = 0b00001101; 
				break;
		case 4:	
				conf = 0b00010001; 
				break;
		case 8:	
				conf = 0b00100001; 
				break;
		case 9:	
				conf = 0b00100101; 
				break;
		case 10:	
				conf = 0b00101001; 
				break;
		case 11:	
				conf = 0b00101101; 
				break;
		case 12:	
				conf = 0b00110001; 
				break;
		case 13:	
				conf = 0b00110101; 
				break;
		default:
				conf = 0b00000000;   //ADC無効
				break;
	}
	
	if(ADCON0 != conf){
		ADCON0 = conf;
		__delay_ms(10);
	}	
	
    GO_nDONE = 1 ;	      // アナログ値読取り開始指示
    while(GO_nDONE) ;        // 読取り完了まで待つ
    temp = ADRESH ;
    temp = ( temp << 8 ) | ADRESL ;

	temp = temp >> 2;
	
    return temp ;
}


/////EOF/////
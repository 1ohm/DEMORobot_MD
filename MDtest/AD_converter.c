#include "GV.h"


void ad_init(void) //�������ǂ̃A�i���O�s�����g�p���邩�̎w��B
{
	unsigned char AN_A,AN_B; //�A�i���O���͂��s���s����ݒ�B
	
	AN_A = 0b001111; //�A�i���O���͂��s���s��A�iRA0-3�ARA5�j�̎w��B�E���珇��AN0,AN1,AN2,AN3���΂���AN4
					 //�T���v���ł�A�͎g��Ȃ��B ��{�A���̒l�͏����ݒ肵�ĈȌ�ύX���Ȃ�
					
	AN_B = 0x000000; //�A�i���O���͂��s���s��B�iRB0-5�j�̎w��B�E���珇��AN12,AN10,AN8,AN9,AN11,AN13
					 //�T���v���ł�AN8����ǂݍ��ށB ��{�A���̒l�͏����ݒ肵�ĈȌ�ύX���Ȃ�
	
	ANSELA = AN_A; //�A�i���O���͂��s���s��A�iRA0-3�ARA5�j�̎w��B�E���珇��AN0,AN1,AN2,AN3���΂���AN4
	ANSELB = AN_B; //�A�i���O���͂��s���s��B�iRB0-5�j�̎w��B�E���珇��AM12,AN10,AN8,AN9,AN11,AN13
	
	ADCON1 = 0b10010000; //0b1"110"0000�̂R�P�^����������A/D�ϊ����s�����x�̃N���b�N��ݒ� 000:FOSC/2 001:FOSC/8 010:FOSC/32 100:FOSC/4 101:FOSC/16 110:FOSC/64
	__delay_ms(10);
}

unsigned char ad_get(unsigned char PIN)
{
	char conf;
	unsigned int temp;
	
	switch(PIN){
		case 0:	
				conf = 0b00000001; //0b0"01010"01�̂T�P�^���������ēǂݍ���AN�s�����w��,AN0=00000,AN1=00001,AN2=00010...AN8=01000...AN13=01101
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
				conf = 0b00000000;   //ADC����
				break;
	}
	
	if(ADCON0 != conf){
		ADCON0 = conf;
		__delay_ms(10);
	}	
	
    GO_nDONE = 1 ;	      // �A�i���O�l�ǎ��J�n�w��
    while(GO_nDONE) ;        // �ǎ�芮���܂ő҂�
    temp = ADRESH ;
    temp = ( temp << 8 ) | ADRESL ;

	temp = temp >> 2;
	
    return temp ;
}


/////EOF/////
#include "GV.h"

void Timer0_Init( void )
{
	OPTION_REG = 0b00000101; //TIMER0���W�X�^�̐ݒ�B�v���X�P�[�����[�g 101 64�{
	GIE = 1; 			 	 //���ׂĂ̊��荞�݂�����
	TMR0IE = 1; 			 //TIMER0���荞�݂�����
	TMR0IF = 0; 			 //TIMER0���荞�݃t���O���Z�b�g	
}	

void Timer0_Interrupt( void )
{
     if(TMR0IF == 1){   //�t���OON
		TMR0 = TMR0VAL; //�J�E���g���Z�b�g
		TMR0IF = 0;	    //�t���O���Z�b�g
	}					
}	
/********************

���[�^�h���C�o�p���[�^����֐�
�Ȃ�ׂ�������Ȃ��ق����ǂ�����

********************/

#include "GV.h"

//���[�^�h���C�o���g�p���邽�߂̃��W�X�^�����ݒ�B
void FirstInit(void){
	OSCCON  = 0b01110000;	// �����N���b�N��32�l�g���Ƃ���
	__delay_ms(10);			// �����N���b�N�̐ݒ肪�I���܂ő҂B10ms
	CM1CON0 = 0x00;			// �R���p���[�^�̐ݒ�
	CM1CON1 = 0x30;			// ����
	TRISA   = 0b00000000;	// �|�[�g�̓��o�͂̐ݒ�
	TRISB   = 0b00000000;	// ����
	TRISC   = 0b00011000;	// ����
	PORTA   = 0b00000000;	// �o�̓s���̏�����(�S��LOW�ɂ���)
	PORTB   = 0b00000000;	// ����
	PORTC	= 0b00000000;	// ����
}

void PWMInit(void)
{

//	CCPTMRS0 = (CCPTMRS0&0b11111100);
    CCPTMRS0 = 0b00000000;
	PR2 = 0xFF;
	T2CON	= 0b00000111;
	CCP1CON = 0b00001100;

//	PWM1CON = 0b00001111;
	PSTR1CON = 0b00000001;          // PWM��P1A�̂�
//	TRISB = (TRISB & 0b111101000);
//	TRISC = (TRISC & 0b111111011);
}

void PWMConfig(char turn,char pwm)
{
//turn��bit0����2�r�b�g����]�����Ƃ�
//00:free
//01:forward
//10:reverse
//11:brake

//turn�̏��2�r�b�g��PWM�̉���2�r�b�g�B
//pwm��pwm�̏��8�r�b�g�B

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
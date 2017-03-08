
#ifndef INTERRUPT_TIMER0_H
#define INTERRUPT_TIMER0_H  //���d�ǂݍ��ݖh�~�̖ڈ�

#define TMR0VAL 131   //�^�C�}�[0�@�J�E���g���W�X�^�̏����l
				      //�v���X�P�[�����[�g64�{�Ȃ̂Ł@
					  //(1 / 32M) * 4 * 64 [s]���Ƃ�1�J�E���g�����
					  //TMR0 > 255�̂Ƃ���TIMER0���荞�݂���������̂�	
					  //125 * 8[us] = 1[ms]���ƂɊ��荞�݂���������B
			    	  //1[ms]���Ƃɔ�������Ԏg���₷���Ǝv���̂ŁA
					  //TMR0VAL��OPTION_REG�͕ύX���Ȃ����Ƃ������߂���B
					  
void Timer0_Init( void );          //�^�C�}�|�O���荞�݃��W�X�^�����ݒ�֐�					  
void Timer0_Interrupt( void );     //�^�C�}�[�O���荞��

#endif // INTERRUPT_TIMER0_H

/////EOF/////
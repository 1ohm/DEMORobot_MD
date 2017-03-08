#include "GV.h"

void UART_Init( void )
{
	//UART�Ɏg�p����ݒ背�W�X�^
	TXSTA = 0b00100100;		//���M���ݒ�
						    //Bit 7: �Ӗ��Ȃ�
							//Bit 6: 0=8�r�b�g�f�[�^�ő��M�i�p���e�B���j 1=9�r�b�g�f�[�^�ő��M�i�p���e�B�L�j
							//Bit 5: ���M���̃r�b�g 1�ɂ��ċ���
							//Bit 4: USART���[�h�̎w��@0�Ƃ��Ĕ񓯊����[�h��
							//Bit 3: �u���[�N�������M�w��r�b�g�@�ʏ��0
							//Bit 2: �����{�[���[�g�̎w��r�b�g�@�ʏ��1
						 	//Bit 1: ���M���W�X�^�̏�Ԃ𓾂�r�b�g 1���Ƌ� 0���Ɩ����M
						 	//Bit 0: �X�r�b�g�ڂ̃f�[�^�p

	RCSTA = 0b10010000;		//��M���ݒ�
							//Bit 7: �V���A���s���g�p�̎w��r�b�g 
							//		 1:�iRX:TX�j�̃s���̓V���A���|�[�g�Ƃ��Ďg�p����
							//		 0:�iRX:TX�j�̃s����I/O�|�[�g�Ƃ��Ďg�p����
							//Bit 6: 9�r�b�g�ł̎�M�w��|�[�g 0�Ƃ��ĂW�r�b�g�Ŏ�M����
							//Bit 5: �V�O�i����M���̎w��r�b�g�@�Ȃ��A�񓯊����[�h�ł͖��Ӗ�
							//Bit 4: �A����M���̎w��r�b�g �ʏ��1
							//Bit 3:�@RX9�iBit6�j��"1"�̎��A�A�h���X���o���r�b�g�̎w��r�b�g �ʏ��0
							//Bit 2:�@�t���[�~���O�G���[�̃X�e�[�^�X�r�b�g 
							//Bit 1:�@�I�[�o�[�����G���[�̃X�e�[�^�X�r�b�g 
							//Bit 0: �X�r�b�g�ڂ̃f�[�^�p
							
	SPBRG = 207;    //�{�[���[�g��9600�ɐݒ�  �ڂ����̓f�[�^�V�[�g229P
					//���� SYNC=0; BRGH=1; BRG16=0�Ȃ̂ŁA SPBRG=207�Ɛݒ肷��B
	ADDEN = 0;			
	
	TRISC = TRISC | 0b10000000;  //TX�i���M�j:RC6 RX(��M):RC7
	TRISC = TRISC & 0b10111111;
	
	__delay_ms(10);
	
	GIE = 1;  	//�S���荞�ݏ�������
	PEIE = 1; 	//���ӑ��u���荞�݂�L����
	RCIE = 1;   //UART�̊��荞�ݎ�M��L���ɂ���
	RCIF = 0;   //UAR���荞�ݎ�M�t���O��������
	
	__delay_ms(10);			
}	

void UART_Interrupt( void )
{
	if(RCIF == 1){   //UART�̒ʐM�Ŋ��荞�݂�����
		RCIF = 0;
		RCV_Buff = RCREG;  //��M�f�[�^���i�[
		
		if('a' <= RCV_Buff && RCV_Buff <= 'z'){   //RCREG�͑��M������ƂȂ���0x0A���i�[����Ă��܂�
			UART_data = RCV_Buff;      			  //�̂Ɏ󂯎�����u�Ԃɕʂ̕ϐ��Ɋi�[���邩�A�t���O���Ă邩������Ɨǂ�
		}
	}			
}

void UART_Send(unsigned char send_data)
{
	TXEN = 1;			//���M����
	TXREG = send_data;	//���M�f�[�^
	__delay_ms(1);		//���M�p�f�B���C
//	TXEN = 0;			//���M�֎~
	TXIF = 1;			//�t���O���N���A
}	
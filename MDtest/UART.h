/*************************

URAT�p���C�u�����֐��v���g�^�C�v�錾

*************************/

#ifndef UART_H
#define UART_H

unsigned char RCV_Buff=0;   //�f�[�^�i�[�ϐ�
unsigned char UART_data;	    //��M�f�[�^

void UART_Init( void );					   //�����ݒ�p�֐�
void UART_Interrupt( void );			   //UART��M�p���荞�݊֐�
void UART_Send(unsigned char send_data);   //���M�p�֐�

#endif
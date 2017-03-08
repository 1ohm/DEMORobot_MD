/*******************************

���[�^�h���C�o�p���[�^����֐��v���g�^�C�v�錾

*******************************/

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#define IN_PWM      RC2
#define IN_A        RB2
#define IN_B        RB1
#define EN          RB4
#define CS           
#define CS_RESO     130

void FirstInit(void);
void PWMConfig(char turn,char pwm);
void PWMInit(void);
char Get_CS(void);

/****************************************************************************************************************************************************

FirstInit()		���{���K�i��Blue�̃h���C�o�p��GPIO�Ƃ��̐ݒ肪�����Ă���Bmain()�̂͂��߂ɋL�q�B
PWMConfig(*,*)	PWMConfig(aug1,aug2) �ƋL�q�Aaug1�̉���2bit�Ń��[�^�̉�]����������@aug2��0~255(0xFF)�܂ł̒l�����APWM�̃f���[�e�B���ς��
PWMInit()		���{���K�i��BLue�̃h���C�o�p��PWM�o�͂̐ݒ肪�����Ă���Bmain()�̂͂��߂ɋL�q�B

******************************************************************************************************************************************************/

#endif

#ifndef AD_CONVERTER_H  
#define AD_CONVERTER_H

void ad_init(void); // AD変換の設定。主にどのアナログピンを使用するかの指定。
extern unsigned char ad_get(unsigned char); //　アナログ値の読み込みと変換関数

#endif

/////EOF/////
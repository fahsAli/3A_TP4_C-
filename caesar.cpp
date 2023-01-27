#include "caesar.h"

caesar::Caesar::Caesar(int shift,std::string plain){
    _plain=plain;
    _shift=shift;
}


void caesar::Caesar::encode(){
    std::string str;
    int num=0;
    for(int i=0;i<_plain.length();i++){
        if(std::isalpha(_plain[i])){
            num = _plain[i] + _shift;
            if(num>'z'){
                num -= 26;
            }
            str = str + char(num);
        }else{
            str = str + _plain[i];
        }
    }
    _cipher = str;
}

void caesar::Caesar::decode(){
    std::string str;
    int num=0;
    for(int i=0;i<_cipher.length();i++){
        if(std::isalpha(_cipher[i])){
            num = _cipher[i] - _shift;
            if(num<'a'){
                num += 26;
            }
            str = str + char(num);
        }else{
            str = str + _cipher[i];
        }
    }
    _plain = str;
}
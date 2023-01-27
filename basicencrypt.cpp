#include "basicencrypt.h"

basicencrypt::BasicEncrypt::BasicEncrypt(std::string plain){
    _plain = plain;
}

void basicencrypt::BasicEncrypt::encode(){
    _cipher = _plain;
}

void basicencrypt::BasicEncrypt::decode(){
    _plain = _cipher;
}


#include "encrypt.h"

std::string encrypt::Encrypt::plain() const{
    return _plain;
}

std::string encrypt::Encrypt::cipher() const{
    return _cipher;
}
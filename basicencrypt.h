#pragma once
#ifndef BASIC_ENCRYPT_HEADER
#define BASIC_ENCRYPT_HEADER
#include <string>
#include "encrypt.h"

namespace basicencrypt{
    class BasicEncrypt : public encrypt::Encrypt{
        public:
            BasicEncrypt(std::string plain="null");
            void encode();
            void decode();
    };

}

#endif
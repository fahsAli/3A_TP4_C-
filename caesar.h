#pragma once
#ifndef CAESAR_HEADER
#define CAESAR_HEADER

#include <string>
#include <cctype>
#include "encrypt.h"

namespace caesar{
    class Caesar : public encrypt::Encrypt{
        public:
            Caesar(int shift=3,std::string plain="null");

            void encode() override;
            void decode() override;

        private:
            int _shift;
    };
}

#endif
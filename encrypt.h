#pragma once
#ifndef ENCRYPT_HEADER
#define ENCRYPT_HEADER
#include <string>

namespace encrypt{
    class Encrypt{
        public:
            std::string plain() const;
            std::string cipher() const;

            virtual void encode()=0;
            virtual void decode()=0;

        protected:
            std::string _plain;
            std::string _cipher;            
    };

}

#endif
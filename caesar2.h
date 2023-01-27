#pragma once
#ifndef CAESAR2_HEADER
#define CAESAR2_HEADER

#include <string>
#include <cctype>
#include <fstream>
#include "encrypt.h"

namespace caesar2{
    class Caesar2 : public encrypt::Encrypt{
        public:
            Caesar2(int shift=3,std::string plain="null");
            int shift() const;

            void shift(int shift);

            void encode() override;
            void decode() override;

            void getPlainFromFile();
            void getCipherFromFile();

            void uploadPlain();
            void uploadCipher();

        private:
            int _shift;
    };
    std::string getElement(std::string str,int index);
    int countLines(std::string fname);
}

#endif
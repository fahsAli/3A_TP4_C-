#pragma once
#ifndef VIGENERE_HEADER
#define VIGENERE_HEADER

#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include "encrypt.h"


namespace vigenere{
    class Vigenere : public encrypt::Encrypt{
        public:
            Vigenere(std::string key,std::string plain="");
            Vigenere(std::vector <int> key,std::string plain="");

            std::vector <int> key() const;
            std::string vecTostr();

            void key(std::string key);
            void key(std::vector <int> key);

            void encode() override;
            void decode() override;

            void uploadPlain();
            void uploadCipher();

            void getPlainFromFile();
            void getCipherFromFile();

        private:
        std::vector <int> _key;
    };
    std::string getElement(std::string str,int index);
    int countLines(std::string fname);
    char shift(char c,int shift);
    char shiftBack(char c,int shift);
}
std::ostream& operator<<(std::ostream& os,std::vector <int> v);

#endif
#include <iostream>
#include "encrypt.h"
#include "basicencrypt.h"
#include "caesar.h"
#include "caesar2.h"
#include "vigenere.h"

int main(){

    std::cout << "************CAESAR**************" << std::endl;

    caesar2::Caesar2 c(4,"Ali");
    c.encode();
    c.decode();
    std::cout << "cipher key 4 : " << c.cipher() << std::endl;
    std::cout <<  "plain key 4 : " << c.plain() << std::endl;

    caesar2::Caesar2 c2(3);
    //get plain from plain.txt
    c2.getPlainFromFile();
    c2.encode();

    //upload to a cipher.txt
    c2.uploadCipher();

    //get from cipher.txt and use same key "4"
    c2.getCipherFromFile();
    c2.decode();

    std::cout << "plain : " << c2.plain() << std::endl;
    std::cout << "shift : " << c2.shift() << std::endl;
    std::cout << "cipher : " << c2.cipher() << std::endl;

    std::cout << "************VIGENERE**************" << std::endl;
    
    vigenere::Vigenere v("abc");
    //get plain from plain.txt
    v.getPlainFromFile();
    v.encode();

    //upload to cipher.txt
    v.uploadCipher();

    //get from cipher.txt and use same key "4"
    v.getCipherFromFile();
    v.decode();

    std::cout << "plain : " << v.plain() << std::endl;
    std::cout << "shift : " << v.key();
    std::cout << "cipher : " << v.cipher() << std::endl;
}
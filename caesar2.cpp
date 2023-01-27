#include "caesar2.h"


caesar2::Caesar2::Caesar2(int shift,std::string plain){
    _plain=plain;
    _shift=shift;
}

int caesar2::Caesar2::shift() const{
    return _shift;
}

void caesar2::Caesar2::shift(int shift){
    _shift = shift;
}

void caesar2::Caesar2::encode(){
    std::string str;
    int num=0;
    for(int i=0;i<_plain.length();i++){
        num = _plain[i] + _shift;
        if(_plain[i]=='\n'){
            num = _plain[i];
        }else if(((std::isupper(_plain[i]))&&(num>'Z'))||((std::islower(_plain[i]))&&(num>'z'))){
            num -= 26;
        }
        str = str + char(num);
    }
    _cipher = str;
}

void caesar2::Caesar2::decode(){
    std::string str;
    int num=0;
    for(int i=0;i<_cipher.length();i++){
        num = _cipher[i] - _shift;
        if(_cipher[i]=='\n'){
            num = _plain[i];
        }else if(((std::isupper(_cipher[i]))&&(num<'A'))||((std::islower(_cipher[i]))&&(num<'a'))){
            num += 26;
        }
        str = str + char(num);
    }
    _plain = str;
}

int caesar2::countLines(std::string fname){
    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile(fname);

    while (std::getline(myfile, line)){
        ++number_of_lines;
    }

    return number_of_lines;
}

std::string caesar2::getElement(std::string str,int index){
    int flag=0;
    std::string elem="";
    for(int i=0;i<str.length();i++){
        if((str[i]==']')&&(flag==index)){
            break;
        }
        if(flag==index){
            elem = elem + str[i];
        }
        if(str[i]=='['){
            flag++;
        }
    }
    return elem;
}



void caesar2::Caesar2::uploadPlain(){
    std::fstream file;
    file.open("plain.txt", std::ios::out);
    if(file.is_open()){
        file << _plain + "\n";
    }
    file.close();
}

void caesar2::Caesar2::uploadCipher(){
    std::fstream file;
    file.open("cipher.txt", std::ios::out);
    if(file.is_open()){
        file << _cipher + "\n";
    }
    file.close();
}

void caesar2::Caesar2::getCipherFromFile(){
    std::fstream file;
    std::string line="",key="";
    _cipher = "";
    file.open("cipher.txt",std::ios::in);
    if(file.is_open()){
        while(std::getline(file,line)){
            _cipher = _cipher + line;
        }
    }
}

void caesar2::Caesar2::getPlainFromFile(){
    std::fstream file;
    std::string line="";
    _plain = "";
    file.open("plain.txt",std::ios::in);
    if(file.is_open()){
        while(std::getline(file,line)){
            _plain = _plain + line + "\n";
        }
    }
}
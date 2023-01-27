#include "vigenere.h"

vigenere::Vigenere::Vigenere(std::vector <int> key,std::string plain){
    _key = key;
    _plain = plain;
}

vigenere::Vigenere::Vigenere(std::string key,std::string plain){
    _plain = plain;
    this->key(key);
}

std::vector <int> vigenere::Vigenere::key() const{
    return _key;
}

void vigenere::Vigenere::key(std::string key){
    for(int i=0;i<key.length();i++){
        if(std::isupper(key[i])){
            _key.push_back((key[i]-'A'+1));
        }else if(std::islower(key[i])){
            _key.push_back((key[i]-'a'+1));
        }
    }
}

void vigenere::Vigenere::key(std::vector <int> key){
    _key = key;
}

char vigenere::shift(char c,int shift){
    int num= c + shift;
    if(c =='\n'){
        num = c;
    }else if(((std::isupper(c))&&(num>'Z'))||((std::islower(c))&&(num>'z'))){
        num -= 26;
    }
    return char(num);
}

char vigenere::shiftBack(char c,int shift){
    int num=0;
    num = c - shift;
    if(c=='\n'){
        num = c;
    }else if(((std::isupper(c))&&(num<'A'))||((std::islower(c))&&(num<'a'))){
        num += 26;
    }
    return char(num);
}

std::string vigenere::Vigenere::vecTostr(){
    std::string str="";
    for(auto it :_key){
        str = str + char('a'+it-1);
    }
    return str;
}

int vigenere::countLines(std::string fname){
    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile(fname);

    while (std::getline(myfile, line)){
        ++number_of_lines;
    }

    return number_of_lines;
}

std::string vigenere::getElement(std::string str,int index){
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


void vigenere::Vigenere::encode(){
    _cipher = "";
    for(int i=0;i<_plain.length();i++){
        _cipher = _cipher + vigenere::shift(_plain[i],_key.at(i%_key.size()));
    }
}

void vigenere::Vigenere::decode(){
    _plain = "";
    for(int i=0;i<_cipher.length();i++){
        _plain = _plain + vigenere::shiftBack(_cipher[i],_key.at(i%_key.size()));
    }
}

void vigenere::Vigenere::uploadPlain(){
    std::fstream file;
    file.open("plain.txt", std::ios::out);
    if(file.is_open()){
        file << _plain + "\n";
    }
    file.close();
}


void vigenere::Vigenere::uploadCipher(){
    std::fstream file;
    file.open("cipher.txt", std::ios::out);
    if(file.is_open()){
        file << _cipher + "\n";
    }
    file.close();
}

void vigenere::Vigenere::getPlainFromFile(){
    std::fstream file;
    std::string line="";
    _plain = "";
    file.open("plain.txt",std::ios::in);
    if(file.is_open()){
        while(std::getline(file,line)){
            _plain = _plain + line;
        }
    }
    file.close();
}


void vigenere::Vigenere::getCipherFromFile(){
    std::fstream file;
    std::string line="",key="";
    _cipher = "";
    file.open("cipher.txt",std::ios::in);
    if(file.is_open()){
        while(std::getline(file,line)){
            _cipher = _cipher + line;
        }
    }
    file.close();
}

std::ostream& operator<<(std::ostream& os,std::vector <int> v){
    std::string str="[ ";
    for(auto it : v){
        str = str + std::to_string(it) + " ";
    }
    str = str + "]\n";
    os << str;
    return os;
}

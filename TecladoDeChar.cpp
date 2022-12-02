#include "TecladoDeChar.h"
#include <stdexcept>
#include <iostream>
using namespace std;

TecladoDeChar::TecladoDeChar() {

}

TecladoDeChar::~TecladoDeChar() {

}

void TecladoDeChar:: escrever(Dado* d){
     throw new logic_error("teclado não é um dispositivo de saída");
}

Dado* TecladoDeChar :: ler(){
    
    char c;
    int x = static_cast<int>(c);
    cout << "Digite um caractere: ";cin >> c;
    Dado* d = new Dado(x);
    return d;
}
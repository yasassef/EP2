#include "Teclado.h"
#include <stdexcept>
#include <iostream>


using namespace std;

Teclado :: Teclado(){

}

Teclado :: ~Teclado(){

}

Dado* Teclado :: ler(){
    int numero;
    cout << "Digite um numero: ";cin >> numero;
    Dado* d = new Dado(numero);
    return d;
}

void Teclado :: escrever(Dado* d){
    throw new logic_error("teclado não é um dispositivo de saída");
}
#include "Dado.h"
#include <iostream>

using namespace std;

Dado::Dado ( int valor) : valor (valor) {
} 

Dado::~Dado(){
}

int Dado::getValor(){
    return this -> valor; 
}

void Dado::imprimir(){
    cout << getValor(); 
}
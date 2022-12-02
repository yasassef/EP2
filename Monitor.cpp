#include "Monitor.h"


#include <iostream>
#include <stdexcept>

using namespace std;

Monitor :: Monitor() : Dispositivo(){

}

Monitor :: ~Monitor(){

}

Dado*  Monitor :: ler(){
   throw new logic_error("monitor não é um dispositivo de entrada.");

}

void Monitor :: escrever(Dado* d){
    cout << d->getValor(); 
}
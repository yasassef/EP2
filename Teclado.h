
#ifndef Teclado_H
#define Teclado_H

#include "Dispositivo.h"
#include"Dado.h"
#include <iostream>
#include <string>


using namespace std;

class Teclado : public Dispositivo{


    public: 
    Teclado();
    virtual ~Teclado(); 
    Dado* ler();
    virtual void escrever(Dado* d);

};
#endif
#ifndef TECLADODECHAR_H
#define TECLADODECHAR_H

#include "Teclado.h"
#include "Dado.h"

#include <iostream>
#include <string>


using namespace std;

class TecladoDeChar : public Teclado{


    public:
    TecladoDeChar();
    virtual ~TecladoDeChar();  
    Dado* ler();
    virtual void escrever(Dado* d);

};
#endif 
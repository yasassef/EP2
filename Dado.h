#ifndef DADO_H
#define DADO_H

#include <iostream>
#include <string>

using namespace std;

class Dado{
    protected: 
    int valor; 

    public:  
    Dado(int valor); 
    virtual ~Dado();
    virtual int getValor();
    virtual void imprimir();

};

#endif
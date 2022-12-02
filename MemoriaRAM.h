#ifndef MEMORIARAM_H
#define MEMORIARAM_H


#include "Dado.h"
#include "Memoria.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class MemoriaRAM : public Memoria{
private: 
int tamanho; 
Dado** Dados;




public: 

MemoriaRAM(int tamanho);
virtual ~MemoriaRAM(); 
virtual void escrever(list <Dado*>* dados);
virtual int getTamanho(); 
virtual Dado* ler(int posicao); 
virtual void escrever(int posicao, Dado* d);
virtual void imprimir(); 

};
#endif
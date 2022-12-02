#ifndef ESMAPEADANAMEMORIA_H
#define ESMAPEADANAMEMORIA_H

#include "Dado.h"
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class ESMapeadaNaMemoria  : public Memoria{
    private:
    MemoriaRAM* m;
    vector<Dispositivo*>* Dispositivos;

    public:
    virtual Dado* ler(int posicao);
    virtual void escrever(int posicao, Dado* d);
    virtual int getTamanho();
    virtual void imprimir(); 
    ESMapeadaNaMemoria(MemoriaRAM* m);
    ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos);
    virtual ~ESMapeadaNaMemoria(); 
    virtual MemoriaRAM* getMemoriaSubjacente(); 
    virtual void adicionar(Dispositivo* d);
    virtual vector<Dispositivo*>* getDispositivos();
    

};
#endif
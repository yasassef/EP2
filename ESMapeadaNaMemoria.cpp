
#include "EsMapeadaNaMemoria.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;


ESMapeadaNaMemoria ::ESMapeadaNaMemoria(MemoriaRAM* m) : Memoria() {
    this -> m = m;

}

ESMapeadaNaMemoria ::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos) : Memoria() {
    this -> m = m;
    Dispositivos = new vector<Dispositivo*>();

    for (unsigned int i =0; i < dispositivos->size(); i++){
        Dispositivos->push_back((dispositivos->at(i)));
    }
    }

ESMapeadaNaMemoria :: ~ESMapeadaNaMemoria(){
    delete this-> m; 

    while (!Dispositivos->empty()) {
    Dispositivo* dis = Dispositivos->back();
    Dispositivos->pop_back();
    delete dis;
    }
   
    delete this -> Dispositivos; 
}

int ESMapeadaNaMemoria :: getTamanho(){
return m-> getTamanho() + Dispositivos->size();
}



MemoriaRAM* ESMapeadaNaMemoria :: getMemoriaSubjacente(){
    return this -> m; 
}


vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos(){
    return this-> Dispositivos;
}


// não entendi como adicionar 
void ESMapeadaNaMemoria :: adicionar(Dispositivo* d){
 Dispositivos -> push_back(d);
}

void ESMapeadaNaMemoria :: imprimir(){
  m-> imprimir(); 
}

Dado*  ESMapeadaNaMemoria :: ler(int posicao){
    if (posicao < 0 || posicao >= getTamanho() + Dispositivos->size()) {
        throw new logic_error("POsição Inválida");
    }
    if (posicao < m->getTamanho()) {
        return m->ler(posicao);
    }
    else {
        posicao -= m->getTamanho();
        return Dispositivos->at(posicao)->ler();
    }
}

void ESMapeadaNaMemoria :: escrever(int posicao, Dado* d){
     if (posicao < 0 || posicao >= getTamanho() + Dispositivos->size()) {
        throw new logic_error("POsição Inválida");
    }
    if (posicao < m->getTamanho()) {
        return m->escrever(posicao, d);
    }
     else {
        posicao -= m->getTamanho();
        Dispositivos->at(posicao)-> escrever(d);
    }

}

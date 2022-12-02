
#include "MemoriaRAM.h"
#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

using namespace std;

MemoriaRAM :: MemoriaRAM(int tamanho) : Memoria(){
    this -> tamanho = tamanho;
    Dados = new Dado*[tamanho];
    for (int i = 0; i < tamanho; i++) Dados[i] = NULL;
}

MemoriaRAM :: ~MemoriaRAM(){
    for (int i = 0; i < tamanho; i++) delete Dados[i];
    delete[] Dados;
}

int  MemoriaRAM :: getTamanho(){
    return tamanho;
}

Dado* MemoriaRAM ::  ler (int posicao){
    if (posicao < 0 || posicao >= this -> tamanho) 
   throw new logic_error("Posição Inválida");

    return Dados[posicao];
}

void MemoriaRAM :: escrever(int posicao, Dado* d){
    if(posicao < 0 || posicao >= getTamanho()) 
    throw new logic_error("Posição Inválida");

    if(Dados[posicao]!=NULL)
    delete Dados[posicao];

    Dados[posicao] = d;
    
}



// não soube escrever 
void MemoriaRAM :: escrever(list <Dado*>* dados){
    
   

    if (dados->size() > tamanho)
    throw new logic_error("A lista é maior que a memória");


     int  t =0; 

    for( list<Dado*>::iterator i = dados->begin(); i != dados->end(); i++) {
        
        if  (Dados[t] != NULL)
        delete Dados[t];

        Dados[t++] = (*i);     
    }
       }
    

void MemoriaRAM :: imprimir(){
    for (int i = 0; i < tamanho; i++){
        if (Dados[i] == NULL) cout << i << ": " << "-" << endl;
        else  cout << i << ": " << Dados[i]->getValor() << endl;
    }
}
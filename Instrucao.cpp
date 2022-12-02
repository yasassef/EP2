#include "Instrucao.h"
#include <iostream>
#include <string>

using namespace std;

const int Instrucao::TIPO_R = 0;
const int Instrucao::FUNCAO_ADD = 32;
const int Instrucao::FUNCAO_SUB = 34;
const int Instrucao::FUNCAO_MULT = 24;
const int Instrucao::FUNCAO_DIV = 26;
const int Instrucao::J = 2;
const int Instrucao::BNE = 5;
const int Instrucao::BEQ = 4;
const int Instrucao::LW = 35;
const int Instrucao::SW = 43;

Instrucao:: Instrucao(int opcode, int origem1, int origem2, int destino, int imediato,
 int funcao) : Dado(opcode) {
  this -> opcode = getValor();
  this -> origem1 = origem1;
  this -> origem2 = origem2;
  this -> destino = destino;
  this -> imediato = imediato;
  this -> funcao = funcao;
}

Instrucao::~Instrucao(){
}

int Instrucao :: getOpcode(){
  return this ->opcode;
}

int Instrucao :: getOrigem1(){
  return  this -> origem1;
}

int Instrucao ::getOrigem2(){
  return this -> origem2;
}

int Instrucao :: getDestino(){
  return this -> destino;
}

int Instrucao :: getImediato(){
  return this -> imediato;
}

int Instrucao :: getFuncao(){
  return this -> funcao;
}


Instrucao* Instrucao:: criarLW(int destino, int imediato){
     return new Instrucao(0,0,0,destino,imediato,0);
    
}

Instrucao* Instrucao:: criarSW(int destino, int imediato){
     return  new  Instrucao(0,0,0,destino,imediato,0);
}
 

Instrucao* Instrucao:: criarJ(int imediato){
 
      return  new  Instrucao(0,0,0,0,imediato,0);
}


Instrucao* Instrucao:: criarBNE(int origem1, int origem2, int imediato){
     return  new  Instrucao(0,origem1,origem2,0,imediato,0);
}

Instrucao* Instrucao::criarBEQ(int origem1, int origem2, int imediato){
    return  new  Instrucao(0,origem1,origem2,0,imediato,0);
}


Instrucao* Instrucao:: criarADD(int destino, int origem1, int origem2){
   return  new  Instrucao(0,origem1,origem2,destino,0,FUNCAO_ADD);
}

Instrucao* Instrucao:: criarSUB(int destino, int origem1, int origem2){
   return  new  Instrucao(0,origem1,origem2,destino,0,FUNCAO_SUB);
}


Instrucao* Instrucao:: criarMULT(int origem1, int origem2){
     return  new  Instrucao(0,origem1,origem2,0,0,FUNCAO_MULT);
}

Instrucao* Instrucao:: criarDIV(int origem1, int origem2){
    return  new  Instrucao(0,origem1,origem2,0,0,FUNCAO_DIV);
}


void Instrucao::imprimir(){
    cout << "Instrucao " << getOpcode(); 
}














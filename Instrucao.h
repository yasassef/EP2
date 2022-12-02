
#ifndef INSTRUCAO_H
#define INSTRUCAO_H
#include "Dado.h"

 


#include <iostream>
#include <string>
 
using namespace std;



class Instrucao : public Dado{

private:
int opcode; int  origem1, origem2, destino, imediato, funcao;
Instrucao(int opcode, int origem1, int origem2, int destino, int imediato, int funcao); 

static const int LW = 35;
static const int SW = 43; 
static const int J = 2; 
static const int BNE = 5; 
static const int BEQ = 4; 
static const int TIPO_R = 0; 
static const int FUNCAO_ADD = 32; 
static const int FUNCAO_SUB = 34; 
static const int FUNCAO_MULT = 24; 
static const int FUNCAO_DIV = 26;


public:

static Instrucao* criarLW(int destino, int imediato); 
static Instrucao* criarSW(int destino, int imediato); 
static Instrucao* criarJ(int imediato); 
static Instrucao* criarBNE(int origem1, int origem2, int imediato); 
static Instrucao* criarBEQ(int origem1, int origem2, int imediato); 
static Instrucao* criarADD(int destino, int origem1, int origem2); 
static Instrucao* criarSUB(int destino, int origem1, int origem2); 
static Instrucao* criarMULT(int origem1, int origem2); 
static Instrucao* criarDIV(int origem1, int origem2); 


virtual ~Instrucao(); 
virtual int getOpcode(); 
virtual int getOrigem1(); 
virtual int getOrigem2(); 
virtual int getDestino(); 
virtual int getImediato(); 
virtual int getFuncao();

void imprimir(); 
};
#endif

#ifndef BANCODEREGISTRADORES_H
#define BANCODEREGISTRADORES_H
#define QUANTIDADE_REGISTRADORES 32

#include <iostream>
#include <string>

using namespace std;

class BancoDeRegistradores{
  protected:
  int registrador, valor; 
  int reg[QUANTIDADE_REGISTRADORES] ;

  public: 
  BancoDeRegistradores(); 
  virtual ~BancoDeRegistradores(); 
  virtual int getValor(int registrador); 
  virtual void setValor(int registrador, int valor); 
  virtual void imprimir(); 
};

#endif

#include "BancoDeRegistradores.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

BancoDeRegistradores :: BancoDeRegistradores(){
  for(int i=0; i<=QUANTIDADE_REGISTRADORES; i++) reg[i] = 0;
}

BancoDeRegistradores :: ~BancoDeRegistradores(){
delete[]reg;
}

int BancoDeRegistradores :: getValor (int registrador){
  if( registrador < 0 || registrador >= 32 )
 throw new logic_error("número do registrador inválido");

  if (registrador == 0)
  return 0; 

  else return this -> reg[registrador]; 
}

void BancoDeRegistradores :: setValor (int registrador, int valor){
  this -> registrador = registrador; 
  this -> valor = valor; 

  if ( this -> registrador > 0 || this -> registrador < 32) 
  reg [registrador] = this -> valor;


 if ( this -> registrador < 0 || this -> registrador >= 32)
 throw new logic_error("número de registrador inválido");

 if ( this -> registrador == 0 ){
  return; 
 }

}

void BancoDeRegistradores :: imprimir(){
  for (int i =0; i<=QUANTIDADE_REGISTRADORES - 1; i++) cout << i << ": " << reg[i] << endl;
} 
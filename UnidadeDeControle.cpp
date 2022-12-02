#include <iostream>
#include "UnidadeDeControle.h"
#include "BancoDeRegistradores.h"
#include "Memoria.h"
#include "Instrucao.h"

using namespace std;

UnidadeDeControle::UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria): 
registradores (registradores), memoria (memoria){
    this -> pc = 0;
}

UnidadeDeControle::~UnidadeDeControle(){
    delete registradores;
    delete memoria;
}

Memoria* UnidadeDeControle::getMemoria(){
    return this -> memoria;
}

BancoDeRegistradores* UnidadeDeControle::getBancoDeRegistradores(){
    return this -> registradores;
}

int UnidadeDeControle::getPC(){
    return this -> pc;
}

void UnidadeDeControle::setPC(int pc){
    this -> pc = pc;
}

void UnidadeDeControle::executarInstrucao(){
    Instrucao *instrucao = dynamic_cast<Instrucao*>(memoria->ler(pc));
    if(instrucao == NULL){
        pc++;
        return;
    }

    const int TIPO_R = 0;
    const int FUNCAO_ADD = 32;
    const int FUNCAO_SUB = 34;
    const int FUNCAO_MULT = 24;
    const int FUNCAO_DIV = 26;
    const int J = 2;
    const int BNE = 5;
    const int BEQ = 4;
    const int LW = 35;
    const int SW = 43;

    if( instrucao -> getOpcode() == 0){
        if(instrucao -> getFuncao() == 32){
            registradores -> setValor(instrucao->getDestino(), 
            registradores->getValor(instrucao->getOrigem1()) + registradores->getValor(instrucao->getOrigem2()));
        }

        if(instrucao -> getFuncao() == 34){
            registradores -> setValor(instrucao -> getDestino(),
            registradores -> getValor(instrucao->getOrigem1()) - registradores -> getValor(instrucao->getOrigem2()));
        }

        if(instrucao -> getFuncao() == 24){
            registradores -> setValor(instrucao -> getDestino(),
            registradores -> getValor(instrucao -> getOrigem1()) * registradores -> getValor(instrucao -> getOrigem2()));
        }

        if(instrucao -> getFuncao() == 26){
            registradores -> setValor(24, 
            registradores -> getValor(instrucao -> getOrigem1()) / registradores -> getValor(instrucao->getOrigem2()));
        }
        this -> pc++;
    }

    if(instrucao -> getOpcode() == 2){
        pc = instrucao -> getImediato();
        return;
    }

    if(instrucao -> getOpcode() == 5){
        if(registradores->getValor(instrucao->getOrigem1()) != registradores->getValor(instrucao->getOrigem2())){
            pc = instrucao -> getImediato();
            return;
        }
    }

    if(instrucao -> getOpcode() == 4){
        if(registradores->getValor(instrucao->getOrigem1()) == registradores->getValor(instrucao->getOrigem2())){
            pc = instrucao -> getImediato();
            return;
        }
    }

    if(instrucao -> getOpcode() == 35){
        Dado* dado = memoria -> ler(instrucao -> getImediato());
        if(dado == NULL){
            registradores -> setValor(instrucao -> getDestino(), 0);
            pc++;
            return;
        }
        registradores -> setValor(instrucao->getDestino(), dado->getValor());
    }

    if(instrucao -> getOpcode() == 43){
        Dado* dado = new Dado(registradores->getValor(instrucao->getDestino()));
        memoria->escrever(instrucao->getImediato(), dado);
    }
    pc++;
}
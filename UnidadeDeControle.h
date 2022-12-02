#ifndef UNIDADEDECONTROLE_H
#define UNIDADEDECONTROLE_H
#include "BancoDeRegistradores.h"
#include "Memoria.h"

class UnidadeDeControle {
    private:
        Memoria* memoria;
        BancoDeRegistradores* registradores;
        int pc;
    public:
        UnidadeDeControle(BancoDeRegistradores* registradores, Memoria* memoria);
        virtual ~UnidadeDeControle();
        virtual BancoDeRegistradores* getBancoDeRegistradores();
        virtual Memoria* getMemoria();
        virtual int getPC();
        virtual void setPC(int pc);
        virtual void executarInstrucao(); 
};

#endif
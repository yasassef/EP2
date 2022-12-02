#ifndef GERENCIADORDEMEMORIA_H
#define GERENCIADORDEMEMORIA_H

#include "MemoriaRAM.h"

class GerenciadorDeMemoria{
    private:
        MemoriaRAM* m;
        string arquivo;
    public:
        GerenciadorDeMemoria();
        virtual ~GerenciadorDeMemoria();
        virtual void load(string arquivo, MemoriaRAM* m);
        virtual void dump(string arquivo, MemoriaRAM* m); 
};

#endif
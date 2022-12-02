#ifndef MONITOR_H
#define MONITOR_H

#include "Dispositivo.h"
#include"Dado.h"
#include <iostream>
#include <string>


using namespace std;

class Monitor : public Dispositivo{


public:
Monitor();
virtual ~Monitor();
virtual Dado* ler(); 
virtual void escrever(Dado* d);

};
#endif

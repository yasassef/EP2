#ifndef MONITORDECHAR_H
#define MONITORDECHAR_H

#include "Monitor.h"
#include"Dado.h"

#include <iostream>
#include <string>

using namespace std;

class MonitorDeChar : public Monitor{
    public:
        MonitorDeChar();
        virtual ~MonitorDeChar();
        virtual void escrever(Dado* d);
};
#endif

#include "MonitorDeChar.h"
#include "Dado.h"
#include <iostream>
#include <string>

using namespace std;

MonitorDeChar :: MonitorDeChar(){
}

MonitorDeChar :: ~MonitorDeChar(){
}

void MonitorDeChar :: escrever(Dado* d){
  cout << static_cast<char>(d->getValor()); 
}
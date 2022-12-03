#include "GerenciadorDeMemoria.h"
#include "MemoriaRAM.h"
#include "Instrucao.h"

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std;

GerenciadorDeMemoria::GerenciadorDeMemoria(){
}

GerenciadorDeMemoria::~GerenciadorDeMemoria(){
}

void GerenciadorDeMemoria::load(string arquivo, MemoriaRAM* m){
    ifstream input;

    input.open("teste1.txt");
    if(input.fail()){
        throw new runtime_error("Não encontrado");
    }

    int tamanho, posicao = 0;
    input >> tamanho;
    if(input.fail()){
        throw new runtime_error("Erro de leitura");
    }

    string s;
    input >> s;
    while(posicao < tamanho){
        if(!input){
            throw new runtime_error("Erro de leitura");
        }
        if(s == "D"){
            int valor;
            input >> valor;
            Dado* dado = new Dado(valor);
            m->escrever(posicao, dado);
        }
        else{
            if (s == "-") {
                m->escrever(posicao, NULL);
            }
            if (s == "ADD") {
                int destino, origem1, origem2;
                input >> destino >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarADD(destino, origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "SUB") {
                int destino, origem1, origem2;
                input >> destino >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarSUB(destino, origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "MULT") {
                int origem1, origem2;
                input >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarMULT(origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "DIV") {
                int origem1, origem2;
                input >> origem1 >> origem2;
                Instrucao* i = Instrucao::criarDIV(origem1, origem2);
                m->escrever(posicao, i);
            }
            if (s == "BNE") {
                int origem1, origem2, imediato;
                input >> origem1 >> origem2 >> imediato;
                Instrucao* i = Instrucao::criarBNE(origem1, origem2, imediato);
                m->escrever(posicao, i);
            }
            if (s == "BEQ") {
                int origem1, origem2, imediato;
                input >> origem1 >> origem2 >> imediato;
                Instrucao* i = Instrucao::criarBEQ(origem1, origem2, imediato);
                m->escrever(posicao, i);
            }
            if (s == "LW") {
                int destino, imediato;
                input >> destino >> imediato;
                Instrucao* i = Instrucao::criarLW(destino, imediato);
                m->escrever(posicao, i);
            }
            if (s == "SW") {
                int destino, imediato;
                input >> destino >> imediato;
                Instrucao* i = Instrucao::criarSW(destino, imediato);
                m->escrever(posicao, i);
            }
            if (s == "J") {
                int imediato;
                input >> imediato;
                Instrucao* i = Instrucao::criarJ(imediato);
                m->escrever(posicao, i);
            }
        }
        posicao++;
        input >> s;
    }

    if(!input.eof()){
        throw new runtime_error("Ainda não chegou ao fim do arquivo");
    }
    input.close();
}

void GerenciadorDeMemoria::dump(string arquivo, MemoriaRAM* m){
    ofstream output;
    
    output.open("teste2.txt");
    if(output.fail()){
        throw new runtime_error("Erro");
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

    int tamanho = m->getTamanho();

    output << tamanho << endl;

    for(int posicao = 0; posicao < tamanho; posicao++){
        Instrucao *instrucao = dynamic_cast<Instrucao*>(m->ler(posicao));
        if(instrucao != NULL){
            if(instrucao -> getOpcode() == 0){
                if(instrucao -> getFuncao() == 32){
                    output << "ADD" << " " << instrucao->getDestino() << " " << instrucao-> getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }

                if(instrucao -> getFuncao() == 34){
                    output << "SUB" << " " << instrucao->getDestino() << " " << instrucao-> getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }

                if(instrucao -> getFuncao() == 24){
                    output << "MULT" << " " << instrucao-> getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }

                if(instrucao -> getFuncao() == 26){
                    output << "DIV" << " " << instrucao-> getOrigem1() << " " << instrucao->getOrigem2() << endl;
                }
            }

            if(instrucao->getOpcode() == 2){
                output << "J" << " " << instrucao->getImediato() << endl;
            }

            if(instrucao->getOpcode() == 5){
                output << "BNE" << " " << instrucao -> getOrigem1() << " " << instrucao -> getOrigem2() << " " << instrucao -> getImediato() << endl;
            }

            if(instrucao->getOpcode() == 4){
                output << "BEQ" << " " << instrucao -> getOrigem1() << " " << instrucao -> getOrigem2() << " " << instrucao -> getImediato() << endl;
            }

            if(instrucao->getOpcode() == 35){
                output << "LW" << " " << instrucao->getDestino() << " " << instrucao -> getImediato() << endl;
            }

            if(instrucao->getOpcode() == 43){
                output << "SW" << " " << instrucao->getDestino() << " " << instrucao -> getImediato() << endl;
            }
        }
        else if (m->ler(posicao) == NULL){
            output << "-" << endl;
        }
        else {
            output << "D" << " " << m->ler(posicao)->getValor() << endl;
        }
        if(output.fail()){
            throw new runtime_error("Erro");
        }
    }
    output.close();
}
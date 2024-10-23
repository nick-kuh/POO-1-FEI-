#pragma once
#include <iostream>
#include "Componente.cpp"
using namespace std;

class Atuador: public Componente{
  private:
    int valor;
    bool ligado;

  public:
    Atuador(bool ligado, bool conectado, int valor, string nome):
    Componente(ligado, conectado, valor, nome){}
    

    virtual bool setValor(int valor){
      this->valor = valor;
      return true;
    }
};
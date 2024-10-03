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
    
    // setValor = 0, pois é um comportamento que depende de cada tipo específico de atuador
    virtual pair <bool, int> setValor(int valor, bool ligado) = 0;
};
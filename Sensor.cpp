#pragma once
#include "Componente.cpp"
#include <map>
#include <iostream>
using namespace std;

class Sensor : public Componente {
private:
  int valor;
public:
  Sensor(bool ligado, bool conectado, int valor, string nome)
      : Componente(ligado, conectado, valor, nome){
  }

  virtual void setValor(int valor){
    this->valor = valor;
  }



};


  // int intesidadeLuz,
  //  float temperaturaEmC, float temperaturaEmF, float temperaturaEmK,
  //  float umidade
  // intesidadeLuz{intesidadeLuz},
  // temperaturaEmC{temperaturaEmC},
  // temperaturaEmF{temperaturaEmF},
  // temperaturaEmK{temperaturaEmK},
  // umidade{umidade}{}
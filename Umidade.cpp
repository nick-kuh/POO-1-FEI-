// #pragma once
#include "Sensor.cpp"
#include <iostream>

using namespace std;

class Umidade: public Sensor{
  private:
    int umidade;

  public:
    Umidade(bool ligado, bool conectado, int valor)
      : Sensor(ligado, conectado, valor, "umidade"){
      }

    float getUmidadeRelativa(){
      return getValor();
    }

    // virtual void printUmidade(){
    //   cout << "Umidade: " << this->getUmidadeRelativa() << endl;
    // }
};


// Níveis de Umidade Relativa:
//   -Muito úmido (acima de 70%):

//   -Pouco úmido (abaixo de 30%): 

// Umidade Ideal:
//   Para o conforto humano, a umidade relativa ideal fica entre 40% e 60%. 
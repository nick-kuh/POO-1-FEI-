#include "Sensor.cpp"
#include <iostream>

using namespace std;

class Temperatura: public Sensor{
  private:
    int temperatura;

  public:
    Temperatura(bool ligado, bool conectado, int valor)
      : Sensor(ligado, conectado, valor, "temperatura"){
      }
    // Temperatura(float valor): Sensor(valor){this->valor}

    float getTemperaturaEmC(){
      return this->getValor();
    }

    float getTemperaturaEmF(){
      return (this->getValor() * 1.8) + 32;
    }

    float getTemperaturaEmK(){
      return this->getValor() + 273.15;
    }

    virtual void setValor(int temperatura){
      this->temperatura = temperatura;
    }
};
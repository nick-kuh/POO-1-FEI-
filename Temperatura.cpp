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

    float getTemperatura(){
      return getValor();
    }

    float getTemperaturaEmF(){
      return (this->getValor() * 1.8) + 32;
    }

    float getTemperaturaEmK(){
      return this->getValor() + 273.15;
    }


    virtual void printTemperatura(){
      cout << "Temperatura em Celsius: " << this->getTemperatura() << endl;
      cout << "Temperatura em Fahreinheit: " << this->getTemperaturaEmF() << endl;
      cout << "Temperatura em Kelvin: " << this->getTemperaturaEmK() << endl;
    }
};
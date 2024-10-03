#include "Sensor.cpp"
#include <iostream>

using namespace std;

class Luminosidade: public Sensor{
  private:
    int temperatura;

  public:
    Luminosidade(bool ligado, bool conectado, int valor)
      : Sensor(ligado, conectado, valor, "luminosidade"){
      }

    int getIntesidadeLuz(){
      return getValor();
    }

    void printIntesidade(){
      int intesidade = this->getIntesidadeLuz();
      cout << "Intesidade da Luz: " << intesidade << " lux" << endl;
      if (intesidade > 340){
        cout << "Lampada Acesa!" << endl;
      }
      else{
        cout << "Lampada Apagada!" << endl;
      }
    }
};


// 0 - 10 lux: Escuridão quase completa (noite sem lua).
// 10 - 50 lux: Ambientes com pouca luz, como corredores ou ruas à noite com pouca iluminação.
// 50 - 200 lux: Iluminação de ambientes internos pouco iluminados, como uma sala de estar à noite.
// 200 - 500 lux: Iluminação média, como escritórios ou salas de aula durante o dia.
// 500 - 1000 lux: Ambientes muito bem iluminados, como um supermercado ou áreas de trabalho bem iluminadas.
// 1000 - 10.000 lux: Exposição à luz solar indireta, como áreas externas em dias nublados.
// 10.000 - 100.000 lux: Luz solar direta (varia conforme a hora do dia e condições climáticas).
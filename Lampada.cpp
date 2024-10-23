#include "Atuador.cpp"
#include <iostream>

using namespace std;

class Lampada: public Atuador{
private:
  bool ligado;
  int intesidade;
  int brilho;

public:
  Lampada(bool ligado, bool conectado, int valor)
    : Atuador(ligado, conectado, valor, "lampada"){
      this->ligado = ligado;
      this->intesidade = valor;
      this->brilho = 0;
    }

  virtual bool setValor(int intesidade){
    if (intesidade == 0){
      this->setBrilho(0);
    }
    else{
      this->setBrilho(intesidade);
    }
    return true;
  }

  bool setBrilho(int brilho) {
    this->brilho = brilho;
    return true; // Operação bem-sucedida
}

  int getBrilho(){
    return brilho;
  }

};




// 0 - 10 lux: Escuridão quase completa (noite sem lua).
// 10 - 50 lux: Ambientes com pouca luz, como corredores ou ruas à noite com pouca iluminação.
// 50 - 200 lux: Iluminação de ambientes internos pouco iluminados, como uma sala de estar à noite.
// 200 - 500 lux: Iluminação média, como escritórios ou salas de aula durante o dia.
// 500 - 1000 lux: Ambientes muito bem iluminados, como um supermercado ou áreas de trabalho bem iluminadas.
// 1000 - 10.000 lux: Exposição à luz solar indireta, como áreas externas em dias nublados.
// 10.000 - 100.000 lux: Luz solar direta (varia conforme a hora do dia e condições climáticas).



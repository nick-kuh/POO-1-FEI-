#include "Atuador.cpp"
#include <iostream>

using namespace std;

class Ventilador: public Atuador{
private:
  bool ligado;
  int velocidade;

public:
  Ventilador(bool ligado, bool conectado, int valor)
    : Atuador(ligado, conectado, valor, "ventilador"){
      this->ligado = ligado;
      this->velocidade = 0;
    }

virtual bool setValor(int velocidade){
  if (velocidade == 0){
    this->setVelocidade(0);
  }
  else{
    this->setVelocidade(1);
  }
  return true;
}

bool setVelocidade(int velocidade) {
  this->velocidade = velocidade;
  return true; // Operação bem-sucedida
}

int getVelocidade(){
  return velocidade;
}

};








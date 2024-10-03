#include "Atuador.cpp"
#include <iostream>

using namespace std;

class Ventilador: public Atuador{
  private:
    bool ligado;
    int temperatura;
    int velocidade;

  public:
    Ventilador(bool ligado, bool conectado, int valor)
      : Atuador(ligado, conectado, valor, "ventilador"){
        this->ligado = ligado;
        this->temperatura = valor;
        this->velocidade = 0;
      }

    // bool getLigado(){
    //   return this->ligado;
    // }

    virtual pair <bool, int> setValor(int valor, bool ligado){
      this->temperatura = valor;
      this->ligado = ligado;

      if (ligado) {
        if (valor < 23){
          this->setVelocidade(0);
          cout << "Ventilador Desligado" << endl;
          return make_pair(this->desligar(), this->temperatura);
        }
        else{
          this->setVelocidade(1);
          this->temperatura -= 1;
          cout << "Ventilador Ligado" << endl;
          return make_pair(this->ligar(), this->temperatura);
        }
      }
      else{
        if (temperatura > 25){
          this->setVelocidade(1);
          cout << "Ventilador Ligado" << endl;
          return make_pair(this->ligar(), this->temperatura);
        }
        else{
          this->setVelocidade(0);
          cout << "Ventilador Desligado" << endl;
          return make_pair(this->desligar(), this->temperatura);
        }
      }
    }

    bool setVelocidade(int velocidade) {
      if (velocidade >= 0 && velocidade <= 2) {
        this->velocidade = velocidade;
        return true; // Operação bem-sucedida
      } 
      else {
        return false; // Velocidade inválida
      }
  }

};

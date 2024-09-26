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
        this->temperatura = valor;
        this->velocidade = 0;
      }

    virtual bool setValor(int valor){
      this->temperatura = valor;
      if (temperatura > 29){
        this->ligar();
        this->setVelocidade(1);
        if(temperatura > 60){
          this->setVelocidade(2);
        }
        return true;
      }
      else{
        this->desligar();
        this->setVelocidade(0);
        return false;
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








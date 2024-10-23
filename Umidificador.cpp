#include "Atuador.cpp"
#include <iostream>

using namespace std;

class Umidificador: public Atuador{
  private:
    bool ligado;
    int configuracao;

  public:
    Umidificador(bool ligado, bool conectado, int valor)
      : Atuador(ligado, conectado, valor, "umidificador"){
        this->ligado = ligado;
        this->configuracao = 0;
      }

    // bool getLigado(){
    //   return this->ligado;
    // }

    virtual bool setValor(int velocidade){
      if (velocidade == 0){
        this->setConfiguracao(0);
      }
      else{
        this->setConfiguracao(1);
      }
      return true;
    }

    bool setConfiguracao(int configuracao) {
      this->configuracao = configuracao;
      return true; // Operação bem-sucedida
    }

    int getConfiguracao(){
      return configuracao;
    }

};

// Níveis de Umidade Relativa:
//   -Muito úmido (acima de 70%):

//   -Pouco úmido (abaixo de 30%): 

// Umidade Ideal:
//   Para o conforto humano, a umidade relativa ideal fica entre 40% e 60%. 
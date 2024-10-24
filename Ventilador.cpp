#include "Atuador.cpp" // Inclui a definição da classe base Atuador
#include <iostream> // Biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de usar 'std::'

// Definição da classe Ventilador que herda da classe Atuador
class Ventilador : public Atuador {
private:
  bool ligado;     // Estado do ventilador (ligado ou desligado)
  int velocidade;  // Velocidade do ventilador

public:
  // Construtor da classe Ventilador que inicializa a classe base Atuador com os parâmetros ligados, conectados e valor
  Ventilador(bool ligado, bool conectado, int valor)
    : Atuador(ligado, conectado, valor, "ventilador") {
      this->ligado = ligado; // Define o estado inicial (ligado/desligado) do ventilador
      this->velocidade = 0;  // Define a velocidade inicial como 0
  }

  // Sobrescreve o método setValor da classe base para definir a velocidade de operação do ventilador
  virtual bool setValor(int velocidade) {
    if (velocidade == 0) {
      this->setVelocidade(0); // Se a velocidade for 0, o ventilador é desligado (velocidade 0)
    } else {
      this->setVelocidade(1); // Caso contrário, o ventilador é ligado (velocidade 1)
    }
    return true; // Operação bem-sucedida
  }

  // Método para definir a velocidade do ventilador
  bool setVelocidade(int velocidade) {
    this->velocidade = velocidade; // Atualiza o valor da velocidade
    return true; // Retorna true indicando sucesso
  }

  // Método para obter a velocidade atual do ventilador
  int getVelocidade() {
    return velocidade; // Retorna a velocidade atual do ventilador
  }
};




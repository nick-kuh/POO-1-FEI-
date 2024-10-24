#include "Atuador.cpp" // Inclui a definição da classe Atuador
#include <iostream> // Biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de escrever std::

// Definição da classe Lampada, que herda da classe Atuador
class Lampada : public Atuador {
private:
  bool ligado; // Estado da lâmpada (ligada ou desligada)
  int intesidade; // Intensidade da lâmpada
  int brilho; // Brilho da lâmpada (lux)

public:
  // Construtor da classe Lampada, que chama o construtor da classe base Atuador
  Lampada(bool ligado, bool conectado, int valor)
    : Atuador(ligado, conectado, valor, "lampada") {
      this->ligado = ligado; // Define o estado da lâmpada (ligado ou desligado)
      this->intesidade = valor; // Define a intensidade inicial da lâmpada
      this->brilho = 0; // Inicializa o brilho como 0
    }

  // Sobrescreve o método setValor da classe base para controlar a intensidade e brilho
  virtual bool setValor(int intesidade) {
    if (intesidade == 0) {
      this->setBrilho(0); // Se a intensidade for 0, o brilho é definido como 0
    } else {
      this->setBrilho(intesidade); // Caso contrário, define o brilho conforme a intensidade
    }
    return true; // Retorna true indicando sucesso
  }

  // Método para definir o brilho da lâmpada
  bool setBrilho(int brilho) {
    this->brilho = brilho; // Atualiza o valor do brilho
    return true; // Operação bem-sucedida
  }

  // Método para obter o brilho atual da lâmpada
  int getBrilho() {
    return brilho; // Retorna o valor atual do brilho
  }

};

// Descrição dos níveis de luminosidade (brilho em lux):
// 0 - 10 lux: Escuridão quase completa (noite sem lua).
// 10 - 50 lux: Ambientes com pouca luz, como corredores ou ruas à noite com pouca iluminação.
// 50 - 200 lux: Iluminação de ambientes internos pouco iluminados, como uma sala de estar à noite.
// 200 - 500 lux: Iluminação média, como escritórios ou salas de aula durante o dia.
// 500 - 1000 lux: Ambientes muito bem iluminados, como um supermercado ou áreas de trabalho bem iluminadas.
// 1000 - 10.000 lux: Exposição à luz solar indireta, como áreas externas em dias nublados.
// 10.000 - 100.000 lux: Luz solar direta (varia conforme a hora do dia e condições climáticas).

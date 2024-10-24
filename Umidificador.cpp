#include "Atuador.cpp" // Inclui a definição da classe base Atuador
#include <iostream> // Biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de 'std::'

// Definição da classe Umidificador que herda da classe Atuador
class Umidificador : public Atuador {
  private:
    bool ligado; // Atributo privado que armazena o estado do umidificador (ligado ou desligado)
    int configuracao; // Atributo que armazena a configuração do umidificador

  public:
    // Construtor da classe Umidificador, que inicializa a classe base Atuador com os parâmetros ligados, conectados e valor
    Umidificador(bool ligado, bool conectado, int valor)
      : Atuador(ligado, conectado, valor, "umidificador") {
        this->ligado = ligado; // Define o estado inicial do umidificador (ligado ou desligado)
        this->configuracao = 0; // Define a configuração inicial como 0
    }

    // Sobrescreve o método setValor da classe base para definir a velocidade de operação do umidificador
    virtual bool setValor(int velocidade) {
      if (velocidade == 0) {
        this->setConfiguracao(0); // Se a velocidade for 0, configura o umidificador para desligado
      } else {
        this->setConfiguracao(1); // Se a velocidade for maior que 0, configura o umidificador para ligado
      }
      return true; // Operação bem-sucedida
    }

    // Define a configuração do umidificador (0 ou 1, desligado ou ligado)
    bool setConfiguracao(int configuracao) {
      this->configuracao = configuracao; // Atualiza a configuração
      return true; // Retorna true indicando sucesso
    }

    // Retorna a configuração atual do umidificador
    int getConfiguracao() {
      return configuracao; // Retorna a configuração atual (0 = desligado, 1 = ligado)
    }
};

// Níveis de Umidade Relativa:
//   - Muito úmido (acima de 70%)
//   - Pouco úmido (abaixo de 30%)
//   Umidade Ideal:
//     Para o conforto humano, a umidade relativa ideal fica entre 40% e 60%.

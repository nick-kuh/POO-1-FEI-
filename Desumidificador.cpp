#include "Atuador.cpp" // Inclui o arquivo Atuador.cpp, que define a classe Atuador
#include <iostream> // Inclui a biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de escrever std::

// Definição da classe Desumidificador, que herda de Atuador
class Desumidificador : public Atuador {
  private:
    bool ligado; // Estado de ligado do desumidificador
    int configuracao; // Configuração de velocidade do desumidificador

  public:
    // Construtor da classe Desumidificador, que chama o construtor da classe base Atuador
    Desumidificador(bool ligado, bool conectado, int valor)
      : Atuador(ligado, conectado, valor, "desumidificador") {
        this->ligado = ligado; // Define o estado ligado do desumidificador
        this->configuracao = 0; // Inicializa a configuração com 0
      }

    // Sobrescreve o método setValor da classe base para controlar a configuração de velocidade
    virtual bool setValor(int velocidade) {
      if (velocidade == 0) {
        this->setConfiguracao(0); // Configura para velocidade 0 (desligado)
      } else {
        this->setConfiguracao(1); // Configura para velocidade 1 (ligado)
      }
      return true; // Operação bem-sucedida
    }

    // Método para definir a configuração do desumidificador
    bool setConfiguracao(int configuracao) {
      this->configuracao = configuracao; // Atualiza a configuração
      return true; // Retorna true para indicar sucesso
    }

    // Método para obter a configuração atual do desumidificador
    int getConfiguracao() {
      return configuracao; // Retorna o valor da configuração
    }
};

// Níveis de Umidade Relativa:
//   - Muito úmido (acima de 70%): desumidificador deve ser ligado para reduzir a umidade
//   - Pouco úmido (abaixo de 30%): desumidificador deve ser desligado

// Umidade Ideal:
//   Para o conforto humano, a umidade relativa ideal fica entre 40% e 60%.

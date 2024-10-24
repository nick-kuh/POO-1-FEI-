#pragma once // Garante que o arquivo de cabeçalho seja incluído apenas uma vez durante a compilação
#include <iostream> // Inclui a biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de escrever std::

// Definição da classe Componente
class Componente {
  private:
    bool ligado; // Indica se o componente está ligado ou não
    bool conectado; // Indica se o componente está conectado ou não
    int valor; // Armazena o valor associado ao componente
    string nome; // Nome do componente

  public:
    // Construtor da classe Componente, inicializa os atributos
    Componente(bool ligado, bool conectado, int valor, string nome) {
      this->ligado = ligado; // Define o estado ligado
      this->conectado = conectado; // Define o estado conectado
      this->valor = valor; // Define o valor do componente
      this->nome = nome; // Define o nome do componente
    }

    // Método para ligar o componente
    bool ligar() {
      this->ligado = true; // Define o componente como ligado
      return true; // Retorna true indicando sucesso
    }

    // Método para desligar o componente
    bool desligar() {
      this->ligado = false; // Define o componente como desligado
      return false; // Retorna false indicando que o componente foi desligado
    }

    // Método para conectar o componente
    void conectar() {
      conectado = true; // Define o componente como conectado
    }

    // Método para desconectar o componente
    void desconectar() {
      conectado = false; // Define o componente como desconectado
    }

    // Método para obter o valor do componente
    int getValor() {
      return valor; // Retorna o valor do componente
    }

    // Método para verificar se o componente está ligado
    bool getLigado() {
      return ligado; // Retorna o estado ligado
    }

    // Método para verificar se o componente está conectado
    bool getConectado() {
      return conectado; // Retorna o estado conectado
    }

    // Método para obter o nome do componente
    string getNome() {
      return nome; // Retorna o nome do componente
    }

    // Método para definir um novo valor para o componente
    void definirValor(int valor) {
      this->valor = valor; // Atualiza o valor do componente
    }

    // Método para alterar o estado de ligado
    void setLigado(int ligado) {
      this->ligado = ligado; // Atualiza o estado de ligado
    }

    // Comentado pois não está sendo usado atualmente, mas poderia ser uma função para definir ambos ligado e valor
    // void setValor(bool ligado, int valor){
    //   this->valor = valor;
    //   this->ligado = ligado;
    // }
};

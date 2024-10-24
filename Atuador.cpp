#pragma once // Garante que o arquivo de cabeçalho seja incluído apenas uma vez durante a compilação
#include <iostream> // Inclui a biblioteca padrão de entrada/saída
#include "Componente.cpp" // Inclui o arquivo Componente.cpp
using namespace std; // Usa o namespace padrão para evitar a necessidade de escrever std::

// Definição da classe Atuador que herda de Componente
class Atuador: public Componente {
  private:
    int valor; // Armazena o valor do atuador
    bool ligado; // Indica se o atuador está ligado ou não

  public:
    // Construtor da classe Atuador que chama o construtor da classe base Componente
    Atuador(bool ligado, bool conectado, int valor, string nome) :
    Componente(ligado, conectado, valor, nome) {}

    // Método que define o valor do atuador e retorna true se bem-sucedido
    virtual bool setValor(int valor) {
      this->valor = valor; // Atualiza o valor do atuador com o valor passado como argumento
      return true; // Retorna true indicando sucesso
    }
};

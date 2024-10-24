#pragma once // Garante que o arquivo seja incluído apenas uma vez durante a compilação
#include "Componente.cpp" // Inclui a classe base Componente
#include <map> // Pode ser utilizada para implementar funcionalidades de mapeamento (ainda não utilizada no código)
#include <iostream> // Biblioteca padrão de entrada/saída
using namespace std; // Evita a necessidade de usar 'std::' antes das funções de biblioteca padrão

// Definição da classe Sensor que herda da classe Componente
class Sensor : public Componente {
private:
  int valor; // Armazena o valor do sensor
  
public:
  // Construtor da classe Sensor que inicializa a classe base Componente
  Sensor(bool ligado, bool conectado, int valor, string nome)
      : Componente(ligado, conectado, valor, nome) {
      // O construtor simplesmente delega a inicialização para a classe base Componente
  }

  // Método virtual para definir o valor do sensor (pode ser sobrescrito por classes derivadas)
  virtual bool setValorSensor(int valor) {
      this->valor = valor; // Atualiza o valor do sensor
      return true; // Retorna true indicando que a operação foi bem-sucedida
  }
};

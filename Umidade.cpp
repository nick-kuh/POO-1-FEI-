// #pragma once // Comentado para garantir que não cause problemas de múltiplas inclusões, dependendo do sistema
#include "Sensor.cpp" // Inclui a classe base Sensor
#include <iostream> // Biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de usar 'std::'

// Definição da classe Umidade que herda da classe Sensor
class Umidade : public Sensor {
  private:
    int umidade; // Atributo privado que armazena o valor da umidade (não utilizado diretamente neste código)

  public:
    // Construtor da classe Umidade que inicializa o Sensor com os parâmetros ligados, conectados e o valor inicial
    Umidade(bool ligado, bool conectado, int valor)
      : Sensor(ligado, conectado, valor, "umidade") {
        // O nome "umidade" é passado para o construtor da classe base Sensor
    }

    // Método para obter o valor da umidade relativa em %
    float getUmidadeRelativa() {
      return getValor(); // Retorna o valor do sensor como a umidade relativa
    }

    // Método virtual (comentado) que imprime a umidade relativa no terminal
    // virtual void printUmidade(){
    //   cout << "Umidade: " << this->getUmidadeRelativa() << endl;
    // }
};

// #pragma once // Evitado por enquanto para garantir múltiplas inclusões em sistemas simples
#include "Sensor.cpp" // Inclui a definição da classe Sensor
#include <iostream> // Biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de std::

// Definição da classe Luminosidade, que herda da classe Sensor
class Luminosidade : public Sensor {
private:
  int limiarClaridade; // Define o limiar de claridade (lux) para considerar se está claro ou escuro

public:
  // Construtor da classe Luminosidade, que chama o construtor da classe base Sensor
  Luminosidade(bool ligado, bool conectado, int valor)
    : Sensor(ligado, conectado, valor, "luminosidade") {
    }

  // Método para definir o valor do limiar de claridade
  virtual bool setValorSensor(int limiarClaridade) {
    this->setLimiarClaridade(limiarClaridade); // Define o novo limiar
    return true; // Retorna true indicando sucesso
  }

  // Método para definir o limiar de claridade
  void setLimiarClaridade(int limiarClaridade) {
    this->limiarClaridade = limiarClaridade; // Atualiza o limiar de claridade
  }

  // Método para obter o limiar de claridade atual
  int getLimiarClaridade() {
    return limiarClaridade; // Retorna o limiar de claridade
  }

  // Método para obter a luminosidade atual (valor lido pelo sensor)
  int getLuminosidade() {
    return getValor(); // Retorna o valor da luminosidade do sensor
  }

  // Método para verificar se está claro com base na luminosidade atual e no limiar de claridade
  bool estaClaro() {
    return (this->getLuminosidade() >= this->limiarClaridade); // Retorna true se estiver claro (luminosidade >= limiar)
  }

};

// Descrição dos níveis de luminosidade (lux):
// 0 - 10 lux: Escuridão quase completa (noite sem lua).
// 10 - 50 lux: Ambientes com pouca luz, como corredores ou ruas à noite com pouca iluminação.
// 50 - 200 lux: Iluminação de ambientes internos pouco iluminados, como uma sala de estar à noite.
// 200 - 500 lux: Iluminação média, como escritórios ou salas de aula durante o dia.
// 500 - 1000 lux: Ambientes muito bem iluminados, como um supermercado ou áreas de trabalho bem iluminadas.
// 1000 - 10.000 lux: Exposição à luz solar indireta, como áreas externas em dias nublados.
// 10.000 - 100.000 lux: Luz solar direta (varia conforme a hora do dia e condições climáticas).

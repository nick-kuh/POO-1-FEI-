// #pragma once // Comentado para garantir que não cause problemas de múltiplas inclusões, dependendo do sistema
#include "Sensor.cpp" // Inclui a classe base Sensor
#include <iostream> // Biblioteca padrão de entrada/saída

using namespace std; // Usa o namespace padrão para evitar a necessidade de usar 'std::' repetidamente

// Definição da classe Temperatura que herda da classe Sensor
class Temperatura : public Sensor {
private:
  // A classe Temperatura não tem atributos adicionais, apenas usa os atributos herdados da classe base Sensor

public:
  // Construtor da classe Temperatura, que inicializa a classe base Sensor com os parâmetros ligados, conectados e valor
  Temperatura(bool ligado, bool conectado, int valor)
    : Sensor(ligado, conectado, valor, "temperatura") { // Chama o construtor da classe base Sensor e define o nome como "temperatura"
  }

  // Método para obter a temperatura em graus Celsius, retorna o valor armazenado no sensor
  float getTemperaturaEmC() {
    return getValor(); // Retorna o valor do sensor como temperatura em Celsius
  }

  // Método para obter a temperatura em Fahrenheit, aplicando a fórmula de conversão
  float getTemperaturaEmF() {
    return (this->getValor() * 1.8) + 32; // Converte a temperatura de Celsius para Fahrenheit
  }

  // Método para obter a temperatura em Kelvin, aplicando a fórmula de conversão
  float getTemperaturaEmK() {
    return this->getValor() + 273.15; // Converte a temperatura de Celsius para Kelvin
  }

  // Método virtual (comentado) que imprime a temperatura em várias escalas
  // virtual void printTemperatura(){
  //   cout << "Temperatura em Celsius: " << this->getTemperatura() << endl;
  //   cout << "Temperatura em Fahreinheit: " << this->getTemperaturaEmF() << endl;
  //   cout << "Temperatura em Kelvin: " << this->getTemperaturaEmK() << endl;
  // }
};

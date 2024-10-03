#pragma once
#include <iostream>
#include <vector>
#include "Sensor.cpp"
#include "Atuador.cpp"
using namespace std;

// Forward declarations (declarações antecipadas)
class Sensor;
class Atuador;

class Sala {
  private:
    vector<Sensor*> sensores;
    vector<Atuador*> atuadores;
    bool ligado;
    int temperatura;

  public:
    // Construtor para inicializar a sala com um sensor e um atuador
    Sala(){}

    void adicionarSensor(Sensor* sensor){
      sensores.push_back(sensor);
    }

    void adicionarAtuador(Atuador* atuador){
      atuadores.push_back(atuador);
    }

    // Atualiza o valor do sensor e mostra o valor lido
    void atualizarSensores(int valor, string tipo){
      // Vai iterar para cada um dos sensores
      for (Sensor* sensor : sensores){
        // Sensor Temperatura
        if (sensor->getNome() == "temperatura" && tipo == "TEMPERATURA"){
          sensor->setValor(valor);
          // cout << "T: " << sensor->getValor() << endl; // Teste
          //? Perguntar pro professor sobre o printTemperatura
          // sensor->printTemperatura(valor);
        }
        else if (sensor->getNome() == "luminosidade" && tipo == "LUMINOSIDADE"){
          sensor->setValor(valor);
          // cout << "L: " << sensor->getValor() << endl; // Teste

        }
      }
    }

    // Atualiza o estado dos atuadores com base no valor do sensor
    void atualizarAtuadores(bool ligado, int valor, string tipo){
      for (Sensor* sensor : sensores){
        for (Atuador* atuador : atuadores){
          // Ventilador
          if (sensor->getNome() == "temperatura" && tipo == "TEMPERATURA"){
            if (atuador->getNome() == "ventilador" && atuador->getConectado()){

              // int valor = sensor->getValor(); // Obtém o valor atual do sensor
              pair<bool, int> resultado = atuador->setValor(valor, ligado); // Atualiza o estado de ligado e a temperatura
              ligado = resultado.first;
              valor = resultado.second;
              atuador->setLigado(ligado);
              sensor->setValor(valor);
            }
          }
      //   }
      // }
      // for (Sensor* sensor : sensores){
      //   for (Atuador* atuador : atuadores){
          // Lampada
          if (sensor->getNome() == "luminosidade" && tipo == "LUMINOSIDADE"){
            if (atuador->getNome() == "lampada" && atuador->getConectado()){
              // int valor = sensor->getValor(); // Obtém o valor atual do sensor
              pair<bool, int> resultado = atuador->setValor(valor, ligado); // Atualiza o estado de ligado e a temperatura
              ligado = resultado.first;
              valor = resultado.second;
              atuador->setLigado(ligado);
              sensor->setValor(valor);
            }
          }  
        } 
      } 
    }
};

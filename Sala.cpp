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
    // Sensor& sensor;
    vector<Atuador*> atuadores;

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
    void atualizarSensores(int valor){
      // Sensor* sensorTemperatura = nullptr;
      for (Sensor* sensor : sensores){
        if (sensor->getNome() == "temperatura"){
          sensor->setValor(valor);
          cout << "Sensor Temperatura: " << valor << endl;
        }
      }
      // if (sensorTemperatura != nullptr) {
      //       cout << "Temperatura: " << sensorTemperatura->getValor() << endl;
      //   } else {
      //       cout << "Sensor de temperatura não encontrado." << endl;
      //   }
    }

    // Atualiza o estado dos atuadores com base no valor do sensor
    void atualizarAtuadores(int valor){
      Sensor* sensorTemperatura = nullptr;
      Atuador* atuadorVentilador = nullptr;
      for (Sensor* sensor : sensores){
        if (sensor->getNome() == "temperatura"){
          for (Atuador* atuador : atuadores){
            // int valor = sensor->getValor(); // Obtém o valor atual do sensor
            bool ligado = atuador->setValor(valor); // Passa o valor para o atuador
            if (ligado) {
              cout << "Ventilador Ligado" << endl;
              valor -= 1;
              sensor->setValor(valor);
            } 
            else {
              cout << "Ventilador Desligado" << endl;
            }
          }
        }
      }
    }
};

// void atualizarAtuadores(){
//     for (Sensor* sensor : sensores){
//         if (sensor->getNome() == "temperatura"){
//             for (Atuador* atuador : atuadores){
//                 atuador->atualizar(sensor->getValor());
//             }
//         }
//     }
// }

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
  vector<string> sensorNomes; // Lista para armazenar os nomes ou tipos dos sensores
  vector<string> atuadorNomes; // Lista para armazenar os nomes ou tipos dos atuadores
  bool ligado;

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
        // sensor->ligar();
        sensor->definirValor(valor);
      }
      // Luminosidade
      else if (sensor->getNome() == "luminosidade" && tipo == "LUMINOSIDADE"){
        // sensor->setValorSensor(valor);
        sensor->definirValor(valor);
      }
      // Umidade
      else if (sensor->getNome() == "umidade" && tipo == "UMIDADE"){
        sensor->definirValor(valor);
      }
    }
  }

  // Atualiza o estado dos atuadores com base no valor do sensor
  void atualizarAtuadores(bool ligado, int valor, string tipo, bool apertouL, int estado){
    for (Sensor* sensor : sensores){
      for (Atuador* atuador : atuadores){
        string nomeSensor = sensor->getNome();
        string nomeAtuador = atuador->getNome();

        if (nomeSensor == "temperatura" && tipo == "TEMPERATURA"){
          if (nomeAtuador == "ventilador" && atuador->getConectado()){

            if (ligado) {
              if (valor < 22){
                atuador->setValor(0); // Coloca a velocidade do Ventilador
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }
              else{
                atuador->setValor(1);
                atuador->ligar();
                valor -= 1;
                atualizarSensores(valor, tipo);
              }
            }
            else{
              if (valor > 25){
                if(estado != 2){
                  atuador->setValor(1);
                  atuador->ligar();
                  atualizarSensores(valor, tipo);
                }
              }
              else{
                atuador->setValor(0);
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }
            }
          }
        }
      }
    }

    // Lampada
    for (Sensor* sensor : sensores){
      for (Atuador* atuador : atuadores){
        string nomeSensor = sensor->getNome();
        string nomeAtuador = atuador->getNome();

        if (nomeSensor == "luminosidade" && tipo == "LUMINOSIDADE"){
          if (nomeAtuador == "lampada" && atuador->getConectado()){
            
            // Para quarto
            if(apertouL){
              if (ligado) {
                valor = 0;
                atuador->setValor(0); // Coloca o quanto de brilho da Lampada (como é lampada desligada -> brilho = 0)
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }

              else{
                if (estado != 2){
                  valor = 300;
                  atuador->setValor(600);
                }
                else{
                  valor = 25;
                  atuador->setValor(125);
                }
                atuador->ligar();
                atualizarSensores(valor, tipo);
              }
            }

            // Para cinema
            else{
              if (estado == 0 || estado == 5) {
                atuador->setValor(0); // Coloca o quanto de brilho da Lampada (como é lampada desligada -> brilho = 0)
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }

              else{
                if (sensor->getValor() > 100){
                  atuador->setValor(500);
                }
                  
                else if (sensor->getValor() > 25){
                  atuador->setValor(125);
                }

                else if (sensor->getValor() > 3){
                  atuador->setValor(50);
                }      

                atuador->ligar();
                atualizarSensores(valor, tipo);
              }
            }
          }
        }  
      } 
    } 

    // Umidificador e Desumidificador
    for (Sensor* sensor : sensores){
      for (Atuador* atuador : atuadores){
        string nomeSensor = sensor->getNome();
        string nomeAtuador = atuador->getNome();
        
        if (nomeSensor == "umidade" && tipo == "UMIDADE"){        
        // Umidificador 
          if (nomeAtuador == "umidificador" && atuador->getConectado()){
            if (ligado) {
              if (valor > 60){
                atuador->setValor(0);
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }
              else{
                valor += 1;
                atuador->setValor(1);
                atuador->ligar();
                atualizarSensores(valor, tipo);
              }
            }
            else{
              if (valor < 40){
                atuador->setValor(1);
                atuador->ligar();
                atualizarSensores(valor, tipo);
              }
              else{
                atuador->setValor(0);
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }
            }
          }
          else if (nomeAtuador == "desumidificador" && atuador->getConectado()){
            
            if (ligado) {
              if (valor < 40){
                estado = 2;
                atuador->setValor(0);
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }
              else{
                if (estado == 1){
                  valor = 66; // Estou utilizando um valor constante na simulação, pois enquanto a umidade aumenta (por causa da cozinha), o desumidificador está simultaneamente diminuindo o nível de umidade
                }
                else{
                  valor -= 1;
                }
                atuador->setValor(1);
                atuador->ligar();
                atualizarSensores(valor, tipo);
              }
            }
            else{
              if (valor > 65){
                atuador->setValor(1);
                atuador->ligar();
                atualizarSensores(valor, tipo);
              }
              else{
                atuador->setValor(0);
                atuador->desligar();
                atualizarSensores(valor, tipo);
              }
            }
          }
        }
      }
    }
  }
};

#include <iostream>
#include <random>
#include <unistd.h>
#include "Sala.cpp"
#include "Sensor.cpp"
#include "Temperatura.cpp"
#include "Ventilador.cpp"
using namespace std;    

int main() {
    // Criando um sensor de temperatura
    Temperatura sensorTemperatura(true, true, 20);
    // Pegando diversos tipos de temperatura
    cout << "Temperatura em Celsius: " << sensorTemperatura.getTemperaturaEmC() << endl;
    cout << "Temperatura em Fahreinheit: " << sensorTemperatura.getTemperaturaEmF() << endl;
    cout << "Temperatura em Kelvin: " << sensorTemperatura.getTemperaturaEmK() << endl;
    int temperatura = sensorTemperatura.getTemperaturaEmC();

    // Criando um ventilador
    Ventilador atuadorVentilador(false, true, temperatura);

    // Criando uma sala com o sensor e o atuador
    Sala sala;
    sala.adicionarSensor(&sensorTemperatura);
    sala.adicionarAtuador(&atuadorVentilador);

    // Atualizando e exibindo os valores dos sensores
    sala.atualizarSensores(temperatura);

    // Atualizando o estado dos atuadores com base nos sensores
    sala.atualizarAtuadores(temperatura);

//_______________________________________________________________

    random_device random;
    mt19937 gen(random()); // gerar números aleatórios.
    uniform_int_distribution<> dis(0, 1); // Distribuição uniforme entre -1 e 1

    temperatura = 20;

    while (true) {
        // Simula o aumento ou diminuição da temperatura de forma aleatória
        temperatura += dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura

        // Limita a temperatura entre 15 e 35 graus
        temperatura = max(15, min(35, temperatura));

        // Pausa para simular o tempo passando
        sleep(1);

        // Atualiza o valor do sensor de temperatura
        sensorTemperatura.setValor(temperatura);
        cout << sensorTemperatura.getTemperaturaEmC() << endl;
        sala.atualizarSensores(temperatura);
        sala.atualizarAtuadores(temperatura);
        // cout << temperatura << endl;
    }


}
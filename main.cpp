#include <iostream>
#include <random>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <conio.h>  // Usado para detectar pressionamento de tecla no Windows (getch())
#include <cstdlib> // para usar system()

#include "Sala.cpp"
#include "Temperatura.cpp"
#include "Luminosidade.cpp"
#include "Ventilador.cpp"
#include "Lampada.cpp"
using namespace std;    

// Variável global para detectar quando o usuário pressiona 'L'l
atomic<bool> apertouL(false);
atomic<bool> rodando(true);  // Variável para controlar o término das threads

void detectarInput() {
    char ch;
    while (rodando) { // rodando é por garantia de que vai sempre funcionar
        if (_kbhit()) {  // Verifica se há uma tecla sendo pressionada, evitando que o programa fique preso esperando um input.
            ch = _getch();  // Detecta pressionamento de tecla
            if (ch == 'L' || ch == 'l') {
                apertouL = true;
                cout << "apertouuuu!" << endl;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(100));  // Pequena pausa para evitar loop rápido demais
    }
}

//! Quarto
int main() {

    // Inicia uma thread para monitorar a entrada do usuário
    thread inputThread(detectarInput);

    // Para restringir na hora de selecionar o sensor
    string tipo;

    // Temperatura Ambiente
    int temperatura = 25;
    // Luminosidade Ambiente (praticamente escuro)
    int luminosidade = 0;

    // Criando uma sala com o sensor e o atuador
    Sala sala;

    // Criando um sensor de temperatura
    Temperatura sensorTemperatura(true, true, temperatura);
    sala.adicionarSensor(&sensorTemperatura);

    // Criando um sensor de temperatura
    Luminosidade sensorLuminosidade(true, true, luminosidade);
    sala.adicionarSensor(&sensorLuminosidade);

    // Criando um ventilador
    Ventilador atuadorVentilador(false, true, temperatura);
    sala.adicionarAtuador(&atuadorVentilador);
    bool vLigado = atuadorVentilador.getLigado();

    // Criando uma Lampada
    Lampada atuadorLampada(false, true, luminosidade);
    sala.adicionarAtuador(&atuadorLampada);
    bool lLigado = atuadorVentilador.getLigado();


//_______________________________________________________________
// Temperatura e Ar-codicionado

    random_device random;
    mt19937 gen(random()); // gerar números aleatórios.
    uniform_int_distribution<> dis(0, 1); // Distribuição uniforme entre -1 e 1

    while (true) {
        
        // Atualiza o valor do sensor de temperatura
        tipo = "TEMPERATURA";
        if (atuadorVentilador.getConectado()) {
            // Simula o aumento ou diminuição da temperatura de forma aleatória
            temperatura += dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura
            // Limita a temperatura entre 15 e 35 graus
            temperatura = max(15, min(35, temperatura));
            // Atualiza o valor do sensor de temperatura
            sensorTemperatura.setValor(temperatura);
            // Imprime a temperatura
            sensorTemperatura.printTemperatura();

            // Atualizando os valores dos sensores
            sala.atualizarSensores(temperatura, tipo); 
            // Atualizando o estado dos atuadores com base nos sensores
            sala.atualizarAtuadores(vLigado, temperatura, tipo); 

            // Depois de atualizado, armazenar na variavel ligado, temperatura
            vLigado = atuadorVentilador.getLigado();
            temperatura = sensorTemperatura.getTemperatura();
        }

        

        // cout << "("<< temperatura << ")" <<endl;
        // cout << "("<< atuadorVentilador.getLigado() << ")" <<endl;
        
    // }

//_______________________________________________________________
// Luminosidade e Lampada


        tipo = "LUMINOSIDADE";

        // Imprime a Intesidadecda Luz
        sensorLuminosidade.printIntesidade();

        // Para ligar ou desligar é apenas apertar a letra L (Luz)
        if (apertouL) {
            
            // cout << "prontooo" << endl;
            apertouL = false;
            // rodando = false; // Sinaliza para parar o loop principal e a thread de input
            // break;

            sala.atualizarSensores(luminosidade, tipo);
            sala.atualizarAtuadores(lLigado, luminosidade, tipo);

            lLigado = atuadorLampada.getLigado();
            luminosidade = sensorLuminosidade.getIntesidadeLuz();
        }

        
        // Pausa para simular o tempo passando
        sleep(1);
        // Limpa a tela
        system("cls"); 
        
    }

    // Espera a thread de input finalizar antes de encerrar o programa
    inputThread.join();
}




//? Perguntar da função lá em cima
//? Perguntar do printTemperatura, se seria legal fazer na sala, e como fazer
/*********************************************************************************
Temperatura ambiente: 25°C

Sala de cinema -> Ar codicionado ligado direto e aumentar a luz quando nao tiver o filme, começou o filme, abaixa a luminação 
    30 min antes de começar - 30 min depois de terminar
    Ar-Codicionado: 22°
    Luz: Durante o filme: 10lux  |  Acabou o filme: vai aumentando aos poucos até 350lux

Quarto -> Umidificador quando dormir , Luz ligada quando estiver acordado, pedir pro usuario desligar a luz, e depois ligar, ar codicionado automatizado, deixar ligado por um tempo, depois desligar automaticamente, e depois ligar, se esquentar muito
    30 min antes de dormir - 30 min depois de acordar
    Umidificador:  40%-60% -> enquanto dorme
    Ar-Codicionado: 22° -> liga e desliga automaticamente
    Luz: Quando acordado: 350lux  |  enquanto dorme: 0lux  |  quando acorda: 350lux

Cozinha -> Desumidificador pouco antes de terminar de cozinhar e deixar um tempo e depois desliga, Luz ligada quando estiver cozinhando,, depois desliga
    15 min antes de terminar de cozinnhar  - 30 min depois de terminar
    Desumidificador :  40%-60%
    Luz: ligada em 500lux (bem iluminada)

*********************************************************************************/
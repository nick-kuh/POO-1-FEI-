#pragma once
// #include <iostream>
// #include <random>
// #include <unistd.h>
// #include <thread>
// #include <atomic>
// #include <conio.h>  // Usado para detectar pressionamento de tecla no Windows (getch())
// #include <windows.h>
// #include <cstdlib> // Para usar a função exit()

// #include "Sala.cpp"
// #include "Temperatura.cpp"
// #include "Luminosidade.cpp"
// #include "Umidade.cpp"
// #include "Ventilador.cpp"
// #include "Lampada.cpp"
// #include "Umidificador.cpp"
// #include "print.cpp"
// #include "time.cpp"
using namespace std;    

//_______________________________________________________________
// Configuração Inicial do Ambiente e Criação de Sensores e Atuadores

//! Quarto
void quarto() {
    // Conta quantas execuções foram feitas
    int n = 0;

    int estado; 

    // Inicia uma thread para monitorar a entrada do usuário
    thread inputThread(detectarInput);

    // Para restringir na hora de selecionar o sensor e o atuador
    string tipo;

    // Temperatura Ambiente
    int temperatura = 25;
    // Luminosidade Ambiente (praticamente escuro)
    int luminosidade = 0;
    // Limiar Claridade para quarto
    int limiarClaridade = 0;
    // Umidade Ambiente
    int umidade = 50;

    // Definindo o horario Inicial, e terá duração de 8 horas nesta sala
    int dia, hora, minuto, segundo = 0, hFinal, mFinal;
    cout << "Digite a hora inicial (DD HH MM): ";
    cin >> dia >> hora >> minuto;
    // while (!((0 < dia) && (dia < 31) || (0 < hora) && (hora < 24) || (0 < minuto) && (minuto < 60))){
        // cout << "Digite corretamente (DD HH MM): ";
        // cin >> dia >> hora >> minuto;
    // }
    bool modoDormir = 0; // Inicializando no Modo Acordado


    // Criando uma sala com o sensor e o atuador
    Sala sala;

    // Criando um sensor de Temperatura
    Temperatura sensorTemperatura(true, true, temperatura);
    sala.adicionarSensor(&sensorTemperatura);

    // Criando um sensor de Luminosidade
    Luminosidade sensorLuminosidade(true, true, luminosidade);
    sala.adicionarSensor(&sensorLuminosidade);

    // Criando um sensor de Umidade
    Umidade sensorUmidade(true, true, umidade);
    sala.adicionarSensor(&sensorUmidade);

    // Criando um Ventilador
    Ventilador atuadorVentilador(false, true, temperatura);
    sala.adicionarAtuador(&atuadorVentilador);
    bool vLigado = atuadorVentilador.getLigado();

    // Criando uma Lampada
    Lampada atuadorLampada(false, true, luminosidade);
    sala.adicionarAtuador(&atuadorLampada);
    bool lLigado = atuadorLampada.getLigado();

    // Criando um Umidificador
    Umidificador atuadorUmidificador(false, true, umidade);
    sala.adicionarAtuador(&atuadorUmidificador);
    bool uLigado = atuadorUmidificador.getLigado();

    // Criando um Desumidificador
    Desumidificador atuadorDesumidificador(false, false, umidade);
    sala.adicionarAtuador(&atuadorDesumidificador);
    bool dLigado = atuadorDesumidificador.getLigado();

//_______________________________________________________________
// "Inicialização do Ambiente de Execução"

    random_device random;
    mt19937 gen(random()); // gerar números aleatórios.
    uniform_int_distribution<> dis(0, 1); // Distribuição uniforme entre -1 e 1

    // Limpando a tela uma vez no início para ter um terminal limpo
    cout << "\033[2J";  // Sequência ANSI para limpar o terminal inteiro

    while (true) {
//_______________________________________________________________
// Temperatura e Ventilador

        // Atualiza o valor do sensor de temperatura
        tipo = "TEMPERATURA";
        if (atuadorVentilador.getConectado()) {
            if(modoDormir){
                estado = 1; // Dizer que esta no modo dormir la na classe Sala
                if (temperatura == 22 && vLigado){
                    temperatura = 23; // FOi colcado 23, pois depois quando for atualizar, ele vai atualizar automaticamente para 22
                    if (n%32 == 0){
                        temperatura += dis(gen); // Adicionando o dis para ser mais aleartório
                        temperatura --; // Diminuindo a temperatura, se caso o codigo acima adicionar mais, aqui vai manter 22, se for 0, vai diminuir para 21 e depois desliga o ventilador
                    }
                }
                else{
                    // Simula o aumento ou diminuição da temperatura de forma aleatória
                    temperatura += dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura
                    // Limita a temperatura entre 15 e 35 graus
                    temperatura = max(10, min(40, temperatura));
                }

                // Atualizando o estado dos atuadores
                sala.atualizarAtuadores(vLigado, temperatura, tipo, apertouL, estado);

                // Depois de atualizado, armazenar na variavel ligado, temperatura
                vLigado = atuadorVentilador.getLigado();
                temperatura = sensorTemperatura.getTemperaturaEmC();
            }
            else{
                estado = 2; // Dizer que esta no modo dormir la na classe Sala (Modo Arcodado)
                vLigado = atuadorVentilador.desligar();
                sala.atualizarAtuadores(vLigado, temperatura, tipo, apertouL, estado);

            }
        }

//_______________________________________________________________
// Luminosidade e Lampada

        tipo = "LUMINOSIDADE";

        if (modoDormir){
            estado = 2;
            sensorLuminosidade.setLimiarClaridade(30); // Para nao ficar muito claro, quando quiser acordar no meio da noite

            if(sensorLuminosidade.estaClaro()){
                luminosidade = 25;
                sala.atualizarAtuadores(lLigado, luminosidade, tipo, apertouL, estado);
            }
        }
        else{
            estado = 1;
            sensorLuminosidade.setLimiarClaridade(300); 
            // limiarClaridade = sensorLuminosidade.getLimiarClaridade();

            if(!sensorLuminosidade.estaClaro() && luminosidade != 0){
                luminosidade = 300;
                sala.atualizarAtuadores(lLigado, luminosidade, tipo, apertouL, estado);   
            }
        }

        // Para ligar ou desligar é apenas apertar a letra L (Luz)
        if (apertouL) {
            sala.atualizarAtuadores(lLigado, luminosidade, tipo, apertouL, estado);
            lLigado = atuadorLampada.getLigado();
            luminosidade = sensorLuminosidade.getLuminosidade();
            apertouL = false;
        }

//_______________________________________________________________
// Umidade, Umidificador e Desumidificador

        // Atualiza o valor do sensor de temperatura
        tipo = "UMIDADE";
        if (atuadorUmidificador.getConectado()) {
            if(modoDormir){
                if (n%4 == 0){
                    // Simula o aumento ou diminuição da temperatura de forma aleatória
                    umidade -= dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura
                    // Limita a temperatura entre 15 e 35 graus
                    umidade = max(15, min(80, umidade));
                    // Atualizando o estado dos atuadores
                    sala.atualizarAtuadores(uLigado, umidade, tipo, apertouL, estado);

                    // Depois de atualizado, armazenar na variavel ligado, temperatura
                    uLigado = atuadorUmidificador.getLigado();
                    umidade = sensorUmidade.getUmidadeRelativa();  
                }   
            }
        }

//_______________________________________________________________
// Atualização do Terminal

        // Pausa para simular o tempo passando
        this_thread::sleep_for(chrono::milliseconds(250));
        // cout << endl;
        
        print(sensorTemperatura, atuadorVentilador, sensorLuminosidade, atuadorLampada, sensorUmidade, atuadorUmidificador, atuadorDesumidificador, apertouL);

        if(apertouD){
            if (modoDormir){
                modoDormir = false;
            }
            else{
                modoDormir = true;
            }
            apertouD = false;
        }

        if (n>=1440){
            break;
        }
        else{
            tie(dia, hora, minuto, segundo) = time(dia, hora, minuto, segundo, 20);
        }

        n += 1;
        cout << "  |  Execuções: "<< n;
        if (modoDormir) {
            if (n >= 10 && n < 100) {
                cout << "  |  Modo Dormir" << "\033[50G" << "\033[K";  // Ajusta para números com 2 dígitos
            }
            else if (n >= 100 && n < 1000) {
                cout << "  |  Modo Dormir" << "\033[51G" << "\033[K";  // Ajusta para números com 3 dígitos
            }
            else if (n >= 1000) {
                cout << "  |  Modo Dormir" << "\033[52G" << "\033[K";  // Ajusta para números com 4 dígitos
            }
            else {
                cout << "  |  Modo Dormir" << "\033[49G" << "\033[K";  // Ajusta para números com 1 dígito
            }
        } 
        else {
            if (n >= 10 && n < 100) {
                cout << "  |  Modo Acordado" << "\033[53G" << "\033[K";  // Ajusta para números com 2 dígitos
            }
            else if (n >= 100 && n < 1000) {
                cout << "  |  Modo Acordado" << "\033[54G" << "\033[K";  // Ajusta para números com 3 dígitos
            }
            else if (n >= 1000) {
                cout << "  |  Modo Acordado" << "\033[55G" << "\033[K";  // Ajusta para números com 4 dígitos
            }
            else {
                cout << "  |  Modo Acordado" << "\033[52G" << "\033[K";  // Ajusta para números com 1 dígito
            }
        } 
        cout << " " << sensorTemperatura.getLigado();
    }
}





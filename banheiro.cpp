#pragma once
// #include <iostream>
// #include <random>
// #include <unistd.h>
// #include <thread>
// #include <windows.h>
// #include <atomic>
// #include <conio.h>  // Usado para detectar pressionamento de tecla no Windows (getch())


// #include "Sala.cpp"
// #include "Temperatura.cpp"
// #include "Luminosidade.cpp"
// #include "Umidade.cpp"
// #include "Ventilador.cpp"
// #include "Lampada.cpp"
// #include "Umidificador.cpp"
// #include "Desumidificador.cpp"
// #include "print.cpp"
// #include "time.cpp"
// #include "ajusteTime.cpp"
// using namespace std;    


// atomic<bool> apertouL(false);
// atomic<bool> rodando(true);  // Variável para controlar o término das threads

// void detectarInput() {
//     char ch;
//     while (rodando) { // rodando é por garantia de que vai sempre funcionar
//         if (_kbhit()) {  // Verifica se há uma tecla sendo pressionada, evitando que o programa fique preso esperando um input.
//             ch = _getch();  // Detecta pressionamento de tecla
//             if (ch == 'L' || ch == 'l') {
//                 apertouL = true;
//                 cout << "\033[24;1H"; 
//                 cout << "apertouuuu!" << endl;

//                 // Pausa para manter a mensagem visível por 0,5 segundos
//                 this_thread::sleep_for(chrono::milliseconds(500));

//             }
//         }
//         this_thread::sleep_for(chrono::milliseconds(150));  // Pequena pausa para evitar loop rápido demais
//     }
// }

//_______________________________________________________________
// Configuração  do Ambiente e Criação de Sensores e Atuadores

//! Quarto
void banheiro() {
    // Garante que todos os caracteres especiais funcionem no terminal
    // SetConsoleOutputCP(CP_UTF8);

    // Conta quantas execuções foram feitas
    int n = 0;

    // Inicia uma thread para monitorar a entrada do usuário
    thread inputThread(detectarInput);

    // Para restringir na hora de selecionar o sensor e o atuador
    string tipo;

    int estado = 0; // Nao existe este estado

    // Temperatura Ambiente
    int temperatura = 25;
    // Luminosidade Ambiente (praticamente escuro)
    int luminosidade = 0;
    // Limiar Claridade para quarto
    int limiarClaridade = 250;
    // Umidade Ambiente
    int umidade = 40;

    int dia = 1, hora, minuto, segundo = 0;


    // Criando uma sala com o sensor e o atuador
    Sala sala;

    // Criando um sensor de Temperatura
    Temperatura sensorTemperatura(false, false, temperatura);
    sala.adicionarSensor(&sensorTemperatura);

    // Criando um sensor de Luminosidade
    Luminosidade sensorLuminosidade(true, true, luminosidade);
    sala.adicionarSensor(&sensorLuminosidade);
    sensorLuminosidade.setLimiarClaridade(limiarClaridade);

    // Criando um sensor de Umidade
    Umidade sensorUmidade(true, true, umidade);
    sala.adicionarSensor(&sensorUmidade);

    // Criando um Ventilador
    Ventilador atuadorVentilador(false, false, temperatura);
    sala.adicionarAtuador(&atuadorVentilador);
    bool vLigado = atuadorVentilador.getLigado();

    // Criando uma Lampada
    Lampada atuadorLampada(false, true, luminosidade);
    sala.adicionarAtuador(&atuadorLampada);
    bool lLigado = atuadorLampada.getLigado();

    // Criando um Umidificador
    Umidificador atuadorUmidificador(false, false, umidade);
    sala.adicionarAtuador(&atuadorUmidificador);
    bool uLigado = atuadorUmidificador.getLigado();

    // Criando um Desumidificador
    Desumidificador atuadorDesumidificador(false, true, umidade);
    sala.adicionarAtuador(&atuadorDesumidificador);
    bool dLigado = atuadorDesumidificador.getLigado();

//_______________________________________________________________
// "Inicialização do Ambiente de Execução"

    random_device random;
    mt19937 gen(random()); // gerar números aleatórios.
    uniform_int_distribution<> dis(0, 1); // Distribuição uniforme entre -1 e 1 (Para temperatura e umidade)

    // Limpando a tela uma vez no início para ter um terminal limpo
    cout << "\033[2J";  // Sequência ANSI para limpar o terminal inteiro

    while (true) {
//_______________________________________________________________
// Temperatura e Ventilador

        // Não irá ter ventilador
        tipo = "TEMPERATURA";
        if (atuadorVentilador.getConectado()) {

            if (temperatura == 23 && vLigado){
                temperatura = 24; // Foi colocado 24, pois depois quando for atualizar, ele vai atualizar automaticamente para 23
                if (n%32 == 0){
                    temperatura += dis(gen); // Adicionando o dis para ser mais aleartório
                    temperatura --; // Diminuindo a temperatura, se caso o codigo acima adicionar mais, aqui vai manter 23, se for 0, vai diminuir para 21 e depois desliga o ventilador
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

//_______________________________________________________________
// Luminosidade e Lampada

        tipo = "LUMINOSIDADE";

        if (apertouL){
            if (estado == 0){
                estado = 1; // Estado 1 -> A banheiro está sendo usado
            }
            else if(estado == 1 && sensorLuminosidade.estaClaro()){
                estado = 2; // Terminou de tomar o banho, assim ligando o desumidificador e desligando a luz
            }

            sala.atualizarAtuadores(lLigado, luminosidade, tipo, apertouL, estado);

            lLigado = atuadorLampada.getLigado();
            luminosidade = sensorLuminosidade.getLuminosidade();

            apertouL = false;
        }

//_______________________________________________________________
// Umidade, Umidificador e Desumidificador

        // Atualiza o valor do sensor deumidade
        tipo = "UMIDADE";
        if (atuadorUmidificador.getConectado()) {
            // Simula o aumento ou diminuição da temperatura de forma aleatória
            umidade -= dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura
            // Limita a temperatura entre 15 e 35 graus
            umidade = max(0, min(100, umidade));


            // Atualizando o estado dos atuadores
            sala.atualizarAtuadores(uLigado, umidade, tipo, apertouL, estado);

            // Depois de atualizado, armazenar na variavel ligado, temperatura
            uLigado = atuadorUmidificador.getLigado();
            umidade = sensorUmidade.getUmidadeRelativa();
        }

        else if (atuadorDesumidificador.getConectado()) {
            if(sensorLuminosidade.estaClaro()){
                estado = 1;
                // Simula o aumento ou diminuição da temperatura de forma aleatória
                umidade += dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura
                // Limita a temperatura entre 15 e 35 graus
                umidade = max(0, min(100, umidade));
                // if (umidade => 80){
                sala.atualizarAtuadores(dLigado, umidade, tipo, apertouL, estado);
                // }
            }
            else{
                if (estado == 2 && !atuadorDesumidificador.getLigado()){
                    estado = 0; // Vai para o estado Inicial 
                }
                // // if (umidade > 65){
                //     sala.atualizarAtuadores(dLigado, umidade, tipo, apertouL, estado); 
                // }
                sala.atualizarAtuadores(dLigado, umidade, tipo, apertouL, estado);
                // dLigado = atuadorDesumidificador.getLigado();
                // umidade = sensorUmidade.getUmidadeRelativa();
            }
            // Atualizando o estado dos atuadores
            // sala.atualizarAtuadores(uLigado, umidade, tipo, apertouL, estado); 

            // Depois de atualizado, armazenar na variavel ligado, temperatura
            dLigado = atuadorDesumidificador.getLigado();
            umidade = sensorUmidade.getUmidadeRelativa();
        }

//_______________________________________________________________
// Atualização do Terminal

        // Pausa para simular o tempo passando
        this_thread::sleep_for(chrono::milliseconds(150));
        
        print(sensorTemperatura, atuadorVentilador, sensorLuminosidade, atuadorLampada, sensorUmidade, atuadorUmidificador, atuadorDesumidificador, apertouL);


        if (n >= 1440){
            break;
        }
        else{
            tie(dia, hora, minuto, segundo) = time(dia, hora, minuto, segundo, 30);
        }

        n += 1;
        cout << "  |  Execuções: "<< n;
        cout << "  |  Estado: "<< estado;
        cout << "  |  U: "<< umidade;

    }
}

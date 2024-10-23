#pragma once
// #include <iostream>
// #include <random>
// #include <unistd.h>
// #include <thread>
// #include <windows.h>

// #include "Sala.cpp"
// #include "Temperatura.cpp"
// #include "Luminosidade.cpp"
// #include "Umidade.cpp"
// #include "Ventilador.cpp"
// #include "Lampada.cpp"
// #include "Umidificador.cpp"
// #include "print.cpp"
// #include "time.cpp"
// #include "ajusteTime.cpp"
// using namespace std;    

//_______________________________________________________________
// Configuração  do Ambiente e Criação de Sensores e Atuadores

//! Quarto
void cinema() {
    // Garante que todos os caracteres especiais funcionem no terminal
    // SetConsoleOutputCP(CP_UTF8);

    // Conta quantas execuções foram feitas
    int n = 0;

    // Para restringir na hora de selecionar o sensor e o atuador
    string tipo;

    // Nao vai ser usado nesta sala, entao é falso
    bool apertouL = 0; 


    // Temperatura Ambiente
    int temperatura = 25;
    // Luminosidade Ambiente (praticamente escuro)
    int luminosidade = 0;
    // Limiar Claridade para quarto
    int limiarClaridade = 150;
    // Umidade Ambiente
    int umidade = 50;
    // Definindo o horario Inicial e Final
    int dia = 1;
    int hora, minuto, segundo, horaFinal, minutoFinal, horaEstado, minutoEstado;
    cout << "Digite a hora de início (HH MM): ";
    cin >> hora >> minuto;
    segundo = 0;
    int estado = 0; // Inicializa o programa no estado 0 
    horaEstado = hora; 
    minutoEstado = minuto; 


    // Criando uma sala com o sensor e o atuador
    Sala sala;

    // Criando um sensor de Temperatura
    Temperatura sensorTemperatura(true, true, temperatura);
    sala.adicionarSensor(&sensorTemperatura);

    // Criando um sensor de Luminosidade
    Luminosidade sensorLuminosidade(true, true, luminosidade);
    sala.adicionarSensor(&sensorLuminosidade);
    sensorLuminosidade.setLimiarClaridade(limiarClaridade);

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
    uniform_int_distribution<> dis(0, 1); // Distribuição uniforme entre -1 e 1 (Para temperatura e umidade)

    // Limpando a tela uma vez no início para ter um terminal limpo
    cout << "\033[2J";  // Sequência ANSI para limpar o terminal inteiro

    while (true) {
//_______________________________________________________________
// Temperatura e Ventilador

        // Atualiza o valor do sensor de temperatura
        tipo = "TEMPERATURA";
        if (atuadorVentilador.getConectado()) {
            // // Simula o aumento ou diminuição da temperatura de forma aleatória
            // temperatura += dis(gen); // Adiciona um valor aleatório entre -1 e 1 à temperatura
            // // Limita a temperatura entre 15 e 35 graus
            // temperatura = max(15, min(35, temperatura));
            // lLigado = atuadorLampada.ligar(); // Deve estar ligado direto

            // Quando fechar, garante deligar o Ventilador 
            if(estado == 5){
                vLigado = atuadorVentilador.desligar();
            }
            if (temperatura == 22 && vLigado){
                temperatura = 23; // FOi colcado 23, pois depois quando for atualizar, ele vai atualizar automaticamente para 22
                if (n%32 == 0){
                    temperatura += dis(gen); // Adicionando o dis para ser mais aleartório
                    temperatura --; // Diminuindo a temperatura, se caso o codigo acima adicionar mais, aqui vai manter 22, se for 0, vai diminuir para 21 e depois desliga o ventilador
                }
            }
            else{
                if (n%4 == 0){
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


        }

//_______________________________________________________________
// Luminosidade e Lampada

        tipo = "LUMINOSIDADE";

        if (estado == 1) {
            cout << "  |  Pré-Sessão";
            cout << "\033[50G" << "\033[K";
            if (!sensorLuminosidade.estaClaro()){
                luminosidade += 30; 
            }
        }
        else if (estado == 2){
            cout << "  |  Rodada de trailers";
            cout << "\033[58G" << "\033[K";
            sensorLuminosidade.setLimiarClaridade(30); // Com anuncios terá pelo menos 30 de limiarClaridade
            if (sensorLuminosidade.estaClaro()){
                luminosidade -= 31; 
            }
        }
        else if (estado == 3){
            cout << "  |  Sessão em andamento";
            cout << "\033[60G" << "\033[K";
            sensorLuminosidade.setLimiarClaridade(5); // Com filme rolando, teremos uma luminosidade baixissima, com 5 de limiarClaridade
            if (sensorLuminosidade.estaClaro()){
                luminosidade -= 11; 
            }
        }
        else if (estado == 4){
            cout << "  |  Pós-Sessão";
            cout << "\033[51G" << "\033[K";
            sensorLuminosidade.setLimiarClaridade(150); // Depois de finalizar o filme, vai aumentar para 150
            if (!sensorLuminosidade.estaClaro()){
                luminosidade += 30; 
            }
        }
        else if(estado == 5){
            cout << "  |  Fechado";
            cout << "\033[48G" << "\033[K";
            sensorLuminosidade.setLimiarClaridade(0); // Depois de 30 min, nao tem ninguem, entao desligará a luz automaticamente
            luminosidade = 0; 
        }

        sala.atualizarAtuadores(lLigado, luminosidade, tipo, apertouL, estado);

        lLigado = atuadorLampada.getLigado();
        luminosidade = sensorLuminosidade.getLuminosidade();

//_______________________________________________________________
// Temperatura e Ventilador

        // Atualiza o valor do sensor de temperatura
        tipo = "UMIDADE";
        if (atuadorUmidificador.getConectado()) {

            // Quando fechar, garante deligar o Umidificador 
            if(estado == 5){
                uLigado = atuadorUmidificador.desligar();
            }

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

//_______________________________________________________________
// Atualização do Terminal

        // Pausa para simular o tempo passando
        this_thread::sleep_for(chrono::milliseconds(250));
        // cout << endl;
        
        print(sensorTemperatura, atuadorVentilador, sensorLuminosidade, atuadorLampada, sensorUmidade, atuadorUmidificador, atuadorDesumidificador, apertouL);


        if ((estado == 0)){
            estado = 1; // Começa no primeiro estado (30 min antes do filme)
            tie(horaEstado, minutoEstado) = ajusteTime(horaEstado, minutoEstado,30);
        }
        
        else if ((hora == horaEstado && minuto == minutoEstado) && (estado == 1)){
            estado = 2; // Começa os anúncios (15 min)
            tie(horaEstado, minutoEstado) = ajusteTime(horaEstado, minutoEstado,15);

        }
        else if ((hora == horaEstado && minuto == minutoEstado) && (estado == 2)){
            estado = 3; // Começa o filme (150 min)
            tie(horaEstado, minutoEstado) = ajusteTime(horaEstado, minutoEstado,150);

        }
        else if ((hora == horaEstado && minuto == minutoEstado) && (estado == 3)){
            estado = 4; // Pós-Sessão (30 min)
            tie(horaEstado, minutoEstado) = ajusteTime(horaEstado, minutoEstado, 15);
        }
        else if ((hora == horaEstado && minuto == minutoEstado) && (estado == 4)){
            estado = 5; // Ultimo estado e finalizará o programa
        }

        // Foi colocado o segundo > 0, pois era preciso executar mais uma vez, para conseguir desligar todos os atuadores
        if (estado == 5 && n >= 1440 & segundo > 0){
            break;
        }
        else{
            tie(dia, hora, minuto, segundo) = time(dia, hora, minuto, segundo, 9);
        }

        n += 1;
        cout << "  |  Execuções: "<< n;

    }
    // exit(0); // Encerra o programa completamente de forma limpa
}

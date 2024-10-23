#include <iostream>
#include <atomic>
#include <random>
#include <unistd.h>
#include <thread>
// #include <windows.h>
#include <cstdlib> // Para usar a função exit()

#include "Sala.cpp"
#include "Temperatura.cpp"
#include "Luminosidade.cpp"
#include "Umidade.cpp"
#include "Ventilador.cpp"
#include "Lampada.cpp"
#include "Umidificador.cpp"
#include "Desumidificador.cpp"
#include "ajusteTime.cpp"
#include "print.cpp"
#include "time.cpp"
#include "detectarInput.cpp"
#include "quarto.cpp"
#include "cinema.cpp"
#include "banheiro.cpp"
#include "msgInicial.cpp"

using namespace std;    
 
int main() {

    // Garante que todos os caracteres especiais funcionem no terminal
    // SetConsoleOutputCP(CP_UTF8);

    msgInicial();

    int escolha;
    cin >> escolha;
    if (escolha == 1){
        quarto();
    }

    else if (escolha == 2){
        cinema();
    }

    else if (escolha == 3){
        banheiro();
    }
    exit(0); // Encerra o programa completamente de forma limpa
    return 0;
}






/*********************************************************************************
Temperatura ambiente: 25°C

Sala de cinema -> Ar codicionado ligado direto e aumentar a luz quando nao tiver o filme, começou o filme, abaixa a luminação 
    30 min antes de começar - 30 min depois de terminar
    Ar-Codicionado: 22°
    Luz: Durante o filme: 5lux  |  Acabou o filme: vai aumentando aos poucos até 150lux

Quarto -> Umidificador quando dormir , Luz ligada quando estiver acordado, pedir pro usuario desligar a luz, e depois ligar, ar codicionado automatizado, deixar ligado por um tempo, depois desligar automaticamente, e depois ligar, se esquentar muito
    30 min antes de dormir - 30 min depois de acordar
    Umidificador:  40%-60% -> enquanto dorme
    Ar-Codicionado: 22° -> liga e desliga automaticamente
    Luz: Quando acordado: 300lux  |  enquanto dorme: 0lux  |  quando acorda: 350lux

Banheiro (na hora de tomar banho) -> Desumidificador na hora de desligar a luz (quando a pessoa sai do banheiro) e deixar um tempo e depois desliga, Luz ligada quando estiver tomando banho, depois desliga E ventilador desconectado
    3 min antes de entrar no banho  - 30 min depois de tomar banho (e o processo será repetido)
    Desumidificador :  40%-60%
    Luz: ligada em 400lux (bem iluminada)

*********************************************************************************/
#pragma once
#include <iostream>
#include <iomanip>  // Para usar std::setw
#include <chrono>

using namespace std;
// using namespace std::chrono;

std::tuple<int, int, int, int> time(int dia, int hora, int minuto, int segundo, int incremento){

    // Definindo a linha para imprimir
    cout << "\033[23;1H";

    // Exibe o horário atual formatado
    cout << "Dia " << dia << "  " << (hora < 10 ? "0" : "") << hora 
                << ":" << (minuto < 10 ? "0" : "") << minuto 
                << ":" << (segundo < 10 ? "0" : "") << segundo << flush;
                

    // A cada sala, será adicionado um intervalo de tantos segundos.
    segundo += incremento;

    // Ajusta os segundos e minutos se necessário
    if (segundo >= 60) {
        segundo = 0;
        minuto++;
    }

    // Ajusta os minutos e horas se necessário
    if (minuto >= 60) {
        minuto = 0;
        hora++;
    }
    // Se as horas passarem de 23, começa um novo dia (volta para 0)
    if (hora >= 24) {
        hora = 0;
        dia++;
    }

    return {dia, hora, minuto, segundo};
}
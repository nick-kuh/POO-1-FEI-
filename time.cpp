#pragma once // Garante que o arquivo seja incluído apenas uma vez durante a compilação
#include <iostream>  // Biblioteca padrão para entrada/saída
#include <iomanip>   // Para usar std::setw para formatação de saída
#include <chrono>    // Inclui a biblioteca de tempo (não utilizada diretamente, mas pode ser útil no futuro)

using namespace std;

// Função para simular o tempo avançando em uma base de incremento de segundos
// Retorna uma tupla contendo o dia, hora, minuto e segundo atualizados
std::tuple<int, int, int, int> time(int dia, int hora, int minuto, int segundo, int incremento) {

    // Move o cursor do terminal para a posição especificada (linha 23, coluna 1) para imprimir o horário
    cout << "\033[23;1H";

    // Exibe o horário atual no formato "Dia XX HH:MM:SS" com preenchimento de zeros à esquerda, se necessário
    cout << "Dia " << dia << "  " << (hora < 10 ? "0" : "") << hora 
         << ":" << (minuto < 10 ? "0" : "") << minuto 
         << ":" << (segundo < 10 ? "0" : "") << segundo << flush;

    // Incrementa os segundos com base no valor fornecido
    segundo += incremento;

    // Verifica se os segundos ultrapassaram 59, e ajusta para o próximo minuto
    if (segundo >= 60) {
        segundo = 0; // Reseta os segundos
        minuto++;    // Incrementa os minutos
    }

    // Verifica se os minutos ultrapassaram 59, e ajusta para a próxima hora
    if (minuto >= 60) {
        minuto = 0;  // Reseta os minutos
        hora++;      // Incrementa a hora
    }

    // Verifica se as horas ultrapassaram 23, e ajusta para o próximo dia
    if (hora >= 24) {
        hora = 0;    // Reseta as horas
        dia++;       // Incrementa o dia
    }

    // Retorna uma tupla contendo o dia, hora, minuto e segundo atualizados
    return {dia, hora, minuto, segundo};
}

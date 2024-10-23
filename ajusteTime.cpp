#include <iostream>
#include <iomanip>

using namespace std;

tuple <int, int> ajusteTime(int hora, int minuto, int addMinutos) {
    // Calcula o número de horas a partir dos minutos
    int addHoras = addMinutos / 60;

    // O restante dos minutos após retirar as horas
    addMinutos = addMinutos % 60;

    // Adicionando os minutos
    minuto += addMinutos;
    
    // Se ultrapassar 60 minutos, adiciona uma hora e ajusta os minutos
    if (minuto >= 60) {
        minuto -= 60;
        hora += 1;
    }

    // Adicionando as horas
    hora += addHoras;
    
    // Se ultrapassar 24 horas, ajusta a hora para o formato de 24h
    if (hora >= 24) {
        hora -= 24;
    }

    return {hora, minuto};
}
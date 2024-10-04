#pragma once
#include <iostream>
#include <iomanip>  // Para usar std::setw

using namespace std;

void print(Temperatura &sensorTemperatura, Ventilador &atuadorVentilador,  Luminosidade &sensorLuminosidade, Lampada &atuadorLampada, bool apertouL){


    cout << "\033[1;1H";    // Move o cursor para a posição inicial no terminal (1,1)

    // Configurar largura das colunas
    int colWidth = 40;  // Largura de cada coluna para alinhar os textos

    // Linha 1: Títulos
    cout << left << setw(colWidth) << "Parte Temperatura"
         << "| " << setw(colWidth) << "Parte Luz"
         << "| " << setw(colWidth) << "Parte Umidade" << endl;

    // Linha 2: Valores de sensores
    cout << setw(colWidth) << (to_string(sensorTemperatura.getTemperatura()) + " C")
        << "| " << setw(colWidth) << (to_string(sensorLuminosidade.getIntesidadeLuz()) + " lux")
        << "| " << setw(colWidth) << "Por enquanto nao existe a umidade" << endl;
        //  << setw(colWidth) << (to_string(sensorUmidade.getUmidade()) + "%") << endl;

    // Linha 3: Status dos dispositivos
    cout << setw(colWidth) << (atuadorVentilador.getLigado() ? "Ventilador Ligado" : "Ventilador Desligado")
         << "| " << setw(colWidth) << (atuadorLampada.getLigado() ? "Lampada Acesa" : "Lampada Apagada")
         << "| " << setw(colWidth) << "Por enquanto nao existe a umidade" << endl;
        //  << setw(colWidth) << (umidificador.estaLigado() ? "Umidificador Ligado" : "Umidificador Desligado") << endl;

    

    cout<<"_______________________________________________________________________________________________________________________"<<endl;


// é caso houver algo "indesejado" que apareceu no terminal que deve ser apagado! 
    if(!apertouL){
        // Como a tabela tem 
        for (int i = 5; i < 50; i++){
            
            if(i==5){
                for (int j = 5; j < 20; j++){
                    cout << "\033[5;" << j << "H"; // 
                    cout << "\033[2K";
                }
            }
                cout << "\033[" << i << ";1H";   //
                cout << "\033[2K";  // Limpa a linha atual onde estava o "apertouuuu!"
        }
    }
    // cout << "\033[6;1H"; 
    // cout << "\033[2K";
 
}




    // cout << "Temperatura em Celsius: " << sensorTemperatura.getTemperatura() << endl;
    // cout << "Temperatura em Fahreinheit: " << sensorTemperatura.getTemperaturaEmF() << endl;
    // cout << "Temperatura em Kelvin: " << sensorTemperatura.getTemperaturaEmK() << endl;
    // if (atuadorVentilador.getLigado()){
    //     cout << "Ventilador Ligado" << endl;

    // }
    // else{
    //     cout << "Ventilador Desligado" << endl;

    // }

























    // cout <<"                                        \n"
    //     "                   #####                   \n"
    //     "                ####   ####                \n"
    //     "               ####     ####               \n"
    //     "                ####   ####                \n"
    //     "                  #######                  \n"
    //     "                  #######                  \n"
    //     "                                           \n"
    //     "                   #####                   \n"
    //     "                    ###                    \n"
    //     "                                           " << endl;


    // cout <<"                                        \n"
    //     "                                           \n"
    //     "               ##        ##                \n"
    //     "                ##      ##                 \n"
    //     "         ##                     ##         \n"
    //     "           ##      #####      ##           \n"
    //     "                ####   ####                \n"
    //     "       ####    ####     ####     ####      \n"
    //     "                ####   ####                \n"
    //     "           ##     #######     ##           \n"
    //     "          ##      #######      ##          \n"
    //     "                                           \n"
    //     "                   #####                   \n"
    //     "                    ###                    \n"
    //     "                                           " << endl;

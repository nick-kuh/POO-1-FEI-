#pragma once
#include <iostream>
#include <iomanip>  // Para usar std::setw

using namespace std;

void print(Temperatura &sensorTemperatura, Ventilador &atuadorVentilador, Luminosidade &sensorLuminosidade, Lampada &atuadorLampada, Umidade &sensorUmidade, Umidificador &atuadorUmidificador, Desumidificador &atuadorDesumidificador, bool apertouL){

     cout << "\033[1;1H";    // Move o cursor para a posição inicial no terminal (1,1)

     // Configurar largura das colunas
     int colWidth = 50;  // Largura de cada coluna para alinhar os textos

     // Linha 1: Títulos
     cout << left << setw(colWidth) << "Parte Temperatura"
          << "| " << setw(colWidth) << "Parte Luz"
          << "| " << setw(colWidth) << "Parte Umidade" << endl;

     // Linha 2: Separador
     cout << string(colWidth, '-') << "+" 
          << string(51, '-') << "+" 
          << string(colWidth, '-') << endl;

     // Linha 3: Valores de sensores
     cout << left << setw(colWidth) << (to_string(static_cast<int>(sensorTemperatura.getTemperaturaEmC())) + " C")
          << "| " << setw(colWidth) << ""  // Espaço vazio para a parte da luz
          << "| " << setw(colWidth) << "" << endl; // Espaço vazio para a umidade

          // Linha 4: Outros valores de temperatura
     cout << left << setw(colWidth) << (to_string(sensorTemperatura.getTemperaturaEmF()) + " F")// Conversão para Fahrenheit
          << "| " << setw(colWidth) << (to_string(sensorLuminosidade.getLuminosidade()) + " lux")
          << "| " << setw(colWidth) << (to_string(static_cast<int>(sensorUmidade.getUmidadeRelativa())) + " %") << endl;

     // Linha 5: Temperatura em Kelvin
     cout << left << setw(colWidth) << (to_string(sensorTemperatura.getTemperaturaEmK()) + " K") // Conversão para Kelvin
          << "| " << setw(colWidth) << "" // Espaço vazio para a parte da luz
          << "| " << setw(colWidth) << "" << endl; // Espaço vazio para a umidade

     // Linha 6: Separador
     cout << string(colWidth, '-') << "+" 
          << string(51, '-') << "+" 
          << string(colWidth, '-') << endl;

     // Linha 7: Status dos dispositivos (Como temos salas que, ou possuem apenas um umidificador, ou tem apenas um desumidificador)
     if (atuadorDesumidificador.getConectado()){
          cout << setw(colWidth) << (atuadorVentilador.getLigado() ? "Ventilador Ligado" : "Ventilador Desligado")
               << "| " << setw(colWidth) << (atuadorLampada.getLigado() ? "Lampada Acesa" : "Lampada Apagada")
               << "| " << setw(colWidth) << (atuadorDesumidificador.getLigado() ? "Desumidificador Ligado" : "Desumidificador Desligado") << endl;

          cout << setw(colWidth) << ("Velocidade do Ventilador: " + to_string(atuadorVentilador.getVelocidade()))
               << "| " << setw(colWidth) << ("Brilho da Lampada: " + to_string(atuadorLampada.getBrilho()) + " lumens")
               << "| " << setw(colWidth) << ("Configuracao do Desumidificador: " + to_string(atuadorDesumidificador.getConfiguracao())) << endl;
     }
     else{
          cout << setw(colWidth) << (atuadorVentilador.getLigado() ? "Ventilador Ligado" : "Ventilador Desligado")
               << "| " << setw(colWidth) << (atuadorLampada.getLigado() ? "Lampada Acesa" : "Lampada Apagada")
               << "| " << setw(colWidth) << (atuadorUmidificador.getLigado() ? "Umidificador Ligado" : "Umidificador Desligado") << endl;
     
          cout << setw(colWidth) << ("Velocidade do Ventilador: " + to_string(atuadorVentilador.getVelocidade()))
               << "| " << setw(colWidth) << ("Brilho da Lampada: " + to_string(atuadorLampada.getBrilho()) + " lumens")
               << "| " << setw(colWidth) << ("Configuracao do Umidificador: " + to_string(atuadorDesumidificador.getConfiguracao())) << endl;
     }
     

     // Linha 8: Separador
     cout << string(colWidth, '-') << "+" 
          << string(51, '-') << "+" 
          << string(colWidth, '-') << endl;

     
     if (!atuadorLampada.getLigado()){
          if(!atuadorVentilador.getLigado()){
               if(!(atuadorUmidificador.getLigado() || atuadorDesumidificador.getLigado())){
               
                    // Animação ASCII formatada
                    cout << setw(colWidth) << ""                                                  << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"         << setw(colWidth-13) << ""  << "|                        #####                      |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"  << "|███)" << setw(colWidth-14) << ""  << "|                    ####     ####                  |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"   << " |██│" << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"              << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"       << setw(colWidth-15) << ""  << "|                                                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"     << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                     << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
               else{
                    cout << setw(colWidth) << ""                                                  << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"         << setw(colWidth-13) << ""  << "|                        #####                      |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"  << "|███)" << setw(colWidth-14) << ""  << "|                    ####     ####                  |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"   << " |██│" << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"              << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"       << setw(colWidth-15) << ""  << "|                                                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"     << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                     << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
          }
          else{
               if(!(atuadorUmidificador.getLigado() || atuadorDesumidificador.getLigado())){
                    // Animação ASCII formatada
                    cout << setw(colWidth) << ""                                                                                   << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"                                          << setw(colWidth-13) << ""  << "|                        #####                      |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"              << "|██│   ▒▒   ▒"              << setw(colWidth-22) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"              << "|███)    ▒▒  ▒"             << setw(colWidth-23) << ""  << "|                    ####     ####                  |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"              << "|██│   ▒▒   ▒ "             << setw(colWidth-23) << ""  << "|                     ####   ####                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"               << " |██│"                      << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"                                               << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"                                        << setw(colWidth-15) << ""  << "|                                                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"                                      << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                                                      << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
                    }
               else{
                    cout << setw(colWidth) << ""                                                                                   << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "| " << setw(colWidth) << "" <<                     "| " << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"                                          << setw(colWidth-13) << ""  << "|                        #####                      |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"              << "|██│   ▒▒   ▒"              << setw(colWidth-22) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"              << "|███)    ▒▒  ▒"             << setw(colWidth-23) << ""  << "|                    ####     ####                  |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"              << "|██│   ▒▒   ▒ "             << setw(colWidth-23) << ""  << "|                     ####   ####                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"               << " |██│"                      << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"                                               << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"                                        << setw(colWidth-15) << ""  << "|                                                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"                                      << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                                                      << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
          }
          

          // for (int i = 20; i < 22; i++){
            
          //   if(i==22){
          //       cout << "\033[" << i << ";1H";   //
          //       cout << "\033[2K";  // Limpa a linha atual onde estava o "apertouuuu!"
          //      }
          // }
     }

     else{
          if(!atuadorVentilador.getLigado()){
               if(!(atuadorUmidificador.getLigado() || atuadorDesumidificador.getLigado())){
               
                    // Animação ASCII formatada
                    cout << setw(colWidth) << ""                                                  << "|                 ##               ##               |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "|                   ##           ##                 |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "|            ##                         ##          |"  << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"         << setw(colWidth-13) << ""  << "|               ##       #####       ##             |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"  << "|███)" << setw(colWidth-14) << ""  << "|          ####      ####     ####      ####        |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"   << " |██│" << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"              << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"       << setw(colWidth-15) << ""  << "|                                                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"     << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                     << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
               else{
                    cout << setw(colWidth) << ""                                                  << "|                 ##               ##               |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "|                   ##           ##                 |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                  << "|            ##                         ##          |"  << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"         << setw(colWidth-13) << ""  << "|               ##       #####       ##             |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"  << "|███)" << setw(colWidth-14) << ""  << "|          ####      ####     ####      ####        |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"  << "|██│"  << setw(colWidth-13) << ""  << "|                     ####   ####                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"   << " |██│" << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"              << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"       << setw(colWidth-15) << ""  << "|                                                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"     << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                     << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
          }
          else{
               if(!(atuadorUmidificador.getLigado() || atuadorDesumidificador.getLigado())){
                    // Animação ASCII formatada
                    cout << setw(colWidth) << ""                                                                                   << "|                 ##               ##               |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "|                   ##           ##                 |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "|            ##                         ##          |"  << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"                                          << setw(colWidth-13) << ""  << "|               ##       #####       ##             |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"              << "|██│   ▒▒   ▒"              << setw(colWidth-22) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"              << "|███)    ▒▒  ▒"             << setw(colWidth-23) << ""  << "|          ####      ####     ####      ####        |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"              << "|██│   ▒▒   ▒ "             << setw(colWidth-23) << ""  << "|                     ####   ####                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"               << " |██│"                      << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"                                               << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      |        |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"                                        << setw(colWidth-15) << ""  << "|                                                   |"  << "            |      | closed |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"                                      << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                                                      << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
               else{
                    cout << setw(colWidth) << ""                                                                                   << "|                 ##               ##               |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "|                   ##           ##                 |"  << setw(colWidth) << "" << endl;
                    cout << setw(colWidth) << ""                                                                                   << "|            ##                         ##          |"  << setw(colWidth) << "" << endl;
                    cout << setw(10)       << "         |██│"                                          << setw(colWidth-13) << ""  << "|               ##       #####       ##             |"  << "             _____________________   " << setw(15) << "" << endl;
                    cout << setw(10)       << "    ┌===┐"              << "|██│   ▒▒   ▒"              << setw(colWidth-22) << ""  << "|                     ####   ####                   |"  << "            |       ________      |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "   (####│"              << "|███)    ▒▒  ▒"             << setw(colWidth-23) << ""  << "|          ####      ####     ####      ####        |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "    └┬ ┬┘"              << "|██│   ▒▒   ▒ "             << setw(colWidth-23) << ""  << "|                     ####   ####                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"               << " |██│"                      << setw(colWidth-13) << ""  << "|                       #######                     |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "     │ │"                                               << setw(colWidth-8)  << ""  << "|                       #######                     |"  << "            |      / open  /|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << "  ___│_│_______"                                        << setw(colWidth-15) << ""  << "|                                                   |"  << "            |     /_______/ |     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " (______________)"                                      << setw(colWidth-17) << ""  << "|                        #####                      |"  << "            |      |________|     |    " << setw(15) << "" << endl;
                    cout << setw(10)       << " "                                                      << setw(colWidth-10) << ""  << "|                         ###                       |"  << "            |_____________________|    " << setw(15) << "" << endl;
               }
          }
     }
     
    
     cout << "\033[22;1H";
    // Linha 21: Separador
     cout << string(colWidth, '-') << "+" 
          << string(51, '-') << "+" 
          << string(colWidth, '-') << endl;


// é caso houver algo "indesejado" que apareceu no terminal que deve ser apagado! 
    if(!apertouL){
        // Como a tabela tem 
        for (int i = 24; i < 75; i++){
            
            // Ocorre um mini bug de impressão no terminal, para evitar esse bug, é preciso apagar a partir da ultima linha e depois do ultimo caractere impresso desejado
            if(i==23){
                for (int j = 35; j < 150; j++){
                    cout << "\033[23;" << j << "H"; // 
                    cout << "\033[2K";
                }
            }
                cout << "\033[" << i << ";1H";   //
                cout << "\033[2K";  // Limpa a linha atual onde estava o "apertouuuu!"
        }
    }
 
}























// ███████╗███████╗     ██╗ █████╗     ██████╗ ███████╗███╗   ███╗      ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ 
// ██╔════╝██╔════╝     ██║██╔══██╗    ██╔══██╗██╔════╝████╗ ████║      ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗
// ███████╗█████╗       ██║███████║    ██████╔╝█████╗  ██╔████╔██║█████╗██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║
// ╚════██║██╔══╝  ██   ██║██╔══██║    ██╔══██╗██╔══╝  ██║╚██╔╝██║╚════╝╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║
// ███████║███████╗╚█████╔╝██║  ██║    ██████╔╝███████╗██║ ╚═╝ ██║       ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝
// ╚══════╝╚══════╝ ╚════╝ ╚═╝  ╚═╝    ╚═════╝ ╚══════╝╚═╝     ╚═╝        ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ 
                                                                                                          
                                                                                               
                                                                                                      


                                      
                    //       #####                   
                    //    ####   ####                
                    //   ####     ####               
                    //    ####   ####                
                    //      #######                  
                    //      #######                  
                                                  
                    //       #####                   
                    //        ###                    
                                                 


     //  "       ______________________             "
     //  "      |       ________      |   "
     //  "      |      / open  /|     |   "
     //  "      |     /_______/ |     |   "
     //  "      |      |________|     |   "
     //  "      |      / open  /|     |   "
     //  "      |     /_______/ |     |   "
     //  "      |      |________|     |    "
     //  "      |_____________________|             "

          //    ______________________             
          //   |       ________      |   
          //   |      |        |     |   
          //   |      | closed |     |   
          //   |      |________|     |   
          //   |      |        |     |   
          //   |      | closed |     |   
          //   |      |________|     |    
          //   |_____________________|             


// cout<<      "                   __            " 
// cout<<      "                  |██│            "
// cout<<      "             ┌===┐|██│   ▒▒   ▒          "
// cout<<      "            (####│|███)    ▒▒  ▒  "
// cout<<      "             └┬ ┬┘|██│   ▒▒   ▒   "
// cout<<      "              │ │ |██│      "
// cout<<      "              │ │                    "
// cout<<      "           ___│_│_______               "
// cout<<      "         (______________)          "

     //              __             
     //             |██│            
     //        ┌===┐|██│          
     //       (####│|███)     
     //        └┬ ┬┘|██│     
     //         │ │ |██│      
     //         │ │                    
     //      ___│_│_______               
     //    (______________)          

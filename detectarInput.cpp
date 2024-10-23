#pragma once
#include <iostream>
#include <thread>
#include <termios.h>
#include <atomic>
#include <unistd.h>

using namespace std;  

// Função para configurar o terminal
void set_terminal_mode() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag &= ~(ICANON | ECHO); // Desativa o modo canônico e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Função para restaurar o terminal
void reset_terminal_mode() {
    struct termios newt;
    tcgetattr(STDIN_FILENO, &newt);
    newt.c_lflag |= (ICANON | ECHO); // Ativa o modo canônico e eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Variável global para detectar quando o usuário pressiona 'L'l
atomic<bool> apertouL(false);
atomic<bool> apertouD(false);
atomic<bool> rodando(true);  // Variável para controlar o término das threads

void detectarInput() {
    set_terminal_mode(); // Configura o terminal

    while (rodando) { // rodando é por garantia de que vai sempre funcionar
        char ch = getchar(); // Lê um caractere diretamente
            if (ch == 'L' || ch == 'l') {
                apertouL = true;
                cout << "\033[24;1H"; 
                cout << "apertouuuu!" << endl;
            }
            if (ch == 'D' || ch == 'd') {
                apertouD = true;
                cout << "\033[24;1H"; 
                cout << "apertouuuu!" << endl;
            }
            // Pausa para manter a mensagem visível por 0,5 segundos
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    this_thread::sleep_for(chrono::milliseconds(100));  // Pequena pausa para evitar loop rápido demais
}

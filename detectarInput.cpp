#pragma once
#include <iostream>
#include <thread> // Necessário para manipulação de threads
#include <termios.h> // Necessário para configurar as propriedades do terminal
#include <atomic> // Necessário para uso de variáveis atômicas (evitam condições de corrida)
#include <unistd.h> // Inclui funções tcsetattr e tcgetattr

using namespace std;

// Função para configurar o terminal em modo não canônico e sem eco
// O modo não canônico permite a leitura imediata de caracteres sem esperar por 'Enter'
// O modo sem eco evita que os caracteres digitados apareçam no terminal
void set_terminal_mode() {
    struct termios newt; // Estrutura para armazenar as configurações do terminal
    tcgetattr(STDIN_FILENO, &newt); // Obtém as configurações atuais do terminal
    newt.c_lflag &= ~(ICANON | ECHO); // Desativa o modo canônico e o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplica as mudanças imediatamente
}

// Função para restaurar as configurações originais do terminal
// Reativa o modo canônico e o eco
void reset_terminal_mode() {
    struct termios newt; // Estrutura para armazenar as configurações do terminal
    tcgetattr(STDIN_FILENO, &newt); // Obtém as configurações atuais do terminal
    newt.c_lflag |= (ICANON | ECHO); // Reativa o modo canônico e o eco
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Aplica as mudanças imediatamente
}

// Variáveis globais atômicas para sinalizar o estado do programa
atomic<bool> apertouL(false); // Indica se a tecla 'L' foi pressionada
atomic<bool> apertouD(false); // Indica se a tecla 'D' foi pressionada
atomic<bool> rodando(true);   // Controla se as threads devem continuar rodando

// Função para detectar a entrada do usuário
// Executada em uma thread separada para monitorar teclas pressionadas sem bloquear o fluxo principal
void detectarInput() {
    set_terminal_mode(); // Configura o terminal para o modo não canônico

    while (rodando) { // Loop continua enquanto a variável 'rodando' for verdadeira
        char ch = getchar(); // Lê um caractere diretamente da entrada padrão (sem esperar 'Enter')

        // Verifica se a tecla pressionada foi 'L' ou 'l'
        if (ch == 'L' || ch == 'l') {
            apertouL = true; // Define a variável apertouL como verdadeira
            cout << "\033[24;1H"; // Move o cursor para uma posição específica no terminal
            cout << "apertouuuu!" << endl; // Exibe a mensagem no terminal
        }
        
        // Verifica se a tecla pressionada foi 'D' ou 'd'
        if (ch == 'D' || ch == 'd') {
            apertouD = true; // Define a variável apertouD como verdadeira
            cout << "\033[24;1H"; // Move o cursor para uma posição específica no terminal
            cout << "apertouuuu!" << endl; // Exibe a mensagem no terminal
        }

        // Pausa para manter a mensagem visível por 0,5 segundos
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    this_thread::sleep_for(chrono::milliseconds(100)); // Pausa curta para evitar um loop excessivamente rápido
}

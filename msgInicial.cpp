#pragma once // Garante que o arquivo seja incluído apenas uma vez durante a compilação
#include <iostream> // Biblioteca padrão de entrada/saída
#include <iomanip>  // Para usar std::setw para formatação de saída
#include <thread>   // Biblioteca para usar funções de controle de tempo e threads

using namespace std;

// Função para exibir uma mensagem de boas-vindas com arte em ASCII
void bemVindo(){
    cout << "███████╗███████╗     ██╗ █████╗     ██████╗ ███████╗███╗   ███╗      ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " << endl;
    cout << "██╔════╝██╔════╝     ██║██╔══██╗    ██╔══██╗██╔════╝████╗ ████║      ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" << endl;
    cout << "███████╗█████╗       ██║███████║    ██████╔╝█████╗  ██╔████╔██║█████╗██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" << endl;
    cout << "╚════██║██╔══╝  ██   ██║██╔══██║    ██╔══██╗██╔══╝  ██║╚██╔╝██║╚════╝╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" << endl;
    cout << "███████║███████╗╚█████╔╝██║  ██║    ██████╔╝███████╗██║ ╚═╝ ██║       ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" << endl;
    cout << "╚══════╝╚══════╝ ╚════╝ ╚═╝  ╚═╝    ╚═════╝ ╚══════╝╚═╝     ╚═╝        ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ " << endl;
}

// Função para exibir uma mensagem "tela cheia" com arte em ASCII
void telaCheia(){
    cout <<  "██████╗  ██████╗ ██████╗     ███████╗ █████╗ ██╗   ██╗ ██████╗ ██████╗   " << endl;
    cout <<  "██╔══██╗██╔═══██╗██╔══██╗    ██╔════╝██╔══██╗██║   ██║██╔═══██╗██╔══██╗  " << endl;
    cout <<  "██████╔╝██║   ██║██████╔╝    █████╗  ███████║██║   ██║██║   ██║██████╔╝  " << endl;
    cout <<  "██╔═══╝ ██║   ██║██╔══██╗    ██╔══╝  ██╔══██║╚██╗ ██╔╝██║   ██║██╔══██╗  " << endl;
    cout <<  "██║     ╚██████╔╝██║  ██║    ██║     ██║  ██║ ╚████╔╝ ╚██████╔╝██║  ██║  " << endl;
    cout <<  "╚═╝      ╚═════╝ ╚═╝  ╚═╝    ╚═╝     ╚═╝  ╚═╝  ╚═══╝   ╚═════╝ ╚═╝  ╚═╝  " << endl;
    cout <<  "████████╗███████╗██╗      █████╗      ██████╗██╗  ██╗███████╗██╗ █████╗  " << endl;
    cout <<  "╚══██╔══╝██╔════╝██║     ██╔══██╗    ██╔════╝██║  ██║██╔════╝██║██╔══██╗ " << endl;
    cout <<  "   ██║   █████╗  ██║     ███████║    ██║     ███████║█████╗  ██║███████║ " << endl;
    cout <<  "   ██║   ██╔══╝  ██║     ██╔══██║    ██║     ██╔══██║██╔══╝  ██║██╔══██║ " << endl;
    cout <<  "   ██║   ███████╗███████╗██║  ██║    ╚██████╗██║  ██║███████╗██║██║  ██║ " << endl;
    cout <<  "   ╚═╝   ╚══════╝╚══════╝╚═╝  ╚═╝     ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═╝ " << endl;
}

// Função para exibir o nome das salas
void salas(){
    cout << " ███████╗ █████╗ ██╗      █████╗ ███████╗ " << endl;
    cout << " ██╔════╝██╔══██╗██║     ██╔══██╗██╔════╝ " << endl;
    cout << " ███████╗███████║██║     ███████║███████╗ " << endl;
    cout << " ╚════██║██╔══██║██║     ██╔══██║╚════██║ " << endl;
    cout << " ███████║██║  ██║███████╗██║  ██║███████║ " << endl;
    cout << " ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝ " << endl;
}                                    

// Função principal que mostra a mensagem inicial, simula animação, e exibe opções de escolha
void msgInicial(){
    bemVindo(); // Exibe a mensagem de boas-vindas
    this_thread::sleep_for(chrono::milliseconds(2500)); // Pausa de 2,5 segundos
    system("clear"); // Limpa a tela

    telaCheia(); // Exibe a tela cheia
    this_thread::sleep_for(chrono::seconds(5)); // Pausa de 5 segundos

    // Faz o texto piscar 5 vezes
    for (int i = 0; i < 5; i++) {
        system("clear"); // Limpa a tela
        this_thread::sleep_for(chrono::milliseconds(400)); // Pausa de 0,4 segundos

        telaCheia(); // Exibe a tela novamente
        this_thread::sleep_for(chrono::milliseconds(400)); // Pausa de 0,4 segundos
    }
    system("clear"); // Limpa a tela novamente

    // Exibe as opções das salas
    salas();
    cout << "Escolha para onde ir e descubra o que cada sala revela!" << endl;

    // Detalhamento das salas com uma pequena descrição
    cout << "==============================================================================================================================================================" << endl;
    cout << "1. ***** QUARTO *****" << endl;
    cout << "Algo estranho acontece quando você entra neste quarto à noite. Ao deitar na cama, o ambiente parece se transformar lentamente, como se o tempo se distorcesse." << endl;
    cout << "Cada segundo de sono é tão profundo e reconfortante que, quando acordar, vai se perguntar por que tudo passou tão rápido." << endl;
    cout << "Será que você está pronto para descobrir o que faz desse quarto um lugar tão único para dormir?" << endl;

    cout << "==============================================================================================================================================================" << endl;
    cout << "2. ***** CINEMA *****" << endl;
    cout << "Assim que você entra na sala, o ambiente à sua volta começa a mudar. As luzes se apagam, o som ambiente se transforma, e, de repente, você está imerso em um cinema." << endl;
    cout << " Mas esse não é um cinema comum... a cada minuto, algo novo acontece, mudando o cenário e intensificando as sensações." << endl;
    cout << "Está pronto para descobrir o que este cinema tem de tão especial?" << endl;

    cout << "==============================================================================================================================================================" << endl;
    cout << "3. ***** BANHEIRO *****" << endl;
    cout << "Depois de um banho relaxante, o vapor toma conta do ambiente." << endl;
    cout << "O espelho embaça, e o lugar parece se transformar por completo. Quer descobrir como tudo muda após o banho?" << endl;
}

// Escolha para onde ir e descubra o que cada sala revela.
// 1. Quarto -> Algo estranho acontece quando você entra neste quarto à noite. Ao deitar na cama, o ambiente parece se transformar lentamente, como se o tempo se distorcesse. Cada segundo de sono é tão profundo e reconfortante que, quando acordar, vai se perguntar por que tudo passou tão rápido. Será que você está pronto para descobrir o que faz desse quarto um lugar tão único para dormir?
// 2. Cinema -> Assim que você entra na sala, o ambiente à sua volta começa a mudar. As luzes se apagam, o som ambiente se transforma, e, de repente, você está imerso em um cinema. Mas esse não é um cinema comum... a cada minuto, algo novo acontece, mudando o cenário e intensificando as sensações. Está pronto para descobrir o que este cinema tem de tão especial?
// 3. Banheiro -> Depois de um banho relaxante, o vapor toma conta do ambiente. O espelho embaça, e o lugar parece se transformar por completo. Quer descobrir como tudo muda após o banho?
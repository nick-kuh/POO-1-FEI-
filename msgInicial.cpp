#pragma once
#include <iostream>
#include <iomanip>  // Para usar std::setw

using namespace std;


void bemVindo(){
    cout << "███████╗███████╗     ██╗ █████╗     ██████╗ ███████╗███╗   ███╗      ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗ " << endl;
    cout << "██╔════╝██╔════╝     ██║██╔══██╗    ██╔══██╗██╔════╝████╗ ████║      ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗" << endl;
    cout << "███████╗█████╗       ██║███████║    ██████╔╝█████╗  ██╔████╔██║█████╗██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║" << endl;
    cout << "╚════██║██╔══╝  ██   ██║██╔══██║    ██╔══██╗██╔══╝  ██║╚██╔╝██║╚════╝╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║" << endl;
    cout << "███████║███████╗╚█████╔╝██║  ██║    ██████╔╝███████╗██║ ╚═╝ ██║       ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝" << endl;
    cout << "╚══════╝╚══════╝ ╚════╝ ╚═╝  ╚═╝    ╚═════╝ ╚══════╝╚═╝     ╚═╝        ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ " << endl;
}

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

void salas(){
cout << " ███████╗ █████╗ ██╗      █████╗ ███████╗ " << endl;
cout << " ██╔════╝██╔══██╗██║     ██╔══██╗██╔════╝ " << endl;
cout << " ███████╗███████║██║     ███████║███████╗ " << endl;
cout << " ╚════██║██╔══██║██║     ██╔══██║╚════██║ " << endl;
cout << " ███████║██║  ██║███████╗██║  ██║███████║ " << endl;
cout << " ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝ " << endl;
}                                    

void msgInicial(){
    bemVindo();
    this_thread::sleep_for(chrono::milliseconds(2500));
    system("clear"); // Apagar o texto (limpar a tela)

    telaCheia();
    this_thread::sleep_for(chrono::seconds(5));
    // Piscar o texto 3 vezes
    for (int i = 0; i < 5; i++) {
        system("clear"); // Apagar o texto (limpar a tela)
        this_thread::sleep_for(chrono::milliseconds(400)); // Pausar por 0,4 segundos

        telaCheia(); // Mostrar o texto novamente
        this_thread::sleep_for(chrono::milliseconds(400)); // Pausar por 0,4 segundos
    }
    system("clear"); // Apagar o texto (limpar a tela)
    salas();
    cout << "Escolha para onde ir e descubra o que cada sala revela!" << endl;

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
    cout << "Cada segundo de sono é tão profundo e reconfortante que, quando acordar, vai se perguntar por que tudo passou tão rápido." << endl;
    cout << "O espelho embaça, e o lugar parece se transformar por completo. Quer descobrir como tudo muda após o banho?" << endl;


}


// Escolha para onde ir e descubra o que cada sala revela.
// 1. Quarto -> Algo estranho acontece quando você entra neste quarto à noite. Ao deitar na cama, o ambiente parece se transformar lentamente, como se o tempo se distorcesse. Cada segundo de sono é tão profundo e reconfortante que, quando acordar, vai se perguntar por que tudo passou tão rápido. Será que você está pronto para descobrir o que faz desse quarto um lugar tão único para dormir?
// 2. Cinema -> Assim que você entra na sala, o ambiente à sua volta começa a mudar. As luzes se apagam, o som ambiente se transforma, e, de repente, você está imerso em um cinema. Mas esse não é um cinema comum... a cada minuto, algo novo acontece, mudando o cenário e intensificando as sensações. Está pronto para descobrir o que este cinema tem de tão especial?
// 3. Banheiro -> Depois de um banho relaxante, o vapor toma conta do ambiente. O espelho embaça, e o lugar parece se transformar por completo. Quer descobrir como tudo muda após o banho?
#include <iostream>  // Biblioteca padrão de entrada/saída
#include <atomic>    // Para usar variáveis atômicas, que garantem consistência em multithread
#include <random>    // Para gerar números aleatórios, se necessário
#include <unistd.h>  // Para usar funções de controle de tempo e do sistema em sistemas UNIX
#include <thread>    // Para trabalhar com threads e programação concorrente
// #include <windows.h> // Caso seja necessário usar o SetConsoleOutputCP no Windows
#include <cstdlib>   // Para a função exit(), que encerra o programa

// Inclusão de todos os módulos do projeto
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

// Função principal do programa
int main() {
    // Garante que todos os caracteres especiais funcionem no terminal (caso seja no Windows)
    // SetConsoleOutputCP(CP_UTF8);

    // Exibe a mensagem inicial para o usuário (definida em msgInicial.cpp)
    msgInicial();

    // Captura a escolha do usuário
    int escolha;
    cin >> escolha;

    // Executa a lógica de acordo com a escolha do usuário
    if (escolha == 1) {
        quarto();  // Função que controla as operações do quarto
    } 
    else if (escolha == 2) {
        cinema();  // Função que controla as operações da sala de cinema
    } 
    else if (escolha == 3) {
        banheiro();  // Função que controla as operações do banheiro
    }

    // Encerra o programa de forma limpa
    exit(0); 
    return 0;  // Retorno da função principal, indicando sucesso
}

/*********************************************************************************
Detalhes sobre o controle de ambientes:

Temperatura ambiente: 25°C

Sala de cinema:
  - Ar condicionado deve ficar ligado direto.
  - Aumenta a luz quando não há filme, e abaixa durante o filme.
  - 30 min antes de começar o filme e 30 min depois de terminar:
    * Ar-condicionado: 22°C
    * Luz: Durante o filme: 5 lux | Após o filme: aumenta gradualmente até 150 lux

Quarto:
  - Umidificador liga quando dormir.
  - Luz ligada quando acordado, usuário pode controlar manualmente para desligar e ligar.
  - Ar-condicionado automatizado: liga/desliga dependendo da temperatura.
  - 30 min antes de dormir - 30 min depois de acordar:
    * Umidificador: Umidade entre 40%-60% enquanto dorme.
    * Ar-condicionado: 22°C, liga e desliga automaticamente.
    * Luz: Acordado: 300 lux | Dormindo: 0 lux | Ao acordar: 350 lux.

Banheiro:
  - Desumidificador liga ao desligar a luz (quando a pessoa sai do banheiro) e mantém ligado por um tempo.
  - Luz ligada durante o banho.
  - Ventilador permanece desconectado.
  - 3 min antes de entrar no banho - 30 min depois de terminar o banho (repete o processo):
    * Desumidificador: Umidade entre 40%-60%.
    * Luz: 400 lux (bem iluminado durante o banho).
*********************************************************************************/

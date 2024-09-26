#pragma once
#include <iostream>

using namespace std;

class Componente{
  private:
    bool ligado;
    bool conectado;
    int valor;
    string nome;

  public:  
    Componente(bool ligado, bool conectado, int valor, string nome){
      this->ligado = ligado;
      this->conectado = conectado;
      this->valor = valor;
      this->nome = nome;
    }
    void ligar(){
      ligado = true;
    }

    void desligar(){
      ligado = false;
    }

    void conectar(){
      conectado = true;
    }

    void desconectar(){
      conectado = false;
    }

    int getValor(){
      return valor;
    }

    string getNome(){
      return nome;
    }

    string getFome(){
      return nome;
    }

};
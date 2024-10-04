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
    bool ligar(){
      return true;
    }

    bool desligar(){
      return false;
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

    bool getLigado(){
      return ligado;
    }

    bool getConectado(){
      return conectado;
    }

    string getNome(){
      return nome;
    }

    void passaValor(int valor){
      this->valor = valor;
    }

    void setLigado(int ligado){
      this->ligado = ligado;
    }

    // void setValor(bool ligado, int valor){
    //   this->valor = valor;
    //   this->ligado = ligado;
    // }

};
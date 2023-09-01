#include <iostream>
#include "Personagem.h"
using namespace std;

Personagem::Personagem(int vidaInicial, int danoInicial) : vida(vidaInicial), dano(danoInicial) {}

void Personagem::atacar(Personagem &alvo) {
  alvo.receberDano(dano);
}

void Personagem::receberDano(int dano) {
  vida -= dano;
}

int Personagem::obterDano() const {
  return dano;
}

int Personagem::obterVida() const {
  return vida;
}

void Jogador::defender() {
  int danoReduzido = obterDano() / 2;
  receberDano(danoReduzido);
}

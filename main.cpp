#include "Personagem.h"
#include "getch.hpp"
#include <iostream>
using namespace std;

void exibirMenu();
void jogar(Jogador &jogador, Esqueleto &esqueleto);
void vitoria(Esqueleto esqueleto);
void derrota(Jogador jogador);
void instrucoes();
void textoAcoes();
void textoLucas();
void textoStatus();
void textoEscolha();
void textoMenu();

int main() {
  char op;
  Jogador jogador;
  Esqueleto esqueleto;

  while (true) {
    system("clear");
    exibirMenu();
    op = getch();

    if (op == '1') {
      system("clear");
      jogar(jogador, esqueleto);
      if (esqueleto.obterVida() <= 0) {
        vitoria(esqueleto);
        break;
      }
      if (jogador.obterVida() <= 0) {
        derrota(jogador);
        break;
      }
    }

    if (op == '2') {
      system("clear");
      instrucoes();
    }
    if (op == '3') {
      cout << "\x1B[1;31mtchau tchau\x1B[0m" << endl;
      break;
    }
    if (op != '1' && op != '2' && op != '3') {
      cout << "Opção invalida!\n\n";
      sleep(1);
    }
  }
  return 0;
}

void exibirMenu() {
  textoMenu();

  cout << "\x1B[1;32m1 - Jogar\n";
  cout << "2 - Instruções\n";
  cout << "3 - SAIR\x1B[0m\n";
}

void jogar(Jogador &jogador, Esqueleto &esqueleto) {
  char escolha;

  textoEscolha();
  cout << "\x1B[1;36m1 - \x1B[0m\x1B[1;33mAtacar\x1B[0m\n";
  cout << "\x1B[1;36m2 - \x1B[0m\x1B[1;33mDefender\x1B[0m\n";
  cout << "\x1B[1;36m3 - \x1B[0m\x1B[1;31mSAIR\x1B[0m\n\n";

  while (true) {

    escolha = getch();
    system("clear");

    textoEscolha();
    cout << "\x1B[1;36m1 - \x1B[0m\x1B[1;33mAtacar\x1B[0m\n";
    cout << "\x1B[1;36m2 - \x1B[0m\x1B[1;33mDefender\x1B[0m\n";
    cout << "\x1B[1;36m3 - \x1B[0m\x1B[1;31mSAIR\x1B[0m\n\n";

    if (escolha == '1') {
      if (jogador.obterVida() > 0 && esqueleto.obterVida() > 0) {
        jogador.atacar(esqueleto);

        textoAcoes();
        cout << "\x1B[1mJogador\x1B[0m \x1B[1;32matacou\x1B[0m o "
                "\x1B[1mEsqueleto\x1B[0m!.\nVida atual do "
                "\x1B[1mEsqueleto\x1B[0m: \x1B[1;31m"
             << esqueleto.obterVida() << "\x1B[0m\n"
             << "\n";

        if (esqueleto.obterVida() <= 0) {
          system("clear");
          cout << "\x1B[1mEsqueleto\x1B[0m derrotado!\n";
          break;
        }

        esqueleto.atacar(jogador);
        cout << "\n\x1B[1mEsqueleto\x1B[0m \x1B[31matacou\x1B[0m o "
                "\x1B[1mJogador\x1B[0m!.\nVida Atual: \x1B[1;32m"
             << jogador.obterVida() << "\x1B[0m\n"
             << endl;

        if (jogador.obterVida() <= 0) {
          system("clear");
          cout << "\x1B[1;31mVoce foi eliminado!\x1B[0m, tente novamente\n";
          break;
        }
      }

      textoStatus();
      cout << "Vida Atual: \x1B[1;32m" << jogador.obterVida() << "\x1B[0m\n"
           << endl;
      cout << "Vida do inimigo: \x1B[1;31m" << esqueleto.obterVida()
           << "\x1B[0m\n"
           << "\n\n";
    }
    if (escolha == '2') {
      jogador.defender();

      textoAcoes();

      cout << "\x1B[1mJogador\x1B[0m escolheu \x1B[1;33mdefender\x1B[0m! "
              "Dano reduzido pela metade.\n";
      cout << "Vida do inimigo: \x1B[1;31m" << esqueleto.obterVida()
           << "\x1B[0m\n"
           << "\n";

      cout << "\n\x1B[1mEsqueleto\x1B[0m \x1B[31matacou\x1B[0m o "
              "\x1B[1mJogador\x1B[0m!.\nVida Atual: \x1B[1;32m"
           << jogador.obterVida() << "\x1B[0m\n"
           << endl;

      if (jogador.obterVida() <= 0) {
        cout << "\x1B[1;31mJogador eliminado!\x1B[0m, tente novamente\n";
        break;
      }

      textoStatus();
      cout << "Vida Atual: \x1B[1;32m" << jogador.obterVida() << "\x1B[0m\n"
           << endl;
      cout << "Vida do inimigo: \x1B[1;31m" << esqueleto.obterVida()
           << "\x1B[0m\n"
           << "\n\n";
    }
    if (escolha == '3') {
      break;
    }
    if (escolha != '1' && escolha != '2' && escolha != '3') {
      cout << "Opção invalida!";
    }
  }
}

void instrucoes() {
  char op2;

  while (true) {
    cout << "\x1B[1;32mBem vindo ao meu jogo!\x1B[0m\n" << endl;
    cout << "Esse é um \x1B[1;34mjoguinho basico de turno\x1B[0m, espero que "
            "se divirta :)\n";
    cout << "Use '\x1B[1;33mAtaque\x1B[0m' para atacar" << endl;
    cout << "Use '\x1B[1;33mDefesa\x1B[0m' para reduzir o dano do ataque "
            "inimigo\n"
         << endl;
    cout << "\x1B[1;32m1 - Voltar\x1B[0m\n";

    textoLucas();
    op2 = getch();

    if (op2 == '1') {
      system("clear");
      break;
    } else {
      cout << "Opção inválida!" << endl;
      sleep(1);
      system("clear");
    }
  }
}

void vitoria(Esqueleto esqueleto) {
  cout << "\n\x1B[1;32m██████████████████████████████████████\x1B[0m";
  cout << "\n\x1B[1;32m█▄─█─▄█▄─▄█─▄─▄─█─▄▄─█▄─▄▄▀█▄─▄██▀▄─██\x1B[0m";
  cout << "\n\x1B[1;32m██▄▀▄███─████─███─██─██─▄─▄██─███─▀─██\x1B[0m";
  cout << "\n\x1B[1;32m▀▀▀▄▀▀▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▄▄▄▀▄▄▀▄▄▀\x1B[0m";
}

void derrota(Jogador jogador) {
  cout << "\n\x1B[1;32m██████████████████████████████████████████\x1B[0m";
  cout << "\n\x1B[1;32m█▄─▄▄▀█▄─▄▄─█▄─▄▄▀█▄─▄▄▀█─▄▄─█─▄─▄─██▀▄─██\x1B[0m";
  cout << "\n\x1B[1;32m██─██─██─▄█▀██─▄─▄██─▄─▄█─██─███─████─▀─██\x1B[0m";
  cout << "\n\x1B[1;32m▀▄▄▄▄▀▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▀▄▄▀▄▄▄▄▀▀▄▄▄▀▀▄▄▀▄▄▀\x1B[0m";
}

void textoAcoes(){
  cout << "\n▄▀█ █▀▀ █▀█ █▀▀ █▀\n";
      cout << "█▀█ █▄▄ █▄█ ██▄ ▄█\n\n";
}

void textoStatus(){
        cout << "\n\n█▀ ▀█▀ ▄▀█ ▀█▀ █░█ █▀\n";
      cout << "▄█ ░█░ █▀█ ░█░ █▄█ ▄█\n\n";
}

void textoEscolha(){
  cout << "\n█▀▀ █▀ █▀▀ █▀█ █░░ █░█ ▄▀█\n";
  cout << "██▄ ▄█ █▄▄ █▄█ █▄▄ █▀█ █▀█\n\n";
}

void textoLucas(){
      cout << ("\n\n\n\n\n█▀▄▀█ █▀▀█ █▀▀▄ █▀▀ 　 █▀▀▄ █──█ 　 █── █──█ █▀▀ █▀▀█ "
             "█▀▀\n");
    cout << ("█─▀─█ █▄▄█ █──█ █▀▀ 　 █▀▀▄ █▄▄█ 　 █── █──█ █── █▄▄█ ▀▀█\n");
    cout << ("▀───▀ ▀──▀ ▀▀▀─ ▀▀▀ 　 ▀▀▀─ ▄▄▄█ 　 ▀▀▀ ─▀▀▀ ▀▀▀ ▀──▀ ▀▀▀\n");
}

void textoMenu(){
  cout << ("███╗░░░███╗███████╗███╗░░██╗██╗░░░██╗\n");
  cout << ("████╗░████║██╔════╝████╗░██║██║░░░██║\n");
  cout << ("██╔████╔██║█████╗░░██╔██╗██║██║░░░██║\n");
  cout << ("██║╚██╔╝██║██╔══╝░░██║╚████║██║░░░██║\n");
  cout << ("██║░╚═╝░██║███████╗██║░╚███║╚██████╔╝\n");
  cout << ("╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚══╝░╚═════╝░\n\n");
}

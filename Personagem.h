#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem {
public:
  Personagem(int vidaInicial, int danoInicial);
  void atacar(Personagem &alvo);
  int obterVida() const;
  int obterDano() const;
  void receberDano(int dano);

private:
  int vida;
  int dano;
};

class Jogador : public Personagem {
public:
  Jogador();
  void defender();
};

class Esqueleto : public Personagem {
public:
  Esqueleto();
};

#endif

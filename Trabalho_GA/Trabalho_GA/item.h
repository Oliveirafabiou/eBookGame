#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    string nome;
    char tipo;        // 'c' = comum, 'r' = armadura, 'w' = arma
    bool combate;     // se pode ser usado em combate
    int bonusFA;      // bônus de força de ataque
    int bonusDano;    // bônus de dano

public:

    Item();
    Item(string nome, char tipo, bool combate, int bonusFA, int bonusDano);

    string getNome() const;
	char getTipo() const;
	bool podeUsarEmCombate() const;
	int getBonusFA() const;
	int getBonusDano() const;

	void exibir() const;
};
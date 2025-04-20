#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include "personagem.h"
using namespace std;

class Inimigo : public Personagem
{
private:
	int cenaSucesso;
	int cenaFracasso;
	bool permiteFuga;

public:
	Inimigo();
	Inimigo(string nome, int habilidade, int energia, int sorte,
		int moedas, int provisoes, Item itemDrop,
		int cenaSucesso, int cenaFracasso, bool permiteFuga = true);

	int getCenaSucesso() const;
	int getCenaFracasso() const;
	Item getItemDrop() const;
	bool podeFugir() const;

	void exibir() const;
};
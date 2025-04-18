#include "item.h"

Item::Item()
{
	nome = "";
	tipo = 'c';
	combate = false;
	bonusFA = 0;
	bonusDano = 0;
}

Item::Item(string nome, char tipo, bool combate, int bonusFA, int bonusDano)
{
	this->nome = nome;
	this->tipo = tipo;
	this->combate = combate;
	this->bonusFA = bonusFA;
	this->bonusDano = bonusDano;
}

string Item::getNome() const
{
	return nome;
}

char Item::getTipo() const
{
	return tipo;
}

bool Item::podeUsarEmCombate() const
{
	return combate;
}

int Item::getBonusFA() const
{
	return bonusFA;
}

int Item::getBonusDano() const
{
	return bonusDano;
}

void Item::exibir() const {
	cout << "Item: " << nome << endl;

	cout << "Tipo: ";
	switch (tipo) {
	case 'w': cout << "Arma"; break;
	case 'r': cout << "Armadura"; break;
	case 'c': default: cout << "Comum"; break;
	}
	cout << endl;

	cout << "Pode usar em combate: " << (combate ? "Sim" : "Não") << endl;
	cout << "Bônus de Força de Ataque: " << bonusFA << endl;
	cout << "Bônus de Dano: " << bonusDano << endl;
}
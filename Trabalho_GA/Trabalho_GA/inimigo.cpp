#include "inimigo.h"

Inimigo::Inimigo() : Personagem()
{
	this->habilidade = 0;
	this->energia = 0;
	this->sorte = 0;
	this->moedas = 0;
	this->provisoes = 0;
	this->cenaSucesso = -1;
	this->cenaFracasso = -1;
	this->permiteFuga = true;

}

Inimigo(string nome, int habilidade, int energia, int sorte, int moedas, int provisoes, Item itemDrop, int cenaSucesso, int cenaFracasso, bool permiteFuga)
{
	this->setHabilidade(habilidade);
	this->setEnergia(energia);
	this->setSorte(sorte);
	this->setMoedas(moedas);
	this->setProvisoes(provisoes);
	this->adicionarItem(itemDrop);

	this->cenaSucesso = cenaSucesso;
	this->cenaFracasso = cenaFracasso;
	this->permiteFuga = permiteFuga;
}

int Inimigo::getCenaSucesso() const {
	return cenaSucesso;
}

int Inimigo::getCenaFracasso() const {
	return cenaFracasso;
}

bool Inimigo::podeFugir() const {
	return permiteFuga;
}

void Inimigo::exibir() const {
	cout << "===== INIMIGO =====" << endl;
	cout << "Nome: " << getNome() << endl;
	cout << "Habilidade: " << getHabilidade() << endl;
	cout << "Energia: " << getEnergia() << endl;
	cout << "Sorte: " << getSorte() << endl;
	cout << "Tesouro: " << getMoedas() << " moedas" << endl;
	cout << "Provisoes: " << getProvisoes() << endl;
	cout << "Pode fugir dele? " << (permiteFuga ? "Sim" : "Nao") << endl;
	cout << "====================" << endl;
}

Item Inimigo::getItemDrop() const {
	if (this->getTamanhoInventario() > 0)
    	return this->inventario[0];
	else
    	return Item();

}
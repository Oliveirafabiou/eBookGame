#include "magia.h"

Magia::Magia()
{
	nome = "";
	descricao = "";
	custoEnergia = 0;
	dano = 0;
}

Magia::Magia(string nome, string descricao, int custoEnergia, int dano)
{
	this->nome = nome;
	this->descricao = descricao;
	this->custoEnergia = custoEnergia;
	this->dano = dano;
}

string Magia::getNome() const
{
	return nome;
}

string Magia::getDescricao() const
{
	return descricao;
}

int Magia::getCustoEnergia() const
{
	return custoEnergia;
}

int Magia::getDano() const
{
	return dano;
}

void Magia::exibir() const
{
	cout << "Magia: " << nome << endl;
	cout << "Descricao: " << descricao << endl;
	cout << "Custo de Energia: " << custoEnergia << endl;
	cout << "Dano causado: " << dano << endl;
}
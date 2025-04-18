#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Magia {
private:
	string nome;
	string descricao;
	int custoEnergia;
	int dano;

public:
	Magia();
	Magia(string nome, string descricao, int custoEnergia, int dano);

	string getNome() const;
	string getDescricao() const;
	int getCustoEnergia() const;
	int getDano() const;

	void exibir() const;
};
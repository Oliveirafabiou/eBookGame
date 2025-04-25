#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include "item.h"
#include "magia.h"
using namespace std;

class Personagem {
protected:
	string nome;
	int habilidade;
	int energia;
	int sorte;
	bool ehMago;
	int moedas;
	int provisoes;

	Item* inventario;
	int tamanhoInventario;
	int capacidadeInventario;

	Magia* magias;
	int quantidadeMagias;
	int capacidadeMagias;

	string* cenasVisitadas;
	int quantidadeCenas;

public:
	Personagem();
    Personagem(string nome, bool mago);
	Personagem(string nome, bool mago, bool inicializaComItens);
	~Personagem();

    void distribuirAtributos();
    void mostrarStatus();
    bool testarSorte();

    virtual void receberDano(int dano);
    void recuperarEnergia(int energia);

    void adicionarItem(const Item& item);
    void removerItem(const string& nomeItem);
    bool possuiItem(const string& nomeItem);
    void usarProvisao();
	void adicionarMagia(const Magia& magia);
	void setAtributos(string nome, bool mago);

    void adicionarCenaVisitada(const string& cena);

	string getNome() const;
	void setNome(string& n);

	int getHabilidade() const;
	void setHabilidade(int h);

	int getEnergia() const;
	void setEnergia(int e);

	int getSorte() const;
	void setSorte(int s);

	int getMoedas() const;
	void setMoedas(int m);

	int getProvisoes() const;
	void setProvisoes(int p);

	int getTamanhoInventario() const;
	Item getItem(int index) const;

	int getQuantidadeMagias() const;
	Magia getMagia(int index) const;

	bool isMago() const;
};
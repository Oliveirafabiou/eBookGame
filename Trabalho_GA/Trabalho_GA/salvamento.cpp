#include "salvamento.h"
#include <fstream>
#include <iostream>
using namespace std;

void salvarJogo(const Personagem& jogador, int cenaAtual) {
    ofstream arquivo("save.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao salvar o jogo!" << endl;
        return;
    }

    arquivo << jogador.getNome() << endl;
    arquivo << jogador.isMago() << endl;
    arquivo << jogador.getHabilidade() << " "
        << jogador.getEnergia() << " "
        << jogador.getSorte() << endl;
    arquivo << jogador.getMoedas() << " "
        << jogador.getProvisoes() << endl;
    arquivo << cenaAtual << endl;

    // Inventário
    arquivo << jogador.getTamanhoInventario() << endl;
    for (int i = 0; i < jogador.getTamanhoInventario(); i++) {
        arquivo << jogador.getItem(i).getNome() << endl;
    }

    // Magias
    arquivo << jogador.getQuantidadeMagias() << endl;
    for (int i = 0; i < jogador.getQuantidadeMagias(); i++) {
        arquivo << jogador.getMagia(i).getNome() << endl;
    }

    arquivo.close();
    cout << "Jogo salvo com sucesso!" << endl;
}

bool carregarJogo(Personagem& jogador, int& cenaAtual) {
    ifstream arquivo("save.txt");
    if (!arquivo.is_open()) {
        cout << "Nenhum jogo salvo encontrado." << endl;
        return false;
    }

    string nome;
    bool mago;
    int habilidade, energia, sorte;
    int moedas, provisoes;

    getline(arquivo, nome);
    arquivo >> mago >> habilidade >> energia >> sorte;
    arquivo >> moedas >> provisoes;
    arquivo >> cenaAtual;
    arquivo.ignore(); 

    jogador = Personagem(nome, mago);
    jogador.setHabilidade(habilidade);
    jogador.setEnergia(energia);
    jogador.setSorte(sorte);
    jogador.setMoedas(moedas);
    jogador.setProvisoes(provisoes);

    // Inventário
    int qtdItens;
    arquivo >> qtdItens;
    arquivo.ignore();
    for (int i = 0; i < qtdItens; i++) {
        string nomeItem;
        getline(arquivo, nomeItem);
        Item item(nomeItem, 'c', false, 0, 0); 
        jogador.adicionarItem(item);
    }

    // Magias
    int qtdMagias;
    arquivo >> qtdMagias;
    arquivo.ignore();
    for (int i = 0; i < qtdMagias; i++) {
        string nomeMagia;
        getline(arquivo, nomeMagia);
        Magia magia(nomeMagia, "Recuperada", 1, 1); 
        jogador.adicionarMagia(magia);
    }

    arquivo.close();
    cout << "Jogo carregado com sucesso!" << endl;
    return true;
}
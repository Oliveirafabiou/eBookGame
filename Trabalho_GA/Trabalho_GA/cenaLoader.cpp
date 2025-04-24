#include "cenaLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

bool carregarInimigoDeCena(const string& nomeArquivo, Inimigo& inimigo) {
    ifstream arquivo(nomeArquivo + ".txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo da cena: " << nomeArquivo << endl;
        return false;
    }

    string linha;
    getline(arquivo, linha);
    if (linha != "m") {
        return false;
    }

    string nome, nomeItem;
    int habilidade, energia, sorte, moedas, provisoes;
    int cenaSucesso, cenaFracasso;
    char permiteFuga;

    getline(arquivo, nome);
    arquivo >> habilidade >> energia >> sorte >> moedas >> provisoes;
    arquivo.ignore();
    getline(arquivo, nomeItem);
    arquivo >> cenaSucesso >> cenaFracasso;
    arquivo >> permiteFuga;
    arquivo.ignore();

    Item item(nomeItem, 'w', true, 1, 1); // simplificado
    inimigo = Inimigo(nome, habilidade, energia, sorte, moedas, provisoes, item, cenaSucesso, cenaFracasso, permiteFuga == 's');

    return true;
}
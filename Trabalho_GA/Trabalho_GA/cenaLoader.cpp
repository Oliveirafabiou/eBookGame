#include "cenaLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>
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
    cout << "Nome do inimigo: [" << nome << "]" << endl;

    arquivo >> habilidade >> energia >> sorte >> moedas >> provisoes;
    cout << "Atributos: hab=" << habilidade << " ene=" << energia << " sor=" << sorte << " moedas=" << moedas << " prov=" << provisoes << endl;

    arquivo.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(arquivo, nomeItem);
    cout << "Item do inimigo: [" << nomeItem << "]" << endl;

    arquivo >> cenaSucesso >> cenaFracasso;
    cout << "Cenas: sucesso=" << cenaSucesso << " fracasso=" << cenaFracasso << endl;

    arquivo >> permiteFuga;
    cout << "Permite fuga? [" << permiteFuga << "]" << endl;

    Item item(nomeItem, 'w', true, 1, 1);
    inimigo.setAtributos(nome, habilidade, energia, sorte, moedas, provisoes, item, cenaSucesso, cenaFracasso, permiteFuga == 's');

    Inimigo* in = new Inimigo(nome, habilidade, energia, sorte, moedas, provisoes, item, cenaSucesso, cenaFracasso, permiteFuga == 's');

    int a = 10;

    delete in;
    return true;
}
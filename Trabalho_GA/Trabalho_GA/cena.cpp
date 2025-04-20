#include "cena.h"
#include "cenaLoader.h"
#include "inimigo.h"
#include "combate.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

void carregarCena(int numeroCena, Personagem& jogador)
{
    // Gera o nome do arquivo:
    ostringstream nomeArq;
    nomeArq << setfill('0') << setw(3) << numeroCena;

    ifstream arquivo("cenas/" + nomeArq.str() + ".txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir a cena " << numeroCena << endl;
        return;
    }

    // Verifica se a cena tem inimigo
    Inimigo inimigo;
    if (carregarInimigoDeCena(nomeArq.str(), inimigo)) {
        combate(jogador, inimigo);

        if (jogador.getEnergia() <= 0) {
            cout << "Fim de jogo." << endl;
            return;
        }

        int proximaCena = (inimigo.getEnergia() <= 0)
            ? inimigo.getCenaSucesso()
            : inimigo.getCenaFracasso();

        arquivo.close();
        carregarCena(proximaCena, jogador);
        return;
    }

    // Cena comum (sem inimigo)
    string linha;
    getline(arquivo, linha);

    cout << "\n------------------------------" << endl;
    cout << linha << endl;

    vector<pair<string, int>> opcoes;

    while (getline(arquivo, linha)) {
        if (linha == "x") {
            cout << "\nFim de jogo!" << endl;
            return;
        }

        if (linha[0] == '*') {
            size_t seta = linha.find("->");
            if (seta != string::npos) {
                string texto = linha.substr(1, seta - 1);
                int destino = stoi(linha.substr(seta + 2));
                opcoes.push_back({ texto, destino });
            }
        }
        else {
            cout << linha << endl;
        }
    }

    for (int i = 0; i < opcoes.size(); i++) {
        cout << i + 1 << ". " << opcoes[i].first << endl;
    }

    int escolha;
    cout << "\nEscolha uma opção: ";
    cin >> escolha;

    if (escolha >= 1 && escolha <= opcoes.size()) {
        carregarCena(opcoes[escolha - 1].second, jogador);
    }
    else {
        cout << "Opção inválida. Fim do jogo." << endl;
    }

    arquivo.close();
}
#include "cena.h"
#include "cenaLoader.h"
#include "inimigo.h"
#include "combate.h"
#include "salvamento.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

void carregarCena(int numeroCena, Personagem& jogador)
{
    // Gera o nome do arquivo:
    ostringstream nomeArq;
    nomeArq << setfill('0') << setw(3) << numeroCena;

    ifstream arquivo(nomeArq.str() + ".txt");


    if (!arquivo.is_open()) {
        cout << "Erro ao abrir a cena " << numeroCena << endl;
        return;
    }

    // Verifica se a cena tem inimigo
    Inimigo inimigo{};
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
            if (seta != string::npos && seta > 1 && seta + 2 < linha.size()) {
                string texto = linha.substr(1, seta - 1); 
                string destinoStr = linha.substr(seta + 2); 

                try {
                    int destino = stoi(destinoStr);
                    opcoes.push_back({ texto, destino });
                }
                catch (...) {
                    cout << "Erro ao interpretar o destino da opção: \"" << linha << "\"" << endl;
                }
            }
            else {
                cout << "Opção mal formatada encontrada na cena: \"" << linha << "\"" << endl;
            }
        }
        else {
            cout << linha << endl;
        }
    }

    for (int i = 0; i < opcoes.size(); i++) {
        cout << i + 1 << ". " << opcoes[i].first << endl;
    }

    int escolha = 0;
    do {
        cout << "\nEscolha uma opção: ";
        cin >> escolha;

        if (cin.fail() || escolha < 1 || escolha > opcoes.size()) {
            cin.clear();              
            cin.ignore(1000, '\n');   
            cout << "Opção inválida. Tente novamente.\n";
        }
        else {
            break;
        }

    } while (true);

    
    int proximaCena = opcoes[escolha - 1].second;
    salvarJogo(jogador, proximaCena);
    carregarCena(proximaCena, jogador);

}
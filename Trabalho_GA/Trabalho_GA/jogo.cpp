#include "jogo.h"
#include "personagem.h"
#include "cena.h"
#include "inventario.h"
#include <iostream>
#include <ctime>  
#include <limits>
using namespace std;

void iniciarJogo() {
    srand(time(NULL)); 

    string nome;
    char classe;

    cout << "============================" << endl;
    cout << "     BEM-VINDO AO JOGO     " << endl;
    cout << "============================" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do {
        cout << "\nDigite o nome do seu personagem: ";
        getline(cin, nome);

        if (nome.empty()) {
            cout << "O nome não pode estar vazio. Tente novamente.\n";
        }
    } while (nome.empty());

    do {
        cout << "Escolha sua classe ([G]uerreiro / [M]ago): ";
        cin >> classe;
        classe = toupper(classe);
    } while (classe != 'G' && classe != 'M');

    bool mago = (classe == 'M');

    Personagem jogador(nome, mago);
    jogador.distribuirAtributos();

    cout << "\nPersonagem criado com sucesso!\n";
    jogador.mostrarStatus();


    cout << "\nIniciando a aventura..." << endl;

    carregarCena(1, jogador); 
}
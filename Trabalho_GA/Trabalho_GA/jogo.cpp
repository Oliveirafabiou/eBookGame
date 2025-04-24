#include "jogo.h"
#include "personagem.h"
#include "cena.h"
#include "inventario.h"
#include <iostream>
#include <ctime>  
#include <limits>
#include <cstdlib>

using namespace std;

void iniciarJogo() {
    srand(time(NULL)); 

    string nome;
    char classe = '\0'; 
    string entrada;

    cout << "============================" << endl;
    cout << "     BEM-VINDO AO JOGO     " << endl;
    cout << "============================" << endl;

    do {
        cout << "\nDigite o nome do seu personagem: ";
        getline(cin, nome);

        if (nome.empty()) {
			system("cls");
            cout << "O nome não pode estar vazio. Tente novamente.\n";

        }
    } while (nome.empty());

    do {
        cout << "\nEscolha sua classe ([G]uerreiro / [M]ago): ";
        getline(cin, entrada); 

        // Verifica se a entrada não tem exatamente um caractere
        if (entrada.length() != 1) { 
            system("cls");
            cout << "Classe inválida. Tente novamente.\n";
            continue;
        }

        classe = toupper(entrada[0]); 

        if (classe != 'G' && classe != 'M') {
            system("cls");
            cout << "Classe inválida. Tente novamente.\n";
        }
    } while (classe != 'G' && classe != 'M');

    bool mago = (classe == 'M'); 

    system("cls");
    Personagem jogador(nome, mago);
    jogador.distribuirAtributos();

    cout << "\nPersonagem criado com sucesso!\n";
    jogador.mostrarStatus();

    system("cls");
    cout << "\nIniciando a aventura..." << endl;
    
	// Inicia o jogo na cena 1
    carregarCena(1, jogador); 
}
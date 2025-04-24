#include "salvamento.h"
#include "jogo.h"
#include "cena.h"
#include <ctime>
#include <cstdlib>


int main() {
	setlocale(LC_ALL, "Portuguese");
    Personagem jogador;
    int cenaAtual = 1;

    char opcao;
    do {
        cout << "\nDeseja carregar um jogo salvo? (S/N): ";
        cin >> opcao;
        opcao = toupper(opcao);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (opcao != 'S' && opcao != 'N');

    if (opcao == 'S') {
        if (!carregarJogo(jogador, cenaAtual)) {
            cout << "\nFalha ao carregar jogo! Iniciando um novo jogo...\n";
            iniciarJogo(); 
        }
        else {
			cout << "\nJogo carregado com sucesso!\n";
            carregarCena(cenaAtual, jogador);
        }
    }
    else {
		system("cls");
		cout << "\nIniciando um novo jogo...\n\n\n";
        
        iniciarJogo();
    }

    return 0;
}
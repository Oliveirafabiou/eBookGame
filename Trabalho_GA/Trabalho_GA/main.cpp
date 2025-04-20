#include "salvamento.h"
#include "jogo.h"
#include "cena.h"

int main() {
    Personagem jogador;
    int cenaAtual = 1;

    char opcao;
    cout << "Deseja carregar o jogo salvo? (s/n): ";
    cin >> opcao;

    if (opcao == 's' || opcao == 'S') {
        if (!carregarJogo(jogador, cenaAtual)) {
            iniciarJogo(); 
        }
        else {
            carregarCena(cenaAtual, jogador);
        }
    }
    else {
        iniciarJogo();
    }

    return 0;
}
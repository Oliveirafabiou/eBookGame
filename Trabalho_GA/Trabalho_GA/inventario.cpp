#include "inventario.h"
#include <iostream>
using namespace std;

void mostrarInventario(const Personagem& jogador) {
    cout << "\n======= INVENTÁRIO =======" << endl;

    if (jogador.getTamanhoInventario() == 0) {
        cout << "Inventário vazio." << endl;
    }
    else {
        for (int i = 0; i < jogador.getTamanhoInventario(); i++) {
            cout << "- " << jogador.getItem(i).getNome() << endl;
        }
    }

    cout << "===========================\n" << endl;
}

void mostrarMagias(const Personagem& jogador) {
    if (!jogador.isMago()) {
        cout << "\nEsse personagem não é um mago!" << endl;
        return;
    }

    cout << "\n======= MAGIAS =======" << endl;

    if (jogador.getQuantidadeMagias() == 0) {
        cout << "Nenhuma magia aprendida." << endl;
    }
    else {
        for (int i = 0; i < jogador.getQuantidadeMagias(); i++) {
            jogador.getMagia(i).exibir();
            cout << "------------------" << endl;
        }
    }

    cout << "=======================\n" << endl;
}
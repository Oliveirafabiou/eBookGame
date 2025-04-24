#include "inventario.h"
#include <iostream>
using namespace std;

void mostrarInventario(const Personagem& jogador) {
    cout << "\n======= INVENTARIO =======" << endl;

    if (jogador.getTamanhoInventario() == 0) {
        cout << "Inventario vazio." << endl;
    }
    else {
        for (int i = 0; i < jogador.getTamanhoInventario(); i++) {
            Item item = jogador.getItem(i);
            cout << "- " << item.getNome() << " (";
            cout << (item.getTipo() == 'w' ? "Arma" : item.getTipo() == 'r' ? "Armadura" : "Comum");
            cout << ", FA: " << item.getBonusFA();
            cout << ", Dano: " << item.getBonusDano();
            cout << ", Combate: " << (item.podeUsarEmCombate() ? "Sim" : "Não") << ")" << endl;
        }
    }

    cout << "===========================\n" << endl;
}

void mostrarMagias(const Personagem& jogador) {
    if (!jogador.isMago()) {
        cout << "\nEsse personagem nao e um mago!" << endl;
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
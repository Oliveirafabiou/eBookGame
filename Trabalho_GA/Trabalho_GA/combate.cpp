#include "combate.h"

void combate(Personagem& jogador, Inimigo& inimigo)
{
	cout << "\n Um combate começou contra " << inimigo.getNome() << "!\n" << endl;

	while (jogador.getEnergia() > 0 && inimigo.getEnergia() > 0) {
		cout << "-------------------------------------" << endl;
		jogador.mostrarStatus();
		inimigo.exibir();

		cout << "Ações disponiveis: " << endl;
		cout << "1. Atacar" << endl;
		cout << "2. Usar sorte" << endl;
		cout << "3. Fugir" << endl;

		int escolha;

		cout << "Escolha sua ação: ";
		cin >> escolha;

		if (escolha == 3) {
			if (inimigo.podeFugir()) {
				cout << "\n Voce fugiu da batalha!" << endl;
				return;
			}
			else {
				cout << "\n Voce nao pode fugir desse inimigo" << endl;
				continue;
			}
		}


		//calculando as forças de ataque

		int faJogador = rand() % 10 + 1 + jogador.getHabilidade();
		int faInimigo = rand() % 10 + 1 + inimigo.getHabilidade();

		cout << "\n Forca de ataque do jogador: " << faJogador << endl;
		cout << " Forca de ataque do inimigo: " << faInimigo << endl;

		if (faJogador > faInimigo) {
			cout << "\n Voce acertou o inimigo!" << endl;
			int dano = 2;
			if (escolha == 2) {
				if (jogador.testarSorte()) {
					dano = 3;
					cout << "Parece que a sorte esta ao seu lado, dano aumentado!" << endl;
				}
				else {
					dano = 1;
					cout << "A sorte nao estava ao seu favor, dano reduzido!" << endl;
				}
			}

			inimigo.receberDano(dano);
		}
		else if (faInimigo > faJogador) {
			cout << "O inimigo acertou voce!" << endl;
			int dano = 2;
			jogador.receberDano(dano);
		}
		else {
			cout << "Empate! Ninguem causou dano." << endl;
		}
	}

	if (inimigo.getEnergia() <= 0) {
		cout << "\n Voce venceu o combate!" << endl;

		jogador.setMoedas(jogador.getMoedas() + inimigo.getMoedas());
		jogador.setProvisoes(jogador.getProvisoes() + inimigo.getProvisoes());
		jogador.adicionarItem(inimigo.getItemDrop());

		cout << "Voce recebeu " << inimigo.getMoedas() << " moedas e " << inimigo.getProvisoes() << " provisoes." << endl;
		cout << "Voce Obteve o item: " << inimigo.getItemDrop().getNome() << endl;

	}
	else if (jogador.getEnergia() <= 0) {
		cout << "\n Voce foi derrotado..." << endl;
	}


}
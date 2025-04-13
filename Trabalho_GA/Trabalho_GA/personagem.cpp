#include "personagem.h"

Personagem::Personagem() 
{
    nome = "";
    ehMago = false;
    habilidade = 0;
    energia = 0;
    sorte = 0;
    moedas = 0;
    provisoes = 0;

    capacidadeInventario = 10;
    tamanhoInventario = 0;
    inventario = new Item[capacidadeInventario];

    capacidadeMagias = 5;
    quantidadeMagias = 0;
    magias = new Magia[capacidadeMagias];

    quantidadeCenas = 0;
    cenasVisitadas = new string[100]; 
}

Personagem::Personagem(string nome, bool mago) 
{
    this->nome = nome;
    this->ehMago = mago;
    habilidade = 0;
    energia = 0;
    sorte = 0;
    moedas = 0;
    provisoes = 2;

    capacidadeInventario = 10;
	tamanhoInventario = 0;
    inventario = new Item[capacidadeInventario];

	capacidadeMagias = 5;
    quantidadeMagias = 0;
	magias = new Magia[capacidadeMagias];

	quantidadeCenas = 0;
	cenasVisitadas = new string[100];
}

Personagem::~Personagem() 
{
	delete[] inventario;
	delete[] magias;
	delete[] cenasVisitadas;
}

void Personagem::distribuirAtributos()
{
    int pontos = 36;
    int hab = 0;
    int ene = 0;
    int sor = 0;

    cout << "Voce tem 36 pontos de atributos para distribuir entre HABILIDADE, ENERGIA e SORTE." << endl;
    cout << "Lembre-se que sua HABILIDADE e SORTE devem ser no minimo 6 e maximo 12.\nJa a sua ENERGIA deve ser no minimo 12 e no maximo 24." << endl;
    cout << "Distribua os pontos entre os atributos." << endl;
    while (true)
    {
        cout << "HABILIDADE (min. 6): " << endl;
        cin >> hab;
        cout << "ENERGIA (min. 12): " << endl;
        cin >> ene;
        cout << "SORTE (min. 6): " << endl;
        cin >> sor;

        int pontosUsados = hab + ene + sor;
        int pontosRestantes = pontos - pontosUsados;

        if (hab < 6 || hab > 12 || ene < 12 || ene > 24 || sor < 6 || sor > 12 || pontosRestantes != 0) {
            cout << "Distribuicao invalida. ";
            cout << "Voce ainda tem " << pontosRestantes << " ponto(s) para distribuir." << endl;
        }
        else {
            break;
        }
    }

	habilidade = hab;
	energia = ene;
    sorte = sor;

    cout << "Distribuicao de atributos concluida!" << endl;
	cout << "Aqui estão seus atributos:" << endl;
    cout << "HABILIDADE: " << habilidade << endl;
    cout << "ENERGIA: " << energia << endl;
    cout << "SORTE: " << sorte << endl;
}

void Personagem::mostrarStatus() 
{
    cout << "\n===== STATUS DO PERSONAGEM =====" << endl;
    cout << "Nome: " << nome << (ehMago ? " (Mago)" : " (Guerreiro)") << endl;
    cout << "Habilidade: " << habilidade << endl;
    cout << "Energia: " << energia << endl;
    cout << "Sorte: " << sorte << endl;
    cout << "Moedas: " << moedas << endl;
    cout << "Provisões: " << provisoes << endl;
    cout << "Itens no inventário: " << tamanhoInventario << endl;
    cout << "=================================\n" << endl;
}

bool Personagem::testarSorte()
{
	int dado = rand() % 12 + 1;
	bool sucesso = dado <= sorte;
    cout << "Teste de sorte: tirou " << dado << " (" << (sucesso ? "SUCESSO" : "FALHA") << ")" << endl;
    if (sorte > 0) sorte--;
	return sucesso;
}

void Personagem::receberDano(int dano)
{
    energia -= dano;
	if (energia < 0) energia = 0;
	cout << "Você recebeu " << dano << " de dano. Energia atual: " << energia << endl;
}

void Personagem::recuperarEnergia(int energiaRecuperada)
{

}
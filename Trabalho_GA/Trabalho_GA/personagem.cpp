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
	energia += energiaRecuperada;
    cout << "Você recuperou " << energiaRecuperada << " de energia. Energia atual: " << energia << endl;
}

void Personagem::adicionarItem(const Item& item)
{
    if (tamanhoInventario >= capacidadeInventario) {
		capacidadeInventario *= 2;
		Item* novoInventario = new Item[capacidadeInventario];

        for (int i = 0; i < tamanhoInventario; i++) {
            novoInventario[i] = inventario[i];
        }

		delete[] inventario;
		inventario = novoInventario;
    }

	inventario[tamanhoInventario] = item;
	tamanhoInventario++;

	cout << "Item adicionado ao inventário: " << item.getNome() << endl;
}

void Personagem::removerItem(const string& nomeItem) {
    for (int i = 0; i < tamanhoInventario; i++) {
        if (inventario[i].getNome() == nomeItem) {
            for (int j = i; j < tamanhoInventario - 1; j++) {
				inventario[j] = inventario[j + 1];
            }
			tamanhoInventario--;
			cout << "Item removido: " << nomeItem << endl;
			return;
        }
    }
	cout << "Item não encontrado: " << nomeItem << endl;
}

bool Personagem::possuiItem(const string& nomeItem) {
    for (int i = 0; i < tamanhoInventario; i++) {
        if (inventario[i].getNome() == nomeItem) {
			return true;
        }
    }
    return false;
}

void Personagem::usarProvisao() {
    if (provisoes) {
        provisoes--;
		recuperarEnergia(4);
    }
    else {
		cout << "Você não tem provisões!" << endl;
    }
}

void Personagem::adicionarCenaVisitada(const string& cena) {
	cenasVisitadas[quantidadeCenas] = cena;
	quantidadeCenas++;
}

string Personagem::getNome() const {
	return nome;
}

void Personagem::setNome(string& n) {
	nome = n;
}

int Personagem::getHabilidade() const {
	return habilidade;
}

void Personagem::setHabilidade(int h) {
	habilidade = h;
}

int Personagem::getEnergia() const {
	return energia;
}

void Personagem::setEnergia(int e) {
	energia = e;
}

int Personagem::getSorte() const {
	return sorte;
}

void Personagem::setSorte(int s) {
	sorte = s;
}

int Personagem::getMoedas() const {
	return moedas;
}

void Personagem::setMoedas(int m) {
	moedas = m;
}

int Personagem::getProvisoes() const {
	return provisoes;
}

void Personagem::setProvisoes(int p) {
	provisoes = p;
}
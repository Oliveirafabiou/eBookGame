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

    cout << "\nVoce tem 36 pontos de atributos para distribuir entre HABILIDADE, ENERGIA e SORTE.\n" << endl;
    cout << "Lembre-se que sua HABILIDADE e SORTE devem ser no minimo 6 e maximo 12.\n\nJa a sua ENERGIA deve ser no minimo 12 e no maximo 24.\n" << endl;
    cout << "Distribua os pontos entre os atributos.\n" << endl;
    while (true)
    {
        cout << "\nHABILIDADE (min. 6): " << endl;
        cin >> hab;
        cout << "\nENERGIA (min. 12): " << endl;
        cin >> ene;
        cout << "\nSORTE (min. 6): " << endl;
        cin >> sor;

        int pontosUsados = hab + ene + sor;
        int pontosRestantes = pontos - pontosUsados;

        if (hab < 6 || hab > 12 || ene < 12 || ene > 24 || sor < 6 || sor > 12 || pontosRestantes != 0) {
            system("cls");
            cout << "Distribuicao invalida. \n";
            if (pontosRestantes < 0) {
                cout << "Voce usou " << abs(pontosRestantes) << " ponto(s) a mais do que o permitido.\nPor favor distribua novamente" << endl;
            }
            else {
                cout << "Voce ainda tem " << pontosRestantes << " ponto(s) para distribuir.\nPor favor distribua novamente" << endl;
            }
        }
        else {
            break;
        }
    }

	habilidade = hab;
	energia = ene;
    sorte = sor;

    system("cls");
    cout << "Distribuicao de atributos concluida!" << endl;
	cout << "\nAqui estao seus atributos:" << endl;
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
    cout << "Provis�es: " << provisoes << endl;
    cout << "Itens no invent�rio: " << tamanhoInventario << endl;
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
	cout << "Voc� recebeu " << dano << " de dano. Energia atual: " << energia << endl;
}

void Personagem::recuperarEnergia(int energiaRecuperada)
{
	energia += energiaRecuperada;
    cout << "Voc� recuperou " << energiaRecuperada << " de energia. Energia atual: " << energia << endl;
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

    if (tamanhoInventario < capacidadeInventario) {
        inventario[tamanhoInventario] = item;
        tamanhoInventario++;
        cout << "Item adicionado ao invent�rio: " << item.getNome() << endl;
    }
    else {
        cout << "Erro: N�o foi poss�vel adicionar o item ao invent�rio." << endl;
    }
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
	cout << "Item n�o encontrado: " << nomeItem << endl;
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
		cout << "Voc� n�o tem provis�es!" << endl;
    }
}

void Personagem::adicionarMagia(const Magia& magia)
{
    if (quantidadeMagias >= capacidadeMagias) {
		capacidadeMagias *= 2;

		Magia* novoArray = new Magia[capacidadeMagias];

		for (int i = 0; i < quantidadeMagias; i++) {
			novoArray[i] = magias[i];
		}

		delete[] magias;
		magias = novoArray;
    }

	magias[quantidadeMagias] = magia;
	quantidadeMagias++;

	cout << "Magia aprendida: " << magia.getNome() << endl;
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


int Personagem::getTamanhoInventario() const {
    return tamanhoInventario;
}

Item Personagem::getItem(int index) const {
    if (index >= 0 && index < tamanhoInventario) {
        return inventario[index];
    }
    return Item();
}

int Personagem::getQuantidadeMagias() const {
    return quantidadeMagias;
}

Magia Personagem::getMagia(int index) const {
    if (index >= 0 && index < quantidadeMagias) {
        return magias[index];
    }
    return Magia();
}

bool Personagem::isMago() const {
    return ehMago;
}
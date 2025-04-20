#pragma once
#include "personagem.h"

void salvarJogo(const Personagem& jogador, int cenaAtual);
bool carregarJogo(Personagem& jogador, int& cenaAtual);
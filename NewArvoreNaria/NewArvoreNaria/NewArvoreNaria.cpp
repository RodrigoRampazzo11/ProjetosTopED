// NewArvoreNaria.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "ArvoreNaria.h"
#include "MinhaInformacao.h"
#include <iostream>

using namespace std;

int main()
{
	ArvoreNaria* arv = new ArvoreNaria(3);

	MinhaInformacao* novaInfo = new MinhaInformacao(21);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(13);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(27);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(17);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(19);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(18);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(24);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(30);
	arv->incluirNovaInfo(novaInfo);

	novaInfo = new MinhaInformacao(29);
	arv->incluirNovaInfo(novaInfo);
	cout << arv->escreverArvore() << "\n";

	MinhaInformacao* infoDesejada = new MinhaInformacao(21);
	arv->excluirInfo(infoDesejada);
	cout << arv->escreverArvore() << "\n";

	infoDesejada = new MinhaInformacao(19);
	arv->excluirInfo(infoDesejada);
	cout << arv->escreverArvore() << "\n";

	infoDesejada = new MinhaInformacao(18);
	arv->excluirInfo(infoDesejada);
	cout << arv->escreverArvore() << "\n";

    return 0;
}


// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Arvore.h"
#include "MinhaInformacao.h"
#include <iostream>

using namespace std;
int main()
{
	Arvore* arv = new Arvore();

	MinhaInformacao* info = new MinhaInformacao(10);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(9);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(12);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(7);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(11);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(13);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(8);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(14);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(6);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

/*
	info = new MinhaInformacao(5);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(13);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(14);
	arv->incluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(9);
	arv->exluirInfo(info);
	cout << arv->toString() << "\n";

	info = new MinhaInformacao(12);
	arv->exluirInfo(info);
	cout << arv->toString() << "\n";
	*/

    return 0;
}


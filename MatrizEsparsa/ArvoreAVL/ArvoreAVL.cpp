// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Arvore.h"
#include "MinhaInformacao.h"
#include <iostream>
#include "ArvoreColunas.h"

using namespace std;
int main()
{
	
	// arvColunas->getArvore()->incluirInfo(1, info);

	// arvLinhas->incluirInfo(1, arvColunas); 


	Arvore* arvLinhas = new Arvore();
	ArvoreColunas* arvColunas = new ArvoreColunas();
	MinhaInformacao* info = new MinhaInformacao("T");

	bool querContinuar = true;
	int opcao;
	int resposta;

	while (querContinuar)
	{
		cout << "\n--------------MATRIZ ESPARSA--------------\n";
		cout << "1- Incluir Informacao;\n";
		cout << "2- Excluir Informacao;\n";
		cout << "3- Escrever arvore;\n";
		cout << "4- Limpar tela;\n";
		cout << "5- Sair.\n";
		cout << "------------------------------------------\n";
		cout << "Qual opcao voce deseja realizar? ";
		cin >> opcao;
		cout << "\n";


		switch (opcao)
		{
		case 1:
			cout << "Qual valor deseja incluir? ";
			cin >> resposta;
			cout << "\n";
			try {
				info = new MinhaInformacao(resposta);
				arv->incluirInfo(info);
				cout << arv->toString() << "\n";
			}
			catch (exception& e) {
				cout << e.what() << "\n";
			}
			break;

		case 2:
			cout << "Qual valor deseja excluir? ";
			cin >> resposta;
			cout << "\n";
			try {
				info = new MinhaInformacao(resposta);
				arv->exluirInfo(info);
				cout << arv->toString() << "\n";
			}
			catch (exception& e) {
				cout << e.what() << "\n";
			}
			break;

		case 3:
			try {
				cout << arv->toString() << "\n";
			}
			catch (exception& e) {
				cout << e.what() << "\n";
			}
			break;

		case 4:
			system("CLS");
			break;

		case 5:
			querContinuar = false;
			break;
		}
	}

	return 0;
}


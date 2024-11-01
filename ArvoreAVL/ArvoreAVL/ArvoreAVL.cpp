// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Arvore.h"
#include "MinhaInformacao.h"
#include <iostream>
#include <conio.h>

using namespace std;

void printArvore(std::string string) {
// ==================================================
// Altera representacao grafica da arvore
// ==================================================

	system("CLS");
	std::string aux = "";

	//std::string UP = "\033[\001A";     // VT100
	//std::string DOWN = "\033[\001B";   // VT100

	std::string UP = "\033A";            // Variação do Windows
	std::string DOWN = "\033B";          // Variação do Windows

	int cntdown = 0;
	int cntLevel = 0;
	for (int i = 0; i < string.size(); i++) {
		if (string[i] == '(') {
			aux += DOWN + " ";
		    cntdown++;
			if (cntdown > cntLevel) {
				cntLevel = cntdown;
			}
		}
		else if (string[i] == ')') {
			aux += UP + " ";
			cntdown--;
		}
		else
			aux += string[i];
	}
	while (cntLevel > 0) {
		aux += DOWN;
		cntLevel--;
	}

	cout << aux << "\n";
	cout << string << "\n";
	// ==================================================
}

int main()
{
	Arvore* arv = new Arvore();
	MinhaInformacao* info;

	bool querContinuar = true;
	int opcao;
	int resposta;

	while (querContinuar)
	{
		cout << "\n----------------ARVORE AVL----------------\n";
		cout << "1- Incluir Informacao;\n";
		cout << "2- Excluir Informacao;\n";
		cout << "3- Escrever arvore;\n";
		cout << "0- Sair.\n";
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
				//cout << arv->toString() << "\n";
				printArvore(arv->toString());
			}
			catch (exception& e) {
				system("CLS");
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
				//cout << arv->toString() << "\n";
				printArvore(arv->toString());
			}
			catch (exception& e) {
				system("CLS");
				cout << e.what() << "\n";
			}
			break;

		case 3:
			try {
				//cout << arv->toString() << "\n";
				printArvore(arv->toString());
			}
			catch (exception& e) {
				system("CLS");
				cout << e.what() << "\n";
			}
			break;

		case 0:
			querContinuar = false;
			break;
		}
	}

	return 0;
}


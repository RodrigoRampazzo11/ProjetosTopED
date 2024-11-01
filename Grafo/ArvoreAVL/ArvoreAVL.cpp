// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include "MatrizEsparsa.h"
#include "Grafo.h"

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
		aux += "\n";
		cntLevel--;
	}

	cout << aux << "\n";
	cout << string << "\n";
	// ==================================================
}


int main()
{
	std::string valorPadraoDesejado;

	cout << "Qual STRING deseja como valor padrao para seu GRAFO? ";
	cin >> valorPadraoDesejado;
	system("CLS");

	Grafo* grafo = new Grafo(valorPadraoDesejado);

	bool querContinuar = true;
	int opcao;
	string origem,
		   destino,
		   custo,
		   resposta;

	while (querContinuar)
	{
		cout << "\n--------------GRAFO--------------\n";
		cout << "Valor padrao: " << valorPadraoDesejado << "\n";
		cout << "---------------------------------\n";
		cout << "1- Adicionar Vertice;\n";
		cout << "2- Deletar Vertice;\n";
		cout << "3- Adicionar Aresta;\n";
		cout << "4- Deletar Aresta;\n";
		cout << "0- Sair.\n";
		cout << "---------------------------------\n";
		cout << "Qual opcao voce deseja realizar? ";
		cin >> opcao;
		cout << "\n";


		switch (opcao)
		{
		case 1:
			cout << "Qual nome de vertice deseja adicionar? ";
			cin >> resposta;
			cout << "\n";
			system("CLS");
			try {
				grafo->AddVertice(resposta);
				cout << grafo->toString();
				//printArvore(matEsp->toString());
			}
			catch (exception& e) {
				cout << grafo->toString() << "\n";
				cout << e.what() << "\n";
			}
			break;

		case 2:
			cout << "Qual nome de vertice deseja deletar? ";
			cin >> resposta;
			cout << "\n";
			system("CLS");
			try {
				grafo->DelVertice(resposta);
				cout << grafo->toString();
				//printArvore(matEsp->toString());
			}
			catch (exception& e) {
				cout << grafo->toString() << "\n";
				cout << e.what() << "\n";
			}
			break;

		case 3:
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			cout << "Custo: ";
			cin >> custo;
			cout << "\n";
			system("CLS");
			try {
				grafo->AddAresta(origem, destino, custo);
				cout << grafo->toString() << "\n";
				//printArvore(matEsp->toString());
			}
			catch (exception& e) {
				cout << grafo->toString() << "\n";
				cout << e.what() << "\n";
			}
			break;

		case 4:
			cout << "Origem: ";
			cin >> origem;
			cout << "Destino: ";
			cin >> destino;
			cout << "\n";
			system("CLS");
			try {
				grafo->DelAresta(origem, destino);
				cout << grafo->toString() << "\n";
				//printArvore(matEsp->toString());
			}
			catch (exception& e) {
				cout << grafo->toString() << "\n";
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


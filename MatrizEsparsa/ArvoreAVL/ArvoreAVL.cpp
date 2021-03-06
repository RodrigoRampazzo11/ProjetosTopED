// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include "MatrizEsparsa.h"

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
		else if (string[i] == '\n') {
			while (cntLevel > 0) {
				aux += DOWN;
				cntLevel--;
			}
			aux += "\n";
			cntdown = 0;
		}
		else {
			aux += string[i];
		}
	}
	while (cntLevel > 0) {
		aux += "\n";
		cntLevel--;
	}

	cout << aux << "\n----------\n";
	cout << string << "\n";
	// ==================================================
}


int main()
{
	std::string valorPadraoDesejado;

	cout << "Qual STRING deseja como valor padrao para sua Matriz Esparsa? ";
	cin >> valorPadraoDesejado;
	system("CLS");

	MatrizEsparsa* matEsp = new MatrizEsparsa(valorPadraoDesejado);

	bool querContinuar = true;
	int opcao;
	int linha;
	int coluna;
	std::string resposta;

	while (querContinuar)
	{
		cout << "\n--------------MATRIZ ESPARSA--------------\n";
		cout << "Valor padrao: " << valorPadraoDesejado << "\n";
		cout << "------------------------------------------\n";
		cout << "1- Incluir Informacao;\n";
		cout << "0- Sair.\n";
		cout << "------------------------------------------\n";
		cout << "Qual opcao voce deseja realizar? ";
		cin >> opcao;
		cout << "\n";


		switch (opcao)
		{
		case 1:
			cout << "Linha: ";
			cin >> linha;
			cout << "Coluna: ";
			cin >> coluna;
			cout << "Qual valor deseja incluir? ";
			cin >> resposta;
			cout << "\n";
			system("CLS");
			try {
				matEsp->incluirInfo(linha, coluna, resposta);
				//cout << matEsp->toString() << "\n";
				printArvore(matEsp->toString());
			}
			catch (exception& e) {
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


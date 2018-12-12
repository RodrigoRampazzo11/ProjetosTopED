// ArvoreAVL.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "Arvore.h"
#include "MinhaInformacao.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

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
//////////////////////////////////////////////////////////////////////////////////////////////////////////
	FILE *arq;
	char Linha[100];
	char *result;
	int i;

	system("CLS");

	// Abre um arquivo TEXTO para LEITURA
	fopen_s(&arq, "Arquivos/entrada.txt", "r+");
	

	if (arq == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return 0;
	}

	i = 1;
	while (!feof(arq))
	{
		// Lê uma linha (inclusive com o '\n')
		result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
		if (result)  // Se foi possível ler
			printf("Linha %d : %s", i, Linha);
		i++;
	}
	fclose(arq);

//////////////////////////////////////////////////////////////////////////////////////////////////////////



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
				//cout << arv->toString() << "\n";
				printArvore(arv->toString());
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
				//cout << arv->toString() << "\n";
				printArvore(arv->toString());
			}
			catch (exception& e) {
				cout << e.what() << "\n";
			}
			break;

		case 3:
			try {
				//cout << arv->toString() << "\n";
				printArvore(arv->toString());
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


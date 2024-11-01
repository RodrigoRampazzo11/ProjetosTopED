// NewArvoreNaria.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "ArvoreNaria.h"
#include "MinhaInformacao.h"
#include <iostream>
#include <conio.h>


using namespace std;

int main()
{
	ArvoreNaria* arv;
	MinhaInformacao* info;
	bool tamanhoDefinido = false;
	int tamanho;
	

	while (!tamanhoDefinido)
	{
		cout << "Quantas infos voce deseja que tenha cada NO da arvore N-aria? ";
		cin >> tamanho;

		if (tamanho > 0)
			tamanhoDefinido = true;
		else
			cout << "\nTamanho invalido. Deve ser maior que 0.\n";
	}
	
	bool querContinuar = true;
	int opcao;
	int resposta;

	arv = new ArvoreNaria(tamanho);

	while (querContinuar)
	{
		cout << "\n----------------ARVORE N-ARIA----------------\n";
		cout << "1- Incluir Informacao;\n";
		cout << "2- Excluir Informacao;\n";
		cout << "3- Escreve Arvore;\n";
		cout << "0- Sair.\n";
		cout << "---------------------------------------------\n";
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
					arv->incluirNovaInfo(info);
					system("CLS");
					cout << arv->escreverArvore() << "\n";
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
					arv->excluirInfo(info);
					system("CLS");
					cout << arv->escreverArvore() << "\n";
				}
				catch (exception& e) {
					system("CLS");
					cout << e.what() << "\n";
				}
				break;

			case 3:
				try {
					system("CLS");
					cout << arv->escreverArvore() << "\n";
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


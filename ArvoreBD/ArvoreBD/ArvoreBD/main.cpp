// ArvoreBD.cpp: Define o ponto de entrada para a aplicação de console.
//

#include <iostream>
using namespace std;
#include "ArvoreArquivos.h"

int main()
{
	ArvoreArquivos<int, int> arvore("dados.txt", "tree.txt");

	bool querContinuar = true;
	int opcao;
	int chave;
	int valor;

	arvore.print(cout);
	cout << '\n';

	while (querContinuar)
	{
		cout << "\n-----------ARVORE AVL EM DISCO-----------\n";
		cout << "1- Incluir Informacao;\n";
		cout << "2- Excluir Informacao;\n";
		cout << "3- Existe Informacao?;\n";
		cout << "4- Excrever Arvore;\n";
		cout << "0- Sair.\n";
		cout << "-----------------------------------------\n";
		cout << "Qual opcao voce deseja realizar? ";
		cin >> opcao;
		cout << "\n";


		switch (opcao)
		{
		case 1:
			cout << "-Valores para inclusao-\n";
			cout << "Chave: ";
			cin >> chave;
			cout << "Valor: ";
			cin >> valor;
			cout << "\n";
			try {
				arvore.add(chave, valor);

				system("CLS");
				arvore.print(cout);
				cout << '\n';
			}
			catch (exception& e) {
				system("CLS");
				cout << e.what() << "\n";
			}
			break;

		case 2:
			cout << "Qual CHAVE deseja excluir? ";
			cin >> chave;
			cout << "\n";
			try {
				arvore.remove(chave);

				system("CLS");
				arvore.print(cout);
				cout << '\n';
			}
			catch (exception& e) {
				system("CLS");
				cout << e.what() << "\n";
			}
			break;

		case 3:
			cout << "Qual CHAVE deseja saber o VALOR? ";
			cin >> chave;
			cout << "\n";
			try {
				system("CLS");
				cout << (arvore.get(chave));
				cout << '\n';
			}
			catch (exception& e) {
				system("CLS");
				cout << e.what() << "\n";
			}
			break;

		case 4:
			try {
				system("CLS");
				arvore.print(cout);
				cout << '\n';
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
	/*
	const int tamanhoVetor = 15;
	const int vetor[tamanhoVetor] = { 12,39,16,93,65,25,24,14,72,31,21,27,83,44,97 };
	
	for (int i = 0; i < tamanhoVetor; i++) {
		
		cout << '\n';
		arvore.add(i,vetor[i]);
		arvore.print(cout);

		cout << '\n';
		//delete minhaInfo;
	}
	//delete minhaInfo;
	const int vetHa[tamanhoVetor] = {13, 7, 8, 14, 6, 10, 1, 4, 0, 5, 3, 2, 12, 11, 9 };
	
	for (int k = 0; k < tamanhoVetor; k++) {
		cout << '\n';
		cout << "Valor da chave";
		cout << vetHa[k];
		cout << " na arvore?R=";
		cout << (arvore.get(vetHa[k]));

		cout << '\n';
		//delete infoSelecionar;
	}
	arvore.print(cout);
	const int vetInd[tamanhoVetor] = { 4,1,8,6,14,7,9,2,12,11,5,13,0,10,3 };

	for (int j = 0; j < tamanhoVetor; j++) {
		cout << '\n';
		arvore.remove(vetInd[j]);
		arvore.print(cout);

		cout << '\n';
	}
	arvore.print(cout);
	*/

	return 0;
}


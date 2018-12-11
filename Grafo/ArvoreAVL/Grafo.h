#pragma once
#include "Matrizesparsa.h"
#include <string>
#include <vector>

using namespace std;

class Grafo
{
	private:
		//char ** nomeVertice;
		vector<string> nomeVertice;
		MatrizEsparsa* aresta;

		bool existeVertice(char* vertice);
		string toStringNomesVertices();
		string toStringArestas();

	public:
		Grafo(string valorPadrao);
		~Grafo();
		void AddVertice(char*);
		void DelVertice(char*);
		void AddAresta(char*, char*, char*);
		void DelAresta(char*, char*);

		string toString();
};


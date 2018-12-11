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

		bool existeVertice(string vertice);
		string toStringNomesVertices();
		string toStringArestas();

	public:
		Grafo(string valorPadrao);
		~Grafo();
		void AddVertice(string);
		void DelVertice(string);
		void AddAresta(string, string, string);
		void DelAresta(string, string);

		string toString();
};


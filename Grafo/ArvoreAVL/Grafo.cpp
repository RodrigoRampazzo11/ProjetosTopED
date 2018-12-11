#include "stdafx.h"
#include "Grafo.h"


Grafo::Grafo(std::string valorPadrao)
{
	this->aresta = new MatrizEsparsa(valorPadrao);
}

Grafo::~Grafo()
{
}

void Grafo::AddVertice(string novoVertice) throw()
{
	if (existeVertice(novoVertice))
		throw invalid_argument("Impossivel incluir vertice. Este vertice ja existe.");

	if (!existeVertice("-"))
		this->nomeVertice.push_back(novoVertice); // inclui novoVertice no final do vetor de vertices
	else
		for (int i = 0; i < this->nomeVertice.size(); i++)
			if (this->nomeVertice[i] == "-")
			{
				this->nomeVertice[i] = novoVertice;  // Deleta vertice do vetor de nome de vertices
				break;
			}
}

void Grafo::DelVertice(string verticeDesejado) throw()
{
	if (!existeVertice(verticeDesejado))
		throw invalid_argument("Impossivel excluir vertice. Este vertice nao existe.");

	for (int i = 0; i < this->nomeVertice.size(); i++)
		if (this->nomeVertice[i] == verticeDesejado)
		{
			this->aresta->deletarVertice(i);
			this->nomeVertice[i] = "-";  // Deleta vertice do vetor de nome de vertices
			return;
		}
}

void Grafo::AddAresta(string origem, string destino, string custo) throw()
{
	if (!existeVertice(origem))
		throw invalid_argument("Impossivel adicionar aresta. Vertice de origem nao existe.");
	if (!existeVertice(destino))
		throw invalid_argument("Impossivel adicionar aresta. Vertice de destino nao existe.");
	if (custo == this->aresta->getValorPadrao())
		throw invalid_argument("Impossivel adicionar aresta. Custo eh igual o valorPadrao.");

	int param1 = 0, 
		param2 = 0;

	for (param1 = 0; param1 < this->nomeVertice.size(); param1++)
		if (nomeVertice[param1] == origem)
			break;

	for (param2 = 0; param2 < this->nomeVertice.size(); param2++)
		if (nomeVertice[param2] == destino)
			break;

	this->aresta->incluirInfo(param1, param2, custo);
}
 
void Grafo::DelAresta(string origem, string destino)
{
	if (!existeVertice(origem))
		throw invalid_argument("Impossivel adicionar aresta. Vertice de origem nao existe.");
	if (!existeVertice(destino))
		throw invalid_argument("Impossivel adicionar aresta. Vertice de destino nao existe.");
	
	int param1 = 0,
		param2 = 0;

	for (param1 = 0; param1 < this->nomeVertice.size(); param1++)
		if (nomeVertice[param1] == origem)
			break;

	for (param2 = 0; param2 < this->nomeVertice.size(); param2++)
		if (nomeVertice[param2] == destino)
			break;

	this->aresta->incluirInfo(param1, param2, this->aresta->getValorPadrao());
}

bool Grafo::existeVertice(string vertice)
{
	for (int i = 0; i < this->nomeVertice.size(); i++)
		if (nomeVertice[i] == vertice)
			return true;
	return false;
}

string Grafo::toStringNomesVertices()
{
	string saida;
	saida = "Nomes Vertices:\n";
	for (int i = 0; i < this->nomeVertice.size(); i++)
		if(this->nomeVertice[i] != "-")
			saida += "[" + to_string(i) + "] " + this->nomeVertice[i] + "\n";
	return saida;
}

string Grafo::toStringArestas()
{
	return this->aresta->toString();
}

string Grafo::toString()
{
	return toStringNomesVertices() + toStringArestas();
}
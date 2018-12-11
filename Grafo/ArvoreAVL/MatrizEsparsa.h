#pragma once
#include "InformacaoDeArvoreAVL.h";
#include "ArvoreLinhas.h";
#include "ArvoreColunas.h";
#include "MinhaInformacao.h";

class MatrizEsparsa
{
private:
	ArvoreLinhas* arvLinhas;
	MinhaInformacao* valorPadrao;

public:
	MatrizEsparsa(std::string valorPadrao);
	~MatrizEsparsa();
	std::string getValorPadrao();

	void incluirInfo(int lin, int col, std::string info);
	void deletarVertice(int vertice);
	std::string toString();
};


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

	void incluirInfo(int lin, int col, std::string info);
	std::string toString();
};


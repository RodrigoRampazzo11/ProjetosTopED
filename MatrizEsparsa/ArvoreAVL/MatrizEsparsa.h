#pragma once
#include "InformacaoDeArvoreAVL.h";
#include "Arvore.h";
#include "ArvoreColunas.h";

class MatrizEsparsa
{
private:
	Arvore* arvLinhas;

public:
	MatrizEsparsa();
	~MatrizEsparsa();

	void incluirInfo(int lin, int col, InformacaoDeArvoreAVL* info);
	std::string toString();
};


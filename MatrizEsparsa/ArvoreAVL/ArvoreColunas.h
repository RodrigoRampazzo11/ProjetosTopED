#pragma once
#include <string>
#include "InformacaoDeArvoreAVL.h"
#include "Arvore.h"

class ArvoreColunas : public InformacaoDeArvoreAVL
{
private:
	Arvore* colunas;

public:
	ArvoreColunas();
	~ArvoreColunas();
	std::string toString();
	//int compareTo(InformacaoDeArvoreAVL* outraInfo);

	Arvore* getArvore();
	void setArvore(Arvore* coluna);
};


#pragma once

#include <string>

#include "InformacaoDeArvoreNaria.h"

class NoDeArvoreNaria
{
	
private:
	int tamanhoNo;
	InformacaoDeArvoreNaria ** vetInfo;
	NoDeArvoreNaria ** vetPtr;
	//int ** vetInfo;
	//int ** vetPtr;

public:
	NoDeArvoreNaria(int numPonteiros);
	~NoDeArvoreNaria();
	int getTamanhoNo();
	NoDeArvoreNaria* getPonteiroPorPos(int posicao);
	InformacaoDeArvoreNaria* getInfoPorPos(int posicao);
	void setInfoPorPos(InformacaoDeArvoreNaria* novaInfo, int posicao);
	void setPonteiroPorPos(NoDeArvoreNaria* novoNo, int posicao);

	int compareTo(InformacaoDeArvoreNaria* outraInfo, int posicao);
	std::string toString(int posicao);
	bool ehFolha();
};
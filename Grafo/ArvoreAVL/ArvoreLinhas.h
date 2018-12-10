#pragma once
#include <string>
#include "InformacaoDeArvoreAVL.h"
#include "Arvore.h"
#include "ArvoreColunas.h";

class ArvoreLinhas : public InformacaoDeArvoreAVL
{
private:
	Arvore* linhas;

public:
	ArvoreLinhas();
	~ArvoreLinhas();
	std::string toString();
	//int compareTo(InformacaoDeArvoreAVL* outraInfo);

	Arvore* getArvore();
	void setArvore(Arvore* linha);
	void incluirInfo(int linha, InformacaoDeArvoreAVL* novaInfo);
	void excluirLinha(int linha);
	bool existeLinha(int linha);
	InformacaoDeArvoreAVL* getInfoDessaLinha(int linha);
	void setInfoDessaLinha(InformacaoDeArvoreAVL* info, int linha);
	std::string toStringEmOrdem();
};


#pragma once
#include "InformacaoDeArvoreAVL.h"


class NoDeArvoreAVL : public InformacaoDeArvoreAVL
{
private:
	int chave;
	InformacaoDeArvoreAVL * info;
	NoDeArvoreAVL* esquerdo;
	NoDeArvoreAVL* direito;
	int equilibrio;

	void percorredor(std::string &saida, NoDeArvoreAVL* noAtual);

public:
	NoDeArvoreAVL(int chave, InformacaoDeArvoreAVL* info);
	~NoDeArvoreAVL();
	int getChave();
	InformacaoDeArvoreAVL* getInfo();
	NoDeArvoreAVL* getEsquerdo();
	NoDeArvoreAVL* getDireito();
	int getEquilibrio();
	void setChave(int chave);
	void setInfo(InformacaoDeArvoreAVL* novaInfo);
	void setEsquerdo(NoDeArvoreAVL* noEsquerdo);
	void setDireito(NoDeArvoreAVL* noDireito);
	void setEquilibrio(int equilibrio);
	std::string toString();
	std::string toString2();
	int compareTo(int outraChave);
};


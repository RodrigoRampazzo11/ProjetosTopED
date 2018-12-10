#pragma once
#include "NoDeArvoreAVL.h"

class Arvore
{
private:
	NoDeArvoreAVL* raiz;
	void incluiInfo(int chave, InformacaoDeArvoreAVL* novaInfo, NoDeArvoreAVL* noAtual);
	void escreveArvAVL(std::string &string, NoDeArvoreAVL* noAtual);
	void escreveInfosArvAVL(std::string &string, NoDeArvoreAVL* noAtual);
	void incluirNovoNo(NoDeArvoreAVL* noExistente, int pos);
	void definirEquilibrio();
	int defineEquilibrio(NoDeArvoreAVL* noAtual);
	void excluiChave(int chaveDes, NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
	bool ehFolha(NoDeArvoreAVL* no);
	NoDeArvoreAVL* acharPaiMaiorDireita(NoDeArvoreAVL* noAtual);
	NoDeArvoreAVL* acharPaiMaiorEsquerda(NoDeArvoreAVL* noAtual);
	void rotacoesNecessarias(NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
	bool estaBalanceado(NoDeArvoreAVL* noAtual);
	void ajustaBalanceamento(NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
	void balancear();
	void rotacaoParaEsquerda(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	void rotacaoParaDireita(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	void rotacaoDuplaEsquerda(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	void rotacaoDuplaDireita(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	bool existeChave(int chave, NoDeArvoreAVL* noAtual);
	InformacaoDeArvoreAVL* getInfoPorChave(int chave, NoDeArvoreAVL* noAtual);
	void setInfoPorChave(InformacaoDeArvoreAVL* info, int chave, NoDeArvoreAVL* noAtual);

public:
	Arvore();
	~Arvore();
	NoDeArvoreAVL* getRaiz();
	void setRaiz(NoDeArvoreAVL* novaRaiz);
	void incluirInfo(int chave, InformacaoDeArvoreAVL* novaInfo);
	void exluirChave(int chave);
	std::string toString();

	bool existeEstaChave(int chave);
	InformacaoDeArvoreAVL* getInfoDessaChave(int chave);
	void setInfoDessaChave(InformacaoDeArvoreAVL* info, int chave);
	std::string toStringEmOrdem();
};


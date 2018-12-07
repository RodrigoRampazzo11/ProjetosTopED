#pragma once
#include "NoDeArvoreAVL.h"

class Arvore
{
private:
	NoDeArvoreAVL* raiz;
	void incluiInfo(int chave, InformacaoDeArvoreAVL* novaInfo, NoDeArvoreAVL* noAtual);
	void escreveArvAVL(std::string &string, NoDeArvoreAVL* noAtual);
	void incluirNovoNo(NoDeArvoreAVL* noExistente, int pos);
	void definirEquilibrio();
	int defineEquilibrio(NoDeArvoreAVL* noAtual);
	bool existeChave(int chave, NoDeArvoreAVL* noAtual);
	void excluiChave(int chaveDes, NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
	bool ehFolha(NoDeArvoreAVL* no);
	void rotacoesNecessarias(NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
	bool estaBalanceado(NoDeArvoreAVL* noAtual);
	void ajustaBalanceamento(NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
	void balancear();
	void rotacaoParaEsquerda(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	void rotacaoParaDireita(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	void rotacaoDuplaEsquerda(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);
	void rotacaoDuplaDireita(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont);

public:
	Arvore();
	~Arvore();
	NoDeArvoreAVL* getRaiz();
	void setRaiz(NoDeArvoreAVL* novaRaiz);
	void incluirInfo(int chave, InformacaoDeArvoreAVL* novaInfo);
	void exluirChave(int chave);
	std::string toString();

	// IT WOULD BE PRIVATE ////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////
};

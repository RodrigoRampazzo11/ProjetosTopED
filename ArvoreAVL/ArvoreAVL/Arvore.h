#include "NoDeArvoreAVL.h"

class Arvore
{
private:
	NoDeArvoreAVL* raiz;
	void incluiInfo(InformacaoDeArvoreAVL* novaInfo, NoDeArvoreAVL* noAtual);
	void escreveArvAVL(std::string &string, NoDeArvoreAVL* noAtual);
	void incluirNovoNo(NoDeArvoreAVL* noExistente, int pos);
	void definirEquilibrio();
	int defineEquilibrio(NoDeArvoreAVL* noAtual);
	bool existeInfo(InformacaoDeArvoreAVL* infoDes, NoDeArvoreAVL* noAtual);
	void excluiInfo(InformacaoDeArvoreAVL* infoDes, NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont);
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
	void incluirInfo(InformacaoDeArvoreAVL* novaInfo);
	void exluirInfo(InformacaoDeArvoreAVL* infoDes);
	std::string toString();

	// IT WOULD BE PRIVATE ////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////
};


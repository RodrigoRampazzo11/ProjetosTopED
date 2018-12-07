
#include <string>
#include "NoDeArvoreNaria.h"

class ArvoreNaria
{
private:
	NoDeArvoreNaria * raiz;
	int tamanhoNo;
	void incluiNovaInfo(InformacaoDeArvoreNaria* novaInfo, NoDeArvoreNaria* noAtual);
	void incluirNovoNo(NoDeArvoreNaria* noExistente, int posDesejada);
	void excluiInfo(InformacaoDeArvoreNaria* info, NoDeArvoreNaria* noAtual, NoDeArvoreNaria* noAnterior, int posPontAnt);
	void escreveArvore(NoDeArvoreNaria* noAtual, std::string &saida);
	bool existeInfo(InformacaoDeArvoreNaria* info, NoDeArvoreNaria* noAtual);

public:
	ArvoreNaria(int tamanhoNo);
	~ArvoreNaria();

	void incluirNovaInfo(InformacaoDeArvoreNaria* novaInfo);
	void excluirInfo(InformacaoDeArvoreNaria* info);
	std::string escreverArvore();
};


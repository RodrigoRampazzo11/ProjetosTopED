#include "InformacaoDeArvoreAVL.h"

class NoDeArvoreAVL : public InformacaoDeArvoreAVL
{
private:
	int chave;
	InformacaoDeArvoreAVL * info;
	NoDeArvoreAVL* esquerdo;
	NoDeArvoreAVL* direito;
	int equilibrio;

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
	int compareTo(int outraChave);
};


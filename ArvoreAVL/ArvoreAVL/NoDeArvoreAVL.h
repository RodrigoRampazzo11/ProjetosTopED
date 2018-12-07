#include "InformacaoDeArvoreAVL.h"

class NoDeArvoreAVL : public InformacaoDeArvoreAVL
{
private:
	InformacaoDeArvoreAVL * info;
	NoDeArvoreAVL* esquerdo;
	NoDeArvoreAVL* direito;
	int equilibrio;

public:
	NoDeArvoreAVL(InformacaoDeArvoreAVL* info);
	~NoDeArvoreAVL();
	InformacaoDeArvoreAVL* getInfo();
	NoDeArvoreAVL* getEsquerdo();
	NoDeArvoreAVL* getDireito();
	int getEquilibrio();
	void setInfo(InformacaoDeArvoreAVL* novaInfo);
	void setEsquerdo(NoDeArvoreAVL* noEsquerdo);
	void setDireito(NoDeArvoreAVL* noDireito);
	void setEquilibrio(int equilibrio);
	std::string toString();
	int compareTo(InformacaoDeArvoreAVL* outraInfo);
};


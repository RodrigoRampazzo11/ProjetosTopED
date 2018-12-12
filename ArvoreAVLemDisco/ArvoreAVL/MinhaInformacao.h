#pragma once
#include <string>
#include "InformacaoDeArvoreAVL.h"

class MinhaInformacao : public InformacaoDeArvoreAVL
{
private:
	int RA;
	std::string nome;

public:
	MinhaInformacao(int RA);
	~MinhaInformacao();
	std::string toString();
	int compareTo(InformacaoDeArvoreAVL* outraInfo);
	
	int getRA();
	void setRA(int RA);
};


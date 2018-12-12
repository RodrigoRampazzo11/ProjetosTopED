#pragma once
#include <string>
#include "InformacaoDeArvoreAVL.h"

class MinhaInformacao : public InformacaoDeArvoreAVL
{
private:
	int numero;

public:
	MinhaInformacao(int numero);
	~MinhaInformacao();
	std::string toString();
	int compareTo(InformacaoDeArvoreAVL* outraInfo);
	
	int getNumero();
	void setNumero(int numero);
};


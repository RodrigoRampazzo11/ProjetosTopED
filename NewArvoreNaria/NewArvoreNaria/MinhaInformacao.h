#pragma once
#include <string>
#include "InformacaoDeArvoreNaria.h"

class MinhaInformacao : public InformacaoDeArvoreNaria
{
private:
	int numero;

public:
	MinhaInformacao(int num);
	~MinhaInformacao();

	int getNumero();
	void setNumero(int num);
	int compareTo(InformacaoDeArvoreNaria* minhaInfo);
	std::string toString();
};

#include "stdafx.h"
#include "MinhaInformacao.h"


int MinhaInformacao::getNumero()
{
	return numero;
}

void MinhaInformacao::setNumero(int num)
{
	this->numero = num;
}

MinhaInformacao::MinhaInformacao(int num)
{
	this->numero = num;
}

MinhaInformacao::~MinhaInformacao()
{

}


int MinhaInformacao::compareTo(InformacaoDeArvoreNaria* teste)
{
	MinhaInformacao* minhaInfo = (MinhaInformacao*)teste;
	// se InfoAtual > OutraInfo
	if (this->getNumero() > minhaInfo->getNumero())
		return -1;
	else
		// se InfoAtual == OutraInfo
		if (this->getNumero() == minhaInfo->getNumero())
			return 0;
		else
			// se InfoAtual < OutraInfo
			// if (this->getNumero() < minhaInfo->getNumero())
			return 1;
}

std::string MinhaInformacao::toString()
{
	return std::to_string(this->getNumero()) + " ";
}
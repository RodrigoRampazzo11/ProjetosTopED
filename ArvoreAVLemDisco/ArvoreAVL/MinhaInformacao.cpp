#include "stdafx.h"
#include "MinhaInformacao.h"



MinhaInformacao::MinhaInformacao(int numero)
{
	this->numero = numero;
}


MinhaInformacao::~MinhaInformacao()
{
}

int  MinhaInformacao::getNumero()
{
	return this->numero;
}

void  MinhaInformacao::setNumero(int numero)
{
	this->numero = numero;
}

std::string MinhaInformacao::toString()
{
	return std::to_string(this->numero);
}

int MinhaInformacao::compareTo(InformacaoDeArvoreAVL* outra)
{
	MinhaInformacao* outraInfo = (MinhaInformacao*)outra;

	if (this->numero > outraInfo->getNumero())
		return -1;
	else
		if (this->numero == outraInfo->getNumero())
			return 0;
		else
			// info < outraInfo
			return 1;
}


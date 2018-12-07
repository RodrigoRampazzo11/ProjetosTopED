#include "stdafx.h"
#include "MinhaInformacao.h"


MinhaInformacao::MinhaInformacao(std::string info)
{
	this->info = info;
}

MinhaInformacao::~MinhaInformacao()
{
}

std::string MinhaInformacao::getInfo()
{
	return this->info;
}

void MinhaInformacao::setInfo(std::string* info)
{
	this->setInfo(info);
}

std::string MinhaInformacao::toString()
{
	return "Info: " + this->info;
}


/*
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
*/


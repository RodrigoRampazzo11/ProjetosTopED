#include "stdafx.h"
#include "MinhaInformacao.h"



MinhaInformacao::MinhaInformacao(int RA)
{
	this->RA = RA;
}


MinhaInformacao::~MinhaInformacao()
{
}

int  MinhaInformacao::getRA()
{
	return this->RA;
}

void  MinhaInformacao::setRA(int RA)
{
	this->RA = RA;
}

std::string MinhaInformacao::toString()
{
	return std::to_string(this->RA);
}

int MinhaInformacao::compareTo(InformacaoDeArvoreAVL* outra)
{
	MinhaInformacao* outraInfo = (MinhaInformacao*)outra;

	if (this->RA > outraInfo->getRA())
		return -1;
	else
		if (this->RA == outraInfo->getRA())
			return 0;
		else
			// info < outraInfo
			return 1;
}


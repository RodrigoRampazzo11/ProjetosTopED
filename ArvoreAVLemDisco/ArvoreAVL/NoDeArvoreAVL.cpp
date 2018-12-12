#include "stdafx.h"
#include "NoDeArvoreAVL.h"


NoDeArvoreAVL::NoDeArvoreAVL(InformacaoDeArvoreAVL* info)
{
	this->info = info;
	this->esquerdo = NULL;
	this->direito = NULL;
	this->equilibrio = 0;
}

NoDeArvoreAVL::~NoDeArvoreAVL()
{
}

InformacaoDeArvoreAVL* NoDeArvoreAVL::getInfo()
{
	return this->info;
}

NoDeArvoreAVL* NoDeArvoreAVL::getEsquerdo()
{
	return this->esquerdo;
}

NoDeArvoreAVL* NoDeArvoreAVL::getDireito()
{
	return this->direito;
}

int NoDeArvoreAVL::getEquilibrio()
{
	return this->equilibrio;
}

void NoDeArvoreAVL::setInfo(InformacaoDeArvoreAVL* novaInfo)
{
	this->info = novaInfo;
}

void NoDeArvoreAVL::setEsquerdo(NoDeArvoreAVL* noEsquerdo)
{
	this->esquerdo = noEsquerdo;
}

void NoDeArvoreAVL::setDireito(NoDeArvoreAVL* noDireito)
{
	this->direito = noDireito;
}

void NoDeArvoreAVL::setEquilibrio(int equilibrio)
{
	this->equilibrio = equilibrio;
}

std::string NoDeArvoreAVL::toString()
{
	return this->info->toString(); // +"[" + std::to_string(this->equilibrio) + "]";
}

int NoDeArvoreAVL::compareTo(InformacaoDeArvoreAVL* outraInfo)
{
	if (outraInfo == NULL)
		throw;

	return this->info->compareTo(outraInfo);
}
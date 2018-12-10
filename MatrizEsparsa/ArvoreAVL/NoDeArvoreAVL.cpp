#include "stdafx.h"
#include "NoDeArvoreAVL.h"
#include "ArvoreColunas.h"
#include "MinhaInformacao.h"

NoDeArvoreAVL::NoDeArvoreAVL(int chave, InformacaoDeArvoreAVL* info)
{
	this->chave = chave;
	this->info = info;
	this->esquerdo = NULL;
	this->direito = NULL;
	this->equilibrio = 0;
}

NoDeArvoreAVL::~NoDeArvoreAVL()
{
}

int NoDeArvoreAVL::getChave()
{
	return this->chave;
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

void NoDeArvoreAVL::setChave(int chave)
{
	this->chave = chave;
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
	return std::to_string(this->chave); // + " " + this->info->toString(); // +"[" + std::to_string(this->equilibrio) + "]";
}

std::string NoDeArvoreAVL::toString2()
{
	ArvoreColunas* info = (ArvoreColunas*)this->info;
	MinhaInformacao* letra = (MinhaInformacao*)info->getInfoDessaColuna((int)this->info);

	std::string saida;
	percorredor(saida, info->getArvore()->getRaiz());

	return saida;
}

void NoDeArvoreAVL::percorredor(std::string &saida, NoDeArvoreAVL* noAtual)
{
	saida += "(";
	if (noAtual->getEsquerdo() != nullptr)
		percorredor(saida, noAtual->getEsquerdo());

	if (noAtual->getInfo() != NULL)
	{
		MinhaInformacao* letra = (MinhaInformacao*)noAtual->getInfo();
		saida += std::to_string(noAtual->getChave()) + " " + letra->toString();
	}

	if (noAtual->getDireito() != nullptr)
		percorredor(saida, noAtual->getDireito());
	saida += ")";
}

int NoDeArvoreAVL::compareTo(int outraChave)
{

	if (this->chave > outraChave)
		return -1;
	else
		if (this->chave == outraChave)
			return 0;
		else
			// chave < outraChave
			return 1;
}
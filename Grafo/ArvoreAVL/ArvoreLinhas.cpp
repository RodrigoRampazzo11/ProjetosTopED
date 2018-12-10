#include "stdafx.h"
#include "ArvoreLinhas.h"


ArvoreLinhas::ArvoreLinhas()
{
	this->linhas = new Arvore();
}

ArvoreLinhas::~ArvoreLinhas()
{
}

Arvore* ArvoreLinhas::getArvore()
{
	return this->linhas;
}

void ArvoreLinhas::setArvore(Arvore* linhas)
{
	this->setArvore(linhas);
}

std::string ArvoreLinhas::toString()
{
	return this->linhas->toString();
}

void ArvoreLinhas::incluirInfo(int linha, InformacaoDeArvoreAVL* novaInfo)
{
	this->linhas->incluirInfo(linha, novaInfo);
}

void ArvoreLinhas::excluirLinha(int linha)
{
	this->linhas->exluirChave(linha);
}

bool ArvoreLinhas::existeLinha(int linha)
{
	return this->linhas->existeEstaChave(linha);
}

InformacaoDeArvoreAVL* ArvoreLinhas::getInfoDessaLinha(int linha)
{
	return this->linhas->getInfoDessaChave(linha);
}

void ArvoreLinhas::setInfoDessaLinha(InformacaoDeArvoreAVL* info, int linha)
{
	this->linhas->setInfoDessaChave(info, linha);
}

std::string ArvoreLinhas::toStringEmOrdem()
{
	return this->linhas->toStringEmOrdem();
}

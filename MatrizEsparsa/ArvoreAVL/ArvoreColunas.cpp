#include "stdafx.h"
#include "ArvoreColunas.h"


ArvoreColunas::ArvoreColunas()
{
	this->colunas = new Arvore();
}

ArvoreColunas::~ArvoreColunas()
{
}

Arvore* ArvoreColunas::getArvore()
{
	return this->colunas;
}

void ArvoreColunas::setArvore(Arvore* colunas)
{
	this->setArvore(colunas);
}

std::string ArvoreColunas::toString()
{
	return this->colunas->toString();
}

void ArvoreColunas::incluirInfo(int coluna, InformacaoDeArvoreAVL* novaInfo)
{
	this->colunas->incluirInfo(coluna, novaInfo);
}

void ArvoreColunas::excluiColuna(int coluna)
{
	this->colunas->exluirChave(coluna);
}

bool ArvoreColunas::existeColuna(int coluna)
{
	return this->colunas->existeEstaChave(coluna);
}

InformacaoDeArvoreAVL* ArvoreColunas::getInfoDessaColuna(int coluna)
{
	return this->colunas->getInfoDessaChave(coluna);
}

void ArvoreColunas::setInfoDessaColuna(InformacaoDeArvoreAVL* info, int coluna)
{
	this->colunas->setInfoDessaChave(info, coluna);
}

std::string ArvoreColunas::toStringEmOrdem()
{
	return this->colunas->toStringEmOrdem();
}
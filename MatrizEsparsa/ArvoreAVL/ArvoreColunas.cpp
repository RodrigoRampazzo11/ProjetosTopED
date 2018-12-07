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

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

void ArvoreLinhas::excluirLinhaDeColunas(int linha)
{
	excluiLinhaDeColunas(linha, this->linhas->getRaiz());
}

void ArvoreLinhas::excluiLinhaDeColunas(int linha, NoDeArvoreAVL* noAtual)
{
	ArvoreColunas* colunasDessaLinha = (ArvoreColunas*)getInfoDessaLinha(noAtual->getChave());
	//if (colunasDessaLinha->existeColuna(linha))
		colunasDessaLinha->excluiColuna(linha);

	if (colunasDessaLinha->getArvore()->getRaiz() == NULL)
	{
		excluirLinha(noAtual->getChave());		// excluiremos a linha atual, pois sua ÁrvoreDeColunas está vazia
		excluirLinhaDeColunas(linha);           // Chama-se o método pela RAIZ novamente, pois balanceamentos podem ter acontecido  
	}

	if (noAtual->getEsquerdo() != nullptr)
		excluiLinhaDeColunas(linha, noAtual->getEsquerdo());

	if (noAtual->getDireito() != nullptr)
		excluiLinhaDeColunas(linha, noAtual->getDireito());
}
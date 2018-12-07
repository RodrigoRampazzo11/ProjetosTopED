#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h>
#include "NoDeArvoreNaria.h"


NoDeArvoreNaria::NoDeArvoreNaria(int tamanhoNo)
{
	//vetInfo = (int**)malloc((numPonteiros-1) * sizeof(int*));
	//vetPtr = (int**)malloc(numPonteiros * sizeof(int*));
	vetInfo = (InformacaoDeArvoreNaria**)malloc(tamanhoNo * sizeof(InformacaoDeArvoreNaria*));
	vetPtr = (NoDeArvoreNaria**)malloc((tamanhoNo + 1) * sizeof(NoDeArvoreNaria*));
	this->tamanhoNo = tamanhoNo;

	for (int i = 0; i < tamanhoNo; i++)
		*(vetInfo + i) = NULL;

	for (int i = 0; i < tamanhoNo + 1; i++)
		*(vetPtr + i) = NULL;
}

NoDeArvoreNaria::~NoDeArvoreNaria()
{
	for (int i = 0; i < tamanhoNo; i++) {
		free(vetInfo[i]);
		free(vetPtr[i]);
	}
	free(vetPtr[tamanhoNo]);

	free(vetInfo);
	free(vetPtr);
}

int NoDeArvoreNaria::getTamanhoNo()
{
	return tamanhoNo;
}


NoDeArvoreNaria* NoDeArvoreNaria::getPonteiroPorPos(int posicao)
{
	if (posicao <= tamanhoNo) // retorna null também se a posicao atual do ponteiro for nula
		return vetPtr[posicao];

	return NULL;
}

InformacaoDeArvoreNaria* NoDeArvoreNaria::getInfoPorPos(int posicao)
{
	if (posicao < tamanhoNo)	// retorna null também se a posicao atual da informacao for nula
		return vetInfo[posicao];

	return NULL;
}

void NoDeArvoreNaria::setInfoPorPos(InformacaoDeArvoreNaria* novaInfo, int posicao)
{
	if (posicao < tamanhoNo)
		vetInfo[posicao] = novaInfo;
}

void NoDeArvoreNaria::setPonteiroPorPos(NoDeArvoreNaria* novoNo, int posicao)
{
	if (posicao <= tamanhoNo)
		vetPtr[posicao] = novoNo;
}

int NoDeArvoreNaria::compareTo(InformacaoDeArvoreNaria* outraInfo, int posicao)
{
	if (outraInfo == NULL)
		throw "Ponteiro nulo";

	if (posicao >= tamanhoNo)
		throw "Posicão Inválida";

	if (this->getInfoPorPos(posicao) == NULL)
		throw "Posição vazia";
	
	return this->getInfoPorPos(posicao)->compareTo(outraInfo);
}

std::string NoDeArvoreNaria::toString(int posicao)
{
	return vetInfo[posicao]->toString();
}

bool NoDeArvoreNaria::ehFolha()
{
	for (int i = 0; i <= this->getTamanhoNo(); i++)
		if (this->getPonteiroPorPos(i) != NULL)
			return false;
	return true;
}
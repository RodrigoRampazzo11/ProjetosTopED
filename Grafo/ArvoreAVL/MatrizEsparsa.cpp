#include "stdafx.h"
#include "MatrizEsparsa.h"


MatrizEsparsa::MatrizEsparsa(std::string valorPadrao)
{
	this->arvLinhas = NULL;
	this->valorPadrao = new MinhaInformacao(valorPadrao);
}


MatrizEsparsa::~MatrizEsparsa()
{
}

void MatrizEsparsa::incluirInfo(int lin, int col, std::string valor)
{	
	MinhaInformacao* infoAtual = new MinhaInformacao(valor);

	if (arvLinhas != NULL && arvLinhas->getArvore()->getRaiz() !=NULL && arvLinhas->existeLinha(lin))                                                
	{
		ArvoreColunas* arvColunas = (ArvoreColunas*)arvLinhas->getInfoDessaLinha(lin);
		if (arvColunas != NULL)
		{
			if (arvColunas->existeColuna(col))
			{
				// Modifica informacao desejada
				MinhaInformacao* infoExistente = (MinhaInformacao*)arvColunas->getInfoDessaColuna(col);
				
				if (infoExistente != NULL)
				{
					if (infoExistente->compareTo(infoAtual) != 0)
						if (infoAtual->compareTo(valorPadrao) == 0)
						{
							arvColunas->excluiColuna(col);// Exclui coluna Atual
							if (arvColunas->getArvore()->getRaiz() == NULL)
								arvLinhas->excluirLinha(lin);
						}
						else
							arvColunas->setInfoDessaColuna(infoAtual, col);
				}
				else
					if (infoAtual->compareTo(valorPadrao) != 0)
						arvColunas->setInfoDessaColuna(infoAtual, col);
			}
			else
				if (infoAtual->compareTo(valorPadrao) != 0) 
				{
					arvColunas->incluirInfo(col, infoAtual); // Adiciona COLUNA e INFO aqui
				}
				
		}
		else
			if (infoAtual->compareTo(valorPadrao) != 0)
			{
				ArvoreColunas* arvColunas = new ArvoreColunas();   // Cria arvCOLUNAS para essa LINHA
				arvColunas->incluirInfo(col, infoAtual);		   // Adiciona informacao desejada
				arvLinhas->setInfoDessaLinha(arvColunas, lin);
			}
	}
	else // inclui nova linha na Arvore de linhas. Inclui arvColunas e informacao desejada
		if (infoAtual->compareTo(valorPadrao) != 0)
		{
			if (arvLinhas == NULL)
				arvLinhas = new ArvoreLinhas();
			ArvoreColunas* arvColunas = new ArvoreColunas();
			arvColunas->incluirInfo(col, infoAtual);
			arvLinhas->incluirInfo(lin, arvColunas);
		}
}

std::string MatrizEsparsa::toString()
{
	std::string string = "Arvore de Linhas:\n" + this->arvLinhas->toString() + "\n";
	string += "LINHAS:\n" + arvLinhas->toStringEmOrdem();
	
	//ArvoreColunas* arvColunas = (ArvoreColunas*)arvLinhas->getInfoDessaLinha(0);
	
	//string += "Colunas:\n" + arvColunas->toStringEmOrdem();
	return string;
}

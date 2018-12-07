#include "stdafx.h"
#include "MatrizEsparsa.h"


MatrizEsparsa::MatrizEsparsa()
{
	arvLinhas = new Arvore();
}


MatrizEsparsa::~MatrizEsparsa()
{
}

void MatrizEsparsa::incluirInfo(int lin, int col, InformacaoDeArvoreAVL* info)
{
	//cria arvcoluna, coloca info nessa coluna
	arvLinhas->incluirInfo(lin, NULL);
}

std::string toString()
{

}


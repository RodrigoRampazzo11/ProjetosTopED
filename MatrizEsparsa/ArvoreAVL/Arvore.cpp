#include "stdafx.h"
#include "Arvore.h"


Arvore::Arvore()
{
}


Arvore::~Arvore()
{
}

NoDeArvoreAVL* Arvore::getRaiz()
{
	return this->raiz;
}

void Arvore::setRaiz(NoDeArvoreAVL* novaRaiz)
{
	this->raiz = novaRaiz;
}

void Arvore::incluirInfo(int chave, InformacaoDeArvoreAVL* novaInfo)
{
	if (novaInfo != NULL)
		if (this->raiz != NULL)
			incluiInfo(chave, novaInfo, raiz);
		else
		{
			NoDeArvoreAVL* novoNo = new NoDeArvoreAVL(chave, novaInfo);
			setRaiz(novoNo);
		}
	else
		throw;
}

std::string Arvore::toString()
{
	
	if (this->raiz != NULL)
	{
		std::string string = "";
		escreveArvAVL(string, raiz);

		return string;
	}
	else
		return "";

}

void Arvore::escreveArvAVL(std::string &string, NoDeArvoreAVL* noAtual)
{
	string += "(";
	if (noAtual->getEsquerdo() != NULL)
		escreveArvAVL(string, noAtual->getEsquerdo());

	string += noAtual->toString();
	
	if (noAtual->getDireito() != NULL)
		escreveArvAVL(string, noAtual->getDireito());
	string += ")";
}


void Arvore::incluiInfo(int chave, InformacaoDeArvoreAVL* novaInfo, NoDeArvoreAVL* noAtual)
{
	if (noAtual->getInfo() == NULL) // caso o novo no tenha sido criado e o mesmo esteja vazio
	{
		noAtual->setChave(chave);   // inclui nova chave
		noAtual->setInfo(novaInfo); // inclui nova informacao que queremos, no seu devido lugar
		balancear();
	}
	else
	{
		if (noAtual->compareTo(chave) == 0)
			throw;
		else
		if (noAtual->compareTo(chave) < 0)
		{
			// novaChave < chaveAtual
			// chamar o método de novo e passar o ponteiro esquerdo do NÓ ATUAL
			if (noAtual->getEsquerdo() == nullptr)       // se o ponteiro não existir ainda, cria um novo nó
				incluirNovoNo(noAtual, 0);
			incluiInfo(chave, novaInfo, noAtual->getEsquerdo());
		}
		else
		{
			// novaChave > chaveAtual
			if (noAtual->getDireito() == nullptr)        // caso não haja espaço no noAtual, e o ponteiro não existir ainda, cria um novo nó
				incluirNovoNo(noAtual, 1);
			incluiInfo(chave, novaInfo, noAtual->getDireito());
		}
	}
}

void Arvore::incluirNovoNo(NoDeArvoreAVL* noExistente, int pos)
{
	NoDeArvoreAVL* novoNo = new NoDeArvoreAVL(0, NULL);

	if (pos == 0)
		noExistente->setEsquerdo(novoNo);
	else
		// pos == 1
		noExistente->setDireito(novoNo);
}

void Arvore::definirEquilibrio()
{
	int resp;
	resp = defineEquilibrio(raiz);
}

int Arvore::defineEquilibrio(NoDeArvoreAVL* noAtual)
{
	int nivEsq = 0;
	int nivDir = 0;

	if (noAtual->getEsquerdo() != NULL)
	{
		nivEsq = defineEquilibrio(noAtual->getEsquerdo());
	}
	if (noAtual->getDireito() != NULL)
	{
		nivDir = defineEquilibrio(noAtual->getDireito());
	}

	noAtual->setEquilibrio(nivDir - nivEsq);

	if (noAtual->getEsquerdo() == NULL && noAtual->getDireito() == NULL)
		return 1;

	if (nivEsq >= nivDir)
		return ++nivEsq;
	else
		return ++nivDir;
}

void Arvore::exluirChave(int chaveDes)
{
	if (this->raiz == NULL)
		return;
	if (!existeChave(chaveDes, this->raiz))
		return;
	
	if (this->raiz->compareTo(chaveDes) == 0)
	{
		if (ehFolha(this->raiz))
			this->raiz = NULL;
		else
		{
			if (this->raiz->getEsquerdo() != nullptr)
			{
				this->raiz->setChave(this->raiz->getEsquerdo()->getChave());
				this->raiz->setInfo(this->raiz->getEsquerdo()->getInfo());
				excluiChave(this->raiz->getEsquerdo()->getChave(), this->raiz->getEsquerdo(), this->raiz, 0);
			}
			else
			{
				this->raiz->setChave(this->raiz->getDireito()->getChave());
				this->raiz->setInfo(this->raiz->getDireito()->getInfo());
				excluiChave(this->raiz->getDireito()->getChave(), this->raiz->getDireito(), this->raiz, 1);
			}
		}
	}
	else
		excluiChave(chaveDes, this->raiz, NULL, 0);
}

bool Arvore::existeChave(int chave, NoDeArvoreAVL* noAtual)
{
	if (noAtual->compareTo(chave) == 0)
		return true;
	else
		if (noAtual->compareTo(chave) < 0)
		{
			// novaChave < chaveAtual
			// chamar o método de novo e passar o ponteiro esquerdo do NÓ ATUAL
			if (noAtual->getEsquerdo() == nullptr)       // caso o ponteiro não exista, chave não existe
				return false;
			else
				return existeChave(chave, noAtual->getEsquerdo());
		}
		else
		{
			// novaInfo > infoAtual
			if (noAtual->getDireito() == nullptr )        // caso o ponteiro não exista, info não existe
				return false;
			else
				return existeChave(chave, noAtual->getDireito());
		}
}

void Arvore::excluiChave(int chaveDes, NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont)  // se pont = 0 (esquerdo). Se pont = 1 (direito).
{
	if (noAtual->compareTo(chaveDes) == 0)
	{
		if (ehFolha(noAtual))
		{
			noAtual = NULL;
			if (pont == 0)  // ponteiro esquerdo
				noAnterior->setEsquerdo(NULL);
			else  // ponteiro direito
				noAnterior->setDireito(NULL);
			balancear();
		}
		else
		{
			if (noAtual->getEsquerdo() != NULL) // pegar filho da arvore esquerda para substituir a info atual
			{
				noAtual->setChave(noAtual->getEsquerdo()->getChave());
				noAtual->setInfo(noAtual->getEsquerdo()->getInfo());
				excluiChave(noAtual->getEsquerdo()->getChave(), noAtual->getEsquerdo(), noAtual, 0);
			}
			else // pegar filho da arvore direita para substituir a info atual
			{
				noAtual->setChave(noAtual->getDireito()->getChave());
				noAtual->setInfo(noAtual->getDireito()->getInfo());
				excluiChave(noAtual->getDireito()->getChave(), noAtual, noAtual, 1);
			}
		}
	}
	else
		if (noAtual->compareTo(chaveDes) < 0)
		{
			// novaChave < chaveAtual
			// chamar o método de novo e passar o ponteiro esquerdo do NÓ ATUAL
			if (noAtual->getEsquerdo() == nullptr)       // caso o ponteiro não exista, info não existe
				return;
			else
				excluiChave(chaveDes, noAtual->getEsquerdo(), noAtual, 0);
		}
		else
		{
			// novaChave > chaveAtual
			if (noAtual->getDireito() == nullptr)        // caso o ponteiro não exista, info não existe
				return;
			else
				excluiChave(chaveDes, noAtual->getDireito(), noAtual, 1);
		}
}


bool Arvore::ehFolha(NoDeArvoreAVL* no)
{
	if (no->getEsquerdo() == nullptr && no->getDireito() == NULL)
		return true;
	else
		return false;
}

void Arvore::rotacaoParaEsquerda(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont)
{
	NoDeArvoreAVL* auxRaiz = new NoDeArvoreAVL(0, NULL);
	auxRaiz = no;
	
	no = no->getDireito();
	auxRaiz->setDireito(no->getEsquerdo());
	no->setEsquerdo(auxRaiz);

	if (pont == 0) // ponteiro esquerdo
		anterior->setEsquerdo(no);
	else
		if (pont == 1) // ponteiro direito
			anterior->setDireito(no);
		else // anterior == raiz
			setRaiz(no);
}

void Arvore::rotacaoParaDireita(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont)
{
	NoDeArvoreAVL* auxRaiz = new NoDeArvoreAVL(0, NULL);
	auxRaiz = no;

	no = no->getEsquerdo();
	auxRaiz->setEsquerdo(no->getDireito());
	no->setDireito(auxRaiz);

	if (pont == 0) // ponteiro esquerdo
		anterior->setEsquerdo(no);
	else
		if (pont == 1) // ponteiro direito
			anterior->setDireito(no);
		else // anterior == raiz
			setRaiz(no);
}

void Arvore::rotacaoDuplaEsquerda(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont)
{
	rotacaoParaDireita(no->getDireito(), no, 1);
	rotacaoParaEsquerda(no, anterior, pont);
}

void Arvore::rotacaoDuplaDireita(NoDeArvoreAVL* no, NoDeArvoreAVL* anterior, int pont)
{
	rotacaoParaEsquerda(no->getEsquerdo(), no, 0);
	rotacaoParaDireita(no, anterior, pont);
}

void Arvore::rotacoesNecessarias(NoDeArvoreAVL* noAtual, NoDeArvoreAVL* anterior, int pont)
{
	//definirEquilibrio(); // ajusta numero de equilibrio de todos os nós

	if (noAtual->getEquilibrio() > 1)
		if (noAtual->getDireito()->getEquilibrio() < 0)
			rotacaoDuplaEsquerda(noAtual, anterior, pont);
		else
			rotacaoParaEsquerda(noAtual, anterior, pont);
	else
		if (noAtual->getEquilibrio() < -1)
			if (noAtual->getEsquerdo()->getEquilibrio() > 0)
				rotacaoDuplaDireita(noAtual, anterior, pont);
			else
				rotacaoParaDireita(noAtual, anterior, pont);
	
	definirEquilibrio(); // ajusta numero de equilibrio de todos os nós
}

bool Arvore::estaBalanceado(NoDeArvoreAVL* noAtual)
{
	if (noAtual == NULL)
		return true;
	
	if (noAtual->getEquilibrio() < -1 || noAtual->getEquilibrio() > 1)
		return false;

	return true;
}

void Arvore::ajustaBalanceamento(NoDeArvoreAVL* noAtual, NoDeArvoreAVL* noAnterior, int pont)
{
	while (!estaBalanceado(noAtual))
	{
		rotacoesNecessarias(noAtual, noAnterior, pont);
	}

	if (noAtual->getEsquerdo() != nullptr)
		ajustaBalanceamento(noAtual->getEsquerdo(), noAtual, 0);

	if (noAtual->getDireito() != nullptr)
		ajustaBalanceamento(noAtual->getDireito(), noAtual, 1);
}

void Arvore::balancear()
{
	definirEquilibrio();
	ajustaBalanceamento(this->raiz, NULL, -1);
}

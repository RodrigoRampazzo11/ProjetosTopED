// ArvoreNaria.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"    
#include "ArvoreNaria.h"
#include <iostream>


ArvoreNaria::ArvoreNaria(int tamanhoNo)
{
	this->tamanhoNo = tamanhoNo;
}

ArvoreNaria::~ArvoreNaria()
{
	// ############################################################
	// TO DO
}

void ArvoreNaria::incluirNovaInfo(InformacaoDeArvoreNaria* novaInfo)
{
	if (this->raiz != NULL)
		incluiNovaInfo(novaInfo, this->raiz);
	else
	{
		NoDeArvoreNaria* novoNo = new NoDeArvoreNaria(tamanhoNo);
		this->raiz = novoNo;
		for (int i = 0; i < this->raiz->getTamanhoNo(); i++)            // preenche o nó com informações e ponteiros nulos
		{
			this->raiz->setInfoPorPos(NULL, i);
			this->raiz->setPonteiroPorPos(NULL, i);
		}
		this->raiz->setPonteiroPorPos(NULL, raiz->getTamanhoNo());  // preenche última posição do vetor de ponteiros

		this->raiz->setInfoPorPos(novaInfo, 0);
	}
}

void ArvoreNaria::incluiNovaInfo(InformacaoDeArvoreNaria* novaInfo, NoDeArvoreNaria* noAtual)
{
	if (noAtual->getInfoPorPos(0) == NULL)   // caso o novo no tenha sido criado e o mesmo esteja vazio
		noAtual->setInfoPorPos(novaInfo, 0); // inclui nova informacao que queremos, no seu devido lugar
	else
		for (int i = 0; i < noAtual->getTamanhoNo(); i++)
		{
			if (noAtual->getInfoPorPos(i) == NULL)
			{
				noAtual->setInfoPorPos(novaInfo, i);
				break;
			}
			else
				if (noAtual->compareTo(novaInfo, i) <= 0)
				{
					// novaInfo <= infoAtual

					// verificar se possui espaço para inclusão no NÓ ATUAL
					// caso contrário, chamar o método de novo e passar o ponteiro esquerdo do NÓ ATUAL

					if (noAtual->getInfoPorPos(noAtual->getTamanhoNo() - 1) == NULL) // tem espaço no NÓ ATUAL
					{
						for (int j = noAtual->getTamanhoNo() - 1; j > i; j--)           // desloca informaçoes e ponteiros no nó atual
							noAtual->setInfoPorPos(noAtual->getInfoPorPos(j - 1), j); // até a posicao que queremos ficar livre

						noAtual->setInfoPorPos(novaInfo, i); // inclui nova informacao que queremos, no seu devido lugar
					}
					else
					{
						if (noAtual->getPonteiroPorPos(i) == nullptr)        // caso não haja espaço no noAtual, e o ponteiro não existir ainda, cria um novo nó
							incluirNovoNo(noAtual, i);

						incluiNovaInfo(novaInfo, noAtual->getPonteiroPorPos(i));
					}

					break; // para não continuar o processo de inclusao nos outros nós de recursões anteriores, pós-inclusão
				}
				else
					// novaInfo > infoAtual
					if (i == noAtual->getTamanhoNo() - 1)
					{
						if (noAtual->getPonteiroPorPos(i+1) == nullptr)        // caso não haja espaço no noAtual, e o ponteiro não existir ainda, cria um novo nó
							incluirNovoNo(noAtual, i+1);
						incluiNovaInfo(novaInfo, noAtual->getPonteiroPorPos(i + 1));
					}
		}
}

void ArvoreNaria::incluirNovoNo(NoDeArvoreNaria* noExistente, int posicao)
{
	NoDeArvoreNaria* novoNo = new NoDeArvoreNaria(this->tamanhoNo);
	noExistente->setPonteiroPorPos(novoNo, posicao);

	for (int i = 0; i < this->tamanhoNo; i++)
	{
		novoNo->setInfoPorPos(NULL, i);
		novoNo->setPonteiroPorPos(NULL, i);
	}
	novoNo->setPonteiroPorPos(NULL, this->tamanhoNo);  // preenche última posição do vetor de ponteiros
}

std::string ArvoreNaria::escreverArvore() throw()
{
	if (this->raiz == NULL)
		throw std::invalid_argument("Nao existe raiz.");

	std::string saida = "";
	escreveArvore(this->raiz, saida);
	return saida;
}

void ArvoreNaria::escreveArvore(NoDeArvoreNaria* noAtual, std::string &saida)
{
	saida += "( ";
	for (int i=0; i<noAtual->getTamanhoNo(); i++)
	{
		if (noAtual->getPonteiroPorPos(i) != NULL)
			escreveArvore(noAtual->getPonteiroPorPos(i), saida);
		if (noAtual->getInfoPorPos(i) != NULL)
			saida += noAtual->toString(i);
		else
			saida += "- ";
	}
	if (noAtual->getPonteiroPorPos(noAtual->getTamanhoNo()) != NULL)
		escreveArvore(noAtual->getPonteiroPorPos(noAtual->getTamanhoNo()), saida);
	saida += ") ";
}

void ArvoreNaria::excluirInfo(InformacaoDeArvoreNaria* info) throw()
{
	if (info == NULL)
		throw std::invalid_argument("Informacao nula.");
	else
		if (raiz == NULL)
			throw std::invalid_argument("Nao existe raiz.");
		else
			if (!existeInfo(info, this->raiz))
				throw std::invalid_argument("Essa informacao nao existe.");
			else
			{
				if (this->raiz->ehFolha())
				{
					if (this->raiz->getTamanhoNo() > 1)
					{
						if (this->raiz->getInfoPorPos(1) == NULL)	// só possui apenas UMA INFO na RAIZ
						{
							this->raiz->~NoDeArvoreNaria();			// Liberar memória alocada
							this->raiz = NULL;                      // Fazer ponteiro ficar nulo
						}
						else
							for (int i=0; i < this->raiz->getTamanhoNo(); i++)
								if (this->raiz->compareTo(info, i) == 0)							  // achou a informação no NÓ ATUAL
								{
									this->raiz->setInfoPorPos(NULL, i);                               // EXCLUI a informação desejada
									if (i != this->raiz->getTamanhoNo() - 1)						  // Deslocamento é feito apenas se não for a última info do nó
									{
										for (int j = i + 1; j < this->raiz->getTamanhoNo(); j++)
											this->raiz->setInfoPorPos(this->raiz->getInfoPorPos(j), j - 1); // DESLOCA para a esquerda informações subsequentes
										this->raiz->setInfoPorPos(NULL, this->raiz->getTamanhoNo()-1);      // ESVAZIA a última posição
									}
									break;
								}

					}
					else
					{
						this->raiz->~NoDeArvoreNaria();             // Raiz de uma Info a ser excluida
						this->raiz = NULL;
					}
				}
				else
					excluiInfo(info, raiz, NULL, 0);
			}
}

void ArvoreNaria::excluiInfo(InformacaoDeArvoreNaria* info, NoDeArvoreNaria* noAtual, NoDeArvoreNaria* noAnterior, int posPontAnt) throw()
{
	if (noAtual->getInfoPorPos(0) == NULL)   // caso o novo no tenha sido criado e o mesmo esteja vazio
		throw std::invalid_argument("Acesso impossivel. NO criado esta vazio.");
	else
		for (int i = 0; i < noAtual->getTamanhoNo(); i++)
		{

			if (noAtual->compareTo(info, i) == 0)  // achou a informação no NÓ ATUAL
			{
				if (noAtual->ehFolha())              // Info está na folha
				{
					if (noAtual->getTamanhoNo() > 1)
					{
						if (noAtual->getInfoPorPos(1) == NULL)	// só possui apenas UMA INFO no NÓ ATUAL
						{
							//noAtual->~NoDeArvoreNaria();		// Liberar memória alocada
							//noAtual = nullptr;                  // Fazer ponteiro ficar nulo (pelo visto não funcionou...)
							noAnterior->setPonteiroPorPos(NULL, posPontAnt);
						}
						else
							//for (int i = 0; i < noAtual->getTamanhoNo(); i++)
								//if (noAtual->compareTo(info, i) == 0)							  // achou a informação no NÓ ATUAL
								{
									if (i != noAtual->getTamanhoNo() - 1)			// Deslocamento é feito apenas se não for a última info do nó
									{
										for (int j = i + 1; j < noAtual->getTamanhoNo(); j++)
											noAtual->setInfoPorPos(noAtual->getInfoPorPos(j), j - 1); // DESLOCA para a esquerda informações subsequentes, e EXCLUI a info desejada

									}
									noAtual->setInfoPorPos(NULL, noAtual->getTamanhoNo() - 1);        // ESVAZIA a última posição e, caso esta fosse a info desejada, EXCLUI do mesmo modo
									break;
								}
					}
					else
						noAnterior->setPonteiroPorPos(NULL, posPontAnt);
				}
				else    // Info não está na folha
				{
					// CASO "E" DO CADERNO DE ANOTAÇÔES DE "TÓPICOS DE ESTRUTURA DE DADOS"

					if (noAtual->getPonteiroPorPos(i) != NULL) // Pegaremos Info do ponteiro ESQUERDO
					{
						NoDeArvoreNaria* noDoPonteiro = noAtual->getPonteiroPorPos(i);
						for (int j = noDoPonteiro->getTamanhoNo()-1; j>= 0; j--)
							if (noDoPonteiro->getInfoPorPos(j) != NULL)
							{
								if (noDoPonteiro->getPonteiroPorPos(j + 1) == nullptr)
								{
									// Método normal
									InformacaoDeArvoreNaria* info = noDoPonteiro->getInfoPorPos(j);
									noAtual->setInfoPorPos(info, i);  // info a ser excluida RECEBE MAIOR VALOR do NÓ apontado pelo ponteiro da ESQUERDA

									excluiInfo(noDoPonteiro->getInfoPorPos(j), noDoPonteiro, noAtual, i);
									break;
								}
								else
								{
									// Método diferenciado - Direitas do da Esquerda
									int posicaoInfo;
									int posPont = j + 1;
									NoDeArvoreNaria* noDesejado = acharPaiMaiorDireita(noDoPonteiro, posPont, posicaoInfo);

									noAtual->setInfoPorPos(noDesejado->getPonteiroPorPos(posPont)->getInfoPorPos(posicaoInfo), i);
									excluiInfo(noDesejado->getPonteiroPorPos(posPont)->getInfoPorPos(posicaoInfo),
											   noDesejado->getPonteiroPorPos(posPont),
											   noDesejado,
										       posPont);
									break;
								}	
							}
					}
					else
						if (noAtual->getPonteiroPorPos(i + 1) != nullptr) // Pegaremos info do ponteiro DIREITO
						{
							NoDeArvoreNaria* noDoPonteiro = noAtual->getPonteiroPorPos(i + 1);
							if (noDoPonteiro->getPonteiroPorPos(0) == nullptr)
							{
								// Método normal
								noAtual->setInfoPorPos(noDoPonteiro->getInfoPorPos(0), i); // info a ser excluida RECEBE MENOR VALOR do NÓ apontado pelo ponteiro da DIREITA
								excluiInfo(noDoPonteiro->getInfoPorPos(0), noDoPonteiro, noAtual, i + 1);
							}
							else
							{
								// Método diferenciado - Esquerdas do da direita
								NoDeArvoreNaria* noDesejado = acharPaiMaiorEsquerda(noDoPonteiro);

								noAtual->setInfoPorPos(noDesejado->getPonteiroPorPos(0)->getInfoPorPos(0), i);
								excluiInfo(noDesejado->getPonteiroPorPos(0)->getInfoPorPos(0),
									       noDesejado->getPonteiroPorPos(0),
									       noDesejado,
									       0);
								break;
							}	
						}
						else
						{
							bool direitaDaInfo = false;
							for (int j = i + 1; j <= noAtual->getTamanhoNo(); j++)
							{
								if (noAtual->getPonteiroPorPos(j) != nullptr)
								{
									direitaDaInfo = true;
									break;
								}
							}

							if (direitaDaInfo) // vamos deslocar da direita pra esquerda
							{
								if (i != noAtual->getTamanhoNo() - 1)
									for (int j = i + 1; j < noAtual->getTamanhoNo(); j++)
									{
										noAtual->setInfoPorPos(noAtual->getInfoPorPos(j), j - 1);
										if (noAtual->getPonteiroPorPos(j+1) != nullptr)
										{
											NoDeArvoreNaria* noDoPonteiro = noAtual->getPonteiroPorPos(j + 1);
											if (noDoPonteiro->getInfoPorPos(0) != nullptr)
											{
												// Método normal
												noAtual->setInfoPorPos(noDoPonteiro->getInfoPorPos(0), j);
												excluiInfo(noDoPonteiro->getInfoPorPos(0), noDoPonteiro, noAtual, j + 1);
												break;
											}
											else
											{
												// Método diferenciado - Esquerdas do da Direita
												NoDeArvoreNaria* noDesejado = acharPaiMaiorEsquerda(noDoPonteiro);

												noAtual->setInfoPorPos(noDesejado->getPonteiroPorPos(0)->getInfoPorPos(0), j);
												excluiInfo(noDesejado->getPonteiroPorPos(0)->getInfoPorPos(0),
														   noDesejado->getPonteiroPorPos(0),
													       noDesejado,
													       0);
												break;
											}		
										}
									}
								else
								{
									NoDeArvoreNaria* noDoPonteiro = noAtual->getPonteiroPorPos(i+1);
									excluiInfo(noDoPonteiro->getInfoPorPos(0), noDoPonteiro, noAtual, i+1);
								}
							}
							else               // vamos deslocar da esquerda pra direita
							{
								if (i != 0)
									for (int j = i - 1; j >= 0; j--)
									{
										noAtual->setInfoPorPos(noAtual->getInfoPorPos(j), j + 1);
										if (noAtual->getPonteiroPorPos(j) != nullptr)
										{		
											NoDeArvoreNaria* noDoPonteiro = noAtual->getPonteiroPorPos(j);
											for (int w = noDoPonteiro->getTamanhoNo() - 1; w >= 0; w--)
												if (noDoPonteiro->getInfoPorPos(w) != NULL)
												{
													if (noDoPonteiro->getPonteiroPorPos(w + 1) == nullptr)
													{
														// Método normal
														noAtual->setInfoPorPos(noDoPonteiro->getInfoPorPos(w), j);  // info a ser excluida RECEBE MAIOR VALOR do NÓ apontado pelo ponteiro da ESQUERDA
														excluiInfo(noDoPonteiro->getInfoPorPos(w), noDoPonteiro, noAtual, j);
														break;
													}
													else
													{
														// Método diferenciado - Direitas do da Esquerda
														int posicaoInfo;
														int posPont = w + 1;
														NoDeArvoreNaria* noDesejado = acharPaiMaiorDireita(noDoPonteiro, posPont, posicaoInfo);

														noAtual->setInfoPorPos(noDesejado->getPonteiroPorPos(posPont)->getInfoPorPos(posicaoInfo), j);
														excluiInfo(noDesejado->getPonteiroPorPos(posPont)->getInfoPorPos(posicaoInfo),
															       noDesejado->getPonteiroPorPos(posPont),
															       noDesejado,
															       posPont);
														break;
													}
													
												}
										}
									}
								else  // info procurada é a primeira da lista
								{
									NoDeArvoreNaria* noDoPonteiro = noAtual->getPonteiroPorPos(i);
									
									for (int j = noDoPonteiro->getTamanhoNo() - 1; j >= 0; j--)
										if (noDoPonteiro->getInfoPorPos(j) != NULL)
										{
											if (noDoPonteiro->getPonteiroPorPos(j + 1) != nullptr)
											{
												// Método normal
												noAtual->setInfoPorPos(noDoPonteiro->getInfoPorPos(j), i);  // info a ser excluida RECEBE MAIOR VALOR do NÓ apontado pelo ponteiro da ESQUERDA
												excluiInfo(noDoPonteiro->getInfoPorPos(j), noDoPonteiro, noAtual, i);
												break;
											}
											else
											{
												// Método diferenciado - Direitas do da Esquerda
												/////////////////////////////////////////////////////////////////
												/// TODO 
												int posicaoInfo;
												int posPont = j + 1;
												NoDeArvoreNaria* noDesejado = acharPaiMaiorDireita(noDoPonteiro, posPont, posicaoInfo);

												noAtual->setInfoPorPos(noDesejado->getPonteiroPorPos(posPont)->getInfoPorPos(posicaoInfo), i);
												excluiInfo(noDesejado->getPonteiroPorPos(posPont)->getInfoPorPos(posicaoInfo),
													       noDesejado->getPonteiroPorPos(posPont),
													       noDesejado,
													       posPont);
												break;
											}
										}
								}
							}

						}
				}
				break; 
			}
				
			if (noAtual->compareTo(info, i) < 0) // novaInfo < infoAtual
			{
				if (noAtual->getPonteiroPorPos(i) == nullptr)        // caso o ponteiro esquerdo da Info do NÓ ATUAL não exista,
																	 // a informação procurada não existe
					throw; // Essa informação não existe
				
				excluiInfo(info, noAtual->getPonteiroPorPos(i), noAtual, i);
				break;
			}
			else
				// InfoProcurada > infoAtual
				if (i == noAtual->getTamanhoNo() - 1)
				{
					if (noAtual->getPonteiroPorPos(i + 1) == nullptr)        // caso o último ponteiro não exista, a Info procurada não existe
						throw; // Essa informação não existe
					excluiInfo(info, noAtual->getPonteiroPorPos(i + 1), noAtual, i+1);
					break;
				}
		}
}


bool ArvoreNaria::existeInfo(InformacaoDeArvoreNaria* info, NoDeArvoreNaria* noAtual)
{
	if (noAtual->getInfoPorPos(0) == NULL)   // caso o novo no tenha sido criado e o mesmo esteja vazio
		throw std::invalid_argument("Acesso impossivel. NO criado esta vazio.");
	else
		for (int i = 0; i < noAtual->getTamanhoNo(); i++)
		{

			if (noAtual->compareTo(info, i) == 0)  // achou a informação no NÓ ATUAL
				return true;

			if (noAtual->compareTo(info, i) < 0) // novaInfo < infoAtual
			{
				if (noAtual->getPonteiroPorPos(i) == nullptr)        // caso o ponteiro esquerdo da Info do NÓ ATUAL não exista,
																	 // a informação procurada não existe
					return false; // Essa informação não existe

				return existeInfo(info, noAtual->getPonteiroPorPos(i));
			}
			else
				// InfoProcurada > infoAtual
				if (i == noAtual->getTamanhoNo() - 1)
				{
					if (noAtual->getPonteiroPorPos(i + 1) == nullptr)        // caso o último ponteiro não exista, a Info procurada não existe
						return false; // Essa informação não existe
					return existeInfo(info, noAtual->getPonteiroPorPos(i + 1));
				}
		}
}

NoDeArvoreNaria* ArvoreNaria::acharPaiMaiorDireita(NoDeArvoreNaria* noAtual, int &posPont, int &posInfo)
{
	for (int i = noAtual->getTamanhoNo() - 1; i >= 0; i--)
		if (noAtual->getPonteiroPorPos(posPont)->getInfoPorPos(i) != NULL)
		{
			if (noAtual->getPonteiroPorPos(posPont)->getPonteiroPorPos(i + 1) == nullptr)
			{
				posInfo = i;
				return noAtual;
			}
			else
			{
				posInfo = i + 1;
				return acharPaiMaiorDireita(noAtual->getPonteiroPorPos(posPont), posInfo, posInfo);
			}
		}
	return nullptr;
}

NoDeArvoreNaria* ArvoreNaria::acharPaiMaiorEsquerda(NoDeArvoreNaria* noAtual)
{
	if (noAtual->getPonteiroPorPos(0)->getInfoPorPos(0) != NULL)
	{
		if (noAtual->getPonteiroPorPos(0)->getPonteiroPorPos(0) == nullptr)
			return noAtual;
		else
			return acharPaiMaiorEsquerda(noAtual->getPonteiroPorPos(0));
	}
	return nullptr;

}

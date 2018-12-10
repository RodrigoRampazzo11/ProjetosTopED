#pragma once
#include <string>
#include "InformacaoDeArvoreAVL.h"
#include "Arvore.h"

class MinhaInformacao : public InformacaoDeArvoreAVL
{
private:
	std::string info;

public:
	MinhaInformacao(std::string info);
	~MinhaInformacao();
	std::string toString();
	int compareTo(InformacaoDeArvoreAVL* outraInfo);
	
	std::string getInfo();
	void setInfo(std::string info);
};


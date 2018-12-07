#pragma once
#include <string>

class InformacaoDeArvoreAVL
{
public:
	InformacaoDeArvoreAVL();
	~InformacaoDeArvoreAVL();
	virtual std::string toString() = 0;
	virtual int compareTo(InformacaoDeArvoreAVL* outraInfo) = 0;

};


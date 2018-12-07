#pragma once
#include <string>

class InformacaoDeArvoreNaria
{
public:
	InformacaoDeArvoreNaria();
	~InformacaoDeArvoreNaria();

	virtual int compareTo(InformacaoDeArvoreNaria* outraInfo) = 0;
	virtual std::string toString() = 0;
};
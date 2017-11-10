#ifndef _FORMA_H_
#define _FORMA_H_

#include <vector>

class Forma{

public:
	
	enum contantesForma {ALTURA=0, LARGURA=1, PROFUNDIDADE=2};

	//Dimensoes da forma
	std::vector<double> dimensoes;

	//Obter o volume da forma
	virtual double obterVolumeTotal() = 0;

	//Obter volume atual do forma
	virtual double obterVolumeAtual(double) = 0;

};


#endif

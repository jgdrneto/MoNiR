#ifndef _RESERVATORIO_H_
#define _RESERVATORIO_H_

#include "formas/forma.h"

class Reservatorio{

public:

	Forma* forma;
	double volumeTotal;

	Reservatorio();
	Reservatorio(Forma*);
	unsigned int obterPorcentagemCheio(double);

};

#include "../src/reservatorio.cpp"

#endif

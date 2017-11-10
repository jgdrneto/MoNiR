#ifndef _RESERVATORIO_H_
#define _RESERVATORIO_H_

#include "formas/forma.h"

class Reservatorio{

public:
	
	Forma* forma;
	double volumeTotal;
	double volumeAtual;

};

#include "../src/reservatorio.cpp"

#endif

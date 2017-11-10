#ifndef _CORPO_CONE_H_
#define _CORPO_CONE_H_

#include <math.h>

#include "forma.h"

class CorpoCone : public Forma{

	double raioMenor;
	double raioMaior;

	double obterVolume();
	double volumeAtual(double);


};

#include "../../src/formas/Cilindro.cpp"

#endif
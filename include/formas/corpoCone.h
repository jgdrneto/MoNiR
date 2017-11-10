#ifndef _CORPO_CONE_H_
#define _CORPO_CONE_H_

#include <math.h>

#include "forma.h"

class CorpoCone : public Forma{
public:
	double raioMenor;
	double raioMaior;

	CorpoCone(double,double,double);

	double obterVolumeTotal();
	double obterVolumeAtual(double);


};

#include "../../src/formas/corpoCone.cpp"

#endif
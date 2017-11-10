#ifndef _PARALELEPIPEDO_H_
#define _PARALELEPIPEDO_H_

#include "forma.h"

class Paralelepipedo : public Forma{
public:
	double obterVolumeTotal();
	double obterVolumeAtual(double);

	Paralelepipedo(double,double,double);

};

#include "../../src/formas/paralelepipedo.cpp"

#endif
#ifndef _CILINDRO_H_
#define _CILINDRO_H_

#include <math.h>

#include "forma.h"

class Cilindro : public Forma{

public:
	
	double raio;

	double obterVolumeTotal();
	double obterVolumeAtual(double);

	Cilindro(double,double);


};

#include "../../src/formas/cilindro.cpp"

#endif
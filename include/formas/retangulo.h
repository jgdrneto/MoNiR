#ifndef _RETANGULO_H_
#define _RETANGULO_H_

#include "forma.h"

class Retangulo : public Forma{

	double obterVolume();
	double volumeAtual(double);

};

#include "../../src/formas/retangulo.cpp"

#endif
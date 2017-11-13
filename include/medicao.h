#ifndef _MEDICAO_H_
#define _MEDICAO_H_

#include <string>

#include "data.h"

class Medicao{

public:

	Data data;
	double volumeAtual;
	
	Medicao(Data&,double);

	static bool comparador(Medicao i,Medicao j);

};

#include "../src/medicao.cpp"

#endif
#ifndef _MEDICAO_H_
#define _MEDICAO_H_

#include <string>

#include "data.h"

class Medicao{

public:

	Data data;
	double volumeAtual;
	
	Medicao(Data&,double);
};

#include "../src/medicao.cpp"

#endif
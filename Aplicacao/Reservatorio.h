#ifndef _RESERVATORIO_H_
#define _RESERVATORIO_H_

#include "Forma.h"

class Reservatorio{

public:

	Forma* forma;
	float volumeTotal;

	Reservatorio(){ /* NULL */ }

	Reservatorio(Forma* nForma){
		this->forma = nForma;

		this->volumeTotal = this->forma->ObterVolumeTotal();
	}

	unsigned int ObterPorcentagemCheio(float volumeAtual){

		float valor = volumeAtual/this->volumeTotal * 100;

		unsigned int castValor=(unsigned int)valor;

		if(valor!=0 && valor!=100){
			castValor++;
		}

		return castValor;

	}

	~Reservatorio(){
		delete forma;
	}

};

#endif

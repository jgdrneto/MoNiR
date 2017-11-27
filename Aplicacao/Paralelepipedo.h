#ifndef _PARALELEPIPEDO_H_
#define _PARALELEPIPEDO_H_

#include "Forma.h"

class Paralelepipedo : public Forma{
public:

	Paralelepipedo(float largura, float altura, float profundidade){
		this->dimensoes = new float[3];

		this->dimensoes[0] = altura;
		this->dimensoes[1] = largura;
		this->dimensoes[2] = profundidade;
	}

	float ObterVolumeTotal(){
		return this->dimensoes[0]*this->dimensoes[1]*this->dimensoes[2];
	}

	float ObterVolumeAtual(float altura){
		return altura*this->dimensoes[1]*this->dimensoes[2];
	}

};

#endif
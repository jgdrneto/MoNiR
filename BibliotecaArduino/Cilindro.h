#ifndef _CILINDRO_H_
#define _CILINDRO_H_

#include "Forma.h"

class Cilindro : public Forma{

public:
	
	float raio;

	Cilindro(float nRaio,float altura){
		this->raio = nRaio;
		this->dimensoes = new float[1];
		this->dimensoes[0] = altura;
	}

	float ObterVolumeTotal(){
		return PI * this->raio * this->raio * this->dimensoes[0];
	}

	float ObterVolumeAtual(float altura){
		return PI * this->raio * this->raio * altura;
	}

};

#endif
#ifndef _CORPO_CONE_H_
#define _CORPO_CONE_H_

#include "Forma.h"

class CorpoCone : public Forma{
public:
	float raioMenor;
	float raioMaior;

	CorpoCone(float nRaioMenor,float nRaioMaior,float altura){
		this->raioMenor = nRaioMenor;
		this->raioMaior = nRaioMaior;
		this->dimensoes = new float[1];
		this->dimensoes[0] = altura;
	}

	float ObterVolumeTotal(){
		return (PI * this->dimensoes[0] * (this->raioMaior * this->raioMaior + 
										   this->raioMaior * this->raioMenor +
										   this->raioMenor * this->raioMenor))/3;
	}

	float ObterVolumeAtual(float altura){
		return (PI * altura * (this->raioMaior * this->raioMaior + 
							   this->raioMaior * this->raioMenor +
							   this->raioMenor * this->raioMenor))/3;
	}

};

#endif
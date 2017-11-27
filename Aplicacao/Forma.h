#ifndef _FORMA_H_
#define _FORMA_H_

class Forma{

public:
	
	//Dimensoes da forma
	float* dimensoes;

	//Obter o volume da forma
	virtual float ObterVolumeTotal() = 0;

	//Obter volume atual do forma
	virtual float ObterVolumeAtual(float) = 0;

	~Forma(){
		delete [] dimensoes;
	}
};


#endif

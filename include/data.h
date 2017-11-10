#ifndef _DATA_H_
#define _DATA_H_

#include <string>

class Data{

public:
	
	typedef unsigned int Tipo;

	enum constantes{DIA=0,MES=1,ANO=2,HORA=3,MINUTO=4,SEGUNDO=5};

	Tipo v[6];

    Data::Tipo& operator[](std::size_t);

    Data();

	Data(Tipo,Tipo,Tipo,Tipo,Tipo,Tipo); 

	static Data& obterDataAtual();
};

#include "../src/data.cpp"

#endif
#ifndef _DISPOSITIVO_H_
#define _DISPOSITIVO_H_

#include <string>

#include "GPIO/GPIO.cpp"

class Dispositivo{
public:
	std::string nome;
	std::vector<PORTNUMBER> portas;
	double valor;
	
	void iniciar(std::string,std::vector<PORTNUMBER>,std::vector<DIRECTION>);

	virtual double acao()=0;

};	

#include "../../src/dispositivos/dispositivo.cpp"

#endif
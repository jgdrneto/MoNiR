#ifndef _LED_H_
#define _LED_H_

#include "dispositivo.h"

class Led : public Dispositivo{
public:

	Led(std::string,PORTNUMBER);

	double acao();
	double ligar();
	double desligar();
};	

#include "../../src/dispositivos/led.cpp"

#endif
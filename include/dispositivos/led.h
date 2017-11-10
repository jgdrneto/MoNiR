#ifndef _LED_H_
#define _LED_H_

#include "dispositivo.h"

class Led : public Dispositivo{
public:

	VALUE valor;

	Led(std::string,PORTNUMBER);

	double acao();
};	

#include "../../src/dispositivos/led.cpp"

#endif
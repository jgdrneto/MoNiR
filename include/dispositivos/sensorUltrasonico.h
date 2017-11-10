#ifndef _SENSOR_ULTRASONICO_H_
#define _SENSOR_ULTRASONICO_H_

#include <unistd.h>

#include "dispositivo.h"

class SensorUltrasonico : public Dispositivo{
public:
	SensorUltrasonico(std::string,PORTNUMBER,PORTNUMBER);

	double acao();
};	

#include "../../src/dispositivos/sensorUltrasonico.cpp"

#endif
#ifndef _SENSOR_ULTRASONICO_H_
#define _SENSOR_ULTRASONICO_H_

#include "Dispositivo.h"

class SensorUltrasonico : public Dispositivo{
public:
	SensorUltrasonico(String nome,int trigger,int echo){

		int* portas = new int[2];

		portas[0] = trigger;
		portas[1] = echo;

		int* direcoes = new int[2];

		direcoes[0] = OUTPUT;
		direcoes[1] = INPUT;

		this->Iniciar(nome,portas,direcoes);

		this->valor=0;
	}

	float Acao(){
		// Clears the trigPin
  		digitalWrite(portas[0], LOW);
  		delayMicroseconds(2);
  		// Sets the trigPin on HIGH state for 10 micro seconds
  		digitalWrite(portas[0], HIGH);
  		delayMicroseconds(10);
  		digitalWrite(portas[0], LOW);
  
  		// Reads the echoPin, returns the sound wave travel time in microseconds
  		unsigned long duration = pulseIn(portas[1], HIGH);
  		// Calculating the distance
  		float distance=duration*0.034/2;
  		
  		delayMicroseconds(60);

  		return distance;
  	}	
};	

#endif

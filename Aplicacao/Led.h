#ifndef _LED_H_
#define _LED_H_

#include "Dispositivo.h"

class Led : public Dispositivo{

public:

	Led::Led(){
		
	}

	Led(String nome,int nPorta){

    this->valor = LOW;

    int* ps = new int[1];
    ps[0] = nPorta;

    int* ds = new int[1];
    ds[0] = OUTPUT;
      
    this->Iniciar(nome,ps,ds);

    digitalWrite(portas[0], LOW);
    
	}

	float Acao(){
	  if(this->valor == LOW){
	    return this->Ligar();
	  }else{
	    return this->Desligar();
	  }
	}
	
	float Ligar(){
	  digitalWrite(this->portas[0], HIGH);
      this->valor = HIGH;
      return HIGH;
	}
	
	float Desligar(){
	  digitalWrite(this->portas[0],LOW);
      this->valor = LOW;
  	  return LOW;
  	}
};	

#endif

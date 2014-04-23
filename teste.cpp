#include <iostream>
#include <stdlib.h>

#include "include/dispositivos/GPIO/GPIO.cpp"

//Método principal
int main(int argc, char *argv[]) {
	
	GPIO::setup(PORTNUMBER::P9_16,DIRECTION::OUT); 

	GPIO::output(PORTNUMBER::P9_16,VALUE::LOW);

	return 0;
}

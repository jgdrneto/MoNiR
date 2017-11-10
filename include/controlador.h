#ifndef _CONTROLADOR_H_
#define _CONTROLADOR_H_

#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <set>

#include "json.hpp"

#include "data.h"
#include "medicao.h"
#include "reservatorio.h"
#include "dispositivos/led.h"
#include "dispositivos/sensorUltrasonico.h"

class Controlador{

public:

	Reservatorio reservatorio;
	std::vector<Dispositivo*> dispositivos;

	Controlador(Reservatorio&);

	void salvarRelatorio(std::string,std::vector<Medicao>&);

	void realizarMedicoes(unsigned int);

	std::vector<Medicao>& realizarMedicoes(unsigned int, double);

	Dispositivo* obterDispositivoPorNome(std::string);

	void modificarLedsNivel(unsigned int);

	bool modificarLedMudanca(std::vector<Medicao>&,unsigned int);

};

#include "../src/controlador.cpp"

#endif	
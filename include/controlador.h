#ifndef _CONTROLADOR_H_
#define _CONTROLADOR_H_

#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

#include "json.hpp"

#include "data.h"
#include "medicao.h"

class Controlador{

public:

	std::vector<Dispositivo*> dispositivo;

	void salvarRelatorio(std::string,std::vector<Medicao>&);
};

#include "../src/controlador.cpp"

#endif	
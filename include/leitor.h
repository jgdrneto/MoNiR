#ifndef _LEITOR_H_
#define _LEITOR_H_

#include <string>

#include "reservatorio.h"
#include "formas/forma.h"
#include "formas/paralelepipedo.h"
#include "formas/corpoCone.h"
#include "formas/cilindro.h"
#include "json.hpp"

class Leitor{
public:

	Reservatorio* ler(std::string);	
};

#include "../src/leitor.cpp"

#endif
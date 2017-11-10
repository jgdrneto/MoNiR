#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>

//#include "include/controlador.h"
#include "include/dispositivos/sensorUltrasonico.h"
#include "include/dispositivos/led.h"

//Método principal
int main(int argc, char *argv[]) {
	
	std::vector<Dispositivo*> dispositivos;

	dispositivos.push_back(new Led("Verde",PORTNUMBER::P9_16));
	dispositivos.push_back(new Led("Vermelho",PORTNUMBER::P9_15));
	dispositivos.push_back(new Led("Amarelo",PORTNUMBER::P9_13));
	dispositivos.push_back(new Led("Branco",PORTNUMBER::P9_14));
	dispositivos.push_back(new SensorUltrasonico("Medidor",PORTNUMBER::P9_10,PORTNUMBER::P9_11));
	
	for(Dispositivo* d :dispositivos){
		std::cout << d << std::endl;
	}

	dispositivos[0]->acao();

	std::cout << ((Led*)dispositivos[0])->valor << std::endl;

	usleep(2000000);

	dispositivos[0]->acao();

	std::cout << ((Led*)dispositivos[0])->valor << std::endl;

	/*
	std::vector<Medicao> mds;

	mds.push_back( *(new Medicao(Data::obterDataAtual(),1000)));
	mds.push_back( *(new Medicao(Data::obterDataAtual(),900)));
	mds.push_back( *(new Medicao(Data::obterDataAtual(),800)));
	mds.push_back( *(new Medicao(Data::obterDataAtual(),700)));
	mds.push_back( *(new Medicao(Data::obterDataAtual(),600)));
	*/
	
	//Controlador c; 



	//c.salvarRelatorio("dados.json",mds);

	return 0;
}
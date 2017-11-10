#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include <string>

#include "include/data.h"
#include "include/formas/cilindro.h"
#include "include/reservatorio.h"
#include "include/controlador.h"


std::string obterNomeArquivo(Data& d){
	std::string data[3]; 

	for(int i =0;i<3;i++){
		if(d[i]<10){
			data[i] = "0"+std::to_string(d[i]);
		}else{
			data[i] = std::to_string(d[i]);
		}
	}

	return "medicoes/" + data[0] + "-" + data[1] + "-" + data[2] + ".json"; 
}

//Método principal
int main(int argc, char *argv[]) {
	
	//Valores em decimetros
	Forma* cilindro = new Cilindro(1,5);
	
	Reservatorio r(cilindro);

	Controlador c(r);

	bool finalizar = true;


	while(finalizar){

		std::cout << "================================================" << std::endl;

		std::cout << "Iniciando novo buffer de medições" << std::endl;

		std::cout << "================================================" << std::endl;

		std::cout << "" << std::endl;

		std::string arquivo = obterNomeArquivo(Data::obterDataAtual());

		std::vector<Medicao> medicoes = c.realizarMedicoes(10,0.5);

		/*
		for(Medicao m : medicoes){
			std::cout << m << std::endl;
		}
		*/
		//std::cout << arquivo << std::endl;

		std::cout << "" << std::endl;

		c.salvarRelatorio(arquivo,medicoes);
		
		std::cout << "Salvo medições no arquivo: " << arquivo << "\n" << std::endl;

	}

	return 0;
}
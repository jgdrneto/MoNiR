#ifndef _LEITOR_RESERVATORIO_H_
#define _LEITOR_RESERVATORIO_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <ArduinoJson.h>

#include "Reservatorio.h"
#include "Forma.h"
#include "Paralelepipedo.h"
#include "CorpoCone.h"
#include "Cilindro.h"

class LeitorReservatorio{

public:

	Reservatorio* Ler(String json){

		//Serial.println("JSON: " + json);

		Reservatorio* reservatorio = nullptr;
		Forma* forma = nullptr;

		const size_t bufferSize = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(3) + 60;
		DynamicJsonBuffer jsonBuffer(bufferSize);

		JsonObject& root = jsonBuffer.parseObject(json);

		String tipo = root["FORMA"];
		
		//Serial.println("Tipo: " + tipo);

		if (tipo == "CILINDRO"){

			forma = new Cilindro(root["RAIO"],
								 root["ALTURA"]);

		}else if (tipo == "PARALELEPIPEDO"){

			forma = new Paralelepipedo(root["LARGURA"],
							           root["ALTURA"],
							           root["PROFUNDIDADE"]);

		}else if (tipo == "CORPO_CONE"){

			forma = new CorpoCone(root["RAIOMENOR"],
							      root["RAIOMAIOR"],
							      root["ALTURA"]);

		}else{
			return nullptr;	
		}
		
   		return new Reservatorio(forma);
   		
	}
};

#endif
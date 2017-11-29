#ifndef _APLICACAO_H_
#define _APLICACAO_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <ArduinoJson.h>

#include "Reservatorio.h"
#include "Led.h"
#include "SensorUltrasonico.h"

enum ordemDePortas{                               //Enumeração para determinar posicao de cada dispositivo
  LED_VERDE,
  LED_AMARELO,
  LED_VERMELHO,
  LED_BRANCO,
  SENSOR_ULTRASONICO  
};

class Aplicacao {

public:	

	Reservatorio reservatorio;
	
	Dispositivo** dispositivos;

	bool mandarEmail;

	Aplicacao(Reservatorio& r, Dispositivo** nDispositivos){
		this->reservatorio = r;
		this->dispositivos = nDispositivos;
	}

	void SalvarRelatorio(float* medicoes, unsigned int tamanho){

		const size_t bufferSize = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(3);
  
  		DynamicJsonBuffer jsonBuffer(bufferSize);

  		JsonObject& root = jsonBuffer.createObject();
  		
  		JsonArray& data = root.createNestedArray("VOLUMES");

  		for(int i=0;i<tamanho;i++){
  			data.add(medicoes[i]);
  		}
  		
  		root["MUDANCA"] = this->mandarEmail;

  		String json="";

  		root.printTo(json);
  		
  		//while(!Serial.availableForWrite()){/* NULL */};
  		
  		Serial.println(json);
  		
	}

	float* RealizarMedicoes(unsigned int quantidade, float intervalo){

		float* medicoes =  new float[quantidade];
		
		for(unsigned int i=0;i<quantidade;i++){

			//Altura medida no sensor ultrasonico
			float alturaParteVazia = dispositivos[SENSOR_ULTRASONICO]->Acao();
			//Serial.println("Altura parte vazia:" + String(alturaParteVazia));
			
			if(alturaParteVazia>this->reservatorio.forma->dimensoes[0]){
				alturaParteVazia = this->reservatorio.forma->dimensoes[0];
			}

			//Altura do nível atual do reservatório
			float alturaParteCheia = this->reservatorio.forma->dimensoes[0] - alturaParteVazia; 
			//Serial.println("Altura parte cheia:" + String(alturaParteCheia));

			//Obtendo o volume atual do reservatório
			float volumeAtual = this->reservatorio.forma->ObterVolumeAtual(alturaParteCheia);
			//Serial.println("Volume Atual:" + String(volumeAtual));

			//Obter procentagem do quanto está cheio o resevatório
			unsigned int porcentagemAtual = this->reservatorio.ObterPorcentagemCheio(volumeAtual);
			//Serial.println("Porcentagem:" + String(porcentagemAtual));

			//Modificar os leds de nível
			ModificarLedsNivel(porcentagemAtual);

			medicoes[i] = volumeAtual;

			delay(intervalo*1000); 
		}
		
		this->mandarEmail = ModificarLedMudanca(medicoes,quantidade);

		return medicoes;
	}

	void ModificarLedsNivel(unsigned int porcentagemAtual){

		Led* vermelho = (Led*)dispositivos[LED_VERMELHO];
		Led* amarelo = (Led*)dispositivos[LED_AMARELO];
		Led* verde = (Led*)dispositivos[LED_VERDE];

		vermelho->Desligar();
		amarelo->Desligar();
		verde->Desligar();

		if(0<=porcentagemAtual && porcentagemAtual<=33){

			vermelho->Ligar();

		}else if(34<=porcentagemAtual && porcentagemAtual<=66){

			amarelo->Ligar();	

		}else{

			verde->Ligar();
		}

	}

	bool ModificarLedMudanca(float* medicoes,unsigned int quantidade){
		
		bool modificou = false;

		double proporcao = medicoes[quantidade-1]/medicoes[0];

		if(proporcao<=0.9){
			((Led*)dispositivos[LED_BRANCO])->Ligar();
			modificou = true;
		}else{
			((Led*)dispositivos[LED_BRANCO])->Desligar();
			modificou = false;
		}

		return modificou;
	}

};

#endif	

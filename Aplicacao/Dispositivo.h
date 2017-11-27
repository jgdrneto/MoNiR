#ifndef _DISPOSITIVO_H_
#define _DISPOSITIVO_H_

class Dispositivo{
public:
	String nome;
	int* portas;
	int* direcoes;
	float valor;

	void Iniciar(String nNome, int* nPortas, int* nDirecoes){

		this->nome = nNome;
   
		this->portas = nPortas;
		this->direcoes = nPortas;
 	
    	int tamanho = sizeof(nPortas)/sizeof(*nPortas);
    	
    	Serial.println(tamanho);

		for(unsigned int i=0;i<tamanho;i++){
			
		  pinMode(nPortas[i],nDirecoes[i]);
      
		}

	}

	virtual float Acao()=0;

	~Dispositivo(){
		delete [] portas;
		delete [] direcoes;
	}

};	

#endif

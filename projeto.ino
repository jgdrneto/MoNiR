/*-----( Declaração de bibliotecas )-----*/
#include <Aplicacao.h>
#include <LeitorReservatorio.h>
#include <ArduinoJson.h>
/*-----( Fim da declaração de bibliotecas )-----*/

/*-----( Declaração de constantes )-----*/
const short unsigned int QUANTDISPOSITIVOS = 5;   //Quantidade de dispositivos utilizados
const short unsigned int QUANTMEDICOES = 10;      //Quantidade de medições
const float INTERVALO = 1;                        //Intervalo entre medições do buffer
/*-----( Fim da declaração de constantes )-----*/

/*-----( Declaração de Pinos )-----*/
const short unsigned int PORTA_LED_VERDE = 13;    //Pino do led verde
const short unsigned int PORTA_LED_AMARELO = 12;  //Pino do led amarelo
const short unsigned int PORTA_LED_VERMELHO = 11; //Pino do led vermelho
const short unsigned int PORTA_LED_BRANCO = 10;   //Pino do led branco
const short unsigned int PORTA_TRIGGER = 9;       //Pino do trigger
const short unsigned int PORTA_ECHO = 8;          //Pino do echo
/*-----( Fim da declaração de pinos )-----*/

/*-----( Declaração de estruturas globais )-----*/

/*-----( Fim da declaração de estruturas globais )-----*/

/*-----( Declaração de objetos globais )-----*/
Dispositivo** dispositivos =  new Dispositivo*[QUANTDISPOSITIVOS];                //Vetor com todos os dispostivos que serão utilizados
Reservatorio* reservatorio = nullptr;
Aplicacao* c = nullptr;
/*-----( Fim da declaração de objetos globais )-----*/

void setup() {
  
  dispositivos[LED_VERDE] = new Led("Verde",PORTA_LED_VERDE);
  dispositivos[LED_AMARELO] = new Led("Amarelo",PORTA_LED_AMARELO);
  dispositivos[LED_VERMELHO] =  new Led("Vermelho", PORTA_LED_VERMELHO );
  dispositivos[LED_BRANCO] = new Led("Branco", PORTA_LED_BRANCO );
  dispositivos[SENSOR_ULTRASONICO] = new SensorUltrasonico("SensorUltrasonico1",PORTA_TRIGGER,PORTA_ECHO);

  Serial.begin(9600); // Starts the serial communication
  
  while(!Serial){ /* NULL */ }

  String json = "";
  
  while(reservatorio==nullptr){
    
    json = Serial.readString(); 
     
    //Serial.println(json);
      
    LeitorReservatorio leitor;
        
    reservatorio = leitor.Ler(json);
  }

  c = new Aplicacao(*reservatorio,dispositivos);
  
}

void loop() {
     
  float* medicoes = c->RealizarMedicoes(QUANTMEDICOES,INTERVALO);
    
  c->SalvarRelatorio(medicoes,QUANTMEDICOES);
      
  delete [] medicoes;
    
}

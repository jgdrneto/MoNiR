#include <Aplicacao.h>
#include <LeitorReservatorio.h>
#include <ArduinoJson.h>

SensorUltrasonico* sensor = new SensorUltrasonico("SensorUltrasonico1",9,8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  Serial.println("Distância: " + String((int)sensor->Acao()));
    
  delay(10); // delay in between reads for stability
}

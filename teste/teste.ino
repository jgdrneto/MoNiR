void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial.available()){};
 
  String input = Serial.readString();
  Serial.println("Valor: " + input);
}

void loop() {
    // read the input on analog pin 0:
    // print out the value you read:
    Serial.println(10);
    delay(1000); // delay in between reads for stability
}

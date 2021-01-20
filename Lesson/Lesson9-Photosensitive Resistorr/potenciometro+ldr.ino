//https://create.arduino.cc/projecthub/ingo-lohs/light-sensing-with-the-flying-fish-series-from-mh-0e51ab

int pinLed1 = 9; // Seleccionamos pin para el Led.
int pinLed2 =10; //
int sensorValue = 0; // variable para el valor del sensor.
void setup() {
  // Se inicia la comunicacion a 9600 baudios
  pinMode(pinLed1, OUTPUT); // Establecemos el pin como salida.
  pinMode(pinLed2, OUTPUT); 
  Serial.begin(9600);
}

// 
void loop() {
  // read the input on analog pin A0:
  // lectura del sensor analógico A0
  sensorValue = analogRead(A0);
  // Convertir la lectura del sensor analógico (va desde 0 - 1023) al voltaje de (0 - 5V):
  float voltage = sensorValue * (5.0 / 1024.0);
  
  // the lower the voltage, the brighter it is
  //a menor  voltaje mayor brillo
  if ((voltage >= 0) && (voltage <= 0.4)) {
    Serial.print ("it is light -  ");
    Serial.print("\t");
    Serial.print("Hay luz - ");
    digitalWrite(pinLed1,LOW);digitalWrite(pinLed2,LOW);
  } else if ((voltage > 0.4) && (voltage <= 2)) {
    Serial.print ("it is bright - ");
    Serial.print("\t");
    Serial.print("Hay penumbra - ");
    digitalWrite(pinLed1,LOW);digitalWrite(pinLed2,HIGH);
  } else {
    Serial.print ("it is dark - ");
    Serial.print("\t");
    Serial.print("está oscuro - ");
    digitalWrite(pinLed1,HIGH);digitalWrite(pinLed2,HIGH);
  }
  // print out the value you read:
  // imprime el valor leído
  Serial.println(voltage);
  delay (1000);

// D0:

// when sensor pin D0 is connected, the sensor only knows the state light (0.14V) and dark (5.0V).
// The brightness at which the particular state is to be set can be set using the rotary potentiometer.

}

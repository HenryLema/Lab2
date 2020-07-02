//Emisor
#include  <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(13,12,11,10,9,8);
char dato;
int cont=0; //variable de conteo 
void setup() {
Wire.begin(); //inicio de comunicación i2c
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
 cont++; //incremento de variable
 Wire.beginTransmission(4); // configuración de esclavo a enviar
 Wire.write(cont);  // envio de mensaje
 Wire.endTransmission(); // fin de comunicación
 delay(1000); // espera

 Wire.requestFrom(4, 2); 
 while(Wire.available()){
  Serial.println("mesaje recibido");
    char c = Wire.read();
  Serial.println(c);

 if(Serial.available()>0){ //verifica el puerto de cx
        dato=Serial.read(); // almacena el dato en variable
        Wire.beginTransmission(4); // empieza cx i2c
        Wire.write(dato); // envía dato
        Wire.endTransmission(); // termina cx i2c
      }
 }
Serial.println();
 delay(1000);
}

//Receptor
#include <LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{
  lcd.begin(16, 2); 
  Wire.begin(4);     // id de esclavo           
  Wire.onReceive(receiveEvent);  //evento de recepción de mensajes
  Wire.onRequest(requestEvent);
  Serial.begin(9600);   // comunicación serial        
}

void loop()
{
delay(100);
}
void receiveEvent(int bytes){ // evento i2c
  while(Wire.available())  // si existe mensaje por leer
  {
    Serial.println(" Mensaje recibido");
    int c = Wire.read();  // recibe dato
    Serial.print(c);    //envia por comunicación serial 
  lcd.setCursor(0,0);
  lcd.print("Recibido");
  lcd.setCursor(0,1);
  lcd.print(c);
  
  }
}
// function that executes whenever data is requested from master
void requestEvent() {
 Wire.write("Hi");  /*send string on request */
}

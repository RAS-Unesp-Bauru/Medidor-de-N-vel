// Biblioteca do Display LCD
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 7;
const int echoPin = 6;
float time, distance,percent;
void setup() 
{
  lcd.begin(20, 4);  
  lcd.setCursor(0, 0);                     
  lcd.print("RAS UNESP-BAURU");               
  lcd.setCursor(0, 1);
  lcd.print("Medidor de nivel");
  delay(3000); 
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  
}

void loop() 
{
lcd.clear();
digitalWrite(trigPin, LOW);  
delayMicroseconds(2);  
digitalWrite(trigPin, HIGH);  
delayMicroseconds(10);  
digitalWrite(trigPin, LOW);  

time = pulseIn(echoPin, HIGH);

distance = (time*.0343)/2;  
percent = ((1-(distance/21))*100);

lcd.setCursor(0, 0);                    

lcd.print("Nivel de Agua:"); 
  
  if ((distance >= 0)&&(distance < 7))
  {
  lcd.setCursor(0, 1); 
  lcd.print("Alto");
  lcd.setCursor(0, 2); 
  lcd.print(percent);
  lcd.setCursor(6, 2); 
  lcd.print("%");
  delay(1000);


  }

  if ((distance >= 7)&&(distance <= 14))
  {
    lcd.setCursor(0, 1); 
    lcd.print("Medio");
    lcd.setCursor(0, 2); 
    lcd.print(percent);
    lcd.setCursor(6, 2); 
    lcd.print("%");
    delay(1000);


  }

  if(distance > 14)
  {

   lcd.setCursor(0, 1); 
   lcd.print("Baixo");
   lcd.setCursor(0, 2); 
   lcd.print(percent);
   lcd.setCursor(6, 2); 
   lcd.print("%");
   delay(1000);


  }
 
delay(1500);
 

}

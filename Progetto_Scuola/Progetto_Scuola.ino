#include <DHT.h>
#include <LiquidCrystal.h>

/* DHTPIN 8 temp sensor pin
 * DHT11 sensor type
 */


#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// DISPLAY CONNECTION
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

 
void setup() {
  lcd.begin(16, 2);
  
  // imposto il tipo di display (colonne, righe)
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print("Umidita'");
}

void loop() {
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  
  // posiziono il cursore alla colonna 12 e riga 0
  lcd.setCursor(14, 0);
  lcd.print(t);
  lcd.setCursor(14, 1);
  lcd.print(h);
}

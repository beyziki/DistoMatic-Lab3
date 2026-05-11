#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int PIN_BUTTON = 2;
const int PIN_ECHO   = 4;
const int PIN_TRIG   = 3;

int   buttonState;
int   lastButtonState = 1;
float pingTime;
float targetDistance;

void lcdPrint(String line1, String line2) {
  // Her satiri 16 karaktere tampon
  while (line1.length() < 16) line1 += " ";
  while (line2.length() < 16) line2 += " ";
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void setup() {
  Serial.begin(9600);
  Serial.println("=== DistoMatic Basliyor ===");

  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_TRIG,   OUTPUT);
  pinMode(PIN_ECHO,   INPUT);

  Wire.begin();
  Serial.println("I2C Tarama...");
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Cihaz: 0x");
      Serial.println(addr, HEX);
    }
  }

  lcd.init();
  lcd.backlight();

  lcdPrint("  DistoMatic    ", " Butona Basin...");
  Serial.println("Hazir. Butona basin.");
}

void loop() {

  buttonState = digitalRead(PIN_BUTTON);

  if (buttonState == 0 && lastButtonState == 1) {

    Serial.println("Buton basildi! Olcum yapiliyor...");

    lcdPrint("  Olcuyor...    ", "                ");

    // Trig pulse
    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    pingTime = pulseIn(PIN_ECHO, HIGH, 30000);

    Serial.print("pingTime (us): ");
    Serial.println(pingTime);

    if (pingTime == 0) {
      Serial.println("HATA: Sinyal alinamadi!");
      lcdPrint("  SENSOR HATASI ", " Kabloyu kontrol");

    } else {
      targetDistance = (pingTime * 0.034) / 2.0;

      Serial.print("Mesafe: ");
      Serial.print(targetDistance, 1);
      Serial.println(" cm");

      String mesajStr = "    " + String(targetDistance, 1) + " cm";
      lcdPrint("    Mesafe:     ", mesajStr);
    }

    delay(5000);

    lcdPrint("  DistoMatic    ", " Butona Basin...");
  }

  lastButtonState = buttonState;
}
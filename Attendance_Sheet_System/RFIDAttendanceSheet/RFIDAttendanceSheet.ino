#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

LiquidCrystal lcd(9, 2, 6, 5, 4, 3);

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte card_ID[4];
byte Name1[4] = {0xD3, 0xF0, 0x9E, 0x0E};
byte Name2[4] = {0x43, 0x7E, 0xBE, 0x0C};
byte Name3[4] = {0x53, 0x40, 0xE9, 0x2F};
byte Name4[4] = {0x73, 0x14, 0xB6, 0xED};
byte Name5[4] = {0xA3, 0x2D, 0xE8, 0x11};
byte Name6[4] = {0x23, 0x7D, 0xB2, 0xF7};

int cardState[6]; // 0 = not read, 1 = first read done, 2 = second read done

// int const RedLed = 6;
// int const GreenLed = 5;
int const Buzzer = 8;

String Name;
int Number;
int j;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("CLEARSHEET");
  Serial.println("Label, Date, Time, Name, Number, Student State"); // Add Greeting column

  // pinMode(RedLed, OUTPUT);
  // pinMode(GreenLed, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.begin(16, 2);

  for (int i = 0; i < 6; i++) {
    cardState[i] = 0;
  }
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  // Match card UID to a known card
  if (compareArray(mfrc522.uid.uidByte, Name1)) { Name = "John"; Number = 1; j = 0; }
  else if (compareArray(mfrc522.uid.uidByte, Name2)) { Name = "Sewar"; Number = 2; j = 1; }
  else if (compareArray(mfrc522.uid.uidByte, Name3)) { Name = "Danny"; Number = 3; j = 2; }
  else if (compareArray(mfrc522.uid.uidByte, Name4)) { Name = "Desiree"; Number = 4; j = 3; }
  else if (compareArray(mfrc522.uid.uidByte, Name5)) { Name = "Kimberly"; Number = 5; j = 4; }
  else if (compareArray(mfrc522.uid.uidByte, Name6)) { Name = "Moussa"; Number = 6; j = 5; }
  else {
    // digitalWrite(GreenLed, LOW);
    // digitalWrite(RedLed, HIGH);
    // delay(2000);
    // digitalWrite(RedLed, LOW);
    return;
  }

  // Decide greeting based on card state
  String studentState;
  if (cardState[j] == 0) {
    studentState = "IN CLASS";
    cardState[j] = 1;
    buzzes(150);
    
    // Show "Welcome to class [Student Name]" on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome to class ");
    lcd.setCursor(0, 1);
    lcd.print(Name);
    lcd.print(" !");
    delay(3000);
    lcd.clear();

  } else if (cardState[j] == 1) {
    studentState = "OUT OF CLASS";
    cardState[j] = 2;  // After second read, no further reads unless reset
    buzzes(500);
    // Show "Goodbye [Student Name] !" on LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Goodbye ");
    lcd.print(Name);
    lcd.print(" !");
    // lcd.setCursor(0, 1);
    // lcd.print(Name);
    delay(3000);
    lcd.clear();
  
  } else {
    return; // Ignore further reads for this card
  }

  // Send data to Excel
  Serial.print("DATA,DATE,TIME,");
  Serial.print(Name);
  Serial.print(",");
  Serial.print(Number);
  Serial.print(",");
  Serial.println(studentState);

  // Buzzer and LED feedback
  // digitalWrite(GreenLed, HIGH);
  // digitalWrite(RedLed, LOW);
  // digitalWrite(Buzzer, HIGH);
  // delay(100);
  // digitalWrite(Buzzer, LOW);
  // delay(500);
  // digitalWrite(GreenLed, LOW);

  Serial.println("SAVEWORKBOOKAS,Names/WorkNames");

  delay(1500); // Small delay to avoid rapid re-scanning of the same card
}

bool compareArray(byte *a, byte *b) {
  for (byte i = 0; i < 4; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void buzzes(int x) {
  digitalWrite(Buzzer, HIGH);
  delay(x);
  digitalWrite(Buzzer, LOW);
  // delay(500);

}
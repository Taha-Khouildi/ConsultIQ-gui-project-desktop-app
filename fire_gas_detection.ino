#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*------------------------ Pin Definitions -----------------------------------*/
#define Smoke_sensor A0
#define Flame_sensor 8
#define Buzzer 9

/*===============================================================================
=============================== Object Instantiation =============================
===========================================================================-*/

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change to 0x3F if needed


/* ---------------------- Sensor Status Variables ---------------------- */
bool flame_status = false;
bool smoke_status = true;
String lastMessage = "";

/* -------------------------- LCD Message Function ----------------------------- */
void displayMessage(const String &msg) {
  if (msg != lastMessage) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg);
    lastMessage = msg;
  }
}

/* ------------------------ Fire & Smoke detect and Alarm Logic ------------------------- */
void check_and_act() {
  flame_status = digitalRead(Flame_sensor); // LOW = flame detected
  smoke_status = digitalRead(Smoke_sensor); // LOW = smoke detected

  if (flame_status == LOW && smoke_status == LOW) {
    displayMessage("FIRE & GAS ALERT");
    digitalWrite(Buzzer, HIGH);
  } else if (flame_status == LOW) {
    displayMessage("FIRE DETECTED");
    digitalWrite(Buzzer, HIGH);
  } else if (smoke_status == LOW) {
    displayMessage("GAS DETECTED");
    digitalWrite(Buzzer, HIGH);
  } else {
    displayMessage("NO DANGER");
    digitalWrite(Buzzer, LOW);
  }
}

/*================================================================================
=============================== Main Functions =============================
===========================================================================-*/

/* ------------------------- Setup Function --------------------------------*/
void setup() {
  Serial.begin(9600);
  while (!Serial);



  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  delay(2000);
  lcd.clear();

  pinMode(Smoke_sensor, INPUT);
  pinMode(Flame_sensor, INPUT);
  pinMode(Buzzer, OUTPUT);

  digitalWrite(Buzzer, LOW);
}

/* ---------------------------- Loop Function ---------------------------------- */
void loop() {
  check_and_act();
  delay(300);
}
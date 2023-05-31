#include <Wire.h>
#include <Zumo32U4.h>

const int omtrek = 11;

Zumo32U4Encoders encoders;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonC buttonC;

int16_t countsLeft;
int16_t countsRight;

void setup()
{

}

void loop()
{
  // Verzamelt de informatie van de linker en rechter wielen
  countsLeft = encoders.getCountsLeft();
  countsRight = encoders.getCountsRight();
  delay(1000);

  // Stuurt de informatie naar de Seriele Monitor
  Serial.print(countsLeft);
  Serial.print(" ");
  Serial.print(countsRight);
  Serial.println(" ");

  // Zorgt ervoor dat als knop A ingedrukt wordt, de robot vooruit rijdt.
  if (buttonA.isPressed()) {
    motors.setSpeeds(400, 400);

  // Zorgt ervoor dat als knop C ingedrukt wordt, de robot achteruit rijdt.
  } else if (buttonC.isPressed()) {
    motors.setSpeeds(-400, -400);
  } else {
    motors.setSpeeds(0, 0);
  }
}
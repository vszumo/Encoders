
#include <Zumo32U4Encoders.h>
#include <Zumo32UMotors.h>
#include <Encoders.h>

Zumo32U4Encoders encoders;
Zumo32U4Motors motors;
Encoder en;

void setup()
{

}



void loop()
{
  // Verzamelt de informatie van de linker en rechter wielen
  en.countsLeft = encoders.getCountsLeft();
  en.countsRight = encoders.getCountsRight();
  delay(50);

  // Stuurt de informatie naar de Seriele Monitor
  Serial.print(en.countsLeft);
  Serial.print(" ");
  Serial.print(en.countsRight);
  Serial.println(" ");

  if (en.countsRight > en.countsLeft){
    motors.setSpeeds(210, 200);
      delay(500);
  }
  else if (en.countsRight < en.countsLeft){
    motors.setSpeeds(200, 210);
      delay(500);
  }
  else {
    motors.setSpeeds(200, 200);
  }
}

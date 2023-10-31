/*
 * Author: DIBYENDU BARMAN
 * Date: 21-June-2023
 * Project Description: LED dimmer using PWM
 */
const int pwmPin = 9;
unsigned int i = 0;

void setup() {
  pinMode(pwmPin, OUTPUT); // Optional

}

void loop() {
  for(i = 0; i < 255; i++) // In an 8-bit system, there are 256 possible values (2^8)
  {
    analogWrite(pwmPin, i);
    delay(2); // delay 2 mili seconds
  }
  
  delay(2000); // delay 2 seconds
  
  for(i = 255; i > 0; i--) // In an 8-bit system, there are 256 possible values (2^8)
  {
    analogWrite(pwmPin, i);
    delay(2); // delay 2 mili seconds
  }
  delay(2000); // delay 2 seconds
}

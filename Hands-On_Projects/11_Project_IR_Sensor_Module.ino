/*
 * Author: DIBYENDU BARMAN
 * Date: 23-June-2023
 * Project Description:  Interfacing IR sensor with Arduino [Infrared Sensor]
 */

const int led = 7;
const int IR_Sensor = 8;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(IR_Sensor, INPUT);
}

unsigned int signal_state = 1;

void loop() {
  signal_state = digitalRead(IR_Sensor);

  if(signal_state == 0)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }

}

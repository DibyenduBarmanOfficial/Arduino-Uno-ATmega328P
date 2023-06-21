const int led = 13;

void setup() {
  pinMode(led, OUTPUT); // set pin 13 as output

}

void loop() {
  digitalWrite(led, HIGH); // led turned on
  delay(1000); // 1 Second delay
  digitalWrite(led, LOW); // led turned off
  delay(1000); // 1 Second delay
}

/*
 * Author: DIBYENDU BARMAN
 * Date: 21-June-2023
 * Project Description: Printing a character on Serial Monitor
 */
 
 
char data = 'A';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}
  
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(data);
  delay(1000);
}

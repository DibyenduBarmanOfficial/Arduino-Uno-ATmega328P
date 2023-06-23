/*
 * Author: DIBYENDU BARMAN
 * Date: 22-June-2023
 * Project Description: 8-bit 16x2 Liquid Crystal Display
 */


const int RS = 3;
const int RW = 4;
const int EN = 5;
const int D0 = 6;
const int D1 = 7;
const int D2 = 8;
const int D3 = 9;
const int D4 = 10;
const int D5 = 11;
const int D6 = 12;
const int D7 = 13;

unsigned char mask[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void printdata(unsigned char data) {
  if ((data & mask[0]) == mask[0]) {
    digitalWrite(D0, LOW);
  } else {
    digitalWrite(D0, HIGH);
  }
  if ((data & mask[1]) == mask[1]) {
    digitalWrite(D1, LOW);
  } else {
    digitalWrite(D1, HIGH);
  }
  if ((data & mask[2]) == mask[2]) {
    digitalWrite(D2, LOW);
  } else {
    digitalWrite(D2, HIGH);
  }
  if ((data & mask[3]) == mask[3]) {
    digitalWrite(D3, LOW);
  } else {
    digitalWrite(D3, HIGH);
  }
  if ((data & mask[4]) == mask[4]) {
    digitalWrite(D4, LOW);
  } else {
    digitalWrite(D4, HIGH);
  }
  if ((data & mask[5]) == mask[5]) {
    digitalWrite(D5, LOW);
  } else {
    digitalWrite(D5, HIGH);
  }
  if ((data & mask[6]) == mask[6]) {
    digitalWrite(D6, LOW);
  } else {
    digitalWrite(D6, HIGH);
  }
  if ((data & mask[7]) == mask[7]) {
    digitalWrite(D7, LOW);
  } else {
    digitalWrite(D7, HIGH);
  }
}

void lcd_data(unsigned char data) // This funtion to passing the character data to LCD 
{
  printdata(data);
  digitalWrite(RS, HIGH); // Enable RS to store data to the data registor of LCD
  digitalWrite(RW, LOW);  // writing the data
  digitalWrite(EN, HIGH); // Enable the clock signal
  delay(2);
  digitalWrite(EN, LOW); // Disable the clock signal
}

void lcd_cmd(unsigned char cmd)
{
  printdata(cmd);
  digitalWrite(RS, LOW); // Disable RS to store instruction to the instruction registor of LCD
  digitalWrite(RW, LOW);  // writing the instruction
  digitalWrite(EN, HIGH); // Enable the clock signal
  delay(2);
  digitalWrite(EN, LOW); // Disable the clock signal
}

void lcd_string(unsigned char str[], unsigned char num)
{
  unsigned int i;

  for(i = 0; i < num; i++)
  {
    lcd_data(str[i]);
  }
}

void lcd_initialise()
{
  lcd_cmd(0x38); //16 column and 2 row
  lcd_cmd(0x0C); //turns display on and cursor off
  lcd_cmd(0x06); //auto incrementing the cursor
  lcd_cmd(0x01); //clear screen 
}


void setup() {
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);
  pinMode(EN, OUTPUT);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  
  lcd_initialise();
}

void loop() {
  lcd_cmd(0x80); // first row first column
  lcd_string("Dibyendu Barman", 15);
  lcd_cmd(0xC0); // second row first column
  lcd_string("Arduino Uno", 11);
}

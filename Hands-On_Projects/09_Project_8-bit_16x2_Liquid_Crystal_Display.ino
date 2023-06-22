/*
 * Author: DIBYENDU BARMAN
 * Date: 22-June-2023
 * Project Description: 8-bit 16x2 Liquid Crystal Display
 */


const int RS = 3, RW = 4, EN = 5, D0 = 6, D1 = 7, D2 = 8, D3 = 9, D4 = 10, D5 = 11, D6 = 12, D7 = 13;
unsigned int i;
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
  for(i = 3; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  lcd_initialise();
}

void loop() {
  lcd_cmd(0x80); // first row first column
  lcd_string("Dibyendu Barman", 14);
  lcd_cmd(0xC0); // second row first column
  lcd_string("Arduino Uno", 10);
}
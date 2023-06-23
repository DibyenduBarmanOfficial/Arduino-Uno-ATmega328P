/*
 * Author: DIBYENDU BARMAN
 * Date: 23-June-2023
 * Project Description: 4-bit 16x2 Liquid Crystal Display // LCD Not working
 */


const int RS = 3;
const int RW = 4;
const int EN = 5;

const int D4 = 10;
const int D5 = 11;
const int D6 = 12;
const int D7 = 13;

unsigned char mask[8] = {0x10, 0x20, 0x40, 0x80};

void lcd_dataPort(unsigned char data) {
  if ((data & mask[4]) == mask[4]) {
    digitalWrite(D4, HIGH);
  } else {
    digitalWrite(D4, LOW);
  }
  if ((data & mask[5]) == mask[5]) {
    digitalWrite(D5, HIGH);
  } else {
    digitalWrite(D5, LOW);
  }
  if ((data & mask[6]) == mask[6]) {
    digitalWrite(D6, HIGH);
  } else {
    digitalWrite(D6, LOW);
  }
  if ((data & mask[7]) == mask[7]) {
    digitalWrite(D7, HIGH);
  } else {
    digitalWrite(D7, LOW);
  }
}

void lcd_data(unsigned char data) // This funtion to passing the character data to LCD 
{
  lcd_dataPort(data & 0x0F); // passing the MSB data
  digitalWrite(RS, HIGH); // Enable RS to store data to the data registor of LCD
  digitalWrite(RW, LOW);  // writing the data
  digitalWrite(EN, HIGH); // Enable the clock signal
  delay(2);
  digitalWrite(EN, LOW); // Disable the clock signal

  lcd_dataPort(data << 4); // passing the LSB data
  digitalWrite(RS, HIGH); // Enable RS to store data to the data registor of LCD
  digitalWrite(RW, LOW);  // writing the data
  digitalWrite(EN, HIGH); // Enable the clock signal
  delay(2);
  digitalWrite(EN, LOW); // Disable the clock signal
}

void lcd_cmd(unsigned char cmd)
{
  lcd_dataPort(cmd & 0x0F); // passing the MSB cmd
  digitalWrite(RS, LOW); // Disable RS to store instruction to the instruction registor of LCD
  digitalWrite(RW, LOW);  // writing the instruction
  digitalWrite(EN, HIGH); // Enable the clock signal
  delay(2);
  digitalWrite(EN, LOW); // Disable the clock signal

  lcd_dataPort(cmd << 4); // passing the LSB cmd
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
  lcd_cmd(0x28); //16 column and 2 row for 4bits
  lcd_cmd(0x0C); //turns display on and cursor off
  lcd_cmd(0x06); //auto incrementing the cursor
  lcd_cmd(0x01); //clear screen 
}


void setup() {
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);
  pinMode(EN, OUTPUT);

  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  
  lcd_initialise();
  delay(1000);
}

void loop() {
  lcd_cmd(0x80); // first row first column
  lcd_string("Arduino Uno", 11);
  lcd_cmd(0xC0); // second row first column
  lcd_string("Embedded System", 15);
}

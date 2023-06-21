/*
 * Author: DIBYENDU BARMAN
 * Date: 21-June-2023
 * Project Description: 2 Digit 7 segment display (Common Anode) [Multiplexing]
 */

const int a = 11;
const int b = 7;
const int c = 4;
const int d = 2;
const int e = 1;
const int f = 10;
const int g = 5;
const int h = 3;
const int Display_1 = 12;
const int Display_2 = 9;
const int Display_3 = 8;
const int Display_4 = 6;

unsigned char Segment[8] = {a, b, c, d, e, f, g, h};
unsigned char mask[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char Segment_data[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int i;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(Segment[i], OUTPUT);
  }
  pinMode(Display_1, OUTPUT);
  pinMode(Display_2, OUTPUT);
  pinMode(Display_3, OUTPUT);
  pinMode(Display_4, OUTPUT);
}

void printdata(unsigned char data) {
  if ((data & mask[0]) == mask[0]) {
    digitalWrite(a, LOW);
  } else {
    digitalWrite(a, HIGH);
  }
  if ((data & mask[1]) == mask[1]) {
    digitalWrite(b, LOW);
  } else {
    digitalWrite(b, HIGH);
  }
  if ((data & mask[2]) == mask[2]) {
    digitalWrite(c, LOW);
  } else {
    digitalWrite(c, HIGH);
  }
  if ((data & mask[3]) == mask[3]) {
    digitalWrite(d, LOW);
  } else {
    digitalWrite(d, HIGH);
  }
  if ((data & mask[4]) == mask[4]) {
    digitalWrite(e, LOW);
  } else {
    digitalWrite(e, HIGH);
  }
  if ((data & mask[5]) == mask[5]) {
    digitalWrite(f, LOW);
  } else {
    digitalWrite(f, HIGH);
  }
  if ((data & mask[6]) == mask[6]) {
    digitalWrite(g, LOW);
  } else {
    digitalWrite(g, HIGH);
  }
  if ((data & mask[7]) == mask[7]) {
    digitalWrite(h, LOW);
  } else {
    digitalWrite(h, HIGH);
  }
}

void loop() {
  digitalWrite(Display_3, LOW); // not using display3
  digitalWrite(Display_4, LOW); // not using display4
  
  printdata(Segment_data[3]); // 0x5B
  digitalWrite(Display_1, HIGH);
  digitalWrite(Display_2, LOW);
  delay(5);
  digitalWrite(Display_1, LOW);
  digitalWrite(Display_2, LOW);

  printdata(Segment_data[8]); // 0x7F
  digitalWrite(Display_1, LOW);
  digitalWrite(Display_2, HIGH);
  delay(5);
  digitalWrite(Display_1, LOW);
  digitalWrite(Display_2, LOW);
}


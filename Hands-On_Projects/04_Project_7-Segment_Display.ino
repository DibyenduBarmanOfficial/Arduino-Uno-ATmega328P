/*
 * Author: DIBYENDU BARMAN
 * Date: 21-June-2023
 * Project Description: Display 0 to 9 on 7-Segment Display (Common Cathode)
 */

const int a = 3;
const int b = 4;
const int c = 5;
const int d = 6;
const int e = 7;
const int f = 8;
const int g = 9;
const int h = 10;

unsigned char data;
unsigned char Segment[8] = {a, b, c, d, e, f, g, h};
unsigned char mask[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char Segment_data[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int i;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(Segment[i], OUTPUT);
  }
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
  for (i = 0; i < 10; i++) {
    printdata(Segment_data[i]);
    delay(1000); // Delay to display each number for 1 second
  }
}




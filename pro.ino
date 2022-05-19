#include "pitches.h"

#define FREQ 1

#define NOTES_DURATION 10

#define SOUND 

bool isPlaying[3] = {0};//ye bool brye inke moshkhs kne dre play mishe ya na
const int leds[] = {3, 4, 5};//3 ta led drim
int notes[3][6] = {//note hamun
  {NOTE_G3, NOTE_GS3, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C4},
  {NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3},
  {NOTE_G2, NOTE_GS2, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C3}
};
int frets[3] = {0};//fret haye guitar
float scale;

void setup() {
  Serial.begin(9600);
 pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
 
  
}

void loop() {
  if (Serial.available() > 0) {
    char key = Serial.read();
    Serial.println(key);

    switch (key) {
      case 'a':
        frets[2] = 0;
        break;
      case 'b':
        frets[2] = 1;
        break;
      case 'c':
        frets[2] = 2;
        break;
      case 'd':
        frets[2] = 3;
        break;
      case 'g':
        frets[1] = 0;
        break;
      case 'h':
        frets[1] = 1;
        break;
      case 'i':
        frets[1] = 2;
        break;
      case 'j':
        frets[1] = 3;
        break;
      case 'm':
        frets[0] = 0;
        break;
      case 'n':
        frets[0] = 1;
        break;
      case 'o':
        frets[0] = 2;
        break;
      case 'p':
        frets[0] = 3;
        break;
//you can use more notes, we just used 4 frets
      case 't':
        if (isPlaying[0]) {
          isPlaying[0] = false;
          digitalWrite(leds[0], LOW);
        } else {
          isPlaying[0] = true;
          digitalWrite(leds[0], HIGH);
        }
        break;
      case 's':
        if (isPlaying[1]) {
          isPlaying[1] = false;
          digitalWrite(leds[1], LOW);
        } else {
          isPlaying[1] = true;
          digitalWrite(leds[1], HIGH);
        }
        break;
      case 'u':
        if (isPlaying[2]) {
          isPlaying[2] = false;
          digitalWrite(leds[2], LOW);
        } else {
          isPlaying[2] = true;
          digitalWrite(leds[2], HIGH);
        }
        break;
    };

  }
if (isPlaying[0]) {
    scale = analogRead(A0) / 512.0;
    tone(SOUND, (int) (notes[0][frets[0]] * FREQ * scale), NOTES_DURATION);
    delay(NOTES_DURATION);
  }
   if (isPlaying[1]) {
    scale = analogRead(A1) / 512.0;
    tone(SOUND, (int) (notes[1][frets[1]] * FREQ * scale), NOTES_DURATION);
    delay(NOTES_DURATION);
  }
  if (isPlaying[2]) {
    scale = analogRead(A2) / 512.0;
    tone(SOUND, (int) (notes[2][frets[2]] * FREQ * scale), NOTES_DURATION);
    delay(NOTES_DURATION);
  }
 
  
}

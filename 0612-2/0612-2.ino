/*
  Melody
  Plays a melody
  circuit:
  - 8 ohm speaker on digital pin 8
  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
#define song1WordNum 62
#define song2WordNum 20
// notes in the control:
unsugned long CT=0,PT=0;
int pauseBetweenNotes;
//int cnt=0;
boolean nexttone=true;

// notes in the melody:
int melody[] = {  //七彩的微風
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, 0,
  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_C6,0,
  NOTE_A5,NOTE_B5,NOTE_C6,0,
  NOTE_A5,NOTE_C6,NOTE_B5,NOTE_C6,NOTE_B5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_G5,0,

  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, 0,
  NOTE_G5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_C6,0,
  NOTE_A5,NOTE_B5,NOTE_C6,0,
  NOTE_A5,NOTE_C6,NOTE_B5,0,
  NOTE_B5,NOTE_B5,NOTE_A5,NOTE_B5,NOTE_B5,NOTE_C6,NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {  //七彩的微風
  8, 8, 4, 8, 6, 4,
  4, 8,8,8,4,8,2,4,
  8,8,2,8,
  4,8,3,8,4,4,8,2,2,8,

  8, 8, 4, 8, 6, 4,
  4, 8,8,8,4,8,2,4,
  8,8,2,8 ,
  4,8,4,8 ,
  8,8,8,8,4,8,2
};

int melody2[]={  //YEE
  NOTE_C5,NOTE_D5,NOTE_C5,NOTE_E5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_G5,NOTE_G5,0,
  NOTE_D5,NOTE_E5,NOTE_D5,NOTE_F5,NOTE_F5,NOTE_G5,NOTE_A5,0,NOTE_C6
};
int noteDurations2[] = {  //YEE
  8,8,8,4,4,8,4,4,8,8,8,
  8,8,8,4,4,8,8,8,2
};



void setup() {
// iterate over the notes of the melody:


}

void loop() {
  // no need to repeat the melody.
  for (int thisNote = 0; thisNote < song2WordNum; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration2 = 1000 / noteDurations2[thisNote];

    if(nexttone){
     tone(8, melody2[thisNote], noteDuration2);
      pauseBetweenNotes=noteDuration2 * 1.80;
     nexttone=false;
    }
   

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    for(int i = 0; i < 8 ; i++){
   //byte colData = colDataMatrix[i];
  digitalWrite(latchPin,LOW);
  // pickDigit(i);
  shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
  shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
  //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
  digitalWrite(latchPin,HIGH);
  delay(delay_time);
  }
    CT=millis();
    if((CT-PT)>pauseDuration){
  //cnt++;
      nexttone=true;
      PT=CT;
     }
    // stop the tone playing:
    noTone(song2WordNum);
  }

   
}

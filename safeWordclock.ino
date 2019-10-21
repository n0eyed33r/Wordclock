// the setup function runs once when you press reset or power the board
#include <FastLED.h>              //https://github.com/FastLED/FastLED
#include "Wordclock_Maske.h"      //2nd library
//FASTLED_USING_NAMESPACE
#define DATA_PIN    6             //used PIN
#define LED_TYPE    WS2812B       //used LED-stripes (type)
#define COLOR_ORDER GRB           //color adjustment
#define NUM_LEDS    160           //number of WS2812 LED
CRGB leds[NUM_LEDS];
//Buttons
const int buttonPinStd = 2;       //the number of the pushbutton pin (first)
int PinStd;                       //Pin used for the hour adjustment
const int buttonPinMin = 4;       //the number of the pushbutton pin (second)
int PinMin;                       //Pin used for the minute adjustment
// variables will change:
int buttonStateStd = 0;           // variable for reading the pushbutton status (first)
int buttonStateMin = 0;           // variable for reading the pushbutton status (second)
//Indizes
int i, n;                         //indices
//Tasterelegung
int taster = 2;                   //taster on Pin 2
int tasterstatus = 0;             //state of taster
int TasterStatus;

// push word to leds array (all credits to https://github.com/dgoersch/wordclock )
void word2stripe(const int word[], int len, CRGB color) {
  for (int letter = 0; letter < len; letter++) {
    leds[word[letter]] = color;
  }
}

void setup() {

  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalPixelString);
  FastLED.setBrightness(5);       //for testing and healthy eyes
  delay(3000);                    
  Serial.begin(9600);
  //LEDs werden eingefügt + Farbkorrektur und Farbtemperatur auf Wolfram (warmweiß)
  word2stripe(wordES, sizeof(wordES) / sizeof(int), CRGB::DarkSlateBlue);     //constant showing words
  word2stripe(wordIST, sizeof(wordIST) / sizeof(int), CRGB::DarkSlateBlue);   //constant showing words
  word2stripe(wordhUhr, sizeof(wordhUhr) / sizeof(int), CRGB::Tomato);        //constant showing words
  delay(1000);
  FastLED.show();

  //pinMode(i, OUTPUT);
  pinMode(taster, INPUT);
}

void loop() {

  delay(500);

  //Stunden - hours: loop counting of the index and show the specific LED
  for (i = 0; i < 12; i++) {
    tasterstatus = digitalRead(taster);
    if (tasterstatus == HIGH)
    { //construction area -> if the button is pushed the index should increase immediatly -> BUT! the second loop needs to be finished first (ERROR)
      digitalWrite(TasterStatus, HIGH);
      i = i + 1;
      delay (100);
      digitalWrite(TasterStatus, LOW);
    }
    else
    {
      digitalWrite(TasterStatus, LOW);
    }
  Serial.println("Stunde");
  Serial.println(i);
  if (i < 1) {
    word2stripe(wordhZwoelf, sizeof(wordhZwoelf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhEin, sizeof(wordhEin) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 2) {
    word2stripe(wordhEin, sizeof(wordhEin) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhZwei, sizeof(wordhZwei) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 3) {
    word2stripe(wordhZwei, sizeof(wordhZwei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhDrei, sizeof(wordhDrei) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 4) {
    word2stripe(wordhDrei, sizeof(wordhDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhVier, sizeof(wordhVier) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 5) {
    word2stripe(wordhVier, sizeof(wordhVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhFuenf, sizeof(wordhFuenf) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 6) {
    word2stripe(wordhFuenf, sizeof(wordhFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhSechs, sizeof(wordhSechs) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 7) {
    word2stripe(wordhSechs, sizeof(wordhSechs) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhSieben, sizeof(wordhSieben) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 8) {
    word2stripe(wordhSieben, sizeof(wordhSieben) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhAcht, sizeof(wordhAcht) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 9) {
    word2stripe(wordhAcht, sizeof(wordhAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhNeun, sizeof(wordhNeun) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 10) {
    word2stripe(wordhNeun, sizeof(wordhNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhZehn, sizeof(wordhZehn) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 11) {
    word2stripe(wordhZehn, sizeof(wordhZehn) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhElf, sizeof(wordhElf) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  else if (i < 12) {
    word2stripe(wordhElf, sizeof(wordhElf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
    word2stripe(wordhZwoelf, sizeof(wordhZwoelf) / sizeof(int), CRGB( 8, 75, 10)); FastLED.show();
  }
  /*Minuten - minutes: loop counting of the index and show the specific LED
    the delays in the second loop was decreased for testing
  */
  for (n = 0; n < 60; n++) {
    Serial.println("Minute");
    Serial.println(n);
    if (n < 1) {
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    if (n < 2) {
      word2stripe(wordmEins, sizeof(wordmEins) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 3) {
      word2stripe(wordmEins, sizeof(wordmEins) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 4) {
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 5) {
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 6) {
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 7) {
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 8) {
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 9) {
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 10) {
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 11) {
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 12) {
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmElf, sizeof(wordmElf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 13) {
      word2stripe(wordmElf, sizeof(wordmElf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwoelf, sizeof(wordmZwoelf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 14) {
      word2stripe(wordmZwoelf, sizeof(wordmZwoelf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 15) {
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 16) {
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 17) {
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSech, sizeof(wordmSech) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 18) {
      word2stripe(wordmSech, sizeof(wordmSech) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSieb, sizeof(wordmSieb) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 19) {
      word2stripe(wordmSieb, sizeof(wordmSieb) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 20) {
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 21) {
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZehn, sizeof(wordmZehn) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 22) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 23) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 24) {
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 25) {
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 26) {
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 27) {
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 28) {
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 29) {
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 30) {
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 31) {
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwanzig, sizeof(wordmZwanzig) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 32) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 33) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 34) {
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 35) {
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 36) {
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 37) {
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 38) {
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 39) {
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 40) {
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 41) {
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDreissig, sizeof(wordmDreissig) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 42) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 43) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 44) {
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 45) {
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 46) {
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 47) {
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 48) {
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 49) {
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 50) {
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }

    else if (n < 51) {
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVierzig, sizeof(wordmVierzig) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 52) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 53) {
      word2stripe(wordmEin, sizeof(wordmEin) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 54) {
      word2stripe(wordmZwei, sizeof(wordmZwei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 55) {
      word2stripe(wordmDrei, sizeof(wordmDrei) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 56) {
      word2stripe(wordmVier, sizeof(wordmVier) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 57) {
      word2stripe(wordmFuenf, sizeof(wordmFuenf) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 58) {
      word2stripe(wordmSechs, sizeof(wordmSechs) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 59) {
      word2stripe(wordmSieben, sizeof(wordmSieben) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmUnd, sizeof(wordmUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
    else if (n < 60) {
      word2stripe(wordmAcht, sizeof(wordmAcht) / sizeof(int), CRGB( 0, 0, 0)); FastLED.show();
      word2stripe(wordmNeun, sizeof(wordmNeun) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      word2stripe(wordmNeunUnd, sizeof(wordmNeunUnd) / sizeof(int), CRGB::Tomato); FastLED.show();
      word2stripe(wordmFuenfzig, sizeof(wordmFuenfzig) / sizeof(int), CRGB::DarkOrchid); FastLED.show();
      delay(1000);//warte 60 Sekunden um nächste Minute anzuzeigen
    }
  }   //Minute-minute-out
}     //Stunde-hour-out
      //show it on the matix
FastLED.show();
}     //Loop-out

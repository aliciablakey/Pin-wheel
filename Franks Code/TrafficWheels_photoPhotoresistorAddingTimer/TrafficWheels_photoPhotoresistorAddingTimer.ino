#include <Event.h>
#include <Timer.h>

#include <FastLED.h>

Timer t;

//Code for Photoresistor

//photoresistor A Style Tech.

int Pr = 0; // will be used for analog 0.
int PrValue = 50; // value of output
int PrInputA = 250; // value of when light is on
int PrInputB = 130;
int PrInputC = 60;
int PrInput = 0;

// How many leds in your strip?
#define NUM_LEDS 4
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
    //photoresistor start
    Serial.begin(9600); //start serial Monitor
    pinMode(8, OUTPUT); // pin 8 as output
     
     // Led control below
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      
}

void loop() { 

PrValue = analogRead(Pr);

Serial.println(PrValue); //prints photoresistor value so we can see it to debug code

// I now need a switch statement to do the following
// Turn it on if its OFF based on Light
// Check the timer and keep it On and Green if ON && TIMER < 10000
// Check timer if ON && Timer > 10000 turn Orange
// Check timer if ON && Timer > 20000 Turn Red
// Check Sensor if PrValue > Pr_Input reset Timer and tuen Led Green

if(PrValue > PrInputA) { PrInput = 1; }
else if (PrValue > PrInputB) { PrInput = 2;}
else PrInput = 3;

switch (PrInput) {
  case 1:
    digitalWrite(8, HIGH);
    // Turn the LED on, then pause
    for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
      }

  FastLED.show();
  delay(500);


break;

  case 2:
    digitalWrite(8, HIGH);
    // Turn the LED on, then pause
    for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::OrangeRed;
    }

  FastLED.show();
  delay(500);


break;

  case 3:
  digitalWrite(8, HIGH);
    // Turn the LED on, then pause
    for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
      }

  FastLED.show();
  delay(500);


break;
}


delay(100); // value updated every 0.1 second.



}

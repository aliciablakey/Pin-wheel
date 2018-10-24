#include <FastLED.h>

//Code for Photoresistor

//photoresistor A Style Tech.

int Pr = 0; // will be used for analog 0.
int PrValue = 0; // value of output
int Pr_Input = 10; // value of when light is on

// How many leds in your strip?
#define NUM_LEDS 30
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

Serial.println(PrValue); //prints photoresistor value

delay(100); // value updated every 0.1 second.


if (PrValue > Pr_Input) // if sensor value is less than 19, light will turn on.

{ digitalWrite(8, HIGH);//LED on } else { digitalWrite(8, LOW);// LED off }

  
  // Turn the LED on, then pause
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
  }

  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
   for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
}

if (PrValue < Pr_Input) // if sensor value is less than 19, light will turn on.

{ digitalWrite(8, HIGH);//LED on } else { digitalWrite(8, LOW);// LED off }

// Turn the LED on, then pause
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
  }

  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
   for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
}

}

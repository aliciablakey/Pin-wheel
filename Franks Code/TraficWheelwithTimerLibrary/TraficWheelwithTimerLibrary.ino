#include <Event.h>
#include <Timer.h>

#include <Event.h>


#include <FastLED.h>

//Start the Timer
int sampleRate = 2000;   //how fast to sample the value
Timer t;
int myTime = 0;


//Code for Photoresistor

//photoresistor A Style Tech.

int Pr = 0; // will be used for analog 0.
int PrValue = 50; // value of output
int PrInputA = 200; // value of when light is on
int PrInputB = 90;
int PrInputC = 55;


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
delay(100); // update PrValue

if (PrValue > PrInputA) { 
  myTime = 0;
  } 
else if (PrValue > PrInputB) { 
  myTime = 1;
  }
else myTime = 2;  

switch (myTime)
 
{
  case 0:
  // turn on led  and do not turn off
  pinMode(8, HIGH);
  t.pulse(8, 1 * 10 * 1000, HIGH); // 10 seconds
  
   //Turn the LED on, then pause
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
  
  break;

  case 1:
  // if time is above 10 seconds Orange
  
  pinMode(8, HIGH);
  t.pulse(8, 1 * 10 * 1000, HIGH); // 10 seconds
  
   //Turn the LED on, then pause
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::OrangeRed;
  }

  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
   for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(500);
  
  break;

  case 2:
  // if time is above 20 seconds turn Red
    pinMode(8, HIGH);
  t.pulse(8, 1 * 10 * 1000, HIGH); // 10 seconds
  
   //Turn the LED on, then pause
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
  break;
}





/* delay(100); // value updated every 0.1 second.

if (PrValue > Pr_Input) // if sensor value is less than 200, light will turn on.

{ digitalWrite(8, HIGH);//LED on } else { digitalWrite(8, LOW);// LED off }
*/
  

}

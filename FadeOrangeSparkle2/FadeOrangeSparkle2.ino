/*
  Fade
  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.
  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Fade
*/
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 60

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 3
#define CLOCK_PIN 13
int randled;

// Define the array of leds
CRGB leds[NUM_LEDS];

int led = 2;           // the PWM pin the LED is attached to
int fadeAmount = 5;    // how many points to fade the LED 

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  FastLED.clear();
     FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);  // BGR ordering is typical
}

// the loop routine runs over and over again forever:
void loop() {
int brightness = 0;
randled = rand() % 61;
FadeIn(randled,brightness);
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

void FadeIn ( int i,int brightness) {
  while(brightness <= 255) {
    leds[i] = (32,160, brightness);
    brightness = brightness + fadeAmount;
  }
  FadeOut (i,brightness);
 }

void FadeOut(int i,int brightness) {
  while(brightness > fadeAmount) {
    leds[i] = (32,160, brightness);
    brightness = brightness - fadeAmount;
  }
}

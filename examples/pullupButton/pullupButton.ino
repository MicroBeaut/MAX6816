#include "MAX6816.h"

#define pushButtonPin   12    // Define the push button input pin
#define debouncePeriod  10UL  // Define the debounce period in milliseconds

MAX6816 pushButton;           // Declare the button switch debouncer

void setup() {
  pushButton.switchMode(pushButtonPin, INPUT_PULLUP, debouncePeriod); // Set the button switch mode
  pinMode(LED_BUILTIN, OUTPUT);                                       // Set the LED BUILTIN output pin mode
}

void loop() {
  pushButton.debounce();                          // The debouncers remove bounce when a switch opens or closes.
  digitalWrite(LED_BUILTIN, pushButton.output);   // Write the LED BUILTIN with debounced state
}
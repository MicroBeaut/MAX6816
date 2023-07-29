#include "MAX6816.h"

#define pushButtonPin   12    // Define the buttonSwitch input pin
#define debouncePeriod  10UL  // Define the debounce period in milliseconds

MAX6816 buttonSwitch;         // Declare the button switch debouncer

bool toggle;                  // Toggle state variable

void setup() {
  buttonSwitch.switchMode(pushButtonPin, INPUT_PULLUP, debouncePeriod); // Set the button switch mode
  pinMode(LED_BUILTIN, OUTPUT);                                         // Set the LED BUILTIN output pin mode
  toggle = false;                                                       // Initial the toggle state
}

void loop() {
  bool previous = buttonSwitch.output;                    // Save previous button state
  buttonSwitch.debounce();                                // The debouncers remove bounce when a switch opens or closes.
  if (!buttonSwitch.output & previous) toggle = !toggle;  // If pressed button, toggle the state
  digitalWrite(LED_BUILTIN, toggle);                      // Write the LED BUILTIN with toggle state
}
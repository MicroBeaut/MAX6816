/*
  MAX6816.h
  Created:  29-Jul-2023
  Author:   MicroBeaut

  MIT License
  Copyright (c) 2023 MicroBeaut
*/

#ifndef MAX6816_H
#define MAX6816_H

#include <Arduino.h>

#define MAX6816_VERSION "1.0.0"
#define MAX6816_AUTHOR "MicroBeaut"

#define DEBOUNCE_PERIOD 10UL

class MAX6816 {
  private:
    boolean _input;
    boolean _output;
    uint8_t _pin;

    unsigned long _debounceStart;
    unsigned long _debouncePeriod;
  public:
    const boolean &input;
    const boolean &output;

    MAX6816();
    void switchMode(const uint8_t pin, const uint8_t mode, const unsigned long debouncePeriod = DEBOUNCE_PERIOD);
    const boolean debounce();
};

#endif  // MAX6816_H
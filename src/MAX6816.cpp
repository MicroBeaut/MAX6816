/*
  MAX6816.h
  Created:  29-Jul-2023
  Author:   MicroBeaut

  MIT License
  Copyright (c) 2023 MicroBeaut
*/

#include "MAX6816.h"

MAX6816::MAX6816(): input(_input), output(_output) {
}

void MAX6816::switchMode(const uint8_t pin, const uint8_t mode, const unsigned long debouncePeriod) {
  boolean pullup = mode == INPUT_PULLUP;
  _pin = pin;
  pinMode(pin, mode);
  _input = pullup;
  _output = pullup;
  _debouncePeriod = debouncePeriod * 1000UL;
}

const boolean MAX6816::debounce() {
  boolean previous = _input;
  _input = digitalRead(_pin);
  if (_input != previous) _debounceStart = micros();
  if (_input == _output) return _output;
  if (micros() - _debounceStart < _debouncePeriod) return _output;
  _output = _input;
  return _output;
}
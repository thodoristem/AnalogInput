/**
 * @file AnalogInput.h
 * @author Theodoros Temourtzidis (thodoristem@gmail.com)
 * @brief Lib for controling analog inputs
 * @version 1.0
 * @date 2024-02-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef AnalogInput_h
#define AnalogInput_h

#include <Arduino.h>

class AnalogInput
{
private:
    byte pin;
    short deadZone;
    short max = 0;
    short min = 1023;
    short raw;
    bool doCal = false;
    bool reverse = false;

public:
    AnalogInput(byte pin, short deadZone);
    AnalogInput(byte pin, short deadZone, short min, short max);
    void begin();
    void reverseDir();
    short getPin();
    short getValue();
    int getRawValue();
    short getMin();
    short getMax();
    void calibrate();
};

#endif
/**
 * @file AnalongInput.cpp
 * @author Theodoros Temourtzidis (thodoristem@gmail.com)
 * @brief Lib for controling analog inputs
 * @version 1.0
 * @date 2024-02-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <Arduino.h>
#include <AnalogInput.h>

AnalogInput::AnalogInput(byte pin, short deadZone)
{
    this->pin = pin;
    this->deadZone = deadZone;
    this->doCal = true;
}

AnalogInput::AnalogInput(byte pin, short deadZone, short min, short max)
{
    this->pin = pin;
    this->deadZone = deadZone;
    this->min = min;
    this->max = max;
}

void AnalogInput::begin()
{
    pinMode(this->pin, INPUT);
}

void AnalogInput::reverseDir()
{
    this->reverse = !this->reverse;
}

void AnalogInput::calibrate()
{
    if (this->raw > this->max)
    {
        this->max = this->raw;
    }

    if (this->raw < this->min)
    {
        this->min = this->raw;
    }
}

short AnalogInput::getPin()
{
    return this->pin;
}

short AnalogInput::getValue()
{
    this->raw = this->getRawValue();

    if (this->doCal)
    {
        calibrate();
    }

    if (this->reverse)
    {
        return map(this->raw, (this->min + this->deadZone), (this->max - this->deadZone), 1023, 0);
    }

    return map(this->raw, (this->min + this->deadZone), (this->max - this->deadZone), 0, 1023);
}

int AnalogInput::getRawValue()
{
    return analogRead(this->pin);
}

short AnalogInput::getMin()
{
    return this->min;
}

short AnalogInput::getMax()
{
    return this->max;
}
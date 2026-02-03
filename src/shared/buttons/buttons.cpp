#include "buttons.hpp"
buttonsClass buttons;
bool buttonsClass::BTN0_Pressed = false;
bool buttonsClass::BTN1_Pressed = false;
bool buttonsClass::BTN2_Pressed = false;
void ARDUINO_ISR_ATTR buttonsClass::buttonConfirmISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                          // 50 ms = good starting value
        BTN1_Pressed = true;   // only register if enough time passed
        lastConfirmTime = now; // update timestamp
    }
}

void ARDUINO_ISR_ATTR buttonsClass::buttonUpISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    { // 50 ms = good starting value
        BTN2_Pressed = true;
        ;                      // only register if enough time passed
        lastConfirmTime = now; // update timestamp
    }
}

void ARDUINO_ISR_ATTR buttonsClass::buttonDownISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                          // 50 ms = good starting value
        BTN0_Pressed = true;   // only register if enough time passed
        lastConfirmTime = now; // update timestamp
    }
}

bool buttonsClass::init()
{
    try
    {
        pinMode(0, INPUT_PULLUP);
        pinMode(1, INPUT_PULLUP);
        pinMode(2, INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(BTN_DOWN_PIN), buttonDownISR, FALLING);
        attachInterrupt(digitalPinToInterrupt(BTN_CONFIRM_PIN), buttonConfirmISR, FALLING);
        attachInterrupt(digitalPinToInterrupt(BTN_UP_PIN), buttonUpISR, FALLING);
        return true;
    }
    catch (int e)
    {
        return false;
    }
}

bool buttonsClass::checkBtnPress(int b)
{
    switch (b)
    {
    case 0:
        if (BTN0_Pressed)
        {
            BTN0_Pressed = false;
            return true;
        }

    case 1:
        if (BTN1_Pressed)
        {
            BTN1_Pressed = false;
            return true;
        }
    case 2:
        if (BTN2_Pressed)
        {
            BTN2_Pressed = false;
            return true;
        }

    default:
        return false;
    }
}

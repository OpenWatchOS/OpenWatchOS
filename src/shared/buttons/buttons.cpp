#include "buttons.hpp"
std::vector<uint8_t> buttonsClass::pressRegistry;
void ARDUINO_ISR_ATTR buttonsClass::buttonConfirmISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                                   // 50 ms = good starting value
        pressRegistry.push_back(BTN_1); // only register if enough time passed
        lastConfirmTime = now;          // update timestamp
    }
}

void ARDUINO_ISR_ATTR buttonsClass::buttonUpISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                                   // 50 ms = good starting value
        pressRegistry.push_back(BTN_2); // only register if enough time passed
        lastConfirmTime = now;          // update timestamp
    }
}

void ARDUINO_ISR_ATTR buttonsClass::buttonDownISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                                   // 50 ms = good starting value
        pressRegistry.push_back(BTN_0); // only register if enough time passed
        lastConfirmTime = now;          // update timestamp
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
    if (pressRegistry.empty())
    {
        return false; // or whatever makes sense for "no press"
    }
    else
    {
        Debug.print(String(pressRegistry.at(0)));
        pressRegistry.erase(pressRegistry.begin());
        return true;
    }
}

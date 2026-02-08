#include "buttons.hpp"
#include <functional>
buttonsClass buttons;
std::function<int(void)> funcs[10];
void ARDUINO_ISR_ATTR buttonsClass::buttonConfirmISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                          // 50 ms = good starting value 
        lastConfirmTime = now; // update timestamp
    }
}

void ARDUINO_ISR_ATTR buttonsClass::buttonUpISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    { // 50 ms = good starting value
        ;                      // only register if enough time passed
        lastConfirmTime = now; // update timestamp
    }
}

void ARDUINO_ISR_ATTR buttonsClass::buttonDownISR()
{
    static unsigned long lastConfirmTime = 0; // static = keeps value between calls
    unsigned long now = millis();             // safe to call in ESP32 ISR

    if (now - lastConfirmTime >= 50)
    {                          // 50 ms = good starting value  // only register if enough time passed
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
        attachInterrupt(BTN_DOWN_PIN, buttonDownISR, FALLING);
        attachInterrupt(BTN_CONFIRM_PIN, buttonConfirmISR, FALLING);
        attachInterrupt(BTN_UP_PIN, buttonUpISR, FALLING);
        return true;
    }
    catch (int e)
    {
        return false;
    }
}

int buttonsClass::installBtnPressHandler(int (*func)(void))
{
    const int count = sizeof(funcs) / sizeof(funcs[0]);

    for (int i = 0; i < count; i++) {
        if (!funcs[i]) {
            funcs[i] = func;
            return i;
        }
    }
    return -1;
}

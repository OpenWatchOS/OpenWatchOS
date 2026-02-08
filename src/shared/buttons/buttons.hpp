#include <Arduino.h>
#include <vector>
#include "shared/debug/debug.hpp"
#include "iostream"
#define BTN_DOWN_PIN 0
#define BTN_CONFIRM_PIN 1
#define BTN_UP_PIN 2
class buttonsClass
{
public:
    enum buttons
    {
        BTN_0,
        BTN_1,
        BTN_2,
        BTN_3
    };
    bool init();
    int installBtnPressHandler(int (*func)(void));

private:
    static void ARDUINO_ISR_ATTR buttonConfirmISR();
    static void ARDUINO_ISR_ATTR buttonUpISR();
    static void ARDUINO_ISR_ATTR buttonDownISR();
};
extern buttonsClass buttons;
#include "debug.hpp"
debug Debug;
debug::debug()
{
    Serial.begin(9600);
}
void debug::print(String in)
{
    Serial.println(in);
    if(displayVerbose){
        display_log(in);
    }
}
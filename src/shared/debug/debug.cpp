#include "debug.hpp"
debug Debug(true);
debug::debug(bool verbose = true) : displayVerbose(verbose)
{
    Serial.begin(9600);
}
void debug::print(String in)
{
    Serial.println(in);

}
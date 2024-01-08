#include <Arduino.h>
#include "debug.h"

void xtouch_debug_json(const JsonDocument &doc)
{
#if XTOUCH_DEBUG_DEBUG == true
    String output;
    serializeJsonPretty(doc, output);
    // ConsoleDebug(output.c_str());
#endif
}
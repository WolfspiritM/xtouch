#ifndef _XLCD_DEBUG
#define _XLCD_DEBUG

#define XTOUCH_DEBUG_INFO true
#define XTOUCH_DEBUG_DEBUG true
#define XTOUCH_DEBUG_ERROR XTOUCH_DEBUG_INFO || XTOUCH_DEBUG_DEBUG

#define ConsoleInfo(tag, format, ...)                                               \
    if (XTOUCH_DEBUG_INFO || XTOUCH_DEBUG_DEBUG || XTOUCH_DEBUG_ERROR) \
    ESP_LOG_LEVEL(ESP_LOG_INFO, tag, format, ##__VA_ARGS__)
#define ConsoleDebug(tag, format, ...)                         \
    if (XTOUCH_DEBUG_DEBUG || XTOUCH_DEBUG_ERROR) \
    ESP_LOG_LEVEL(ESP_LOG_DEBUG, tag, format, ##__VA_ARGS__)
#define ConsoleWarning(tag, format, ...)                         \
    if (XTOUCH_DEBUG_DEBUG || XTOUCH_DEBUG_ERROR) \
    ESP_LOG_LEVEL(ESP_LOG_WARN, tag, format, ##__VA_ARGS__)
#define ConsoleError(tag, format, ...)   \
    if (XTOUCH_DEBUG_ERROR) \
    ESP_LOG_LEVEL(ESP_LOG_ERROR, tag, format, ##__VA_ARGS__)

#define ConsoleInfoPrintf ConsoleInfo
#define ConsoleDebugPrintf ConsoleDebug
#define ConsoleErrorPrintf ConsoleError


#ifdef __cplusplus
#include <ArduinoJson.h>
void xtouch_debug_json(const JsonDocument &doc);
#endif

#endif

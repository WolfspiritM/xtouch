#ifndef _XLCD_FTPS
#define _XLCD_FTPS

#include <WiFiClientSecure.h>
#include "../ESP32_FTPClient.h"

void xtouch_ftps_connect(String address, int port, String user, String pass)
{
    ESP32_FTPClient ftp (address.c_str(), port, user,pass, 10000, 2);
    ftp.OpenConnection();
    if(ftp.isConnected())
    {
        Serial.println("Connected");
        String list[128];
        ftp.InitFile("Type A");
        ftp.ContentListWithListCommand("model/", list);
        ftp.CloseFile();

        String combined = "";

        for( uint8_t i = 0; i < (sizeof(list) / sizeof(String)); i++)
        {
            uint8_t indexSize = 0;
            uint8_t indexMod  = 0;
            Serial.println(list[i]);
            if(list[i].length() > 0)
            {
                String firstChar = list[i].substring(0, 1);
                String fileName = list[i].substring(48);
                fileName.trim();
                fileName.replace("\r", "");
                fileName.replace("\n", "");
                if(firstChar == "d")
                {
                    // Directory
                    combined += LV_SYMBOL_DIRECTORY " ./"+ fileName + "/\n";
                }
                else
                {
                    // File
                    combined += LV_SYMBOL_FILE " ./"+fileName + "\n";
                }
            }            
        }

        combined.remove(combined.length() - 1);

        lv_roller_set_options(ui_sdcardScreenRoller, combined.c_str(), LV_ROLLER_MODE_NORMAL);
    }
    else
    {
        Serial.println("Not connected");
    }
    ftp.CloseConnection();
}

#endif
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <switch.h>


int main(int argc, char **argv)
{
    consoleInit(NULL);

   

    // Main loop
    while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu

         printf("\x1b[16;16HHello Switch~        Press PLUS to exit.");

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}

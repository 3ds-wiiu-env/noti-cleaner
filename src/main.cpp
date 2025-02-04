#include <iostream>
#include <fstream>
#include <3ds.h>

int main() {
    // Initialize services
    gfxInitDefault();
    consoleInit(GFX_TOP, nullptr);
    
    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        
        // Exit on START button press
        if (kDown & KEY_START) {
            break;
        }
        
        // Clear notifications logic will go here
        
        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }
    
    gfxExit();
    return 0;
}
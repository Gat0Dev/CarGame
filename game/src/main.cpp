#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions
#include <iostream>
#include <main.h>
#include <string.h>

int main(void)
{
    //Inicializacion de ventana (OpenGL).
    int WindowWidth = 960;
    int WindowHeigh = 540;
    InitWindow(WindowWidth, WindowHeigh, "Car Game");

    //Creacion de FlipBook para el background y Rectangles para posicionar Flipbook.
    FlipBook FB_StartBackGround("resources/SpriteSheets/BackGround/StartBackgroundSheet.png", 0, 0, WHITE, 42);
    //Rapido y mal, ya me creare si lo veo necesario un sistema que analice un archivo de texto con estos datos.
    *FB_StartBackGround.SheetRec[0] = {600, 0, 600, 338 };
    *FB_StartBackGround.SheetRec[1] = {1200, 0, 600, 338 };
    *FB_StartBackGround.SheetRec[2] = {1800, 0, 600, 338 };
    *FB_StartBackGround.SheetRec[3] = {0, 338, 600, 338 };
    *FB_StartBackGround.SheetRec[4] = {600, 338, 600, 338 };
    *FB_StartBackGround.SheetRec[5] = {1200, 338, 600, 338 };
    *FB_StartBackGround.SheetRec[6] = {1800, 338, 600, 338 };
    *FB_StartBackGround.SheetRec[7] = {0, 676, 600, 338 };
    *FB_StartBackGround.SheetRec[8] = {600, 676, 600, 338 };
    *FB_StartBackGround.SheetRec[9] = {1200, 676, 600, 338 };
    *FB_StartBackGround.SheetRec[10] = {1800, 676, 600, 338 };
    *FB_StartBackGround.SheetRec[11] = {0, 1014, 600, 338 };
    *FB_StartBackGround.SheetRec[12] = {600, 1014, 600, 338 };
    *FB_StartBackGround.SheetRec[13] = {1200, 1014, 600, 338 };
    *FB_StartBackGround.SheetRec[14] = {1800, 1014, 600, 338 };
    *FB_StartBackGround.SheetRec[15] = {0, 1352, 600, 338 };
    *FB_StartBackGround.SheetRec[16] = {600, 1352, 600, 338 };
    *FB_StartBackGround.SheetRec[17] = {1200, 1352, 600, 338 };
    *FB_StartBackGround.SheetRec[18] = {1800, 1352, 600, 338 };
    *FB_StartBackGround.SheetRec[19] = {0, 1690, 600, 338 };
    *FB_StartBackGround.SheetRec[20] = {600, 1690, 600, 338 };
    *FB_StartBackGround.SheetRec[21] = {1200, 1690, 600, 338 };
    *FB_StartBackGround.SheetRec[22] = {1800, 1690, 600, 338 };
    *FB_StartBackGround.SheetRec[23] = {0, 2028, 600, 338 };
    *FB_StartBackGround.SheetRec[24] = {600, 2028, 600, 338 };
    *FB_StartBackGround.SheetRec[25] = {1200, 2028, 600, 338 };
    *FB_StartBackGround.SheetRec[26] = {1200, 2028, 600, 338 };
    *FB_StartBackGround.SheetRec[27] = {1800, 2028, 600, 338 };
    *FB_StartBackGround.SheetRec[28] = {0, 2366, 600, 338 };
    *FB_StartBackGround.SheetRec[29] = {600, 2366, 600, 338 };
    *FB_StartBackGround.SheetRec[30] = {1200, 2366, 600, 338 };
    *FB_StartBackGround.SheetRec[31] = {1800, 2366, 600, 338 };
    *FB_StartBackGround.SheetRec[32] = {2400, 0, 600, 338 };
    *FB_StartBackGround.SheetRec[33] = {2400, 338, 600, 338 };
    *FB_StartBackGround.SheetRec[34] = {2400, 338, 600, 338 };
    *FB_StartBackGround.SheetRec[35] = {2400, 676, 600, 338 };
    *FB_StartBackGround.SheetRec[36] = {2400, 1014, 600, 338 };
    *FB_StartBackGround.SheetRec[37] = {2400, 1352, 600, 338 };
    *FB_StartBackGround.SheetRec[38] = {2400, 1690, 600, 338 };
    *FB_StartBackGround.SheetRec[39] = {2400, 2028, 600, 338 };
    *FB_StartBackGround.SheetRec[40] = {2400, 2366, 600, 338 };
    *FB_StartBackGround.SheetRec[41] = {0, 2704, 600, 338 };
    FB_StartBackGround.FlipBookPosition = { 0.0, 0.0, (float)WindowWidth, (float)WindowHeigh};
    
    //Game Bucle:
    bool globalRunning = true;
    SetTargetFPS(165);
    while (globalRunning)
    {    
        
        BeginDrawing();
        
        FB_StartBackGround.PlayFlipBook(0.05, 0.0, FB_StartBackGround.TotalSprites);     

        DrawFPS(850, 20);
        EndDrawing();
        ClearBackground(BLACK);

        //Verificar si se debe cerrar la ventana al pulsar ESC o la X.
        if (WindowShouldClose()) {
            globalRunning = false;
            CloseWindow();
        };
    };

    return 0;
};

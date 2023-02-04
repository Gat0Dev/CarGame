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
    FlipBook FB_StartBackGround("resources/SpriteSheets/BackGround/StartBackgroundSheet.png", 0, 0, WHITE);
    const short BackGroundSpriteLong = 43;
    //Rapido y mal, ya me creare si lo veo necesario un sistema que analice un archivo de texto con estos datos.
    Rectangle BackGroundRec[BackGroundSpriteLong] = {
    {0, 0, 600, 338},
    {600, 0, 600, 338},
    {1200, 0, 600, 338},
    {1800, 0, 600, 338},
    {0, 338, 600, 338},
    {600, 338, 600, 338},
    {1200, 338, 600, 338},
    {1800, 338, 600, 338},
    {0, 676, 600, 338},
    {600, 676, 600, 338},
    {1200, 676, 600, 338},
    {1800, 676, 600, 338},
    {0, 1014, 600, 338},
    {600, 1014, 600, 338},
    {1200, 1014, 600, 338},
    {1800, 1014, 600, 338},
    {0, 1352, 600, 338},
    {600, 1352, 600, 338},
    {1200, 1352, 600, 338},
    {1800, 1352, 600, 338},
    {0, 1690, 600, 338},
    {600, 1690, 600, 338},
    {1200, 1690, 600, 338},
    {1800, 1690, 600, 338},
    {0, 2028, 600, 338},
    {600, 2028, 600, 338},
    {1200, 2028, 600, 338},
    {1200, 2028, 600, 338},
    {1800, 2028, 600, 338},
    {0, 2366, 600, 338},
    {600, 2366, 600, 338},
    {1200, 2366, 600, 338},
    {1800, 2366, 600, 338},
    {2400, 0, 600, 338},
    {2400, 338, 600, 338},
    {2400, 338, 600, 338},
    {2400, 676, 600, 338},
    {2400, 1014, 600, 338},
    {2400, 1352, 600, 338},
    {2400, 1690, 600, 338},
    {2400, 2028, 600, 338},
    {2400, 2366, 600, 338},
    {0, 2704, 600, 338}
    }; //Creacion de matriz que va ligada a la funcion "void PlayFlipBook" que asigna los puntos de la textura (Falta asignarlos)
    Rectangle BackgroundRecPos = {0.0, 0.0, WindowWidth, WindowHeigh}; 
    
    //Game Bucle:
    bool globalRunning = true;
    SetTargetFPS(165);
    while (globalRunning)
    {    
        
        BeginDrawing();
        
        FB_StartBackGround.PlayFlipBook(BackGroundRec, BackgroundRecPos, 0.05, 0.0, BackGroundSpriteLong);
        FB_StartBackGround.BackGroundRec[10]; //<--- TODO: INTENTAR METER LAS VARIABLES DE LAS QUE DEPENDE EL FLIPBOOK EN LA CLASE.

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

#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions
#include <iostream>
#include <main.h>
#include <string.h>

int main(void)
{
    int WindowWidth = 960;
    int WindowHeigh = 540;

    FlipBook FB_BackGround("resources/SpriteSheets/BackGround/testSheet.png", WindowWidth/2, WindowHeigh/2, 0.1f, WHITE);
    Rectangle BackGroundRec[2] = {
    {0.0, 0.0, 1152, 648},
    {0.0, 0.0, 1152, 648}
    }; //Creacion de matriz que va ligada a la funcion "void PlayFlipBook" que asigna los puntos de la textura (Falta asignarlos)
    
    bool globalRunning = true;
    SetTargetFPS(165);
    InitWindow(WindowWidth, WindowHeigh, "Car Game");
    while (globalRunning)
    {    
        
        BeginDrawing();
        DrawFPS(850,20);

        FB_BackGround.PlayFlipBook(BackGroundRec);

        EndDrawing();
        ClearBackground(BLACK);

        //Verificar si se debe cerrar la ventana al pulsar ESC o la X.
        if (WindowShouldClose()) {
            globalRunning = false;
            CloseWindow();
        };
    };

    FB_BackGround.PlayFlipBook(BackGroundRec);

    return 0;
}; 
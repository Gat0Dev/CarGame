#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions
#include <iostream>
#include <main.h>
#include <string.h>

int main(void)
{
    int WindowWidth = 960;
    int WindowHeigh = 540;
    InitWindow(WindowWidth, WindowHeigh, "Car Game");

    FlipBook FB_BackGround("resources/SpriteSheets/BackGround/testSheet.png", 0, 0, 0.01f, WHITE);
    Rectangle BackGroundRec[2] = {
    {0.0, 0.0, FB_BackGround.SpriteSheet.width, FB_BackGround.SpriteSheet.height},
    {0.0, FB_BackGround.SpriteSheet.width/2, FB_BackGround.SpriteSheet.width, FB_BackGround.SpriteSheet.height}
    }; //Creacion de matriz que va ligada a la funcion "void PlayFlipBook" que asigna los puntos de la textura (Falta asignarlos)
    
    bool globalRunning = true;
    SetTargetFPS(165);
    while (globalRunning)
    {    
        
        BeginDrawing();
        
        FB_BackGround.PlayFlipBook(BackGroundRec);

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
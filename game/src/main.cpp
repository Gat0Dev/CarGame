#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions
#include <iostream>
#include <string.h>

#include <main.h>

bool globalRunning = true; //Variable tratada como global para acceder al cierre desde cualquier parte del programa.

int main(void)
{
    //Inicializacion de ventana (Y OpenGL).
    int WindowWidth = 960;
    int WindowHeigh = 540;
    InitWindow(WindowWidth, WindowHeigh, "Car Game");
    InitAudioDevice();

    /////////////////////START STATE///////////////////////
    // 
    //CARGA DE FLIPBOOKS:
    //Creacion de FlipBook para el background y Rectangles para posicionar Flipbook.
    C_FlipBook FB_StartBackGround("resources/SpriteSheets/BackGround/StartBackgroundSheet.png", DARKBROWN, 42);
    //COMENTARIO AL PROFESOR: Lei de un archivo txt que puedo meter todas las coordenadas y luego leerlas en C++ para no hacer todo esto pero al ser pocos Sprites y tener el tiempo ajustado no lo he hecho.
    *FB_StartBackGround.SheetRec[0] = {600, 0, 600, 338};
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
    FB_StartBackGround.Transform = { 0.0, 0.0, (float)WindowWidth, (float)WindowHeigh};

    C_FlipBook FB_StartControls("resources/SpriteSheets/BackGround/controls.png", WHITE, 1);
    *FB_StartControls.SheetRec[0] = {0, 0, (float)FB_StartControls.SpriteSheet.width,(float)FB_StartControls.SpriteSheet.height};
    FB_StartControls.Transform = {-100, 250, (float)WindowWidth - 450, (float)WindowHeigh - 220 };

    C_FlipBook FB_StartPlayStart("resources/SpriteSheets/BackGround/playStartSheet.png", WHITE, 6);
    for (int i = 0; i < FB_StartPlayStart.TotalSprites; i++)
    {
        *FB_StartPlayStart.SheetRec[i] = { (600 * (float)i), 0, 600, 400 };
    };
    FB_StartPlayStart.Transform = { 190, 0, 600,300 };

    //CARGA DE SONIDO:
    Sound StartThemeSound = LoadSound("resources/Sounds/Start/themeSong.wav");

    /////////////////////INGAME STATE///////////////////////
    //CARGA DE FLIPBOOKS:
    C_FlipBook FB_InGameBackground("resources/SpriteSheets/Race/raceSheet.png", WHITE, 4);
    for (int i = 0; i < FB_InGameBackground.TotalSprites; i++)
    {
        *FB_InGameBackground.SheetRec[i] = { (320 * (float)i), 0, 320, 200};
    };
    FB_InGameBackground.Transform = { 0, 0, (float)WindowWidth, (float)WindowHeigh };
    //Trees:
    //TO-DO: Buscar como crear un arreglo de varios arboles para no crearlos uno por uno.
    //IDEAS: Crear funciones, usar bucles, usar arrays o matrices, crear un spawner general.
    //C_FlipBook FB_InGameTree[3]("resources/SpriteSheets/Race/tree.png", WHITE, 1);
    //for (int i = 0; i < 3; i++)
    //{
    //    
    //    *FB_InGameTree.SheetRec[0] = { 0, 0, 32,23 };
    //    FB_InGameTree.Transform = { 70,10,42,33 };
    //};
    C_FlipBook FB_InGameTree("resources/SpriteSheets/Race/tree.png", WHITE, 1);
    *FB_InGameTree.SheetRec[0] = { 0, 0, 32,23 };
    FB_InGameTree.Transform = { 70,10,42,33 };
    //Game Bucle:
    E_GamePlayState GamePlayState = Start;
    HideCursor();
    SetTargetFPS(165);

    while (globalRunning)
    {    
        
        BeginDrawing();

        switch (GamePlayState)
        {
        case Start:
            if (!IsSoundPlaying(StartThemeSound)) {
                PlaySound(StartThemeSound);
            };
                FB_StartBackGround.Play(0.04, 0.0, false);
                FB_StartControls.Play(0, 0.0, false);
                FB_StartPlayStart.Play(0.1, 0, false);
                if (GetKeyPressed() || IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
                    GamePlayState = InGame;
                    StopSound(StartThemeSound);
                };
            break;
        case InGame:
                FB_InGameBackground.Play(0.1, 0, false);

                FB_InGameTree.Play(0, 0, false);
                FB_InGameTree.Play(0, 0, false);
                FB_InGameTree.MoveTo(0, 40, 0.12);
                FB_InGameTree.ClampPos(0, 500, 70, 10, 70, 0);


            break;
        case Dead:
            break;
        };
     
        /*DrawFPS(850, 20);*/
        EndDrawing();
        ClearBackground(BLACK);

        //Esto verifica si se debe cerrar la ventana al pulsar ESC o la X.
        if (WindowShouldClose()) {
            globalRunning = false;
            CloseWindow();
        };
    };

    return 0;
};

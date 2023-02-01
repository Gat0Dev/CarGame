#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions
#include <iostream>
#include <main.h>

int main(void)
{
    FlipBook F1(2);
    *F1.Sprites[0] = LoadTexture("Esto es un test. Cargar textura aqui."); //Se desreferencia el puntero para poder acceder al contenido.
    *F1.Sprites[1] = LoadTexture("Esto es un test. Cargar textura aqui.");
    system("pause");
    return 0;
}; 
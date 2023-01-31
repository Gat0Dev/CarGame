//Room Main
//
//int main(void)
//{
//    int widhtRes = 800;
//    int heighRes = 400;
//    InitWindow(widhtRes, heighRes, "Sprite Game");
//    SetTargetFPS(165);
//    bool globalRunning = true;
//
//
//    //Textures
//    Texture2D Cloud = LoadTexture("resources/cloud.png");
//    Texture2D SkyBG = LoadTexture("resources/skyBG.png");
//
//    //ButtonFlipBookToRedAnimation
//    int const totalFrames = 8;
//    Texture2D buttonFlipBookToRed[totalFrames];
//    buttonFlipBookToRed[0] = LoadTexture("resources/Switch/switch1.png");
//    buttonFlipBookToRed[1] = LoadTexture("resources/Switch/switch2.png");
//    buttonFlipBookToRed[2] = LoadTexture("resources/Switch/switch3.png");
//    buttonFlipBookToRed[3] = LoadTexture("resources/Switch/switch4.png");
//    buttonFlipBookToRed[4] = LoadTexture("resources/Switch/switch5.png");
//    buttonFlipBookToRed[5] = LoadTexture("resources/Switch/switch6.png");
//    buttonFlipBookToRed[6] = LoadTexture("resources/Switch/switch7.png");
//    buttonFlipBookToRed[7] = LoadTexture("resources/Switch/switch8.png");
//
//    //FlipBook Variables
//    int frameDuration = 12;
//    int currentFrame = 0;
//    int timer = 0;
//    int flipBookState = 0;
//    Vector2 FlipBookPos = { 10.0f, 10.0f };
//
//    //Running
//    while (globalRunning)
//    {
//        if (WindowShouldClose()) {globalRunning = false;};
//        BeginDrawing();
//        ClearBackground(BLACK);
//
//
//        //Background draw
//        DrawTexture(SkyBG, 0, 0, WHITE);
//        DrawTexture(Cloud, 10, 5, WHITE);
//        DrawTexture(Cloud, 160, 70, WHITE);
//        DrawTexture(Cloud, 360, 5, WHITE);
//        DrawTexture(Cloud, 550, 70, WHITE);
//
//        //Room Information
//        DrawText("EXTERIOR", widhtRes / 2 - 180, heighRes / 2 - 70, 60, WHITE);
//        DrawText("Zona principal. El inicio de todo.", widhtRes / 2-250, heighRes / 2, 30, BLACK);
//
//        //Room Options
//        DrawText("Entrar al edificio por la puerta.", 20, heighRes / 2+100, 20, DARKBLUE);
//        DrawText("Entrar al edificio por la ventana.", 20, heighRes / 2+70, 20, DARKBLUE);
//        DrawText("Explorar exterior del edificio.", 20, heighRes / 2+130, 20, DARKBLUE);
//        
//        //Draw FPS
//        DrawFPS(700, 20);
//        
//        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
//                flipBookState = 1;
//        };
//
//
//        
//        //FlipBook
//
//        timer++;
//        switch (flipBookState)
//        {
//            case 0:
//                DrawTextureEx(buttonFlipBookToRed[0], FlipBookPos, 0, 2, WHITE);
//            break;
//            case 1:
//                if (timer >= frameDuration) {
//                    currentFrame++;
//                    timer = 0;
//                }
//                DrawTextureEx(buttonFlipBookToRed[currentFrame], FlipBookPos, 0, 2, WHITE);
//
//                if (currentFrame == 7) {
//                    flipBookState = 2;
//                } break;
//            case 2:
//                DrawTextureEx(buttonFlipBookToRed[7], FlipBookPos, 0, 2, WHITE);
//                break;
//        default:
//            break;
//        }
//
//
//        EndDrawing();
//
//    }
//    CloseWindow();
//
//    return 0;
//}
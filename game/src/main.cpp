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
	 
	//CARGA DE FLIPBOOKS:
	//Creacion de FlipBook para el background y Rectangles para posicionar Flipbook.
	C_FlipBook FB_StartBackGround("resources/SpriteSheets/BackGround/StartBackgroundSheet.png", DARKBROWN, 42);
	//COMENTARIO AL PROFESOR: Lei de un archivo txt que puedo meter todas las coordenadas y luego leerlas en C++ para no hacer todo esto pero al ser pocos Sprites y tener el tiempo ajustado no lo he hecho.
	*FB_StartBackGround.SheetRec[0] = { 600, 0, 600, 338 };
	*FB_StartBackGround.SheetRec[1] = { 1200, 0, 600, 338 };
	*FB_StartBackGround.SheetRec[2] = { 1800, 0, 600, 338 };
	*FB_StartBackGround.SheetRec[3] = { 0, 338, 600, 338 };
	*FB_StartBackGround.SheetRec[4] = { 600, 338, 600, 338 };
	*FB_StartBackGround.SheetRec[5] = { 1200, 338, 600, 338 };
	*FB_StartBackGround.SheetRec[6] = { 1800, 338, 600, 338 };
	*FB_StartBackGround.SheetRec[7] = { 0, 676, 600, 338 };
	*FB_StartBackGround.SheetRec[8] = { 600, 676, 600, 338 };
	*FB_StartBackGround.SheetRec[9] = { 1200, 676, 600, 338 };
	*FB_StartBackGround.SheetRec[10] = { 1800, 676, 600, 338 };
	*FB_StartBackGround.SheetRec[11] = { 0, 1014, 600, 338 };
	*FB_StartBackGround.SheetRec[12] = { 600, 1014, 600, 338 };
	*FB_StartBackGround.SheetRec[13] = { 1200, 1014, 600, 338 };
	*FB_StartBackGround.SheetRec[14] = { 1800, 1014, 600, 338 };
	*FB_StartBackGround.SheetRec[15] = { 0, 1352, 600, 338 };
	*FB_StartBackGround.SheetRec[16] = { 600, 1352, 600, 338 };
	*FB_StartBackGround.SheetRec[17] = { 1200, 1352, 600, 338 };
	*FB_StartBackGround.SheetRec[18] = { 1800, 1352, 600, 338 };
	*FB_StartBackGround.SheetRec[19] = { 0, 1690, 600, 338 };
	*FB_StartBackGround.SheetRec[20] = { 600, 1690, 600, 338 };
	*FB_StartBackGround.SheetRec[21] = { 1200, 1690, 600, 338 };
	*FB_StartBackGround.SheetRec[22] = { 1800, 1690, 600, 338 };
	*FB_StartBackGround.SheetRec[23] = { 0, 2028, 600, 338 };
	*FB_StartBackGround.SheetRec[24] = { 600, 2028, 600, 338 };
	*FB_StartBackGround.SheetRec[25] = { 1200, 2028, 600, 338 };
	*FB_StartBackGround.SheetRec[26] = { 1200, 2028, 600, 338 };
	*FB_StartBackGround.SheetRec[27] = { 1800, 2028, 600, 338 };
	*FB_StartBackGround.SheetRec[28] = { 0, 2366, 600, 338 };
	*FB_StartBackGround.SheetRec[29] = { 600, 2366, 600, 338 };
	*FB_StartBackGround.SheetRec[30] = { 1200, 2366, 600, 338 };
	*FB_StartBackGround.SheetRec[31] = { 1800, 2366, 600, 338 };
	*FB_StartBackGround.SheetRec[32] = { 2400, 0, 600, 338 };
	*FB_StartBackGround.SheetRec[33] = { 2400, 338, 600, 338 };
	*FB_StartBackGround.SheetRec[34] = { 2400, 338, 600, 338 };
	*FB_StartBackGround.SheetRec[35] = { 2400, 676, 600, 338 };
	*FB_StartBackGround.SheetRec[36] = { 2400, 1014, 600, 338 };
	*FB_StartBackGround.SheetRec[37] = { 2400, 1352, 600, 338 };
	*FB_StartBackGround.SheetRec[38] = { 2400, 1690, 600, 338 };
	*FB_StartBackGround.SheetRec[39] = { 2400, 2028, 600, 338 };
	*FB_StartBackGround.SheetRec[40] = { 2400, 2366, 600, 338 };
	*FB_StartBackGround.SheetRec[41] = { 0, 2704, 600, 338 };
	FB_StartBackGround.Transform = { 0.0, 0.0, (float)WindowWidth, (float)WindowHeigh }; //Posicionamiento del Flipbook.

	//Creacion de FlipBook para controles.
	C_FlipBook FB_StartControls("resources/SpriteSheets/BackGround/controls.png", WHITE, 1);
	*FB_StartControls.SheetRec[0] = { 0, 0, (float)FB_StartControls.SpriteSheet.width,(float)FB_StartControls.SpriteSheet.height };
	FB_StartControls.Transform = { -100, 250, (float)WindowWidth - 450, (float)WindowHeigh - 220 };

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
		*FB_InGameBackground.SheetRec[i] = { (320 * (float)i), 0, 320, 200 };
	};
	FB_InGameBackground.Transform = { 0, 0, (float)WindowWidth, (float)WindowHeigh };

	//Trees:
	//TO-DO: Si usas la desviacion de los árboles con la Y hacia arriba, spawnearan con una Y diferente y no se notará porque estará por fuera.
	//Cambiar además la barra de gasolina por una de progreso que vaya acordé a la puntuación final. Por lo cual el juego tendrá WIN.
	const short TotalLTrees = 5;
	short LeftTreesStartPos = 70;
	C_FlipBook* LTrees = new C_FlipBook[TotalLTrees]{
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	};
	for (int i = 0; i < TotalLTrees; i++)
	{
		LTrees[i].SheetRec[0]->x = 0;
		LTrees[i].SheetRec[0]->y = 0;
		LTrees[i].SheetRec[0]->width = 32;
		LTrees[i].SheetRec[0]->height = 23;
		LTrees[i].Transform.x = LeftTreesStartPos + GetRandomValue(70 * -1, 70);
		LTrees[i].Transform.y = GetRandomValue(0 * -1, 500);
		LTrees[i].Transform.width = 42;
		LTrees[i].Transform.height = 33;
	};

	const short TotalRTrees = 5;
	short RightTreesStartPos = 660;
	C_FlipBook* RTrees = new C_FlipBook[TotalRTrees]{
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	C_FlipBook("resources/SpriteSheets/Race/tree.png", WHITE, 1),
	};
	for (int i = 0; i < TotalRTrees; i++)
	{
		RTrees[i].SheetRec[0]->x = 0;
		RTrees[i].SheetRec[0]->y = 0;
		RTrees[i].SheetRec[0]->width = 32;
		RTrees[i].SheetRec[0]->height = 23;
		RTrees[i].Transform.x = RightTreesStartPos + GetRandomValue(70 * -1, 70);
		RTrees[i].Transform.y = GetRandomValue(0 * -1, 500);
		RTrees[i].Transform.width = 42;
		RTrees[i].Transform.height = 33;
	};

	//Player Vehicle:
	C_Vehicle RedCar("resources/SpriteSheets/Race/redCarSheet.png", 1);
	*RedCar.Vehicle.SheetRec[0] = { 5,5,28,54 };

	RedCar.Vehicle.Transform.x = WindowWidth / 2 - 113;
	RedCar.Vehicle.Transform.y = 390;
	RedCar.Vehicle.Transform.width = 42;
	RedCar.Vehicle.Transform.height = 81;

	//Static Enemy Vehicle:
	C_Enemy_Vehicle EnemyCars("resources/SpriteSheets/Race/yellowCar.png", 1, 10);

	//USER INTERFACE:
	//Health:
	C_FlipBook Health("resources/SpriteSheets/Race/health.png", WHITE, 1);
	*Health.SheetRec[0] = { 161,5,42,18 };
	Health.Transform.x = 798;
	Health.Transform.y = 190;
	Health.Transform.width = 126;
	Health.Transform.height = 54;

	//Progress Bar:
	C_FlipBook ProgressBar("resources/SpriteSheets/Race/progressBar.png", WHITE, 1);
	*ProgressBar.SheetRec[0] = { 5,5,59,18 };
	ProgressBar.Transform.x = 774;
	ProgressBar.Transform.y = 114;
	ProgressBar.Transform.width = 177;
	ProgressBar.Transform.height = 54 ;
	ProgressSystem PS;
	


	//Game Bucle:
	bool RestartVariables = false;
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
			//Gestion de reinicio del juego.
			if (RestartVariables) {
				RestartVariables = false;
				PS.GameCompleted = false;
				PS.Timer = 0;
				PS.Score = 0;
				RedCar.HP = 3;
				*Health.SheetRec[0] = { 161,5,42,18 };
				RedCar.Vehicle.Transform.x = WindowWidth / 2 - 113;
				RedCar.Vehicle.Transform.y = 390;
				RedCar.HPLock = false;
				RedCar.CanAnimDead = false;
				RedCar.AnimTimer = 0.0f;
				for (int i = 0; i < EnemyCars.TotalEnemysStatic - 1; i++)
				{
					delete EnemyCars.StaticVehicles[i];
					
				}
				for (int i = 0; i < EnemyCars.TotalEnemysMovable - 1; i++)
				{
					delete EnemyCars.MovableVehicles[i];
					
				}
				EnemyCars.TotalEnemysStatic = 0;
				EnemyCars.TotalEnemysMovable = 0;
			}
			break;

			//EJECUCION ESTADO InGAME:
		case InGame:

			FB_InGameBackground.Play(0.1, 0, false);

			for (int i = 0; i < TotalLTrees; i++)
			{
				LTrees[i].Play(0, 0, false);
				LTrees[i].MoveTo(0, 40, 0.12);
				LTrees[i].ClampPos(0, 500, 70, 10, 70, 0);
			}

			for (int i = 0; i < TotalRTrees; i++)
			{
				RTrees[i].Play(0, 0, false);
				RTrees[i].MoveTo(0, 40, 0.12);
				RTrees[i].ClampPos(0, 500, RightTreesStartPos, 10, 70, 0);
			}
			RedCar.Vehicle.Play(0, 0, false);

			//Car Movement:

			if (IsKeyDown(KEY_W)) {
				RedCar.Vehicle.MoveTo(0, -4, 0.01);
			}
			else if (IsKeyDown(KEY_S)) {
				RedCar.Vehicle.MoveTo(0, 4, 0.01);
			}
			else if (IsKeyDown(KEY_A)) {
				RedCar.Vehicle.MoveTo(-4, 0, 0.01);
			}
			else if (IsKeyDown(KEY_D)) {
				RedCar.Vehicle.MoveTo(4, 0, 0.01);
			}
			RedCar.RestrainToRoads();

			for (int i = EnemyCars.TotalEnemysStatic-1; i >= 0; i--) {

				EnemyCars.StaticVehicles[i]->Play(0, 0, false);
				EnemyCars.StaticVehicles[i]->MoveTo(0, 3, 0.01);
				EnemyCars.DeleteAtPos(0, 560, i, false);
				RedCar.CheckCollisions(EnemyCars.StaticVehicles[i]->Transform, Health);
			}

			for (int i = EnemyCars.TotalEnemysMovable - 1; i >= 0; i--) {

				EnemyCars.MovableVehicles[i]->Play(0, 0, false);
				EnemyCars.MovableVehicles[i]->MoveTo(EnemyCars.LeftRightAnim(EnemyCars.MovableVehicles[i]->Transform.x), 3, 0.01);
				EnemyCars.DeleteAtPos(0, 560, i, true);
				RedCar.CheckCollisions(EnemyCars.MovableVehicles[i]->Transform, Health);
			}
			EnemyCars.Spawn(GetRandomValue(200, 545), -100, 1, 2);
			RedCar.DeadAnimationManager();

			ProgressBar.Play(0, 0, false);
			PS.UpdateProgressBar(ProgressBar);
			PS.UpdateScore();
			if (PS.GameCompleted) {
				GamePlayState = Win;
			}

			Health.Play(0, 0, false);

			if (RedCar.HP == 0) {
				GamePlayState = Dead;
			}
			break;

			//EJECUCION ESTADO Win:
		case Win:
			DrawText("YOU WIN!", WindowWidth / 2 - 144, WindowHeigh / 2 - 150, 60, GREEN);
			DrawText("Score:", WindowWidth / 2 - 250, WindowHeigh / 2, 50, WHITE);
			DrawText(PS.ScoreCh, WindowWidth / 2 - 58, WindowHeigh / 2 + 2, 50, WHITE);
			DrawText("Press Space To Restart", WindowWidth / 2 - 250, WindowHeigh / 2 + 200, 40, WHITE);
			if (IsKeyPressed(KEY_SPACE)) {
				RestartVariables = true;
				GamePlayState = Start;
			}
			break;

			//EJECUCION ESTADO Dead:
		case Dead:
			DrawText("YOU ARE DEAD!", WindowWidth / 2-220, WindowHeigh / 2-150, 60, RED);
			DrawText("Score:", WindowWidth / 2 - 250, WindowHeigh / 2,50, WHITE);
			DrawText(PS.ScoreCh, WindowWidth / 2-58, WindowHeigh / 2+2, 50, WHITE);
			DrawText("Press Space To Restart", WindowWidth / 2-250, WindowHeigh / 2+200,40, WHITE);
			if (IsKeyPressed(KEY_SPACE)) {
				RestartVariables = true;
				GamePlayState = Start;
			}
			break;
		};
		DrawText("By: iDavidXx", 800, 500, 20, WHITE);
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

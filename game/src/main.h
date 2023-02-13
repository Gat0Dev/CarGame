#pragma once

class C_FlipBook
{
private:
	float AnimSecTimer;
	float MoveSecTimer;
	int CurrentFrame;
	Vector2 Position;
	Color SpritesColor;

public:
	Texture2D SpriteSheet;
	const short TotalSprites;
	Rectangle** SheetRec; //Puntero que almacena puntero el cual almacena punteros que almacenan las instancias de Rectangle.
	Rectangle Transform;

	C_FlipBook(char* TextureUrl, Color SpritesColor_, const short TotalSprites_) : TotalSprites(TotalSprites_) {
		MoveSecTimer = 0;
		SpriteSheet = LoadTexture(TextureUrl);

		Position.x = 0;
		Position.y = 0;

		CurrentFrame = 0;
		AnimSecTimer = 0.0f;

		SpritesColor = SpritesColor_;

		SheetRec = new Rectangle * [TotalSprites]; //Creacion de punteros de tipo Rectangle.
		for (int i = 0; i != TotalSprites; i++)
		{
			SheetRec[i] = new Rectangle; //Asignacion de instancias Rectangle a los punteros.
		};

	};
	~C_FlipBook() {
		UnloadTexture(SpriteSheet);


		for (int i = 0; i != TotalSprites; i++) //Eliminacion de memoria tanto los punteros de las instancias y del puntero principal.
		{
			delete SheetRec[i];
		};
		delete SheetRec;
	};
	void Play(float PlayRate, float Rotation, bool Debug) {
		AnimSecTimer += GetFrameTime();
		DrawTexturePro(SpriteSheet, *SheetRec[CurrentFrame], Transform, Position, Rotation, SpritesColor);
		if (AnimSecTimer > PlayRate) {
			CurrentFrame++;

			AnimSecTimer = 0.0f;
		};
		if (CurrentFrame == TotalSprites) {
			CurrentFrame = 0;
		};
		// v Display de FPS del FlipBook para debug. v
		if (Debug) {
			char DebugText[100];
			sprintf(DebugText, "%d", CurrentFrame);
			DrawText(DebugText, 0, 0, 20, RED);
		};
		// ^ Display de FPS del FlipBook para debug.^
	};

	void MoveTo(float AddX, float AddY, float MoveRate) {
		MoveSecTimer += GetFrameTime();
		if (MoveSecTimer > MoveRate) {
			Transform.x += AddX;
			Transform.y += AddY;

			MoveSecTimer = 0;
		}
	}

	void ClampPos(float MaxX, float MaxY, float MoveToX, float MoveToY, int XDesviation, int YDesviation) {
		if (MaxX != 0 && Transform.x > MaxX) {
			Transform.x = MoveToX;
			Transform.x += GetRandomValue(XDesviation * -1, XDesviation);
			Transform.y = MoveToY;
			Transform.y += GetRandomValue(YDesviation * -1, YDesviation);
		};
		if (MaxY != 0 && Transform.y > MaxY) {
			Transform.y = MoveToY;
			Transform.y += GetRandomValue(YDesviation * -1, YDesviation);
			Transform.x = MoveToX;
			Transform.x += GetRandomValue(XDesviation * -1, XDesviation);
		};
	};

};

class C_Enemy_Vehicle {
private:
	float StaticSpawnTimer;
	float MovableSpawnTimer;
	float LeftRightTimer;

	char* VehicleFlipBook;
	short FlipBookFrames;
	short SpawnProbability;
public:
	short TotalEnemysStatic = 0;
	short TotalEnemysMovable = 0;
	short MaxEnemys;
	C_FlipBook** StaticVehicles;
	C_FlipBook** MovableVehicles;
	C_Enemy_Vehicle(char* VehicleFlipBook_, int FlipBookFrames_, short MaxEnemys_) : VehicleFlipBook(VehicleFlipBook_), FlipBookFrames(FlipBookFrames_), MaxEnemys(MaxEnemys_) {
		StaticVehicles = new C_FlipBook * [MaxEnemys];
		MovableVehicles = new C_FlipBook * [MaxEnemys];

		StaticSpawnTimer = 0.0f;
		MovableSpawnTimer = 0.0f;
		LeftRightTimer = 0.0f;
	}
	void Spawn(short PosX, short PosY, float StaticTimeSpawn, float MovableTimeSpawn) {
		StaticSpawnTimer += GetFrameTime();
		MovableSpawnTimer += GetFrameTime();

		if (StaticSpawnTimer > StaticTimeSpawn) { //NOTA AL PROFE: Intente aleatorizar aqui pero me fue imposible. No me funcionaba el Random. {

			StaticVehicles[TotalEnemysStatic] = new C_FlipBook("resources/SpriteSheets/Race/yellowCar.png", WHITE, 1);
			StaticVehicles[TotalEnemysStatic]->SheetRec[0]->x = 0;
			StaticVehicles[TotalEnemysStatic]->SheetRec[0]->y = 0;
			StaticVehicles[TotalEnemysStatic]->SheetRec[0]->width = 28;
			StaticVehicles[TotalEnemysStatic]->SheetRec[0]->height = 69;

			StaticVehicles[TotalEnemysStatic]->Transform.x = PosX;
			StaticVehicles[TotalEnemysStatic]->Transform.y = PosY;
			StaticVehicles[TotalEnemysStatic]->Transform.width = 42;
			StaticVehicles[TotalEnemysStatic]->Transform.height = 81;

			TotalEnemysStatic++;
			StaticSpawnTimer = 0.0f;
		}

		if (MovableSpawnTimer > MovableTimeSpawn) {
			MovableVehicles[TotalEnemysMovable] = new C_FlipBook("resources/SpriteSheets/Race/blueCar.png", WHITE, 1);
			MovableVehicles[TotalEnemysMovable]->SheetRec[0]->x = 0;
			MovableVehicles[TotalEnemysMovable]->SheetRec[0]->y = 0;
			MovableVehicles[TotalEnemysMovable]->SheetRec[0]->width = 28;
			MovableVehicles[TotalEnemysMovable]->SheetRec[0]->height = 69;

			MovableVehicles[TotalEnemysMovable]->Transform.x = PosX;
			MovableVehicles[TotalEnemysMovable]->Transform.y = PosY-120;
			MovableVehicles[TotalEnemysMovable]->Transform.width = 42;
			MovableVehicles[TotalEnemysMovable]->Transform.height = 81;

			TotalEnemysMovable++;
			MovableSpawnTimer = 0.0f;
		}
	}
	void DeleteAtPos(short MaxX, short MaxY, short VehicleIndex, bool Movable) {
		switch (Movable) {
		case false:
			if (MaxX != 0 && StaticVehicles[VehicleIndex]->Transform.x > MaxX) {
				// /!\ Void
			}
			if (MaxY != 0 && StaticVehicles[VehicleIndex]->Transform.y > MaxY) {
				delete StaticVehicles[VehicleIndex];
				for (int i = VehicleIndex; i < TotalEnemysStatic; i++) //Realiaza una redimension del array ya que al eliminarse de la memoria el objeto, este deja un hueco en el array. Por lo cual con este algoritmo remplazamos el valor de adelante por el vacio asi sucesivamente con todos hasta que el hueco quede al final. Ya con el control total del array podremos cerrar el hueco final.
				{
					StaticVehicles[i] = StaticVehicles[i + 1];
				}
				TotalEnemysStatic--;
			}
			break;
		case true:
			if (MaxX != 0 && MovableVehicles[VehicleIndex]->Transform.x > MaxX) {
				// /!\ Void
			}
			if (MaxY != 0 && MovableVehicles[VehicleIndex]->Transform.y > MaxY) {
				delete MovableVehicles[VehicleIndex];
				for (int i = VehicleIndex; i < TotalEnemysMovable; i++) //Realiaza una redimension del array ya que al eliminarse de la memoria el objeto, este deja un hueco en el array. Por lo cual con este algoritmo remplazamos el valor de adelante por el vacio asi sucesivamente con todos hasta que el hueco quede al final. Ya con el control total del array podremos cerrar el hueco final.
				{
					MovableVehicles[i] = MovableVehicles[i + 1];
				}
				TotalEnemysMovable--;
			}
			break;
		}

	}
	int LeftRightAnim(int XPos) {
		LeftRightTimer += GetFrameTime();
		static bool Right = true;
		if (XPos >= 500) {
			XPos -= 3;
			Right = false;
		}
		else if (XPos <= 200) {
			XPos += 3;
			Right = true;
		}
		else if (LeftRightTimer > 2) {
			Right = !Right;
			LeftRightTimer = 0.0f;
		}
		return Right ? 3 : -3;
	}
};

class C_Vehicle {
private:
	char* VehicleFlipBook;
	int FlipBookFrames;
	Sound Crash;
public:
	bool HPLock;
	bool CanAnimDead;
	float AnimTimer;
	short HP;
	C_FlipBook Vehicle = { C_FlipBook(VehicleFlipBook, WHITE, 1) };
	C_Vehicle(char* VehicleFlipBook_, int FlipBookFrames_) : VehicleFlipBook(VehicleFlipBook_) { //Uso de inicializacion de variables miembro antes del cuerpo del constructor para poder usarlas en la clase C_FlipBook.
		FlipBookFrames = FlipBookFrames_;
		AnimTimer = 0.0f;
		CanAnimDead = false;
		HP = 3;
		HPLock = false;
		Crash = LoadSound("resources/Sounds/InGame/crash.mp3");
	};
	~C_Vehicle() {};

	void RestrainToRoads() {
		if (Vehicle.Transform.x > 540) { Vehicle.Transform.x = 540; }
		if (Vehicle.Transform.x < 192) { Vehicle.Transform.x = 192; }
		if (Vehicle.Transform.y < 10) { Vehicle.Transform.y = 10; }
		if (Vehicle.Transform.y > 440) { Vehicle.Transform.y = 440; }
	}

	void CheckCollisions(Rectangle Collision1, C_FlipBook& Health) { //NOTA AL PROFESOR: He estado leyendo que necesito pasar la copia de una referencia mediante el &. No entiendo porque debo usar esto aqui.
		if (CheckCollisionRecs(Vehicle.Transform, Collision1)) {
			CanAnimDead = true;
			if (HPLock == false) {
				HPLock = true;
				PlaySound(Crash);
				--HP;
				switch (HP) {
				case 2:
					Health.SheetRec[0]->x = 109;
					Health.SheetRec[0]->y = 5;
					break;
				case 1:
					Health.SheetRec[0]->x = 57;
					Health.SheetRec[0]->y = 5;
					break;
				case 0:
					Health.SheetRec[0]->x = 5;
					Health.SheetRec[0]->y = 5;
					break;
				}
			}
		}
	}

	void DeadAnimationManager() {
		AnimTimer += GetFrameTime();
		static short AnimCycle = 0;
		static bool AnimDead;
		if (AnimTimer > 0.15&&CanAnimDead == true) {
			if (AnimDead == true) {
				Vehicle.SheetRec[0]->x = 43;
				Vehicle.SheetRec[0]->y = 5;
				AnimDead = false;
				AnimCycle++;
			}
			else if (AnimDead == false) {
				Vehicle.SheetRec[0]->x = 5;
				Vehicle.SheetRec[0]->y = 5;
				AnimDead = true;
				AnimCycle++;
			}
			if (AnimCycle >= 10) {
				Vehicle.SheetRec[0]->x = 5;
				Vehicle.SheetRec[0]->y = 5;
				CanAnimDead = false;
				AnimCycle = 0;
				HPLock = false;
			}
			AnimTimer = 0;
		}
	}

};

struct ProgressSystem
{
	bool GameCompleted = false;
	float Timer = 0.0f;
	int Score = 0;
	char ScoreCh[50];

	void UpdateProgressBar(C_FlipBook& ProgressBar) {
		Timer += GetFrameTime();
		if (Timer < 10) {
			ProgressBar.SheetRec[0]->x = 5;
			ProgressBar.SheetRec[0]->y = 5;
		}
		else if (Timer > 10&&Timer < 11) {
			ProgressBar.SheetRec[0]->x = 74;
			ProgressBar.SheetRec[0]->y = 5;
		}
		else if(Timer > 20 && Timer < 21){
			ProgressBar.SheetRec[0]->x = 143;
			ProgressBar.SheetRec[0]->y = 5;
		}
		else if (Timer > 30 && Timer < 31) {
			ProgressBar.SheetRec[0]->x = 212;
			ProgressBar.SheetRec[0]->y = 5;
		}
		else if (Timer > 40 && Timer < 41) {
			ProgressBar.SheetRec[0]->x = 281;
			ProgressBar.SheetRec[0]->y = 5;
		}
		else if (Timer > 50 && Timer < 51) {
			ProgressBar.SheetRec[0]->x = 350;
			ProgressBar.SheetRec[0]->y = 5;
			GameCompleted = true;
		}
	}

	void UpdateScore() {
		
		Score++;
		sprintf(ScoreCh, "%d", Score);
		DrawText(ScoreCh, 840, 55, 25, WHITE);
	}

};

enum E_GamePlayState
{
	Start,
	InGame,
	Win,
	Dead
};
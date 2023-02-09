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

class C_Vehicle {
private:
	char* VehicleFlipBook;
	int FlipBookFrames;
public:
	C_FlipBook Vehicle = { C_FlipBook(VehicleFlipBook, WHITE, 1) };
	C_Vehicle(char* VehicleFlipBook_, int FlipBookFrames_) : VehicleFlipBook(VehicleFlipBook_) { //Uso de inicializacion de variables miembro antes del cuerpo del constructor para poder usarlas en la clase C_FlipBook.
		FlipBookFrames = FlipBookFrames_;
	};

	void RestrainToRoads() {
	if (Vehicle.Transform.x > 540) { Vehicle.Transform.x = 540; }
	if (Vehicle.Transform.x < 192) { Vehicle.Transform.x = 192; }
	if (Vehicle.Transform.y < 10) { Vehicle.Transform.y = 10; }
	if (Vehicle.Transform.y > 440) { Vehicle.Transform.y = 440; }
	}
};

class C_Enemy_Vehicle : public C_Vehicle {
private:
	char* VehicleFlipBook;
	int FlipBookFrames;
public:
	C_Enemy_Vehicle(char* VehicleFlipBook_, int FlipBookFrames_) : C_Vehicle(VehicleFlipBook_, FlipBookFrames_) {
	
	}
};

enum E_GamePlayState
{
	Start,
	InGame,
	Dead
};
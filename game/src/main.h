#pragma once

class C_FlipBook
{
private:
	float SecondTimer;
	int CurrentFrame;
	Vector2 Position;
	Color SpritesColor;
	
public:
	Texture2D SpriteSheet;
	const short TotalSprites;
	Rectangle** SheetRec; //Puntero que almacena puntero el cual almacena punteros que almacenan las instancias de Rectangle.
	Rectangle FlipBookPosition;
	C_FlipBook(char* TextureUrl, int PosX, int PosY, Color SpritesColor_, const short TotalSprites_) : TotalSprites(TotalSprites_) {
		
		SpriteSheet = LoadTexture(TextureUrl);

		Position.x = PosX;
		Position.y = PosY;

		CurrentFrame = 0;
		SecondTimer = 0.0f;

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
	void PlayFlipBook(float PlayRate, float Rotation, bool Debug) {
			SecondTimer += GetFrameTime();
			DrawTexturePro(SpriteSheet, *SheetRec[CurrentFrame], FlipBookPosition, Position, Rotation, SpritesColor);
			if (SecondTimer > PlayRate) {
				CurrentFrame++;
				SecondTimer = 0.0f;
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
	

};

enum E_GamePlayState
{
	Start,
	InGame,
	Dead
};
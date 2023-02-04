#pragma once

class FlipBook
{
private:
	float SecondTimer;
	int CurrentFrame;
	Vector2 Position;
	Color SpritesColor;
public:
	Texture2D SpriteSheet;
	Rectangle* BackGroundRec;

	FlipBook(char* TextureUrl, int PosX, int PosY, Color SpritesColor_) {
		
		SpriteSheet = LoadTexture(TextureUrl);

		Position.x = PosX;
		Position.y = PosY;

		SpritesColor = SpritesColor_;

		CurrentFrame = 0;
		SecondTimer = 0.0f;
			
	};
	~FlipBook() {
		UnloadTexture(SpriteSheet);
	};
	void PlayFlipBook(Rectangle* SpritesFrame, Rectangle SpritePos, float PlayRate, float Rotation, short SpriteTotalFrames) {
			SecondTimer += GetFrameTime();
			DrawTexturePro(SpriteSheet, SpritesFrame[CurrentFrame], SpritePos, Position, Rotation, SpritesColor);
			if (SecondTimer > PlayRate) {
				CurrentFrame++;
				SecondTimer = 0.0f;
		};
			if (CurrentFrame == SpriteTotalFrames) {
				CurrentFrame = 0;
			};
			// v Display de FPS del FlipBook para debug. v
			char DebugText[100];
			sprintf(DebugText, "%d", CurrentFrame);
			DrawText(DebugText, 0, 0, 20, RED);
			// ^ Display de FPS del FlipBook para debug.^
	};
	

};
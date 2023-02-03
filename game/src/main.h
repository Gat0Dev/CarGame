#pragma once

class FlipBook
{
private:
	float SecondTimer;
	Vector2 Position;
	Color SpritesColor;
	int CurrentFrame;
public:
	Texture2D SpriteSheet; 

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
	void PlayFlipBook(Rectangle* SpritesPos, float PlayRate) {	
			SecondTimer += GetFrameTime();
			DrawTextureRec(SpriteSheet, SpritesPos[CurrentFrame], Position, SpritesColor);
			if (SecondTimer > PlayRate) {
				CurrentFrame++;
				SecondTimer = 0.0f;
		};
			if (CurrentFrame > sizeof(*SpritesPos) / sizeof(SpritesPos[0])) {
				CurrentFrame = 0;
			};
	};
	

};
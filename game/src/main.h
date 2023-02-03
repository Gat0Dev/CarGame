#pragma once

class FlipBook
{
private:
	Vector2 Position;
	Color SpritesColor;
	int CurrentFrame;
	float CurrentTime;
	float FrameSpeed;
public:
	
	Texture2D SpriteSheet; 
	FlipBook(char* TextureUrl, int PosX, int PosY, float FrameSpeed_, Color SpritesColor_) {
		
		SpriteSheet = LoadTexture(TextureUrl);

		Position.x = PosX;
		Position.y = PosY;

		SpritesColor = SpritesColor_;

		FrameSpeed = FrameSpeed_;
		CurrentFrame = 0;
		CurrentTime = 0.0f;
			
	};
	~FlipBook() {
		UnloadTexture(SpriteSheet);
	};
	void PlayFlipBook(Rectangle* SpritesPos) {
			DrawTextureRec(SpriteSheet, SpritesPos[CurrentFrame], Position, SpritesColor);			
			CurrentTime += FrameSpeed;
			if (CurrentTime > 1) {
				CurrentFrame++;
				CurrentTime = 0.0f;
		};
			if (CurrentFrame > sizeof(*SpritesPos) / sizeof(SpritesPos[0])) {
				CurrentFrame = 0;
			};
			
	};
	

};
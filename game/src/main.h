#pragma once

class FlipBook
{
private:
	int TotalFrames;
	Texture2D* Sprites;
public:
	

	FlipBook(int TotalFrames_) {
		TotalFrames_ = TotalFrames;
		Sprites = new Texture2D[TotalFrames];

		for (int i = 0; i < TotalFrames; i++)
		{	
			Sprites[i] = LoadTexture("");
		}

	};
	~FlipBook() {
		delete Sprites;
	};
};
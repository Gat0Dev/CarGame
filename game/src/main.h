#pragma once

class FlipBook
{
private:
	int TotalSprites; //Total de sprites que contiene el FlipBook.
public:
	
	Texture2D** Sprites; //El doble asterisco me permite crear un puntero en el Stack del procesador que almacene varios punteros de tipo Texture2D.
	FlipBook(int TotalSprites_) {
		TotalSprites = TotalSprites_;
		Sprites = new Texture2D * [TotalSprites]; //Creo un array de punteros en la memoria RAM (heap) de tipo Texture2D.

		for (int i = 0; i < TotalSprites; i++)
		{
			Sprites[i] = new Texture2D; //Asigno al array de punteros una instancia de tipo Texture2D.
		};

	};
	~FlipBook() {
		for (int i = 0; i < TotalSprites; i++) //Este bucle destruye el array de punteros de tipo Texture2D de la RAM (heap).
		{
			delete Sprites[i];
		};
		delete Sprites; //Aqui destruimos el puntero que contiene los demas punteros (aunque es innecesario realmente porque al salir del scope ya se elimina del stack).
	};

	//TO-DO: Crear funcion(es) que muevan el sprite por frame.

};
#include <SDL.h>
#include <string>
#include <iostream>
#include "res_path.h"
#include "cleanup.h"
#include "SDL_image.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;

//We'll just be using square tiles for now
const int TILE_SIZE = 70;

/*
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message too
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
	SDL_Delay(3000);
}


/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr) {
		logSDLError(std::cout, "LoadTexture");
	}
	return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
	int w, h;
	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	renderTexture(tex, ren, x, y, w, h);
}


int main(int, char**) {

	

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			logSDLError(std::cout, "SDL_Init");
			return 1;
		}

		if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
			logSDLError(std::cout, "IMG_Init");
			SDL_Quit();
			return 1;
		}

		SDL_Window *window = SDL_CreateWindow("Lesson 3", 100, 200, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			logSDLError(std::cout, "CreateWindow");
			SDL_Quit();
			return 1;
		}

		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr) {
			logSDLError(std::cout, "CreateRenderer");
			cleanup(window);
			SDL_Quit();
			return 1;
		}

		const std::string resPath = getResourcePath("Lesson3");
		SDL_Texture *background = loadTexture(resPath + "background.png", renderer);
		SDL_Texture *image = loadTexture(resPath + "image.png", renderer);
		//Make sure they both loaded ok
		if (background == nullptr || image == nullptr) {
			cleanup(background, image, renderer, window);
			IMG_Quit();
			SDL_Quit();
			return 1;
		}

		SDL_RenderClear(renderer);


		//Determine how many tiles we'll need to fill the screen
		int xTiles = SCREEN_WIDTH / TILE_SIZE;
		int yTiles = SCREEN_HEIGHT / TILE_SIZE;

		/*int bW, bH;
		SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
		renderTexture(background, renderer, 0, 0);
		renderTexture(background, renderer, bW, 0);
		renderTexture(background, renderer, 0, bH);
		renderTexture(background, renderer, bW, bH);*/

		//Draw the tiles by calculating their positions
		for (int i = 0; i < xTiles * yTiles; ++i) {
			int x = i % xTiles;
			int y = i / xTiles;
			renderTexture(background, renderer, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
				TILE_SIZE);
		}

		//foreground picture
		int iW, iH;
		SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
		int x = SCREEN_WIDTH / 2 - iW / 2;
		int y = SCREEN_HEIGHT / 2 - iH / 2;
		renderTexture(image, renderer, x, y);

		//render
		SDL_RenderPresent(renderer);
		SDL_Delay(5000);

		//Our event structure
		SDL_Event e;
		bool quit = false;
		while (!quit) {
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				if (e.type == SDL_KEYDOWN) {
					quit = true;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					quit = true;
				}
			}
			//Render the scene
			SDL_RenderClear(renderer);
			renderTexture(image, renderer, x, y);
			SDL_RenderPresent(renderer);
		}

		//cleanup
		cleanup(background, image, renderer, window);
		IMG_Quit();
		SDL_Quit();

		return 0;
	
}
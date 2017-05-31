#pragma once
#include "Constants.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Window
{
public:
	Window();
	~Window();

	SDL_Surface * getImageSurf();
	SDL_Window * getWindow();
	SDL_Renderer * getRenderer();

	void initWindow();
	bool loadTexture(string file);
	void close();
    void clear();
	void drawWindow();
	void drawToWindow(string file);

private:
	SDL_Window * window;
	SDL_Surface * screenSurface;
	SDL_Texture * texture;
	SDL_Renderer * renderer;
};
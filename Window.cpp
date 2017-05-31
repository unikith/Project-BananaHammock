#include "Window.hpp"

Window::Window()
{
	window = nullptr;
	screenSurface = nullptr;
	texture = nullptr;
	renderer = nullptr;
    initWindow();
}

Window::~Window()
{
	close();
}

SDL_Surface * Window::getImageSurf()
{
	return this->screenSurface;
}

SDL_Window * Window::getWindow()
{
	return this->window;
}

SDL_Renderer * Window::getRenderer()
{
	return this->renderer;
}

//Initializes SDL video
//Creates a window
//Creates a renderer
//Initializes image handling
//Sets BG color to black

void Window::initWindow() //Probably move Init_video and Init_Image to main init
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        if(!(window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN))) {
            printf("Failed to create Window: %s", SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL){
                printf("Couldn't load renderer: %s", SDL_GetError());
            } else {
                SDL_SetRenderDrawColor(renderer, 0XFF, 0XFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_PNG;
                if((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
                    printf("Failed to initialize image loader: %s", IMG_GetError());
                } else {
                    screenSurface = SDL_GetWindowSurface(window);
                    /* For Text
                    if(TTF_Init() == -1)
                        printf("TTF failed to initialize");
                    else{
                        //More initialization
                    }
                     */
                }
            }
        }
    }
}

bool Window::loadTexture(string file)
{
	bool success = true;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(file.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Unable to load image!" << file << "SDL Error: \n" << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			cout << "Unable to create texture! SDL error: \n" << SDL_GetError() << endl;
			success = false;
		}
		SDL_FreeSurface(loadedSurface);
	}
	return success;
}

void Window::close()
{
	//Deallocate surface
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Window::clear() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); //Remove for efficiency? 
    SDL_RenderClear(renderer);
}
void Window::drawWindow()
{
    SDL_RenderPresent(renderer);
}

void Window::drawToWindow(string file)
{
	if (!loadTexture(file))
	{
		cout << "Failed to load !" << endl;
	}

	//SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

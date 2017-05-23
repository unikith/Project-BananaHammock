//
//  Sprite.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/19/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

//#include <iostream>
#include "Constants.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Drawable.hpp"

class Sprite : public Drawable {
    Sprite(SDL_Renderer * renderer = nullptr);
    ~Sprite();
    void attachRenderer(SDL_Renderer * renderer);
    bool loadTexture(std::string path);
    bool setPosition(int x, int y);
    bool move(int x, int y);
    void draw();
    
    
private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect cropRect;
    SDL_Rect dstRect;
    bool ifCropped;
};

#endif /* Sprite_hpp */

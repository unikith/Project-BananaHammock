//
//  Sprite.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/19/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer * renderer) {
    this->renderer = renderer;
    texture = nullptr;
    cropRect = {0,0,0,0};
    dstRect = {0,0,0,0};
    ifCropped = false;
}
void Sprite::attachRenderer(SDL_Renderer * renderer) {
    this->renderer = renderer;
}

bool Sprite::loadTexture(std::string path) {
    bool success = true;
    texture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        success = false;
    }
    else
    {
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface );
        if( texture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
            success = false;
        }
        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    return success;
}

bool Sprite::setPosition(int x, int y) {
    if(x >= 0 && x <= SCREEN_WIDTH && y >= 0 && y <= SCREEN_HEIGHT) {
        dstRect.x = x;
        dstRect.y = y;
        printf("Setting Position out of bounds");
        return true;
    }
    return false;
}
bool Sprite::move(int x, int y) {
    return setPosition(dstRect.x + x, dstRect.y + y);
}

void Sprite::draw() {
    if(ifCropped) {
        SDL_RenderCopy(renderer, texture, &cropRect, &dstRect);
    } else {
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    }
}

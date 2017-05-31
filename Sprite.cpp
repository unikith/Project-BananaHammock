//
//  Sprite.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/19/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite(Window * window, const std::string &path) {
    if(path != "" && window != nullptr)
        loadTexture(window, path);
    else
        this->window = window;
    cropRect = {0,0,0,0};
    dstRect = {0,0,0,0};
    ifCropped = false;
    angle = 0;
    origin = {0,0};
    flipFlags = SDL_FLIP_NONE;
}
Sprite::~Sprite() {
    
}

void Sprite::loadTexture(Window * window, const std::string &path) {
    this->window = window;
    texture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if( loadedSurface == NULL )
    {
        printf( "Sprite:Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(window->getRenderer(), loadedSurface );
        if( texture == NULL )
        {
            printf( "Sprite:Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        //Get rid of old loaded surface
        dstRect = loadedSurface->clip_rect;
        SDL_FreeSurface( loadedSurface );
    }
}

void Sprite::loadTexture(Window * window, SDL_Texture * texture) { //PROBLEM can't set dstRect
    this->window = window;
    this->texture = texture;
}

void Sprite::setPosition(int x, int y) {
        dstRect.x = x - origin.x;
        dstRect.y = y - origin.y;
}
void Sprite::move(int x, int y) {
    setPosition(dstRect.x + x, dstRect.y + y);
}
void Sprite::setAngle(double deg) {
    angle = deg;
    normalizeAngle();
}
void Sprite::rotate(double deg) {
    angle += deg;
    normalizeAngle();
}
void Sprite::scale(float widthScalar, float heightScalar) {
    dstRect.w *= widthScalar;
    dstRect.h *= heightScalar;
}
void Sprite::scaleToPixel(int widthPixels, int heightPixels) {
    dstRect.w = widthPixels;
    dstRect.h = heightPixels;
}
void Sprite::crop(const SDL_Rect &cRect) {
    ifCropped = true;
    cropRect = cRect;
    dstRect.w = cRect.w;
    dstRect.h = cRect.h;
}
void Sprite::unCrop() {
    ifCropped = false;
}
void Sprite::setOrigin(int x, int y) {
    origin.x = x;
    origin.y = y;
    //Reset the image location to fit new origin
    setPosition(dstRect.x, dstRect.y);
}
void Sprite::flipHorizontal() {
    flipFlags = flipFlags ^ SDL_FLIP_HORIZONTAL;
}
void Sprite::flipVertical() {
    flipFlags = flipFlags ^ SDL_FLIP_VERTICAL;
}
void Sprite::draw() {
    if(ifCropped) {
        SDL_RenderCopyEx(window->getRenderer(), texture, &cropRect, &dstRect, angle, &origin, (SDL_RendererFlip)flipFlags);
    } else {
        SDL_RenderCopyEx(window->getRenderer(), texture, NULL, &dstRect, angle, &origin,
            (SDL_RendererFlip)flipFlags);
    }
}
//PRIVATE FUNCTIONS
void Sprite::normalizeAngle() {
    angle -= ((int)angle / 360) * 360;
    if(angle < 0)
        angle *= -1;
}

//
//  TileHighlighter.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/30/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "TileHighlighter.hpp"

TileHighlighter::TileHighlighter(int tileLength, Window * window) : tileLength(tileLength) {
    highlightSprite.loadTexture(window, HIGHLIGHT_IMAGE_PATH);
    highlightSprite.scaleToPixel(tileLength, tileLength);
}
TileHighlighter::~TileHighlighter() {
    
}

void TileHighlighter::update() {
    //Get mouse position
    int x, y;
    SDL_GetMouseState(&x, &y);
    if(x >= 0 && x <= SCREEN_WIDTH && y >= 0 && y <= SCREEN_HEIGHT) {
        highlightSprite.setPosition(x/tileLength * tileLength, y/tileLength * tileLength);
        highlightSprite.draw();
    }
}

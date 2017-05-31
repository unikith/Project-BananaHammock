//
//  ToolBar.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/30/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "ToolBar.hpp"

ToolBar::ToolBar(Window * window) : window(window) {
    drawSpaceRect = {0, SCREEN_HEIGHT - barHeight, SCREEN_WIDTH, barHeight};
}
ToolBar::~ToolBar() {
    
}

void ToolBar::update() {
    drawBarBackground();
}
void ToolBar::drawBarBackground() {
    SDL_SetRenderDrawColor(window->getRenderer(), 100, 100, 0, 0xFF);
    SDL_RenderFillRect(window->getRenderer(), &drawSpaceRect);
}
void ToolBar::drawGrid() {
    SDL_SetRenderDrawColor(window->getRenderer(), 100, 100, 100, 100);
    //Draw Horizontal grid lines
    
}
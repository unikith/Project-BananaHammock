//
//  MapMaker.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/30/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "MapMaker.hpp"

MapMaker::MapMaker() {
    
}
MapMaker::~MapMaker() {
    
}

void MapMaker::runMapMaker(Window & window) {
    bool running = true;
    TileHighlighter tileHighlighter(100, &window);
    ToolBar toolBar(&window);
    SDL_Event e;
    while(running) {
        //Poll through all events
        while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
                running = false;
            }
            window.clear();
            tileHighlighter.update();
            toolBar.update();
            window.drawWindow();
        }
        //Run normal stuff
        
    }
}
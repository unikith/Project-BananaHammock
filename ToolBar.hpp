//
//  ToolBar.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/30/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef ToolBar_hpp
#define ToolBar_hpp

#include "Tile.hpp"

class ToolBar {
public:
    ToolBar(Window * window);
    ~ToolBar();
    
    void update();
private:
    //FUNCTIONS
    void drawBarBackground();
    void drawGrid();
    //MEMBER VARIABLES
    int pixelSpacing;
    Window * window;
    SDL_Rect drawSpaceRect;
    
    const int barHeight = 250;
};

#endif /* ToolBar_hpp */

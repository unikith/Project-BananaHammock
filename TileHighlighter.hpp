//
//  TileHighlighter.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/30/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef TileHighlighter_hpp
#define TileHighlighter_hpp

#include <stdio.h>
#include "SDL_obj.h"
#include "MapMaker_Constants.h"
#include "Constants.h"

class TileHighlighter {
public:
    TileHighlighter(int tileLength, Window * window);
    ~TileHighlighter();
    
    void update();
private:
    int tileLength;
    Sprite highlightSprite;
};

#endif /* TileHighlighter_hpp */

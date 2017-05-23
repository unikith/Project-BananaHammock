//
//  Tile.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/18/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
//#include <SDL2/SDL.h>
#include "Character.hpp"

//Tile makes up the board. Derive from drawable which will contain texture and rect?**//
class Tile {
    friend class GameBoard;
public:
    
private:
    //Contains pixel position and pixel size
    //SDL_Rect src;
    //Character in tile, Null if no Character
    Character *character;
    //Can't move into this tile if wall
    bool isWall;
    //If this object can be selected
    bool isSelectable;
    //Amount of moves taken from character to walk into (more for mud areas and stuff)
    int terrainCost;
};


#endif /* Tile_hpp */

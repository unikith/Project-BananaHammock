//
//  Tile.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/18/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

//#include <SDL2/SDL.h>
#include "Character.hpp"


class Tile : public Sprite {
    friend class GameBoard;
    friend class TileHighlighter;
private:
    //Defined constant tiles, no touchy unless adding/removing tiles
    static const int NumberOfTiles;
    typedef enum {
        GROUND = 0, WATER = 1
    }TilesIndex;
    static const Tile *DefinedTiles;
    
public:
    Tile(Window * window = nullptr, const std::string& path = "");
    ~Tile();
    /*
        Draws the tile to the window.
     */
    void draw();
    /*
        Initializes the pre-defined tiles (ground, water, etc.) so that
        these tiles may be able to get copied to other Tile instances.
     */
    static void initDefinedTiles(Window * window);
    /*
        Frees the pre-defined tiles from dynamic memory.
     */
    static void unallocateDefinedTiles();
    /*
     
     */
    static Sprite makeTileSprite(TilesIndex index);
    
private:
    //FUNCTIONS
    /*
        Sets a tile to the given values.
     */
    void setTile(bool isWall, bool isSelectable, int terrainCost, Character *character, Window * window, const std::string& path);
    
    //MEMBER VARIABLES
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

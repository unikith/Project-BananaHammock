//
//  Tile.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/18/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "Tile.hpp"

//Initialize static constants
const int Tile::NumberOfTiles = 2;
const Tile * Tile::DefinedTiles = new Tile[NumberOfTiles];

//FUNCTIONS
Tile::Tile(Window * window, const std::string& path) : Sprite(window, path) {
}
Tile::~Tile() {
    
}

void Tile::draw() {
    //Draw tile art
    Sprite::draw();
    //Draw character on tile
    if(character != nullptr)
        character->draw();
}
void Tile::setTile(bool isWall, bool isSelectable, int terrainCost, Character *character, Window * window, const std::string& path) {
    this->isWall = isWall;
    this->isSelectable = isSelectable;
    this->terrainCost = terrainCost;
    this->character = character;
    this->window = window;
    loadTexture(window, path);
}

void Tile::initDefinedTiles(Window * window) {
    const_cast<Tile*>(DefinedTiles)[GROUND].setTile(false, false, 1, nullptr, window,
                                                    "images/groundTile.png");
    const_cast<Tile*>(DefinedTiles)[WATER].setTile(false, false, 1, nullptr, window,
                                                "images/waterTile.png");
}
void Tile::unallocateDefinedTiles() {
    delete [] DefinedTiles;
}
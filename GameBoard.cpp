//
//  GameBoard.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/16/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "GameBoard.hpp"

GameBoard::GameBoard(Window * window) {
    this->window = window;
    this->tileLength = TILELENGTH;
    this->rows = BOARDROWS;
    this->columns = BOARDCOLUMNS;
    board = new class Tile*[rows];
    for(int i = 0; i < rows; ++i) {
        board[i] = new class Tile[columns]();
    }
    generateMap();
    
}
GameBoard::~GameBoard() {
    
}
void GameBoard::draw() {
    //Draw each tile
    drawTiles();
}

bool GameBoard::selectTile(const Cordinate& src) {
    bool success = false;
    if(tileAt(src).isSelectable) {
        selectedTile = src;
        success = true;
    }
    return success;
}

//private
Tile& GameBoard::tileAt(Cordinate cord) {
    return board[cord.row][cord.column];
}

void GameBoard::drawTiles() {
    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < columns; ++c) {
            board[r][c].draw();
        }
    }
}
void GameBoard::generateMap() {
    for(int r = 0; r < rows; ++r) {
        for(int c = 0; c < columns; ++c) {
            board[r][c] = Tile::DefinedTiles[rand() % Tile::NumberOfTiles];
            board[r][c].scaleToPixel(tileLength, tileLength);
            board[r][c].setPosition(tileLength * c, tileLength * r);
        }
    }
}

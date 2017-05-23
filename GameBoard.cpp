//
//  GameBoard.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/16/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#include "GameBoard.hpp"

GameBoard::GameBoard() {
    board = new class Tile*[rows];
    for(int i = 0; i < rows; ++i) {
        board[i] = new class Tile[columns]();
    }
}
bool GameBoard::selectTile(Cordinate src) {
    bool success = false;
    if(tileAt(src).isSelectable) {
        selectedTile = src;
        success = true;
    }
    return success;
}
Tile& GameBoard::tileAt(Cordinate cord) {
    return board[cord.row][cord.column];
}

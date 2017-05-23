//
//  GameBoard.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/16/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include "Tile.hpp"

typedef struct cordinate {
    int row;
    int column;
}Cordinate;

class GameBoard : public Drawable {
public:
    GameBoard();
    ~GameBoard();
    /**
        Selects the given tile.
     */
    bool selectTile(Cordinate src);
    /**
        See corresponding private members, performs
        with the currently selected tile. Will return false
        if no selected tile.
     */
    bool moveCharacter(Cordinate dst);
    bool attack(Cordinate dst);
    bool highlightPossibleMoves();
private:
    //Functions
    /**
     Moves the character at the given cordinate to another.
     Returns true if it's a valid move and false if an invalid move.
     */
    bool moveCharacter(Cordinate src, Cordinate dst);
    /**
     Attacks character at dst from src.
     Returns true if it's a valid attack and false if an invalid attack.
     */
    bool attack(Cordinate& src, Cordinate dst);
    /**
     Highlights all tiles the character can move to or attack.
     Returns true if there is a valid character else false.
     */
    bool highlightPossibleMoves(Cordinate src);
    /**
        Checks if the given character move is legal and returns
        true if so.
     */
    bool checkCharacterMove(Cordinate src, Cordinate dst) const;
    /**
        Returns a reference to the corresponding tile.
     */
    Tile& tileAt(Cordinate cord);
    
    //Members
    Tile** board;
    int rows;
    int columns;
    //-1,-1 if none selected
    Cordinate selectedTile;
};

#endif /* GameBoard_hpp */

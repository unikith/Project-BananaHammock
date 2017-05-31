//
//  Character.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/16/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include "Sprite.hpp"

class Character : public Sprite {
public:
    Character(Window * window, std::string path) : Sprite(window, path){};
private:
    //Beginning of turn amount of moves (moving and attacks)
    int maxNMoves;
    //Current amount of moves left
    int currentNMoves;
    int attackDamage;
};

#endif /* Character_hpp */

//
//  Character.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/16/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "Sprite.hpp"

class Character : public Sprite {
public:
    
private:
    //Beginning of turn amount of moves (moving and attacks)
    int maxNMoves;
    //Current amount of moves left
    int currentNMoves;
    int attackDamage;
};

#endif /* Character_hpp */

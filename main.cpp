//
//  main.cpp
//  Summer Game
//
//  Created by Christian Burke on 5/16/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

//#include <iostream>
#include "SDL_obj.h"
#include "GameBoard.hpp"
#include <time.h>
#include "MapMaker.hpp"

void initGame(Window * window);
void closeGame();

int main(int argc, const char * argv[]) {
    printf("Enter 0 for map maker and 1 for game: ");
    int input = -1;
    scanf("%d", &input);
    Window window;
    initGame(&window);
    if(input == 0) { //MAP MAKER CODE
        MapMaker::runMapMaker(window);
    } else if(input == 1) { //GAME CODE
        GameBoard gameBoard(&window);
        bool running = true;
        SDL_Event e;
        while(running) {
            //Poll through all events
            while(SDL_PollEvent(&e) != 0) {
                if(e.type == SDL_QUIT) {
                    running = false;
                }
            }
            window.clear(); //In future probably won't need a clear
            gameBoard.draw();
            window.drawWindow();
            //SDL_Delay(200);
        }
    } else {
        printf("Invalid input");
    }
}

void initGame(Window * window) {
    srand((unsigned int)time(0));
    Tile::initDefinedTiles(window);
}

void closeGame() {
    Tile::unallocateDefinedTiles();
}
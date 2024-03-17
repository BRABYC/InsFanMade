#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
private:
    Player player;
public:
    Game(const Player& player) : player(player) {}

    void showUI(){
        
    }
};

#endif

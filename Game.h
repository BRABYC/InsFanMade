#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
private:
    Player player;
public:
    Game(const Player& player) : player(player) {}

    void PlayerInput() {
        player.moveInEquipment();
    }
    void showUI(){
        player.displayPlayerStats();
    }
    void input(){
        char player_input;
        cin>>player_input;
        switch (player_input)
        {
        switch(player_input)
        {
            case 'w': case 'a': case 's': case 'd':
                player.moveInEquipment(player_input);
                break;
            case 'e':
                
            
        }
        
        default:
            break;
        }

    }
};

#endif

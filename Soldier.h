//
// Created by avi on 13/06/2021.
//

#ifndef GAME_SOLDIER_H
#define GAME_SOLDIER_H

#include "Character.h"


class Soldier : public Character{
    int moving_range = 3;
    int reload = 3;
    int ammo_cost = 1;
    bool canAttack(GridPoint points);
};


#endif //GAME_SOLDIER_H

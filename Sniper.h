//
// Created by avi on 13/06/2021.
//

#ifndef GAME_SNIPER_H
#define GAME_SNIPER_H

#include "Character.h"

namespace mtm {

    class Sniper : public Character {
    private:
        static const int RELOAD_AMMO = 5;
        static const int MOVING_RANGE = 2;
        static const int AMMO_PER_ATTACK = 1;
    public:
        Sniper(Team team, int health, int currentAmmo, int range, int power);
    };
}
#endif //GAME_SNIPER_H

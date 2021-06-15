//
// Created by avi on 13/06/2021.
//

#ifndef GAME_SNIPER_H
#define GAME_SNIPER_H

#include "Character.h"

namespace mtm {

    class Sniper : public Character {
    private:
        static const int RELOAD_AMMO = 2;
        static const int MOVING_RANGE = 4;
        static const int AMMO_PER_ATTACK = 1;
        static const int STRONG_ATTACK = 3;
        int attack_counter;
    public:
        Sniper(Team team, int health, int currentAmmo, int range, int power);

        std::vector<GridPoint> getAttackCoordinates(const GridPoint &src_coordinate,const GridPoint &dst_coordinate) override;

        void attack(Character &victim, int distance_from_attacked_point,bool reduce) override;
        std::string& addToString(std::string& str) override;
    };
}
#endif //GAME_SNIPER_H

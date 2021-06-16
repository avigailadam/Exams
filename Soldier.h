//
// Created by avi on 13/06/2021.
//

#ifndef GAME_SOLDIER_H
#define GAME_SOLDIER_H

#include "Character.h"

namespace mtm {
    class Soldier : public Character {
    private:
        static const int RELOAD_AMMO = 3;
        static const int MOVING_RANGE = 3;
        static const int AMMO_PER_ATTACK = 1;

    public:
        Soldier(Team team, int health, int currentAmmo, int range, int power);

        std::vector<GridPoint>
        getAttackCoordinates(const GridPoint &src_coordinate, const GridPoint &dst_coordinate) override;

        void attack(Character &victim, int distance_from_attacked_point,bool reduce) override;

        std::string &addToString(std::string &str) override;

        std::shared_ptr<Character> clone() const override;
    };
}

#endif //GAME_SOLDIER_H

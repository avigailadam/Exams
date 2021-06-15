//
// Created by avi on 13/06/2021.
//
#include "Character.h"

#ifndef GAME_MEDIC_H
#define GAME_MEDIC_H
namespace mtm {
    class Medic : public Character {
    private:
        static const int RELOAD_AMMO = 5;
        static const int MOVING_RANGE = 5;
        static const int AMMO_PER_ATTACK = 1;
    public:
        Medic(Team team, int health, int currentAmmo, int range, int power);

        std::vector<GridPoint>
        getAttackCoordinates(const GridPoint &src_coordinate, const GridPoint &dst_coordinate) override;

        void attack(Character &victim, int distance_from_attacked_point, bool reduce) override;

        std::string &addToString(std::string &str) override;


    };
}

#endif //GAME_MEDIC_H

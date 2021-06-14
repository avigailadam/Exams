//
// Created by avi on 13/06/2021.
//

#include "Sniper.h"

namespace mtm {
    Sniper::Sniper(Team team, int health, int currentAmmo, int range, int power) : Character(team, health, currentAmmo,
                                                                                             Sniper::RELOAD_AMMO,
                                                                                             range, power,
                                                                                             Sniper::MOVING_RANGE,
                                                                                             Sniper::AMMO_PER_ATTACK) {}

    void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        if ()

    }
}


//
// Created by avi on 13/06/2021.
//

#include "Soldier.h"

namespace mtm {
    Soldier::Soldier(Team team, int health, int currentAmmo, int range, int power) :
            Character(team, health, currentAmmo, Soldier::RELOAD_AMMO, range, power, Soldier::MOVING_RANGE,
                      Soldier::AMMO_PER_ATTACK) {};
}




//
// Created by avi on 13/06/2021.
//

#include "Soldier.h"

Soldier::Soldier(int health, int currentAmmo, int range, int power) :
        Character(health, currentAmmo, Soldier::RELOAD_AMMO, range, power, Soldier::MOVING_RANGE,
                  Soldier::AMMO_PER_ATTACK) {};




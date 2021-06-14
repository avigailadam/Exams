
#include "Medic.h"

Medic::Medic(int health, int currentAmmo, int range, int power) :
        Character(health, currentAmmo, Medic::RELOAD_AMMO, range, power, Medic::MOVING_RANGE,
                  Medic::AMMO_PER_ATTACK) {}

void Medic::attack(const Game &game, const GridPoint &src, const GridPoint &dst) {
    if (GridPoint::distance(src, dst) > getAttackRange()) {
        return;
    }

}


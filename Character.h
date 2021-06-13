//
// Created by avi on 13/06/2021.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "Auxiliaries.h"
#include "Game.h"

using namespace mtm;


class Character {
private:
    int health;
    int current_ammo;
    const int reload_ammo;
    const int range;
    const int power;
    const int moving_range;
    const int ammo_per_attack;
protected:
    Character(int health, int ammo, const int range, const int power, const int moving_range, const int ammo_per_attack)
            :
            health(health), current_ammo(ammo), reload_ammo(ammo), range(range), power(power),
            moving_range(moving_range), ammo_per_attack(ammo_per_attack) {}

public:
    virtual void attack(const Game &game, const GridPoint &src, const GridPoint &dst) = 0;

    virtual bool canAttack(GridPoint points) = 0;

    void reload() {
        current_ammo += reload_ammo;
    }

    int getHealth() const {
        return health;
    }

    void reduceHealth(int amount) {
        health -= amount;
    }

    int getCurrentAmmo() const {
        return current_ammo;
    }

    int getRange() const {
        return range;
    }

    int getPower() const {
        return power;
    }
};

#endif //GAME_CHARACTER_H

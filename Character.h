//
// Created by avi on 13/06/2021.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H
#include "Exceptions.h"
#include "Auxiliaries.h"
#include <cmath>
#include <vector>


namespace mtm {
    class Character {
    private:
        Team team;
        int health;
        int current_ammo;
        const int reload_ammo;
        const int range;
        const int power;
        const int moving_range;
    public:
    private:

        const int ammo_per_attack;
    protected:
        Character(Team team, int health, int currentAmmo, int reloadAmmo, int range, int power,
                  int movingRange, int ammoPerAttack) : team(team), health(health), current_ammo(currentAmmo),
                                                        reload_ammo(reloadAmmo), range(range), power(power),
                                                        moving_range(movingRange),
                                                        ammo_per_attack(ammoPerAttack) {}

        void reduceHealth(int amount) {
            health -= amount;
        }

    public:

        virtual std::vector<GridPoint> getAttackCoordinates(const GridPoint &dst_coordinate) = 0;

        virtual void attack(Character &victim, int i) = 0;

        void reload() {
            current_ammo += reload_ammo;
        }

        Team getTeam() const {
            return team;
        }

        int getHealth() const {
            return health;
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

        int getMovingRange() const {
            return moving_range;
        }
    };
}

#endif //GAME_CHARACTER_H

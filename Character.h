//
// Created by avi on 13/06/2021.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include "Auxiliaries.h"
#include "Exceptions.h"
#include <cmath>
#include <memory>
#include <vector>


namespace mtm {
    class Character {
    private:
        Team team;
        int health;
        int current_ammo;
        int reload_ammo;
        int range;
        int power;
        int moving_range;
        int ammo_per_attack;

    protected:

        Character(Team team, int health, int currentAmmo, int reloadAmmo, int range, int power,
                  int movingRange, int ammoPerAttack) : team(team), health(health), current_ammo(currentAmmo),
                                                        reload_ammo(reloadAmmo), range(range), power(power),
                                                        moving_range(movingRange),
                                                        ammo_per_attack(ammoPerAttack) {}

    public:
        virtual std::shared_ptr<Character> clone() const = 0;
        virtual std::vector<GridPoint>
        getAttackCoordinates(const GridPoint &src_coordinate, const GridPoint &dst_coordinate) = 0;

        virtual void attack(Character &victim, int distance_from_attacked_point,bool reduce) = 0;

        void reduceHealth(int amount) {
            health -= amount;
        }

        void cureTeammate(int amount) {
            health += amount;
        }

        void reduceAmmo() {
            current_ammo -= ammo_per_attack;
        }

        void reload() {
            current_ammo += reload_ammo;
        }

        int getAmmoPerAttack() const {
            return ammo_per_attack;
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

        virtual std::string &addToString(std::string &str) = 0;
    };
}

#endif //GAME_CHARACTER_H

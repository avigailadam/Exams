//
// Created by avi on 13/06/2021.
//

#include "Soldier.h"

namespace mtm {
    Soldier::Soldier(Team team, int health, int currentAmmo, int range, int power) :
            Character(team, health, currentAmmo, Soldier::RELOAD_AMMO, range, power, Soldier::MOVING_RANGE,
                      Soldier::AMMO_PER_ATTACK) {}

    std::string &Soldier::addToString(std::string &str) {
        return getTeam() == POWERLIFTERS ? str += "S" : str += "s";
    }

    std::vector<GridPoint>
    Soldier::getAttackCoordinates(const GridPoint &src_coordinate, const GridPoint &dst_coordinate) {
        std::vector<GridPoint> vector;
        int distance = GridPoint::distance(src_coordinate, dst_coordinate);
        int range = getRange();
        if (distance > range ||
            ((src_coordinate.row != dst_coordinate.row) && (src_coordinate.col != dst_coordinate.col))) {
            throw OutOfRange();
        }
        int max_dist = ceil(double(range) / 3);
        for (int i = dst_coordinate.row - max_dist; i <= dst_coordinate.row + max_dist; ++i) {
            for (int j = dst_coordinate.col - max_dist; j <= dst_coordinate.col + max_dist; ++j) {
                GridPoint curr_point(i, j);
                int dist = GridPoint::distance(curr_point, dst_coordinate);
                if (dist > max_dist) {
                    continue;
                }
                vector.push_back(curr_point);
            }
        }
        return vector;
    }

    void Soldier::attack(Character &victim, int distance_from_attacked_point,bool reduce) {
        if (getTeam() == victim.getTeam()){
            return;
        }
        if (reduce) {
            if (getCurrentAmmo()<getAmmoPerAttack()){
                throw OutOfAmmo();
            }
            reduceAmmo();
        }
        int power = getPower();
        if (distance_from_attacked_point == 0){
            victim.reduceHealth(power);
            return;
        }
        victim.reduceHealth(ceil(double(power)/2));
    }

    std::shared_ptr<Character> Soldier::clone() const {
        return std::shared_ptr<Character>(new Soldier(getTeam(), getHealth(), getCurrentAmmo(), getRange(), getPower()));
    }
}




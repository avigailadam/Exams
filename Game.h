//
// Created by avi on 13/06/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H


#include "Character.h"

enum Team {
    POWERLIFTERS, CROSSFITTERS
};
enum CharacterType {
    SOLDIER, MEDIC, SNIPER
};
enum CompareTeamResult {
    SAME, DIFFERENT, EMPTY
};
typedef int units_t;

class Game {
private:
    vector<vector<Character>>  board;
public:

    Game(int height, int width);

    ~Game();

    Game(const Game &other);

    Game &operator=(const Game &other);

    void move(const GridPoint &src, const GridPoint dst);

    void addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character);

    void attack(const GridPoint &src, const GridPoint dst);

    static std::shared_ptr<Character>
    makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power);


};


#endif //GAME_GAME_H

//
// Created by avi on 13/06/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H


#include "Character.h"
#include <vector>
#include <memory>
#include <ostream>

namespace mtm {

    enum CompareTeamResult {
        SAME, DIFFERENT, EMPTY
    };
    typedef int units_t;

    class Game {
    private:
        int height;
        int width;
        std::vector<std::vector<std::shared_ptr<mtm::Character>>> board;

        std::shared_ptr<Character> getCharacterAt(const GridPoint &place) const; //return null if empty

        bool isOutOfBounds(const GridPoint &point) const;

    public:
        friend std::ostream &operator<<(std::ostream &os, const Game &game) ;

        Game(int height, int width);

        ~Game() = default;

        Game(const Game &other) = default;

        Game &operator=(const Game &other) = default;

    void move(const GridPoint &src, const GridPoint dst);

        void addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character);

        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        bool isOver(Team *winningTeam = NULL) const;

        void reload(const GridPoint &coordinates);

        static std::shared_ptr<Character>
        makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power);
    };
}


#endif //GAME_GAME_H

#ifndef PLAYER_CHARACTER_ANCESTRY_H
#define PLAYER_CHARACTER_ANCESTRY_H

#include <iostream>
#include "characters/AttributeBoost.h"

namespace characters
{
    class PlayerCharacterAncestry
    {
    public:
        PlayerCharacterAncestry(std::string name, int health, characters::AttributeBoost boost);
        int GetHealth() const;

    private:
        std::string name;
        int health;
        characters::AttributeBoost boost;
    };

}

#endif // PLAYER_CHARACTER_ANCESTRY_H
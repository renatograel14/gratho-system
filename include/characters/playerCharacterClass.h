#ifndef PLAYER_CHARACTER_CLASS_H
#define PLAYER_CHARACTER_CLASS_H
#include <iostream>
#include "characters/EnumAttributes.h"

namespace characters
{
    class PlayerCharacterClass
    {
    public:
        PlayerCharacterClass(std::string name, int health, characters::EnumAttributes keyAttribute);
        int GetHealth() const;
        characters::EnumAttributes GetKeyAttribute() const;

    private:
        std::string name;
        int health;
        characters::EnumAttributes keyAttribute;
    };

}

#endif // PLAYER_CHARACTER_CLASS_H
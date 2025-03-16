#ifndef PLAYER_CHARACTER_CLASS_H
#define PLAYER_CHARACTER_CLASS_H
#include <iostream>
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"

namespace characters
{
    class PlayerCharacterClass
    {
    public:
        PlayerCharacterClass(std::string name, int health, EnumAttributes keyAttribute);
        int GetHealth() const;
        const EnumAttributes &GetKeyAttribute() const;

    private:
        std::string name;
        int health;
        EnumAttributes keyAttribute;
    };

}

#endif // PLAYER_CHARACTER_CLASS_H
#include <iostream>
#include "characters/PlayerCharacterClass.h"

namespace characters
{
    PlayerCharacterClass::PlayerCharacterClass(
        std::string name,
        int health,
        characters::EnumAttributes keyAttribute)
        : name(name), health(health), keyAttribute(keyAttribute) {}
    int PlayerCharacterClass::GetHealth() const
    {
        return health;
    }
    characters::EnumAttributes PlayerCharacterClass::GetKeyAttribute() const {
        return keyAttribute;
    }
}
#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/EnumAttributes.h"
#include "characters/AttributeBoost.h"

namespace characters
{
    PlayerCharacterClass::PlayerCharacterClass(
        std::string name,
        int health,
        characters::EnumAttributes keyAttribute)
        : name(name), health(health), keyAttribute(keyAttribute) {}

    const EnumAttributes &PlayerCharacterClass::GetKeyAttribute() const
    {
        return keyAttribute;
    }

    const int &PlayerCharacterClass::GetHealth() const
    {
        return health;
    }

    const std::string &PlayerCharacterClass::GetName() const
    {
        return name;
    }
}
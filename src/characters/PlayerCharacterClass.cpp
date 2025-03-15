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
        : name(name), health(health), keyAttribute(keyAttribute), classBoost(name, {{keyAttribute, true}}, {{}}) {}
    int PlayerCharacterClass::GetHealth() const
    {
        return health;
    }

    const characters::AttributeBoost &PlayerCharacterClass::GetBoost() const
    {
        return classBoost;
    }
}
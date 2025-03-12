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
    int PlayerCharacterClass::GetHealth() const
    {
        return health;
    }

    characters::AttributeBoost PlayerCharacterClass::GetBoost() const
    {
        characters::AttributeBoost classBoost(name, {{keyAttribute, true}}, {{}});
        return classBoost;
    }
}
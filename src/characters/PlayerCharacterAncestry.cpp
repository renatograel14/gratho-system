#include <iostream>
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterAncestry::PlayerCharacterAncestry(
        std::string name,
        int health,
        const characters::AttributeBoost &boost)
        : name(name), health(health), boost(boost) {}

    int PlayerCharacterAncestry::GetHealth() const
    {
        return health;
    }

    const AttributeBoost &PlayerCharacterAncestry::GetBoost() const
    {
        return boost;
    }
}
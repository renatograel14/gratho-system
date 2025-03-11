#include <iostream>
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterAncestry::PlayerCharacterAncestry(
        std::string name,
        int health,
        characters::AttributeBoost boost)
        : name(name), health(health), boost(boost) {}

    int PlayerCharacterAncestry::GetHealth() const
    {
        return health;
    }
}
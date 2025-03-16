#include <iostream>
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterAncestry::PlayerCharacterAncestry(
        std::string name,
        int health)
        : name(name), health(health) {}

    const int &PlayerCharacterAncestry::GetHealth() const
    {
        return health;
    }

    const std::string &PlayerCharacterAncestry::GetName() const
    {
        return name;
    }
}
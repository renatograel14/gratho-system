#include <iostream>
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterAncestry::PlayerCharacterAncestry(std::string name, int health) : name(name), health(health) {}

    int PlayerCharacterAncestry::GetHealth() const
    {
        return health;
    }
}
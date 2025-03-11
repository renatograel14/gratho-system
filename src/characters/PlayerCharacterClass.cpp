#include <iostream>
#include "characters/PlayerCharacterClass.h"

namespace characters
{
    PlayerCharacterClass::PlayerCharacterClass(std::string name, int health) : name(name), health(health) {}
    int PlayerCharacterClass::GetHealth() const {
        return health;
    }
}
#include <iostream>
#include "characters/PlayerCharacterClass.h"

namespace characters {
    PlayerCharacterClass::PlayerCharacterClass(std::string name, characters::PlayerCharacterClassHealth health) : name(name), health(health) {}
}
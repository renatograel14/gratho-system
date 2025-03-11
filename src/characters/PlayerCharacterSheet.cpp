#include <iostream>
#include "characters/PlayerCharacterSheet.h"
#include "characters/PlayerCharacterClass.h"

namespace characters {
    PlayerCharacterSheet::PlayerCharacterSheet(std::string name, PlayerCharacterClass& playerClass) : name(name), playerClass(playerClass) {}
}
#include <iostream>
#include "characters/PlayerCharacterSheet.h"
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(
        std::string name,
        PlayerCharacterAncestry &ancestry,
        PlayerCharacterClass &playerClass)
        : name(name), ancestry(ancestry), playerClass(playerClass) {}
}
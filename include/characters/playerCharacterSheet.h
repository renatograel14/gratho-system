#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    class PlayerCharacterSheet
    {
    public:
        PlayerCharacterSheet(std::string name, PlayerCharacterAncestry &ancestry, PlayerCharacterClass &playerClass);

    private:
        std::string name;
        PlayerCharacterAncestry &ancestry;
        PlayerCharacterClass &playerClass;
    };

}

#endif // PLAYER_CHARACTER_SHEET_H
#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include "characters/PlayerCharacterClass.h"

namespace characters
{
    class PlayerCharacterSheet
    {
    public:
        PlayerCharacterSheet(std::string name, PlayerCharacterClass& playerClass);

    private:
        std::string name;
        PlayerCharacterClass& playerClass;
    };

}

#endif // PLAYER_CHARACTER_SHEET_H
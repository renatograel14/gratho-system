#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/EnumAttributes.h"

namespace characters
{
    class PlayerCharacterSheet
    {
    public:
        PlayerCharacterSheet(
            std::string name, 
            PlayerCharacterAncestry &ancestry, 
            PlayerCharacterClass &playerClass,
            std::map<characters::EnumAttributes, int> attributes
        );
        int GetAttribute(characters::EnumAttributes attributeName) const;
        int GetHealth() const;

    private:
        std::string name;
        PlayerCharacterAncestry &ancestry;
        PlayerCharacterClass &playerClass;
        std::map<characters::EnumAttributes, int> attributes;
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include <map>
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
            PlayerCharacterClass &playerClass);

        std::string GetName() const;
        int GetAttribute(characters::EnumAttributes attr) const;
        int GetHealth() const;

    private:
        std::string name;
        PlayerCharacterAncestry &ancestry;
        PlayerCharacterClass &playerClass;

        std::map<characters::EnumAttributes, int> attributes;

        std::map<characters::EnumAttributes, int> AccumulateBoosts() const;

        int CalculateAttributeValue(int boostCount) const;
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
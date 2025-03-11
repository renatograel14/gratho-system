#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include <map>
#include <vector>

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
            AttributeBoost firstLevelBoost);

        std::string GetName() const;
        int GetAttribute(characters::EnumAttributes attr) const;
        int GetHealth() const;
        void AddLevelBoost(AttributeBoost newLevelBoost);
        void PrintAllAtttributes() const;
        std::vector<characters::AttributeBoost> GetAllAttributeBoosts() const;

    private:
        std::string name;
        characters::PlayerCharacterAncestry &ancestry;
        characters::PlayerCharacterClass &playerClass;
        std::vector<AttributeBoost> levelBoosts;
        std::map<characters::EnumAttributes, int> attributes;
        std::map<characters::EnumAttributes, int> AccumulateBoosts() const;

        int CalculateAttributeValue(int boostCount) const;
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
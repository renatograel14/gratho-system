#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include <map>
#include <vector>

#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/EnumAttributes.h"
#include "skill.h"

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
        void AddSkill(Skill newSkill);
        Skill GetSkill(std::string skillName);

    private:
        std::string name;
        characters::PlayerCharacterAncestry &ancestry;
        characters::PlayerCharacterClass &playerClass;
        std::vector<AttributeBoost> levelBoosts;
        std::map<characters::EnumAttributes, int> attributes;
        std::map<characters::EnumAttributes, int> AccumulateBoosts() const;
        std::vector<characters::Skill> skills;

        int CalculateAttributeValue(int boostCount) const;
        void CalculateAttributes();
        void SetSkills();
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
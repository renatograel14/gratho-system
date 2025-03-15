#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include <map>
#include <vector>

#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"
#include "characters/CharacterVisitor.h"

namespace characters
{
    class PlayerCharacterSheet
    {
    public:
        PlayerCharacterSheet(
            std::string name,
            AttributeBoost firstLevelBoost);

        const std::string &GetName() const;
        const int GetAttribute(EnumAttributes attr) const;
        const int &GetTotalHealth() const;

        void acceptCharacterVisitor(const CharacterVisitor &visitor);

        const std::vector<AttributeBoost> &GetBoosts() const;
        void AddLevelBoost(const AttributeBoost &newLevelBoost);

        void AddSkill(const Skill &newSkill);
        const Skill &GetSkill(const std::string &skillName) const;

        void PrintAllAttributes() const;

    private:
        std::string name;
        std::vector<AttributeBoost> levelBoosts;
        std::map<EnumAttributes, int> attributes;
        std::vector<Skill> skills;
        std::vector<AttributeBoost> boosts;
        int totalHealth;

        std::map<EnumAttributes, int> AccumulateBoosts() const;
        int CalculateAttributeValue(int boostCount) const;
        void CalculateAttributes();
        void InitializeDefaultSkills();
        void ConsolidateBoosts();
        void CalculateTotalHealth();
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
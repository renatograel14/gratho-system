#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include <map>
#include <vector>

#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"

namespace characters
{
    class PlayerCharacterVisitor;
    class PlayerCharacterSheet
    {
    public:
        explicit PlayerCharacterSheet(std::string name);

        const std::string &GetName() const;
        const int GetAttribute(EnumAttributes attr) const;
        const int &GetTotalHealth() const;

        const PlayerCharacterClass &GetPlayerClass() const;
        void SetPlayerClass(const PlayerCharacterClass &newPlayerClass);

        const PlayerCharacterAncestry &GetAncestry() const;
        void SetAncestry(const PlayerCharacterAncestry &newAncestry);

        void AcceptCharacterVisitor(const PlayerCharacterVisitor &visitor);

        const std::vector<AttributeBoost> &GetBoosts() const;
        void AddBoost(const AttributeBoost &newLevelBoost);

        void AddSkill(const Skill &newSkill);
        void SetSkillRank(const std::string &skillName, EnumProficiencies proficiency);
        Skill &GetSkill(const std::string &skillName);

        void CalculateTotalHealth();

        void PrintAllAttributes() const;

    private:
        std::string name;

        PlayerCharacterClass playerClass;
        PlayerCharacterAncestry ancestry;

        std::map<EnumAttributes, int> attributes;
        std::vector<Skill> skills;
        std::vector<AttributeBoost> boosts;
        int totalHealth;

        std::map<EnumAttributes, int> AccumulateBoosts() const;
        int CalculateAttributeValue(int boostCount) const;
        void CalculateAttributes();
        void InitializeDefaultSkills();
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
#ifndef PLAYER_CHARACTER_SHEET_H
#define PLAYER_CHARACTER_SHEET_H

#include <iostream>
#include <map>
#include <vector>

#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/EnumAttributes.h"
#include "characters/EnumSkillRank.h"
#include "characters/PlayerCharacterProficiency.h"
#include "characters/Skill.h"

namespace characters
{
    class PlayerCharacterVisitor;
    class PlayerCharacterSheet
    {
    public:
        explicit PlayerCharacterSheet(std::string name);

        const std::string GetName() const;
        const int GetAttribute(EnumAttributes attr) const;
        int GetTotalHealth() const;

        const PlayerCharacterClass &GetPlayerClass() const;
        void SetPlayerClass(const PlayerCharacterClass &newPlayerClass);

        const PlayerCharacterAncestry &GetAncestry() const;
        void SetAncestry(const PlayerCharacterAncestry &newAncestry);

        void AcceptCharacterVisitor(const PlayerCharacterVisitor &visitor);

        const std::vector<AttributeBoost> &GetBoosts() const;
        void AddBoost(const AttributeBoost &newLevelBoost);

        void AddProficiency(const Skill &skill, EnumSkillRank proficiency, const std::string &source);
        int GetProficiencyModifier(const Skill &skill) const;
        const PlayerCharacterProficiency &GetProficiency(const Skill &skill) const;
        std::vector<PlayerCharacterProficiency> GetProficienciesBySource(const std::string &source) const;
        std::vector<PlayerCharacterProficiency> GetProficienciesByRank(const EnumSkillRank &rank) const;

        void CalculateTotalHealth();

        std::string ToString() const;

    private:
        PlayerCharacterClass playerClass;
        PlayerCharacterAncestry ancestry;

        std::string name;
        std::map<EnumAttributes, int> attributes;
        std::vector<PlayerCharacterProficiency> proficiencies;
        std::vector<AttributeBoost> boosts;
        int totalHealth;
        int level;

        std::map<EnumAttributes, int> AccumulateBoosts() const;
        int CalculateAttributeValue(int boostCount) const;
        void CalculateAttributes();
        void InitializeDefaultSkills();
        std::vector<PlayerCharacterProficiency>::iterator FindSkillIteratorByName(const std::string &skillName);
        std::vector<PlayerCharacterProficiency>::const_iterator FindSkillIteratorByName(const std::string &skillName) const;
    };
}

#endif // PLAYER_CHARACTER_SHEET_H
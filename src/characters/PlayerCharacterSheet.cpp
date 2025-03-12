#include "characters/PlayerCharacterSheet.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(
        std::string name,
        PlayerCharacterAncestry &ancestry,
        PlayerCharacterClass &playerClass,
        AttributeBoost firstLevelBoost)
        : name(name), ancestry(ancestry), playerClass(playerClass), levelBoosts({firstLevelBoost})
    {
        CalculateAttributes();
        SetSkills();
    }

    std::string PlayerCharacterSheet::GetName() const
    {
        return name;
    }

    int PlayerCharacterSheet::GetAttribute(characters::EnumAttributes attr) const
    {
        try
        {
            return attributes.at(attr);
        }
        catch (std::out_of_range &e)
        {
            return 0;
        }
    }

    int PlayerCharacterSheet::GetHealth() const
    {
        int constitution = GetAttribute(characters::EnumAttributes::Constitution);
        return ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }

    std::vector<characters::AttributeBoost> PlayerCharacterSheet::GetAllAttributeBoosts() const
    {
        const AttributeBoost &ancestryBoost = ancestry.GetBoost();
        const AttributeBoost &playerClassBoost = playerClass.GetBoost();
        std::vector<characters::AttributeBoost> boosts({ancestryBoost, playerClassBoost});
        boosts.insert(boosts.end(), levelBoosts.begin(), levelBoosts.end());
        return boosts;
    }

    std::map<characters::EnumAttributes, int> PlayerCharacterSheet::AccumulateBoosts() const
    {
        std::map<EnumAttributes, int> totalBoosts;

        // init
        for (int i = 0; i < 6; ++i)
        {
            totalBoosts[static_cast<EnumAttributes>(i)] = 0;
        }

        for (const auto &boost : GetAllAttributeBoosts())
        {
            for (int i = 0; i < 6; ++i)
            {
                EnumAttributes attr = static_cast<EnumAttributes>(i);
                totalBoosts[attr] += boost.CountAttributeInBoost(attr);
            }
        }

        return totalBoosts;
    }

    void PlayerCharacterSheet::AddLevelBoost(AttributeBoost newLevelBoost)
    {
        levelBoosts.push_back(newLevelBoost);
        CalculateAttributes();
    }

    void PlayerCharacterSheet::PrintAllAtttributes() const
    {
        std::cout << "Attributes" << std::endl;
        for (const auto pair : attributes)
        {
            std::string attrName = EnumAttributesToString.at(pair.first);
            std::cout << attrName << ": " << std::setw(15 - attrName.length()) << std::right << pair.second << std::endl;
        }
    }

    void PlayerCharacterSheet::CalculateAttributes()
    {
        for (int i = 0; i < 6; ++i)
        {
            attributes[static_cast<EnumAttributes>(i)] = 0;
        }

        std::map<EnumAttributes, int> totalBoosts = AccumulateBoosts();

        for (const auto &pair : totalBoosts)
        {
            attributes[pair.first] = CalculateAttributeValue(pair.second);
        }
    }

    int PlayerCharacterSheet::CalculateAttributeValue(int boostCount) const
    {
        if (boostCount <= 4)
        {
            return boostCount;
        }
        else
        {
            double value = 4 + (boostCount - 4) * 0.5;
            return static_cast<int>(std::floor(value));
        }
    }

    void PlayerCharacterSheet::SetSkills()
    {
        skills.push_back(Skill("Creation",
                               "Name",
                               characters::EnumAttributes::Strength,
                               characters::EnumProficiencies::Untrained));
    }

    void PlayerCharacterSheet::AddSkill(Skill newSkill)
    {
        skills.push_back(newSkill);
    }

    characters::Skill PlayerCharacterSheet::GetSkill(std::string skillName)
    {
        auto it = std::find_if(skills.begin(), skills.end(), [&skillName](const characters::Skill &obj) {return obj.GetSkillName() == skillName;});
        if (it != skills.end())
        {
            auto index = std::distance(skills.begin(), it);
            return skills.at(index);
        }
    }
}
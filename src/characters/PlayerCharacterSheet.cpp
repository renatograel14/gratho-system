#include "characters/PlayerCharacterSheet.h"
#include "characters/DefaultSkills.h"
#include "characters/PlayerCharacterVisitor.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(std::string name)
        : name(name),
          boosts({}),
          ancestry(PlayerCharacterAncestry("No Acestry", 0)),
          playerClass(PlayerCharacterClass("No Class", 0, EnumAttributes::Strength))
    {
        CalculateAttributes();
        InitializeDefaultSkills();
        CalculateTotalHealth();
    }

    void PlayerCharacterSheet::AcceptCharacterVisitor(const PlayerCharacterVisitor &visitor)
    {
        visitor.visit(*this);
    }

    const std::vector<AttributeBoost> &PlayerCharacterSheet::GetBoosts() const
    {
        return boosts;
    }

    const std::string &PlayerCharacterSheet::GetName() const
    {
        return name;
    }

    const int PlayerCharacterSheet::GetAttribute(EnumAttributes attr) const
    {
        try
        {
            return attributes.at(attr);
        }
        catch (const std::out_of_range &e)
        {
            return 0;
        }
    }

    const int &PlayerCharacterSheet::GetTotalHealth() const
    {
        return totalHealth;
    }

    void PlayerCharacterSheet::AddBoost(const AttributeBoost &newLevelBoost)
    {
        boosts.push_back(newLevelBoost);
        CalculateAttributes();
    }

    void PlayerCharacterSheet::PrintAllAttributes() const
    {
        std::cout << "Attributes" << std::endl;
        for (const auto pair : attributes)
        {
            std::string attrName = EnumAttributesToString.at(pair.first);
            std::cout << attrName << ": " << std::setw(15 - attrName.length()) << std::right << pair.second << std::endl;
        }
    }

    const Skill &PlayerCharacterSheet::GetSkill(const std::string &skillName) const
    {
        auto it = std::find_if(skills.begin(), skills.end(), [&skillName](const Skill &obj)
                               { return obj.GetSkillName() == skillName; });
        if (it != skills.end())
        {
            auto index = std::distance(skills.begin(), it);
            return skills.at(index);
        }
        throw std::invalid_argument("Skillname not found in this sheet" + skillName);
    }

    void PlayerCharacterSheet::AddSkill(const Skill &newSkill)
    {
        skills.push_back(newSkill);
    }

    // PRIVATE METHODS

    void PlayerCharacterSheet::InitializeDefaultSkills()
    {
        for (const auto &skill : DefaultSkills())
        {
            AddSkill(skill);
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

    std::map<EnumAttributes, int> PlayerCharacterSheet::AccumulateBoosts() const
    {
        std::map<EnumAttributes, int> totalBoosts;

        // init
        for (int i = 0; i < 6; ++i)
        {
            totalBoosts[static_cast<EnumAttributes>(i)] = 0;
        }

        for (const auto &boost : GetBoosts())
        {
            for (int i = 0; i < 6; ++i)
            {
                EnumAttributes attr = static_cast<EnumAttributes>(i);
                totalBoosts[attr] += boost.CountAttributeInBoost(attr);
            }
        }

        return totalBoosts;
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

    void PlayerCharacterSheet::CalculateTotalHealth()
    {
        const int &constitution = GetAttribute(EnumAttributes::Constitution);
        totalHealth = ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }
}
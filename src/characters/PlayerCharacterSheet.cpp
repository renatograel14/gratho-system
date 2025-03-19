#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include "characters/PlayerCharacterSheet.h"
#include "characters/DefaultSkills.h"
#include "characters/PlayerCharacterVisitor.h"

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(std::string name)
        : name(name),
          boosts({}),
          ancestry(PlayerCharacterAncestry("No Acestry", 0, {}, {})),
          playerClass(PlayerCharacterClass("No Class", 0, EnumAttributes::Strength, 0, {}, {}))
    {
        CalculateAttributes();
        InitializeDefaultSkills();
        CalculateTotalHealth();
    }

    void PlayerCharacterSheet::SetPlayerClass(const PlayerCharacterClass &newPlayerClass)
    {
        playerClass = newPlayerClass;
        CalculateTotalHealth();
    }

    void PlayerCharacterSheet::SetAncestry(const PlayerCharacterAncestry &newAncestry)
    {
        ancestry = newAncestry;
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

    const std::string PlayerCharacterSheet::GetName() const
    {
        return name;
    }

    const PlayerCharacterAncestry &PlayerCharacterSheet::GetAncestry() const
    {
        return ancestry;
    }

    const PlayerCharacterClass &PlayerCharacterSheet::GetPlayerClass() const
    {
        return playerClass;
    }

    const int PlayerCharacterSheet::GetAttribute(EnumAttributes attr) const
    {
        auto it = attributes.find(attr);
        if (it != attributes.end())
        {
            return it->second;
        }
        return 0;
    }

    int PlayerCharacterSheet::GetTotalHealth() const
    {
        return totalHealth;
    }

    void PlayerCharacterSheet::AddBoost(const AttributeBoost &newLevelBoost)
    {
        boosts.push_back(newLevelBoost);
        CalculateAttributes();
        CalculateTotalHealth();
    }

    std::vector<PlayerCharacterProficiency> PlayerCharacterSheet::GetProficienciesBySource(const std::string &source) const
    {
        std::vector<PlayerCharacterProficiency> filteredProficiencies;
        filteredProficiencies.reserve(proficiencies.size());

        std::copy_if(proficiencies.begin(), proficiencies.end(), std::back_inserter(filteredProficiencies),
                     [source](const PlayerCharacterProficiency &proficiency)
                     {
                         return proficiency.GetSource() == source;
                     });

        return filteredProficiencies;
    }

    std::vector<PlayerCharacterProficiency> PlayerCharacterSheet::GetProficienciesByRank(const EnumSkillRank &rank) const
    {
        std::vector<PlayerCharacterProficiency> filteredProficiencies;
        filteredProficiencies.reserve(proficiencies.size());

        std::copy_if(proficiencies.begin(), proficiencies.end(), std::back_inserter(filteredProficiencies),
                     [rank](const PlayerCharacterProficiency &proficiency)
                     {
                         return proficiency.GetRank() == rank;
                     });

        return filteredProficiencies;
    }

    const PlayerCharacterProficiency &PlayerCharacterSheet::GetProficiency(const Skill &skill) const
    {
        auto it = FindSkillIteratorByName(skill.GetSkillName());
        if (it != proficiencies.end())
        {
            return *it;
        }
        throw std::invalid_argument("No proficiency found in this sheet: " + skill.GetSkillName());
    }

    void PlayerCharacterSheet::AddProficiency(const Skill &skill, EnumSkillRank rank, const std::string &source)
    {
        auto it = FindSkillIteratorByName(skill.GetSkillName());
        if (it != proficiencies.end())
        {
            it->SetRank(rank);
            it->SetSource(source);
        }
        else
        {
            proficiencies.push_back(PlayerCharacterProficiency(source, skill, rank));
        }
    }

    std::string PlayerCharacterSheet::ToString() const
    {
        std::ostringstream oss;

        // Informações básicas do personagem
        oss << "Character Name: " << name << "\n";
        oss << "Ancestry: " << GetAncestry().GetName() << "\n";
        oss << "Class: " << GetPlayerClass().GetName() << "\n";

        oss << "\nTotal Health: " << GetTotalHealth() << "\n";

        // Atributos
        oss << "\nAttributes:\n";
        for (const auto &[attribute, value] : attributes)
        {
            oss << "  " << EnumAttributesToString.at(attribute) << ": " << value << "\n";
        }

        // Proficiências
        oss << "\nProficiencies:\n";
        for (const auto &proficiency : proficiencies)
        {
            if (proficiency.GetRank() != EnumSkillRank::Untrained)
            {
                oss << "  " << proficiency.GetSkill().GetSkillName()
                    << " (Rank: " << EnumSkillRankToString.at(proficiency.GetRank())
                    << ", Source: " << proficiency.GetSource() << ")\n";
            }
        }

        return oss.str();
    }

    // PRIVATE METHODS

    void PlayerCharacterSheet::InitializeDefaultSkills()
    {
        for (const auto &skill : DefaultSkills())
        {
            AddProficiency(skill, EnumSkillRank::Untrained, "default");
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

    std::vector<PlayerCharacterProficiency>::iterator PlayerCharacterSheet::FindSkillIteratorByName(const std::string &skillName)
    {
        return std::find_if(proficiencies.begin(), proficiencies.end(), [&skillName](const PlayerCharacterProficiency &obj)
                            { return obj.GetSkill().GetSkillName() == skillName; });
    }

    std::vector<PlayerCharacterProficiency>::const_iterator PlayerCharacterSheet::FindSkillIteratorByName(const std::string &skillName) const
    {
        return std::find_if(proficiencies.begin(), proficiencies.end(), [&skillName](const PlayerCharacterProficiency &obj)
                            { return obj.GetSkill().GetSkillName() == skillName; });
    }
}
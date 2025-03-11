#include "characters/PlayerCharacterSheet.h"
#include <cmath> 

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(
        std::string name,
        PlayerCharacterAncestry &ancestry,
        PlayerCharacterClass &playerClass)
        : name(name), ancestry(ancestry), playerClass(playerClass)
    {
        for (int i = 0; i < 6; ++i) {
            attributes[static_cast<EnumAttributes>(i)] = 0;
        }

        std::map<EnumAttributes, int> totalBoosts = AccumulateBoosts();

        for (const auto& pair : totalBoosts) {
            attributes[pair.first] = CalculateAttributeValue(pair.second);
        }
    }

    std::string PlayerCharacterSheet::GetName() const
    {
        return name;
    }

    int PlayerCharacterSheet::GetAttribute(characters::EnumAttributes attr) const
    {
        try {
            return attributes.at(attr);
        } catch (std::out_of_range) {
            return 0;
        }
    }

    int PlayerCharacterSheet::GetHealth() const
    {
        int constitution = GetAttribute(characters::EnumAttributes::Constitution);
        return ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }

    std::map<characters::EnumAttributes, int> PlayerCharacterSheet::AccumulateBoosts() const
    {
        std::map<EnumAttributes, int> totalBoosts;

        for (int i = 0; i < 6; ++i) {
            totalBoosts[static_cast<EnumAttributes>(i)] = 0;
        }

        const AttributeBoost& ancestryBoost = ancestry.GetBoost();
        for (int i = 0; i < 6; ++i) {
            EnumAttributes attr = static_cast<EnumAttributes>(i);
            totalBoosts[attr] += ancestryBoost.CountAttributeInBoost(attr);
        }

        return totalBoosts;
    }

    int PlayerCharacterSheet::CalculateAttributeValue(int boostCount) const
    {
        if (boostCount <= 4) {
            return boostCount; 
        } else {
            double value = 4 + (boostCount - 4) * 0.5;
            return static_cast<int>(std::floor(value));
        }
    }
}
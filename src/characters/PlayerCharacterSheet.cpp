#include <iostream>
#include "characters/PlayerCharacterSheet.h"
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(
        std::string name,
        PlayerCharacterAncestry &ancestry,
        PlayerCharacterClass &playerClass)
        : name(name), ancestry(ancestry), playerClass(playerClass) {}

    std::string PlayerCharacterSheet::GetName() const
    {
        return name;
    }

    int PlayerCharacterSheet::GetAttribute(characters::EnumAttributes attr) const
    {
        return ancestry.GetBoost().CountAttributeInBoost(attr);
    }

    int PlayerCharacterSheet::GetHealth() const
    {
        int constitution = GetAttribute(characters::EnumAttributes::Constitution);
        return ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }
}
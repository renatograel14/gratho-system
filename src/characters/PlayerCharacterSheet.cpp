#include <iostream>
#include "characters/PlayerCharacterSheet.h"
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(
        std::string name,
        PlayerCharacterAncestry &ancestry,
        PlayerCharacterClass &playerClass,
        std::map<characters::EnumAttributes, int> attributes)
        : name(name), ancestry(ancestry), playerClass(playerClass), attributes(attributes) {}

    int PlayerCharacterSheet::GetAttribute(characters::EnumAttributes attr) const {
        return attributes.at(attr);
    }

    int PlayerCharacterSheet::GetHealth() const {
        int constitution = GetAttribute(characters::EnumAttributes::Constitution);
        return ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }
}
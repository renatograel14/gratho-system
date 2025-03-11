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

    std::string PlayerCharacterSheet::GetName() const {
        return name;
    }

    int PlayerCharacterSheet::GetAttribute(characters::EnumAttributes attr) const {
        try {
            return attributes.at(attr);
        } catch(const std::out_of_range outOfRangeError) {
            return 0;
        }
    }

    int PlayerCharacterSheet::GetHealth() const {
        int constitution = GetAttribute(characters::EnumAttributes::Constitution);
        return ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }
}
#include <iostream>
#include <map>
#include "characters/PlayerCharacterAncestry.h"

namespace characters
{
    PlayerCharacterAncestry::PlayerCharacterAncestry(
        std::string name,
        int health,
        const std::map<EnumAttributes, bool> &boosts,
        const std::map<EnumAttributes, bool> &flaws)
        : name(name), health(health), boosts(boosts), flaws(flaws) {}

    const std::map<EnumAttributes, bool> &PlayerCharacterAncestry::GetAttributeBoosts() const
    {
        return boosts;
    }

    const std::map<EnumAttributes, bool> &PlayerCharacterAncestry::GetAttributeFlaws() const
    {
        return flaws;
    }

    const int &PlayerCharacterAncestry::GetHealth() const
    {
        return health;
    }

    const std::string &PlayerCharacterAncestry::GetName() const
    {
        return name;
    }
}
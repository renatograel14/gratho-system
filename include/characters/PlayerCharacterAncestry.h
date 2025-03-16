#ifndef PLAYER_CHARACTER_ANCESTRY_H
#define PLAYER_CHARACTER_ANCESTRY_H

#include <iostream>
#include <map>
#include "characters/AttributeBoost.h"

namespace characters
{
    class PlayerCharacterAncestry
    {
    public:
        PlayerCharacterAncestry(
            std::string name,
            int health,
            const std::map<EnumAttributes, bool> &boosts,
            const std::map<EnumAttributes, bool> &flaws);
        const int &GetHealth() const;
        const std::string &GetName() const;
        const std::map<EnumAttributes, bool> &GetAttributeBoosts() const;
        const std::map<EnumAttributes, bool> &GetAttributeFlaws() const;

    private:
        std::string name;
        std::map<EnumAttributes, bool> boosts;
        std::map<EnumAttributes, bool> flaws;
        int health;
    };

}

#endif // PLAYER_CHARACTER_ANCESTRY_H
#ifndef PLAYER_CHARACTER_CLASS_H
#define PLAYER_CHARACTER_CLASS_H
#include <iostream>
#include <map>
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"

namespace characters
{
    class PlayerCharacterClass
    {
    public:
        PlayerCharacterClass(
            std::string name,
            int health,
            EnumAttributes keyAttribute,
            int freeSkillsQuantity,
            const std::map<Skill *, bool> &givenSkills,
            const std::map<Skill *, bool> &requiredSkills);

        const int &GetHealth() const;
        const EnumAttributes &GetKeyAttribute() const;
        const std::string &GetName() const;
        int GetFreeSkillsQuantity() const;
        const std::map<Skill *, bool> &GetGivenSkills() const;
        const std::map<Skill *, bool> &GetRequiredSkills() const;

    private:
        std::string name;
        int health;

        EnumAttributes keyAttribute;

        int freeSkillsQuantity;
        std::map<Skill *, bool> givenSkills;
        std::map<Skill *, bool> requiredSkills;
    };

}

#endif // PLAYER_CHARACTER_CLASS_H
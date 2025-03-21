#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/EnumAttributes.h"
#include "characters/AttributeBoost.h"
#include "characters/Skill.h"

namespace characters
{
    PlayerCharacterClass::PlayerCharacterClass(
        std::string name,
        int health,
        characters::EnumAttributes keyAttribute,
        int freeSkillsQuantity,
        const std::map<Skill *, bool> &givenSkills,
        const std::map<Skill *, bool> &requiredSkills)
        : name(name),
          health(health),
          keyAttribute(keyAttribute),
          freeSkillsQuantity(freeSkillsQuantity),
          givenSkills(givenSkills),
          requiredSkills(requiredSkills)
    {
    }

    int PlayerCharacterClass::GetFreeSkillsQuantity() const
    {
        return freeSkillsQuantity;
    }

    const std::map<Skill *, bool> &PlayerCharacterClass::GetGivenSkills() const
    {
        return givenSkills;
    }

    const std::map<Skill *, bool> &PlayerCharacterClass::GetRequiredSkills() const
    {
        return requiredSkills;
    }

    const EnumAttributes &PlayerCharacterClass::GetKeyAttribute() const
    {
        return keyAttribute;
    }

    const int &PlayerCharacterClass::GetHealth() const
    {
        return health;
    }

    const std::string &PlayerCharacterClass::GetName() const
    {
        return name;
    }
}
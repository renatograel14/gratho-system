#include <iostream>
#include <map>
#include <vector>
#include "characters/EnumProficiences.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"

namespace characters
{
    Skill::Skill(
        std::string source,
        std::string name,
        characters::EnumAttributes attribute,
        characters::EnumProficiencies proficiency)
        : source(source),
          name(name),
          attribute(attribute),
          proficiency(proficiency)
    {
    }

    void Skill::SetSkillRank(characters::EnumProficiencies rank)
    {
        proficiency = rank;
    }

    const std::string &Skill::GetSkillName() const
    {
        return name;
    }

    const EnumProficiencies &Skill::GetProficiency() const
    {
        return proficiency;
    }
}
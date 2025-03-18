#include <iostream>
#include <map>
#include <vector>
#include "characters/EnumSkillRank.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"

namespace characters
{
    Skill::Skill(
        std::string name,
        characters::EnumAttributes attribute)
        : name(name),
          attribute(attribute)
    {
    }
    const std::string &Skill::GetSkillName() const
    {
        return name;
    }
}
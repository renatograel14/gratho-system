#ifndef SKILL_H
#define SKILL_H
#include <iostream>
#include "characters/EnumAttributes.h"
#include "characters/EnumSkillRank.h"

namespace characters
{
    class Skill
    {
    public:
        Skill(std::string name,
              characters::EnumAttributes attribute);
        const std::string &GetSkillName() const;

    private:
        std::string name;
        characters::EnumAttributes attribute;
    };

}

#endif // SKILL_H
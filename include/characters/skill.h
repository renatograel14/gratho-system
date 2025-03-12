#ifndef SKILL_H
#define SKILL_H
#include <iostream>
#include "EnumAttributes.h"
#include "EnumProficiences.h"

namespace characters
{
    class Skill
    {
    public:
        Skill(std::string source,
              std::string name,
              characters::EnumAttributes attribute,
              characters::EnumProficiencies proficiency);
        void SetSkillRank(characters::EnumProficiencies rank);
        const std::string &GetSkillName() const;

    private:
        std::string source;
        std::string name;
        characters::EnumAttributes attribute;
        characters::EnumProficiencies proficiency;
    };

}

#endif // SKILL_H
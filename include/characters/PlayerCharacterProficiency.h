#ifndef PLAYER_CHARACTER_PROFICIENCY_H
#define PLAYER_CHARACTER_PROFICIENCY_H
#include <iostream>
#include "characters/Skill.h"
#include "characters/EnumSkillRank.h"

namespace characters
{
    class PlayerCharacterProficiency
    {
    public:
        PlayerCharacterProficiency(
            std::string source,
            const Skill &skill,
            const EnumSkillRank &rank);

        const std::string &GetSource() const;
        const Skill &GetSkill() const;
        const EnumSkillRank &GetRank() const;
        void SetRank(EnumSkillRank rank);

    private:
        std::string source;
        Skill skill;
        EnumSkillRank rank;
    };

}

#endif // PLAYER_CHARACTER_PROFICIENCY_H
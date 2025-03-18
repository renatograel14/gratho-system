#ifndef PLAYER_CHARACTER_PROFICIENCY_H
#define PLAYER_CHARACTER_PROFICIENCY_H
#include <iostream>
#include "characters/Skill.h"
#include "characters/EnumProficiences.h"
#include "characters/EnumProficiences.h"

namespace characters
{
    class PlayerCharacterProficiency
    {
    public:
        PlayerCharacterProficiency(
            std::string source,
            const Skill &skill,
            const EnumProficiencies &rank);

        const Skill &GetSkill() const;
        const EnumProficiencies &GetRank() const;
        void SetRank(EnumProficiencies rank);

    private:
        std::string source;
        Skill skill;
        EnumProficiencies rank;
    };

}

#endif // PLAYER_CHARACTER_PROFICIENCY_H
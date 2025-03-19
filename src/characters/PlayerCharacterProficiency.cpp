#include <iostream>
#include <map>
#include <vector>
#include "characters/PlayerCharacterProficiency.h"
#include "characters/EnumSkillRank.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"

namespace characters
{
    PlayerCharacterProficiency::PlayerCharacterProficiency(
        std::string source,
        const Skill &skill,
        const EnumSkillRank &rank)
        : source(source), skill(skill), rank(rank) {}

    const std::string &PlayerCharacterProficiency::GetSource() const
    {
        return source;
    }

    const EnumSkillRank &PlayerCharacterProficiency::GetRank() const
    {
        return rank;
    }

    const Skill &PlayerCharacterProficiency::GetSkill() const
    {
        return skill;
    }

    void PlayerCharacterProficiency::SetRank(EnumSkillRank newRank)
    {
        rank = newRank;
    }

    void PlayerCharacterProficiency::SetSource(const std::string &newSource)
    {
        source = newSource;
    }

}
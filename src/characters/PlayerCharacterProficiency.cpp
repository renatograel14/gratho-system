#include <iostream>
#include <map>
#include <vector>
#include "characters/PlayerCharacterProficiency.h"
#include "characters/EnumProficiences.h"
#include "characters/EnumAttributes.h"
#include "characters/Skill.h"

namespace characters
{
    PlayerCharacterProficiency::PlayerCharacterProficiency(
        std::string source,
        const Skill &skill,
        const EnumProficiencies &rank)
        : source(source), skill(skill), rank(rank) {}

    const EnumProficiencies &PlayerCharacterProficiency::GetRank() const
    {
        return rank;
    }

    const Skill &PlayerCharacterProficiency::GetSkill() const
    {
        return skill;
    }

    void PlayerCharacterProficiency::SetRank(EnumProficiencies newRank)
    {
        rank = newRank;
    }

}
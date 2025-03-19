#include <iostream>
#include <map>
#include <vector>
#include <utility>
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
        : source(source), skill(skill), rank(rank)
    {
        rankHistory.push_back(std::make_pair(rank, source));
    }

    const EnumSkillRank &PlayerCharacterProficiency::GetRank() const
    {
        return rank;
    }

    const Skill &PlayerCharacterProficiency::GetSkill() const
    {
        return skill;
    }

    void PlayerCharacterProficiency::SetRank(EnumSkillRank newRank, const std::string &changeSource)
    {
        rank = newRank;
        source = changeSource;
        rankHistory.push_back(std::make_pair(newRank, changeSource));
    }

    const std::vector<std::pair<EnumSkillRank, std::string>> &PlayerCharacterProficiency::GetRankHistory() const
    {
        return rankHistory;
    }
}
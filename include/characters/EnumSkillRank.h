#ifndef ENUM_SKILL_RANK_H
#define ENUM_SKILL_RANK_H
#include <iostream>
#include <map>

namespace characters
{
    enum class EnumSkillRank
    {
        Untrained,
        Trained,
        Expert,
        Master,
        Legendary,
    };

    static const std::map<characters::EnumSkillRank, int> EnumSkillRankToValue = {
        {EnumSkillRank::Untrained, 0},
        {EnumSkillRank::Trained, 2},
        {EnumSkillRank::Expert, 4},
        {EnumSkillRank::Master, 6},
        {EnumSkillRank::Legendary, 8}};

    static const std::map<characters::EnumSkillRank, std::string> EnumSkillRankToString = {
        {EnumSkillRank::Untrained, "Untrained"},
        {EnumSkillRank::Trained, "Trained"},
        {EnumSkillRank::Expert, "Expert"},
        {EnumSkillRank::Master, "Master"},
        {EnumSkillRank::Legendary, "Lengendary"}};
}

#endif // ENUM_SKILL_RANK_H
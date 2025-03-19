#ifndef PLAYERCHARACTERPROFICIENCY_H
#define PLAYERCHARACTERPROFICIENCY_H

#include <string>
#include <vector>
#include <utility>
#include "characters/EnumSkillRank.h"
#include "characters/Skill.h"

namespace characters
{
    class PlayerCharacterProficiency
    {
    public:
        PlayerCharacterProficiency(std::string source, const Skill &skill, const EnumSkillRank &rank);

        const std::string &GetSource() const;
        const EnumSkillRank &GetRank() const;
        const Skill &GetSkill() const;

        void SetRank(EnumSkillRank newRank, const std::string &changeSource);
        void SetSource(const std::string &newSource);

        const std::vector<std::pair<EnumSkillRank, std::string>> &GetRankHistory() const;

    private:
        std::string source;
        Skill skill;
        EnumSkillRank rank;

        std::vector<std::pair<EnumSkillRank, std::string>> rankHistory;
    };
}

#endif // PLAYERCHARACTERPROFICIENCY_H
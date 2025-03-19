#ifndef SKILLTRAINING_H
#define SKILLTRAINING_H

#include <map>
#include <string>
#include "characters/Skill.h"
#include "characters/PlayerCharacterVisitor.h"
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"

namespace characters
{
    class SkillTrainingVisitor : public PlayerCharacterVisitor
    {
    public:
        explicit SkillTrainingVisitor(const std::map<Skill *, bool> &skillChoices);

        void visit(PlayerCharacterSheet &sheet) const override;

    private:
        const std::map<Skill *, bool> skillChoices;
    };
}

#endif // SKILLTRAINING_H
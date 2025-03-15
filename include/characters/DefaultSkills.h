#ifndef DEFAULT_SKILLS_H
#define DEFAULT_SKILLS_H
#include "characters/Skill.h"
#include <vector>

namespace characters
{
    std::vector<Skill> DefaultSkills()
    {
        std::vector<Skill> defaultSkills = {
            Skill("default",
                  "Acrobatics",
                  EnumAttributes::Dexterity,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Athletics",
                  EnumAttributes::Strength,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Deception",
                  EnumAttributes::Charisma,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Intimidation",
                  EnumAttributes::Charisma,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Nature",
                  EnumAttributes::Wisdom,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Performance",
                  EnumAttributes::Charisma,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Survival",
                  EnumAttributes::Wisdom,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Arcana",
                  EnumAttributes::Intelligence,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Crafting",
                  EnumAttributes::Intelligence,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Diplomacy",
                  EnumAttributes::Charisma,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Medicine",
                  EnumAttributes::Wisdom,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Occultism",
                  EnumAttributes::Intelligence,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Religion",
                  EnumAttributes::Wisdom,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Stealth",
                  EnumAttributes::Dexterity,
                  EnumProficiencies::Untrained),
            Skill("default",
                  "Thievery",
                  EnumAttributes::Dexterity,
                  EnumProficiencies::Untrained),
        };
        return defaultSkills;
    }
}

#endif // DEFAULT_SKILLS_H
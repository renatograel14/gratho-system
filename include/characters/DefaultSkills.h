#ifndef DEFAULT_SKILLS_H
#define DEFAULT_SKILLS_H
#include "characters/Skill.h"
#include <vector>

namespace characters
{
      std::vector<Skill> DefaultSkills()
      {
            std::vector<Skill> defaultSkills = {
                Skill("Acrobatics",
                      EnumAttributes::Dexterity),
                Skill("Athletics",
                      EnumAttributes::Strength),
                Skill("Deception",
                      EnumAttributes::Charisma),
                Skill("Intimidation",
                      EnumAttributes::Charisma),
                Skill("Nature",
                      EnumAttributes::Wisdom),
                Skill("Performance",
                      EnumAttributes::Charisma),
                Skill("Survival",
                      EnumAttributes::Wisdom),
                Skill("Arcana",
                      EnumAttributes::Intelligence),
                Skill("Crafting",
                      EnumAttributes::Intelligence),
                Skill("Diplomacy",
                      EnumAttributes::Charisma),
                Skill("Medicine",
                      EnumAttributes::Wisdom),
                Skill("Occultism",
                      EnumAttributes::Intelligence),
                Skill("Religion",
                      EnumAttributes::Wisdom),
                Skill("Stealth",
                      EnumAttributes::Dexterity),
                Skill("Thievery",
                      EnumAttributes::Dexterity),
            };
            return defaultSkills;
      }
}

#endif // DEFAULT_SKILLS_H
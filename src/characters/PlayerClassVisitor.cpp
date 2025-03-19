#include <map>
#include <algorithm>
#include <stdexcept>
#include "characters/PlayerClassVisitor.h"

using namespace characters;

PlayerClassVisitor::PlayerClassVisitor(
    const PlayerCharacterClass &playerClass,
    const Skill &skillChoice)
    : playerClass(playerClass), skillChoice(skillChoice)
{
}

void PlayerClassVisitor::visit(PlayerCharacterSheet &sheet) const
{
    // If there are required skills, validate them
    if (playerClass.GetRequiredSkills().size() > 0)
    {
        // Use std::any_of to check if at least one required skill matches the chosen skill
        bool isSkillChosen = std::any_of(
            playerClass.GetRequiredSkills().begin(),
            playerClass.GetRequiredSkills().end(),
            [this](const std::pair<Skill *, bool> &requiredSkill)
            {
                return requiredSkill.first->GetSkillName() == skillChoice.GetSkillName();
            });

        // If no required skill is chosen, throw an exception
        if (!isSkillChosen)
        {
            throw std::invalid_argument("At least one required skill must be chosen.");
        }
    }

    // Apply the fixed skills provided by the class
    for (const auto &pair : playerClass.GetGivenSkills())
    {
        sheet.AddProficiency(*pair.first, EnumSkillRank::Trained, playerClass.GetName());
    }

    // Apply the skills chosen by the player
    sheet.AddProficiency(skillChoice, EnumSkillRank::Trained, playerClass.GetName());

    // Set the player's class and apply the attribute boost
    sheet.SetPlayerClass(playerClass);
    sheet.AddBoost(AttributeBoost(playerClass.GetName(), {{playerClass.GetKeyAttribute(), true}}, {}));
}
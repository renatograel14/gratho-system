#include <map>
#include <algorithm>
#include <stdexcept>
#include "characters/PlayerClassVisitor.h"

using namespace characters;

PlayerClassVisitor::PlayerClassVisitor(
    const PlayerCharacterClass &playerClass,
    const std::map<std::string, bool> &skillChoices)
    : playerClass(playerClass), skillChoices(skillChoices)
{
}

void PlayerClassVisitor::visit(PlayerCharacterSheet &sheet) const
{
    // Calculate the total number of allowed skills:
    // Free skills + Given skills
    int countSkills = playerClass.GetFreeSkillsQuantity() +
                      playerClass.GetGivenSkills().size();

    // If there are required skills, validate them
    if (playerClass.GetRequiredSkills().size() > 0)
    {
        // Add a counter because the class provides an additional option between required skills
        countSkills++;

        // Use std::find_if to check if any required skill is missing in the player's choices
        auto missingSkill = std::find_if(
            playerClass.GetRequiredSkills().begin(),
            playerClass.GetRequiredSkills().end(),
            [this](const std::pair<std::string, bool> &requiredSkill)
            {
                return skillChoices.find(requiredSkill.first) == skillChoices.end();
            });

        // If a missing skill is found, throw an exception
        if (missingSkill != playerClass.GetRequiredSkills().end())
        {
            throw std::invalid_argument("Required skill not chosen: " + missingSkill->first);
        }
    }

    // Since `skillChoices` is a map, the number of selected skills must match:
    // Free skills + Given skills
    // Example:
    // Animist is trained in Religion AND a choice between Nature or Occultism, totaling 2 skills.
    // Additionally, they get 2 skills. So, 2 + 2 = 4.
    if (skillChoices.size() != countSkills)
    {
        throw std::invalid_argument("Invalid skills quantity");
    }

    // Apply the fixed skills provided by the class
    for (const auto &pair : playerClass.GetGivenSkills())
    {
        sheet.SetSkillRank(pair.first, EnumProficiencies::Trained);
    }

    // Apply the skills chosen by the player
    for (const auto &pair : skillChoices)
    {
        sheet.SetSkillRank(pair.first, EnumProficiencies::Trained);
    }

    // Set the player's class and apply the attribute boost
    sheet.SetPlayerClass(playerClass);
    sheet.AddBoost(AttributeBoost(playerClass.GetName(), {{playerClass.GetKeyAttribute(), true}}, {}));
}
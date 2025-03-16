#include "characters/PlayerClassVisitor.h"
#include <stdexcept>

using namespace characters;

PlayerClassVisitor::PlayerClassVisitor(
    PlayerCharacterClass &playerClass,
    std::vector<std::string> &skillChoices)
    : playerClass(playerClass), skillChoices(skillChoices)
{
}

void PlayerClassVisitor::visit(PlayerCharacterSheet &sheet) const
{
    if (skillChoices.size() != 5)
    {
        throw std::invalid_argument("Skill choices must be exactly 5.");
    }

    for (const auto &skill : skillChoices)
    {
        sheet.SetSkillRank(skill, EnumProficiencies::Trained);
    }

    sheet.SetPlayerClass(playerClass);
    sheet.AddBoost(AttributeBoost(playerClass.GetName(), {{playerClass.GetKeyAttribute(), true}}, {}));
}
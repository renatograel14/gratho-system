#include <map>
#include <algorithm>
#include <stdexcept>
#include "characters/Skill.h"
#include "characters/SkillTrainingVisitor.h"

using namespace characters;

SkillTrainingVisitor::SkillTrainingVisitor(
    const std::map<Skill *, bool> &skillChoices)
    : skillChoices(skillChoices) {}

void SkillTrainingVisitor::visit(PlayerCharacterSheet &sheet) const
{
    auto untrainedProficiencies = sheet.GetProficienciesByRank(EnumSkillRank::Untrained);
    auto alreadyTrainedProficiencies = sheet.GetProficienciesBySource("Skill Training");

    int shouldBeTrained = sheet.GetPlayerClass().GetFreeSkillsQuantity() +
                          sheet.GetAttribute(EnumAttributes::Intelligence);

    for (const auto &pair : skillChoices)
    {
        Skill *skill = pair.first;
        auto it = std::find_if(untrainedProficiencies.begin(), untrainedProficiencies.end(),
                               [skill](const PlayerCharacterProficiency &proficiency)
                               {
                                   return proficiency.GetSkill().GetSkillName() == skill->GetSkillName();
                               });

        if (it == untrainedProficiencies.end())
        {
            throw std::invalid_argument("One or more skills you selected is already trained");
        }
    }

    int totalTrained = alreadyTrainedProficiencies.size() + skillChoices.size();
    if (totalTrained > shouldBeTrained)
    {
        throw std::invalid_argument("The number of skills selected has exceed the maximum: " + shouldBeTrained);
    }

    // Adiciona as novas habilidades treinadas
    for (const auto &pair : skillChoices)
    {
        sheet.AddProficiency(*pair.first, EnumSkillRank::Trained, "Skill Training");
    }
}
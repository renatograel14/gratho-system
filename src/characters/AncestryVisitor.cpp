#include "characters/AncestryVisitor.h"
#include <stdexcept>

using namespace characters;

AncestryVisitor::AncestryVisitor(
    PlayerCharacterAncestry &ancestry,
    std::map<EnumAttributes, bool> &boostChoices,
    std::map<EnumAttributes, bool> &flawChoices)
    : ancestry(ancestry), boostChoices(boostChoices), flawChoices(flawChoices)
{
}

void AncestryVisitor::visit(PlayerCharacterSheet &sheet) const
{
    if (boostChoices.size() == 3 && flawChoices.size() != 1)
    {
        throw std::invalid_argument("Invalid boost or flaw choices.");
    }

    sheet.SetAncestry(ancestry);
    sheet.AddBoost(AttributeBoost(ancestry.GetName(), boostChoices, flawChoices));
}
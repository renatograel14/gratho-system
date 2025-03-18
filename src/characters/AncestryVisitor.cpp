#include "characters/AncestryVisitor.h"
#include <stdexcept>

using namespace characters;

AncestryVisitor::AncestryVisitor(
    PlayerCharacterAncestry &ancestry,
    const std::map<EnumAttributes, bool> &boostChoices,
    const std::map<EnumAttributes, bool> &flawChoices)
    : ancestry(ancestry), boostChoices(boostChoices), flawChoices(flawChoices)
{
}

void AncestryVisitor::visit(PlayerCharacterSheet &sheet) const
{
    auto boostChoicesAux = boostChoices;
    auto flawChoicesAux = flawChoices;

    // merge ancestry boost into choices
    for (const auto &[key, value] : ancestry.GetAttributeBoosts())
    {
        boostChoicesAux[key] = value;
    }

    // merge ancestry flaws into choices
    for (const auto &[key, value] : ancestry.GetAttributeFlaws())
    {
        flawChoicesAux[key] = value;
    }

    sheet.SetAncestry(ancestry);
    sheet.AddBoost(AttributeBoost(ancestry.GetName(), boostChoicesAux, flawChoicesAux));
}
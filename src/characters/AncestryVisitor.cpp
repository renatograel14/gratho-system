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

    // validate if has more than one flaw
    if (flawChoicesAux.size() > 1)
    {
        throw std::invalid_argument("More than one flaw");
    }

    // validate number of boosts
    if (boostChoicesAux.size() < 2 || boostChoicesAux.size() > 3)
    {
        throw std::invalid_argument("Invalid number of boosts");
    }

    // validate u can only has 3 boosts if you have one flaw
    if (boostChoicesAux.size() == 3 and flawChoicesAux.size() == 0)
    {
        throw std::invalid_argument("Invalid you have to get a flaw for having 3 boosts.");
    }

    sheet.SetAncestry(ancestry);
    sheet.AddBoost(AttributeBoost(ancestry.GetName(), boostChoicesAux, flawChoicesAux));
}
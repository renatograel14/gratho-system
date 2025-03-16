#ifndef ANCESTRYVISITOR_H
#define ANCESTRYVISITOR_H

#include <map>
#include "characters/PlayerCharacterVisitor.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"

namespace characters
{
    class AncestryVisitor : public PlayerCharacterVisitor
    {
    private:
        PlayerCharacterAncestry &ancestry;
        const std::map<EnumAttributes, bool> &boostChoices;
        const std::map<EnumAttributes, bool> &flawChoices;

    public:
        AncestryVisitor(
            PlayerCharacterAncestry &ancestry,
            const std::map<EnumAttributes, bool> &boostChoices,
            const std::map<EnumAttributes, bool> &flawChoices);

        void visit(PlayerCharacterSheet &sheet) const override;
    };
}

#endif // ANCESTRYVISITOR_H
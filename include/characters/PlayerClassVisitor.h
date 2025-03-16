#ifndef PLAYERCLASSVISITOR_H
#define PLAYERCLASSVISITOR_H

#include <map>
#include <string>
#include "characters/PlayerCharacterVisitor.h"
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"

namespace characters
{
    class PlayerClassVisitor : public PlayerCharacterVisitor
    {
    public:
        PlayerClassVisitor(
            const PlayerCharacterClass &playerClass,
            const std::map<std::string, bool> &skillChoices);

        void visit(PlayerCharacterSheet &sheet) const override;

    private:
        PlayerCharacterClass playerClass;
        std::map<std::string, bool> skillChoices;
    };
}

#endif // PLAYERCLASSVISITOR_H
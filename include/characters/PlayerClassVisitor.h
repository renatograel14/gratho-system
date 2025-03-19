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
            const Skill &skillChoice);

        void visit(PlayerCharacterSheet &sheet) const override;

    private:
        PlayerCharacterClass playerClass;
        Skill skillChoice;
    };
}

#endif // PLAYERCLASSVISITOR_H
#ifndef PLAYERCLASSVISITOR_H
#define PLAYERCLASSVISITOR_H

#include <vector>
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
    private:
        PlayerCharacterClass playerClass;
        std::vector<std::string> skillChoices;

    public:
        PlayerClassVisitor(
            PlayerCharacterClass &playerClass,
            std::vector<std::string> &skillChoices);

        void visit(PlayerCharacterSheet &sheet) const override;
    };
}

#endif // PLAYERCLASSVISITOR_H
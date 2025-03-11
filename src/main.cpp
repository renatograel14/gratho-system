#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"

int main()
{
    std::cout << "Running..." << std::endl;

    characters::PlayerCharacterClass fighter("Fighter", 10, characters::EnumAttributes::Strength);

    std::map<characters::EnumAttributes, bool> boost = {
        {characters::EnumAttributes::Strength, true},
        {characters::EnumAttributes::Constitution, true},
        {characters::EnumAttributes::Dexterity, true},
    };
    std::map<characters::EnumAttributes, bool> flaw = {
        {characters::EnumAttributes::Intelligence, true},
    };
    characters::AttributeBoost humanBoost("Human", boost, flaw);
    characters::PlayerCharacterAncestry human("Human", 8, humanBoost);

    characters::AttributeBoost firstLevelBoost("Level 1", {
        {characters::EnumAttributes::Strength, true},
        {characters::EnumAttributes::Constitution, true},
        {characters::EnumAttributes::Intelligence, true},
        {characters::EnumAttributes::Dexterity, true},
    }, {});
    characters::PlayerCharacterSheet playerCharacterFighter("José", human, fighter, firstLevelBoost);

    characters::AttributeBoost fifthLevelBoost("Level 5", {
        {characters::EnumAttributes::Strength, true},
        {characters::EnumAttributes::Constitution, true},
        {characters::EnumAttributes::Intelligence, true},
        {characters::EnumAttributes::Dexterity, true},
    }, {});
    playerCharacterFighter.AddLevelBoost(fifthLevelBoost);

    std::cout << "Name: " << playerCharacterFighter.GetName() << std::endl;
    std::cout << "Max Health Points: " << playerCharacterFighter.GetHealth() << std::endl;
    return 0;
}
#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"


int main()
{
    std::cout << "Running..." << std::endl;

    characters::PlayerCharacterClass fighter("Fighter", 10);
    characters::EnumAttributes boost[6] = {characters::EnumAttributes::Constitution, characters::EnumAttributes::Dexterity};
    characters::EnumAttributes flaw[6] = {};
    characters::AttributeBoost humanBoost("Human", boost, flaw);
    characters::PlayerCharacterAncestry human("Human", 8, humanBoost);

    std::map<characters::EnumAttributes, int> attr = {
        {characters::EnumAttributes::Strength, 4},
        {characters::EnumAttributes::Dexterity, 2},
        {characters::EnumAttributes::Constitution, 1},
        {characters::EnumAttributes::Intelligence, -2},
        {characters::EnumAttributes::Winsdom, 2},
        {characters::EnumAttributes::Charisma, 0}};

    characters::PlayerCharacterSheet playerCharacterFighter("José", human, fighter, attr);

    std::cout << "Name: " << playerCharacterFighter.GetName() << std::endl;
    std::cout << "Max Health Points: " << playerCharacterFighter.GetHealth() << std::endl;
    return 0;
}
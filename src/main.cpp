#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/EnumAttributes.h"

int main()
{
    std::cout << "Running..." << std::endl;

    characters::PlayerCharacterAncestry human("Human", 8);
    characters::PlayerCharacterClass fighter("Fighter", 10);

    std::map<characters::EnumAttributes, int> attr = {{characters::EnumAttributes::Strength, 0}, {characters::EnumAttributes::Dexterity, 0}, {characters::EnumAttributes::Constitution, 2}, {characters::EnumAttributes::Intelligence, 0}, {characters::EnumAttributes::Winsdom, 0}, {characters::EnumAttributes::Charisma, 0}};

    characters::PlayerCharacterSheet playerCharacterFighter("José", human, fighter, attr);


    std::cout << "Name: " << playerCharacterFighter.GetName() << std::endl;
    std::cout << "Max Health Points: " << playerCharacterFighter.GetHealth() << std::endl;
    return 0;
}
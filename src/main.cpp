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
       { characters::EnumAttributes::Strength,true},
       { characters::EnumAttributes::Intelligence,true},
       { characters::EnumAttributes::Dexterity,true},
    };
    std::map<characters::EnumAttributes, bool> flaw = {
        { characters::EnumAttributes::Constitution,true},
     };
    characters::AttributeBoost humanBoost("Human", boost, flaw);
    characters::PlayerCharacterAncestry human("Human", 8, humanBoost);

    characters::PlayerCharacterSheet playerCharacterFighter("José", human, fighter);

    std::cout << "Name: " << playerCharacterFighter.GetName() << std::endl;
    std::cout << "Max Health Points: " << playerCharacterFighter.GetHealth() << std::endl;
    return 0;
}
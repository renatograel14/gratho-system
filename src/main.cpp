#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"

int main() {
    std::cout << "Running...";

    characters::PlayerCharacterAncestry human("Human", 8);
    
    characters::PlayerCharacterClassHealth figherHealth = {"constitution", 10};
    characters::PlayerCharacterClass fighter("Fighter", figherHealth);
    characters::PlayerCharacterSheet playerCharacterFighter("José", human, fighter);

    return 0;
}
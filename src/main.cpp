#include <iostream>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"

int main() {
    std::cout << "Running...";

    characters::PlayerCharacterAncestry human("Human", 8);
    characters::PlayerCharacterClass fighter("Fighter");
    characters::PlayerCharacterSheet playerCharacterFighter("José", human, fighter);

    return 0;
}
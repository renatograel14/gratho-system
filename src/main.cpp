// src/main.cpp
#include "characters/Person.h"
#include "items/Weapon.h"
#include <iostream>

int main() {
    items::Weapon sword(20);
    characters::Person player(100, sword);

    std::cout << "Player health: " << player.GetHealth() << std::endl;
    std::cout << "Weapon damage: " << player.GetWeapon().GetDamage() << std::endl;

    player.TakeDamage(30);
    std::cout << "Player health after damage: " << player.GetHealth() << std::endl;

    return 0;
}
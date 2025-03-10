// src/characters/Person.cpp
#include "characters/Person.h"

namespace characters {

Person::Person(int health, const items::Weapon& weapon)
    : health(health), weapon(weapon) {}

void Person::TakeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

int Person::GetHealth() const {
    return health;
}

const items::Weapon& Person::GetWeapon() const {
    return weapon;
}

} // namespace characters
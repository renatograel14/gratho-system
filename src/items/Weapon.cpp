// src/items/Weapon.cpp
#include "items/Weapon.h"

namespace items {

Weapon::Weapon(int damage) : damage(damage) {}

int Weapon::GetDamage() const {
    return damage;
}

void Weapon::SetDamage(int newDamage) {
    damage = newDamage;
}

} // namespace items
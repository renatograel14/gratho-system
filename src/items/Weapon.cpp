// src/items/Weapon.cpp
#include "items/Weapon.h"

namespace items {

Weapon::Weapon(int damage) : damage(damage) {}

int Weapon::GetDamage() const {
    return damage;
}

} // namespace items
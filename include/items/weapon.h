// include/items/Weapon.h
#ifndef ITEMS_WEAPON_H
#define ITEMS_WEAPON_H

namespace items {

class Weapon {
public:
    Weapon(int damage);
    int GetDamage() const;

private:
    int damage;
};

} // namespace items

#endif // ITEMS_WEAPON_H
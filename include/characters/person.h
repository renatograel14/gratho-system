// include/person/Person.h
#ifndef PERSON_PERSON_H
#define PERSON_PERSON_H
#include "items/weapon.h"

namespace characters {

class Person {
public:
    Person(int health, items::Weapon& weapon);
    void TakeDamage(int amount);
    
    int GetHealth() const;

    const items::Weapon& GetWeapon() const;
    void SetWeapon(items::Weapon& newWeapon);

private:
    int health;
    items::Weapon& weapon;
};

}

#endif // PERSON_PERSON_H
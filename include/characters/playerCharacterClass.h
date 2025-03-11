#ifndef PLAYER_CHARACTER_CLASS_H
#define PLAYER_CHARACTER_CLASS_H
#include <iostream>

namespace characters
{
    class PlayerCharacterClass
    {
    public:
        PlayerCharacterClass(std::string name, int health);
        int GetHealth() const;

    private:
        std::string name;
        int health;
    };

}

#endif // PLAYER_CHARACTER_CLASS_H
#ifndef PLAYER_CHARACTER_ANCESTRY_H
#define PLAYER_CHARACTER_ANCESTRY_H

#include <iostream>

namespace characters
{
    class PlayerCharacterAncestry
    {
    public:
        PlayerCharacterAncestry(std::string name, int health);
        int GetHealth() const;

    private:
        std::string name;
        int health;
    };

}

#endif // PLAYER_CHARACTER_ANCESTRY_H
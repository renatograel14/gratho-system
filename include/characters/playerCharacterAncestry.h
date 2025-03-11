#ifndef PLAYER_CHARACTER_ANCESTRY_H
#define PLAYER_CHARACTER_ANCESTRY_H

#include <iostream>

namespace characters
{
    class PlayerCharacterAncestry
    {
    public:
        PlayerCharacterAncestry(std::string name);

    private:
        std::string name;
    };

}

#endif // PLAYER_CHARACTER_ANCESTRY_H
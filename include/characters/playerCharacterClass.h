#ifndef PLAYER_CHARACTER_CLASS_H
#define PLAYER_CHARACTER_CLASS_H
#include <iostream>

namespace characters
{
    struct PlayerCharacterClassHealth
    {
        std::string attribute;
        int healthPoints;
    };
    
    class PlayerCharacterClass
    {
    public:
        PlayerCharacterClass(std::string name, PlayerCharacterClassHealth health);

    private:
        std::string name;
        PlayerCharacterClassHealth health;
    };

}

#endif // PLAYER_CHARACTER_CLASS_H
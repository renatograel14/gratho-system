#ifndef ENUM_PROFICIENCIES_H
#define ENUM_PROFICIENCIES_H

namespace characters
{
    enum class EnumProficiencies
    {
        Untrained,
        Trained,
        Expert,
        Master,
        Legendary,
    };

    static const std::map<EnumProficiencies, int> EnumProficienciesToValue = {
        {EnumProficiencies::Untrained, 0},
        {EnumProficiencies::Trained, 2},
        {EnumProficiencies::Expert, 4},
        {EnumProficiencies::Master, 6},
        {EnumProficiencies::Legendary, 8}
    };
}

#endif // ENUM_PROFICIENCIES_H
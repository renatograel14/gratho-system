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

    static const std::map<characters::EnumProficiencies, int> EnumProficienciesToValue = {
        {EnumProficiencies::Untrained, 0},
        {EnumProficiencies::Trained, 2},
        {EnumProficiencies::Expert, 4},
        {EnumProficiencies::Master, 6},
        {EnumProficiencies::Legendary, 8}};

    static const std::map<characters::EnumProficiencies, std::string> EnumProficienciesToString = {
        {EnumProficiencies::Untrained, "Untrained"},
        {EnumProficiencies::Trained, "Trained"},
        {EnumProficiencies::Expert, "Expert"},
        {EnumProficiencies::Master, "Master"},
        {EnumProficiencies::Legendary, "Lengendary"}};
}

#endif // ENUM_PROFICIENCIES_H
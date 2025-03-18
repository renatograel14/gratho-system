#ifndef ENUM_ATTRIBUTES_H
#define ENUM_ATTRIBUTES_H

#include <string>
#include <map>

namespace characters
{
    enum class EnumAttributes
    {
        Strength,
        Dexterity,
        Constitution,
        Intelligence,
        Wisdom,
        Charisma,
        None,
    };

    static const std::map<EnumAttributes, std::string> EnumAttributesToString =
        {
            {EnumAttributes::Strength, "Strength"},
            {EnumAttributes::Dexterity, "Dexterity"},
            {EnumAttributes::Constitution, "Constitution"},
            {EnumAttributes::Intelligence, "Intelligence"},
            {EnumAttributes::Wisdom, "Wisdom"},
            {EnumAttributes::Charisma, "Charisma"},
            {EnumAttributes::None, "None"},
    };

    static const std::map<std::string, EnumAttributes> StringToEnumAttributes = {
        {"Strength", EnumAttributes::Strength},
        {"Dexterity", EnumAttributes::Dexterity},
        {"Constitution", EnumAttributes::Constitution},
        {"Intelligence", EnumAttributes::Intelligence},
        {"Wisdom", EnumAttributes::Wisdom},
        {"Charisma", EnumAttributes::Charisma},
        {"None", EnumAttributes::None},
    };
}

#endif // ENUM_ATTRIBUTES_H
#ifndef ATTRIBUTE_BOOST_H
#define ATTRIBUTE_BOOST_H

#include <iostream>
#include "characters/EnumAttributes.h"

namespace characters
{
    class AttributeBoost
    {
    public:
        AttributeBoost(
            std::string source,
            characters::EnumAttributes (&boost)[6],
            characters::EnumAttributes (&flaw)[6]);

        int CountAttributeInBoost(characters::EnumAttributes attr) const;

    private:
        std::string source;
        characters::EnumAttributes (&boost)[6];
        characters::EnumAttributes (&flaw)[6];
    };

}

#endif // ATTRIBUTE_BOOST_H
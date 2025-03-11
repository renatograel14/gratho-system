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
            std::map<characters::EnumAttributes, bool> boost,
            std::map<characters::EnumAttributes, bool> flaw);

        int CountAttributeInBoost(characters::EnumAttributes attr) const;

    private:
        std::string source;
        std::map<characters::EnumAttributes, bool> boost;
        std::map<characters::EnumAttributes, bool> flaw;
    };

}

#endif // ATTRIBUTE_BOOST_H
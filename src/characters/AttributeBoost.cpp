#include <iostream>
#include "characters/AttributeBoost.h"

namespace characters
{
    AttributeBoost::AttributeBoost(
        std::string source,
        characters::EnumAttributes (&boost)[6],
        characters::EnumAttributes (&flaw)[6]
    ) : source(source), boost(boost), flaw(flaw) {}

    int AttributeBoost::CountAttributeInBoost(characters::EnumAttributes attr) const
    {
        int count = 0;
        for (int i = 0; i < 6; ++i) {
            if (boost[i] == attr) {
                count++;
            }
        }
        for (int i = 0; i < 6; ++i) {
            if (flaw[i] == attr) {
                count--;
            }
        }
        return count;
    }
}
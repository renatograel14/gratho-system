#include <iostream>
#include "characters/AttributeBoost.h"

namespace characters
{
    AttributeBoost::AttributeBoost(
        std::string source,
        characters::EnumAttributes (&boost)[6],
        characters::EnumAttributes (&flaw)[6]
    ) : source(source), boost(boost), flaw(flaw) {}
}
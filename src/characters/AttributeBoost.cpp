#include <iostream>
#include <algorithm>
#include "characters/AttributeBoost.h"

namespace characters
{
    AttributeBoost::AttributeBoost(
        std::string source,
        const std::map<characters::EnumAttributes, bool> &boost,
        const std::map<characters::EnumAttributes, bool> &flaw) : source(source), boost(boost), flaw(flaw) {}

    int AttributeBoost::CountAttributeInBoost(characters::EnumAttributes attr) const
    {
        const int countBoost = std::count_if(boost.begin(), boost.end(), [attr](std::pair<characters::EnumAttributes, bool> const &pair)
                                             { return pair.first == attr && pair.second; });

        const int countFlaw = std::count_if(flaw.begin(), flaw.end(), [attr](std::pair<characters::EnumAttributes, bool> const &pair)
                                            { return pair.first == attr && pair.second; });

        return countBoost - countFlaw;
    }
}
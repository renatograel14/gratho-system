#include <iostream>
#include "characters/AttributeBoost.h"

namespace characters
{
    AttributeBoost::AttributeBoost(
        std::string source,
        std::map<characters::EnumAttributes, bool> boost,
        std::map<characters::EnumAttributes, bool> flaw
    ) : source(source), boost(boost), flaw(flaw) {}

    int AttributeBoost::CountAttributeInBoost(characters::EnumAttributes attr) const
    {

        int count = 0;
        for(const auto& pair : boost) {
            if(pair.first == attr && pair.second) {
                count++;
            }
        }

        for(const auto& pair : flaw) {
            if(pair.first == attr && pair.second) {
                count--;
            }
        }
        return count;
    }
}
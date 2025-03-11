#include "characters/PlayerCharacterSheet.h"
#include <cmath> // Para usar a função std::floor

namespace characters
{
    PlayerCharacterSheet::PlayerCharacterSheet(
        std::string name,
        PlayerCharacterAncestry &ancestry,
        PlayerCharacterClass &playerClass)
        : name(name), ancestry(ancestry), playerClass(playerClass)
    {
        // Inicializa os atributos com valores base (por exemplo, 0)
        for (int i = 0; i < 6; ++i) {
            attributes[static_cast<EnumAttributes>(i)] = 0;
        }

        // Acumula os boosts de todas as fontes
        std::map<EnumAttributes, int> totalBoosts = AccumulateBoosts();

    // Aplica os boosts acumulados aos atributos
        for (const auto& pair : totalBoosts) {
            attributes[pair.first] = CalculateAttributeValue(pair.second);
        }
    }

    std::string PlayerCharacterSheet::GetName() const
    {
        return name;
    }

    int PlayerCharacterSheet::GetAttribute(characters::EnumAttributes attr) const
    {
        // Retorna o valor do atributo (já com os boosts aplicados)
        return attributes.at(attr);
    }

    int PlayerCharacterSheet::GetHealth() const
    {
        int constitution = GetAttribute(characters::EnumAttributes::Constitution);
        return ancestry.GetHealth() + playerClass.GetHealth() + constitution;
    }

    std::map<characters::EnumAttributes, int> PlayerCharacterSheet::AccumulateBoosts() const
    {
        std::map<EnumAttributes, int> totalBoosts;

        // Inicializa os boosts totais com 0
        for (int i = 0; i < 6; ++i) {
            totalBoosts[static_cast<EnumAttributes>(i)] = 0;
        }

        // Acumula os boosts da ancestry
        const AttributeBoost& ancestryBoost = ancestry.GetBoost();
        for (int i = 0; i < 6; ++i) {
            EnumAttributes attr = static_cast<EnumAttributes>(i);
            totalBoosts[attr] += ancestryBoost.CountAttributeInBoost(attr);
        }

        return totalBoosts;
    }

    int PlayerCharacterSheet::CalculateAttributeValue(int boostCount) const
    {
        if (boostCount <= 4) {
            return boostCount; // Até 4 boosts, valor = número de boosts
        } else {
            // Acima de 4 boosts, cada boost adicional aumenta 0.5
            double value = 4 + (boostCount - 4) * 0.5;
            return static_cast<int>(std::floor(value)); // Arredonda para baixo
        }
    }
}
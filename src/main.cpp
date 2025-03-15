#include <iostream>
#include <vector>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"
#include "characters/PlayerCharacterVisitor.h"

class FighterVisitor : public characters::PlayerCharacterVisitor
{
private:
    std::vector<std::string> skillChoices;

public:
    explicit FighterVisitor(std::vector<std::string> &skillChoices) : skillChoices(skillChoices) {}
    void visit(characters::PlayerCharacterSheet &sheet) const override
    {

        // validar se Acrobatics ou Athletics estão presentes nas escolhas
        if (skillChoices.size() != 5)
        {
            throw std::invalid_argument("");
        }

        for (const auto &skill : skillChoices)
        {
            sheet.SetSkillRank(skill, characters::EnumProficiencies::Trained);
        }

        sheet.AddBoost(characters::AttributeBoost("Fighter", {{characters::EnumAttributes::Strength, true}}, {}));

        sheet.SetPlayerClass(characters::PlayerCharacterClass("Fighter", 10, characters::EnumAttributes::Strength));
        std::cout
            << sheet.GetName() << ": Now, I'm a fighter class" << std::endl;
    }
};

class HumanVisitor : public characters::PlayerCharacterVisitor
{
private:
    std::map<characters::EnumAttributes, bool> boostChoices;
    std::map<characters::EnumAttributes, bool> flawChoices;

public:
    HumanVisitor(
        std::map<characters::EnumAttributes, bool> &boostChoices,
        std::map<characters::EnumAttributes, bool> &flawChoices) : boostChoices(boostChoices), flawChoices(flawChoices) {}

    void visit(characters::PlayerCharacterSheet &sheet) const override
    {
        sheet.SetAncestry(characters::PlayerCharacterAncestry("Human", 8));

        if (boostChoices.size() == 3 && flawChoices.size() != 1)
        {
            throw std::invalid_argument("");
        }

        sheet.AddBoost(characters::AttributeBoost("Human", boostChoices, flawChoices));
        std::cout << sheet.GetName() << ": Now, I'm a human ancestry" << std::endl;
    }
};

int main()
{
    using namespace characters;
    using namespace std;
    cout << "Running..." << endl;

    PlayerCharacterSheet playerCharacterFighter("José");

    map<EnumAttributes, bool> humanBoostChoices = {
        {EnumAttributes::Strength, true},
        {EnumAttributes::Constitution, true},
        {EnumAttributes::Dexterity, true},
    };

    map<EnumAttributes, bool> humanFlawChoices = {
        {{EnumAttributes::Intelligence, true}}};

    playerCharacterFighter.AcceptCharacterVisitor(
        HumanVisitor(humanBoostChoices, humanFlawChoices));

    vector<string> fighterSkillChoices = {"Athletics", "Acrobatics", "Deception", "Intimidation", "Stealth"};

    playerCharacterFighter.AcceptCharacterVisitor(FighterVisitor(fighterSkillChoices));

    cout << endl;
    cout << endl;
    cout << "Name: " << playerCharacterFighter.GetName() << endl;
    cout << "Health Points: " << playerCharacterFighter.GetTotalHealth() << endl;
    playerCharacterFighter.PrintAllAttributes();
    cout << endl;
    cout << endl;
    return 0;
}
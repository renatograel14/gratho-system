#include <iostream>
#include <vector>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"
#include "characters/PlayerCharacterVisitor.h"

using namespace characters;
using namespace std;

class FighterVisitor : public PlayerCharacterVisitor
{
private:
    vector<string> skillChoices;

public:
    explicit FighterVisitor(vector<string> &skillChoices) : skillChoices(skillChoices) {}
    void visit(PlayerCharacterSheet &sheet) const override
    {
        // validar se Acrobatics ou Athletics estão presentes nas escolhas
        if (skillChoices.size() != 5)
        {
            throw invalid_argument("");
        }

        for (const auto &skill : skillChoices)
        {
            sheet.SetSkillRank(skill, EnumProficiencies::Trained);
        }

        PlayerCharacterClass fighter("Fighter", 10, EnumAttributes::Strength);
        sheet.SetPlayerClass(fighter);
        sheet.AddBoost(AttributeBoost("Fighter", {{fighter.GetKeyAttribute(), true}}, {}));

        cout
            << sheet.GetName() << ": Now, I'm a fighter class" << endl;
    }
};

class HumanVisitor : public PlayerCharacterVisitor
{
private:
    map<EnumAttributes, bool> boostChoices;
    map<EnumAttributes, bool> flawChoices;

public:
    HumanVisitor(
        map<EnumAttributes, bool> &boostChoices,
        map<EnumAttributes, bool> &flawChoices) : boostChoices(boostChoices), flawChoices(flawChoices) {}

    void visit(PlayerCharacterSheet &sheet) const override
    {
        sheet.SetAncestry(PlayerCharacterAncestry("Human", 8));

        if (boostChoices.size() == 3 && flawChoices.size() != 1)
        {
            throw invalid_argument("");
        }

        sheet.AddBoost(AttributeBoost("Human", boostChoices, flawChoices));
        cout << sheet.GetName() << ": Now, I'm a human ancestry" << endl;
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
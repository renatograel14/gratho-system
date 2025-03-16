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

class PlayerClassVisitor : public PlayerCharacterVisitor
{
private:
    PlayerCharacterClass playerClass;
    vector<string> skillChoices;

public:
    PlayerClassVisitor(
        PlayerCharacterClass &playerClass,
        vector<string> &skillChoices)
        : playerClass(playerClass), skillChoices(skillChoices)
    {
    }
    void visit(PlayerCharacterSheet &sheet) const override
    {
        // validar se skills que a classe fornece playerClass.GetAvailableSkills()
        if (skillChoices.size() != 5)
        {
            throw invalid_argument("");
        }

        for (const auto &skill : skillChoices)
        {
            sheet.SetSkillRank(skill, EnumProficiencies::Trained);
        }

        sheet.SetPlayerClass(playerClass);
        sheet.AddBoost(AttributeBoost(playerClass.GetName(), {{playerClass.GetKeyAttribute(), true}}, {}));
    }
};

class AncestryVisitor : public PlayerCharacterVisitor
{
private:
    PlayerCharacterAncestry ancestry;
    map<EnumAttributes, bool> boostChoices;
    map<EnumAttributes, bool> flawChoices;

public:
    AncestryVisitor(
        PlayerCharacterAncestry &ancestry,
        map<EnumAttributes, bool> &boostChoices,
        map<EnumAttributes, bool> &flawChoices) : ancestry(ancestry), boostChoices(boostChoices), flawChoices(flawChoices) {}

    void visit(PlayerCharacterSheet &sheet) const override
    {

        // validate attribute boost by ancestry available boosts
        if (boostChoices.size() == 3 && flawChoices.size() != 1)
        {
            throw invalid_argument("");
        }

        sheet.SetAncestry(ancestry);
        sheet.AddBoost(AttributeBoost(ancestry.GetName(), boostChoices, flawChoices));
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
    PlayerCharacterAncestry human("Human", 8);

    playerCharacterFighter.AcceptCharacterVisitor(
        AncestryVisitor(human, humanBoostChoices, humanFlawChoices));

    PlayerCharacterClass fighter("Fighter", 10, EnumAttributes::Strength);
    vector<string> fighterSkillChoices = {"Athletics", "Acrobatics", "Deception", "Intimidation", "Stealth"};
    PlayerClassVisitor fighterVisitor(fighter, fighterSkillChoices);

    playerCharacterFighter.AcceptCharacterVisitor(fighterVisitor);

    cout << endl;
    cout << endl;
    cout << "Name: " << playerCharacterFighter.GetName() << endl;
    cout << "Health Points: " << playerCharacterFighter.GetTotalHealth() << endl;
    playerCharacterFighter.PrintAllAttributes();
    cout << endl;
    cout << endl;
    return 0;
}
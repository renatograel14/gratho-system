#include <iostream>
#include <vector>
#include <map>
#include "characters/PlayerCharacterClass.h"
#include "characters/PlayerCharacterAncestry.h"
#include "characters/PlayerCharacterSheet.h"
#include "characters/AttributeBoost.h"
#include "characters/EnumAttributes.h"
#include "characters/PlayerCharacterVisitor.h"
#include "characters/PlayerClassVisitor.h"
#include "characters/AncestryVisitor.h"

using namespace characters;
using namespace std;

int main()
{
    cout << "Running..." << endl;

    PlayerCharacterSheet playerCharacterFighter("José");

    map<EnumAttributes, bool> humanBoostChoices = {
        {EnumAttributes::Strength, true},
        {EnumAttributes::Constitution, true},
        {EnumAttributes::Dexterity, true},
    };

    map<EnumAttributes, bool> humanFlawChoices = {
        {EnumAttributes::Intelligence, true}};
    PlayerCharacterAncestry human("Human", 8);

    playerCharacterFighter.AcceptCharacterVisitor(
        AncestryVisitor(human, humanBoostChoices, humanFlawChoices));

    PlayerCharacterClass fighter("Fighter", 10, EnumAttributes::Strength);
    vector<string> fighterSkillChoices = {"Athletics", "Acrobatics", "Deception", "Intimidation", "Stealth"};
    PlayerClassVisitor fighterVisitor(fighter, fighterSkillChoices);

    playerCharacterFighter.AcceptCharacterVisitor(fighterVisitor);

    cout
        << "\n";
    cout << "\n";
    cout << "Name: " << playerCharacterFighter.GetName() << "\n";
    cout << "Ancestry: " << playerCharacterFighter.GetAncestry().GetName() << "\n";
    cout << "Class: " << playerCharacterFighter.GetPlayerClass().GetName() << "\n";
    cout << "Athletics Skill: " << EnumProficienciesToString.at(playerCharacterFighter.GetSkill("Athletics").GetProficiency()) << "\n";
    cout << "Health Points: " << playerCharacterFighter.GetTotalHealth() << "\n";
    playerCharacterFighter.PrintAllAttributes();
    cout << "\n";
    cout << "\n";
    return 0;
}
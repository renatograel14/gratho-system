#include <iostream>
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

Skill Athletics("Athletics", EnumAttributes::Strength);
Skill Acrobatics("Acrobatics", EnumAttributes::Dexterity);
Skill Survival("Survival", EnumAttributes::Dexterity);
Skill Intimidation("Intimidation", EnumAttributes::Charisma);

int main()
{
    cout << "Running..." << endl;

    PlayerCharacterSheet playerCharacterFighter("José");

    PlayerCharacterAncestry elf("Elf", 6,
                                {
                                    {EnumAttributes::Dexterity, true},
                                    {EnumAttributes::Intelligence, true},
                                },
                                {{EnumAttributes::Constitution, true}});

    playerCharacterFighter.AcceptCharacterVisitor(
        AncestryVisitor(elf, {{EnumAttributes::Strength, true}}, {}));

    PlayerCharacterClass fighter("Fighter", 10, EnumAttributes::Strength, 3, {},
                                 {
                                     {&Athletics, true},
                                     {&Acrobatics, true},
                                 });

    PlayerClassVisitor fighterVisitor(fighter,
                                      {{&Athletics, true},
                                       {&Acrobatics, true},
                                       {&Survival, true},
                                       {&Intimidation, true}});

    playerCharacterFighter.AcceptCharacterVisitor(fighterVisitor);

    playerCharacterFighter.AddBoost(AttributeBoost("Level 1",
                                                   {
                                                       {EnumAttributes::Strength, true},
                                                       {EnumAttributes::Dexterity, true},
                                                       {EnumAttributes::Intelligence, true},
                                                       {EnumAttributes::Constitution, true},
                                                   },
                                                   {}));

    cout << "\n";
    cout << "\n";
    cout << "Name: " << playerCharacterFighter.GetName() << "\n";
    cout << "Ancestry: " << playerCharacterFighter.GetAncestry().GetName() << "\n";
    cout << "Class: " << playerCharacterFighter.GetPlayerClass().GetName() << "\n";
    cout << "Athletics Skill: " << EnumProficienciesToString.at(playerCharacterFighter.GetProficiency(Athletics).GetRank()) << "\n";
    cout << "Health Points: " << playerCharacterFighter.GetTotalHealth() << "\n";
    playerCharacterFighter.PrintAllAttributes();
    cout << "\n";
    cout << "\n";
    return 0;
}
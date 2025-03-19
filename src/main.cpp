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
#include "characters/SkillTrainingVisitor.h"

using namespace characters;
using namespace std;

Skill Athletics("Athletics", EnumAttributes::Strength);
Skill Acrobatics("Acrobatics", EnumAttributes::Dexterity);
Skill Survival("Survival", EnumAttributes::Dexterity);
Skill Society("Society", EnumAttributes::Charisma);
Skill Intimidation("Intimidation", EnumAttributes::Charisma);
Skill Arcana("Arcana", EnumAttributes::Charisma);
Skill Occultism("Occultism", EnumAttributes::Charisma);
Skill SimpleWeapons("SimpleWeapons", EnumAttributes::None);
Skill MartialWeapon("MartialWeapon", EnumAttributes::None);

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

    PlayerCharacterClass fighter("Fighter", 10, EnumAttributes::Strength, 3,
                                 {
                                     {&SimpleWeapons, true},
                                     {&MartialWeapon, true},
                                 },
                                 {
                                     {&Athletics, true},
                                     {&Acrobatics, true},
                                 });

    PlayerClassVisitor fighterVisitor(fighter, Athletics);

    playerCharacterFighter.AcceptCharacterVisitor(fighterVisitor);

    playerCharacterFighter.AddBoost(AttributeBoost("Level 1",
                                                   {
                                                       {EnumAttributes::Strength, true},
                                                       {EnumAttributes::Dexterity, true},
                                                       {EnumAttributes::Intelligence, true},
                                                       {EnumAttributes::Constitution, true},
                                                   },
                                                   {}));

    playerCharacterFighter.AcceptCharacterVisitor(SkillTrainingVisitor(
        {
            {&Survival, true},
            {&Intimidation, true},
            {&Society, true},
        }));
    playerCharacterFighter.AcceptCharacterVisitor(SkillTrainingVisitor(
        {
            {&Acrobatics, true},
            {&Arcana, true},
        }));

    cout << "\n";
    cout << "\n";
    cout << playerCharacterFighter.ToString() << "\n";
    cout << "\n";
    cout << Athletics.GetSkillName() << " modifier: " << EnumSkillRankToValue.at(playerCharacterFighter.GetProficiency(Athletics).GetRank()) << "\n";
    cout << "\n";
    return 0;
}
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
public:
    void visit(characters::PlayerCharacterSheet &sheet) const override
    {
        std::cout << sheet.GetName() << ": Now, I'm a fighter class" << std::endl;
    }
};

class HumanVisitor : public characters::PlayerCharacterVisitor
{
private:
    std::vector<characters::EnumAttributes> boostChoices;
    std::vector<characters::EnumAttributes> flawChoices;

public:
    HumanVisitor(
        std::vector<characters::EnumAttributes> boostChoices,
        std::vector<characters::EnumAttributes> flawChoices) : boostChoices(boostChoices), flawChoices(flawChoices) {}

    void visit(characters::PlayerCharacterSheet &sheet) const override
    {
        std::cout << sheet.GetName() << ": Now, I'm a human ancestry" << std::endl;
    }
};

int main()
{
    using namespace characters;
    using namespace std;
    cout << "Running..." << endl;

    PlayerCharacterSheet playerCharacterFighter("José");
    playerCharacterFighter.AcceptCharacterVisitor(HumanVisitor({}, {}));
    playerCharacterFighter.AcceptCharacterVisitor(FighterVisitor());

    cout << endl;
    cout << endl;
    cout << "Name: " << playerCharacterFighter.GetName() << endl;
    cout << "Health Points: " << playerCharacterFighter.GetTotalHealth() << endl;
    playerCharacterFighter.PrintAllAttributes();
    cout << endl;
    cout << endl;
    return 0;
}
#ifndef CHARACTER_VISITOR_H
#define CHARACTER_VISITOR_H

namespace characters
{
    class PlayerCharacterSheet;

    class PlayerCharacterVisitor
    {
    public:
        virtual ~PlayerCharacterVisitor() = default;
        virtual void visit(PlayerCharacterSheet &sheet) const = 0;
    };

}
#endif // CHARACTER_VISITOR_H
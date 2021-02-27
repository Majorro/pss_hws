#ifndef CABINET
#define CABINET

#include"../Abstracts/Room.cpp"

class Cabinet : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl

public:
    Cabinet(int roomFloor)
    : Room(roomFloor)
    {
        this->requiredAccessLevel = RedAccess;
    }
};
#endif /* CABINET */
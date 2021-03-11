#ifndef CLASS_ROOM
#define CLASS_ROOM

#include"../Abstracts/Room.cpp"

class ClassRoom : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl
public:
    ClassRoom(int roomFloor)
    : Room(roomFloor)
    {
        this->requiredAccessLevel = YellowAccess;
    }
};
#endif /* CLASS_ROOM */
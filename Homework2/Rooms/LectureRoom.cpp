#ifndef LECTURE_ROOM
#define LECTURE_ROOM

#include"../Abstracts/Room.cpp"

class LectureRoom : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl
    
public:
    LectureRoom(int roomFloor)
    : Room(roomFloor)
    {
        this->requiredAccessLevel = BlueAccess;
    }
};

#endif /* LECTURE_ROOM */
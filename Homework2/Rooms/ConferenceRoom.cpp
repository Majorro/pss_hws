#ifndef CONFERENCE_ROOM
#define CONFERENCE_ROOM

#include"../Abstracts/Room.cpp"

class ConferenceRoom : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl

public:
    ConferenceRoom(int roomFloor)
    : Room(roomFloor)
    {
        if(roomFloor == 1)
            this->requiredAccessLevel = BlueAccess;
        else
            this->requiredAccessLevel = GreenAccess;
    }
};

#endif /* CONFERENCE_ROOM */
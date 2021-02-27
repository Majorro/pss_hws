#ifndef CONFERENCE_ROOM
#define CONFERENCE_ROOM

class ConferenceRoom : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl
public:
    ConferenceRoom(int roomFloor)
    : Room(roomFloor)
    {
        this->requiredAccessLevel = GreenAccess;
    }
};

#endif /* CONFERENCE_ROOM */
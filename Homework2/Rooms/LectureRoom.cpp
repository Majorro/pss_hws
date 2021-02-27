#ifndef LECTURE_ROOM
#define LECTURE_ROOM

class LectureRoom : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl
public:
    LectureRoom(int roomFloor)
    : Room(roomFloor)
    {
        this->requiredAccessLevel = YellowAccess;
    }
};

#endif /* LECTURE_ROOM */
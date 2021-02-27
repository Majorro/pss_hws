#ifndef CABINET
#define CABINET

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
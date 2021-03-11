#ifndef DIRECTOR_CABINET
#define DIRECTOR_CABINET

#include<iostream>
#include"../Abstracts/Room.cpp"

class DirectorCabinet : public Room
{
private:
    void IamAbstract() override {}; //legendary costyl
    static bool isCreated;

public:
    DirectorCabinet(int roomFloor)
    : Room(roomFloor)
    {
        if(isCreated)
            throw std::logic_error("Director cabined has already built");
        else
        {
            this->requiredAccessLevel = FullAccess;
            isCreated = 1;
        }
    }

    static bool IsAdded()
    {
        return isCreated;
    }
};

bool DirectorCabinet::isCreated = 0;

#endif /* DIRECTOR_CABINET */
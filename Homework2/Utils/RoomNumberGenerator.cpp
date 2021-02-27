#ifndef ROOM_NUMBER_COUNTER
#define ROOM_NUMBER_COUNTER

#include<iostream>

class RoomNumberGenerator
{
public:
    static const int lowestFloor = 1, // can't be less than 0 and more than highestFloor
                     highestFloor = 5, // can't be less than highestFloor
                     maxRoomsOnFloor = 100; //should be the power of 10
    static int GetNextRoomOnFloor(int floor)
    {
        if(floors[floor-1]==maxRoomsOnFloor)
            throw std::runtime_error("There's no space on floor to make a room");
        return floors[floor-1]++;
    }

private:
    static int floors[highestFloor];
};

int RoomNumberGenerator::floors[RoomNumberGenerator::highestFloor] = {0, 0, 0, 0};

#endif /* ROOM_NUMBER_COUNTER */
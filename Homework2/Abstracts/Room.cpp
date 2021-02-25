#ifndef ROOM
#define ROOM

#include<iostream>
#include"../Utils/RoomNumberCounter.cpp"

class Room
{
private:
    const int lowestFloor = RoomNumberCounter::lowestFloor,
              highestFloor = RoomNumberCounter::highestFloor;
    int roomFullNumber, roomNumber, roomFloor;
    AccessLevel requiredAccessLevel;
public:
    Room(int roomFloor) // in children constructors requiredAccessLevel should be initialized
    {
        if(roomFloor < lowestFloor || roomFloor > highestFloor)
            throw std::invalid_argument("Invalid room floor was given");
        this->roomFloor = roomFloor;
        this->roomNumber = RoomNumberCounter::GetNextRoomOnFloor(roomFloor);
        this->roomFullNumber = this->roomFloor*RoomNumberCounter::maxRoomsOnFloor+
                               this->roomNumber;
    }

    // GETTERS SETTERS
    virtual AccessLevel GetRequiredAccessLevel()
    {
        return requiredAccessLevel;
    }
    virtual int GetRoomNumber() const
    {
        return roomFullNumber;
    }
    // END GETTERS SETTERS
};
inline bool operator==(const Room& lhs, const Room& rhs){ return lhs.GetRoomNumber() == rhs.GetRoomNumber(); }
inline bool operator!=(const Room& lhs, const Room& rhs){ return !operator==(lhs,rhs);}
inline bool operator< (const Room& lhs, const Room& rhs){ return lhs.GetRoomNumber() < rhs.GetRoomNumber(); }
#endif /* ROOM */
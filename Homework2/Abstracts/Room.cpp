#ifndef ROOM
#define ROOM

#include<iostream>
#include<string>
#include"../Utils/AccessLevel.cpp"
#include"../Utils/RoomNumberGenerator.cpp"
#include"../Utils/Utils.cpp"

//do not instantiate this!!!!!!(can't make true abstract:[)
class Room
{
protected:
    AccessLevel requiredAccessLevel;
    virtual void IamAbstract(){}; // legendary costyl

private:
    const int lowestFloor = RoomNumberGenerator::lowestFloor,
              highestFloor = RoomNumberGenerator::highestFloor;
    int roomFullNumber, roomNumber, roomFloor;
    
public:
    Room(int roomFloor) // requiredAccessLevel should be initialized in children constructors
    {
        if(roomFloor < lowestFloor || roomFloor > highestFloor)
            throw std::invalid_argument("Invalid room floor was given");
        this->roomFloor = roomFloor;
        this->roomNumber = RoomNumberGenerator::GetNextRoomOnFloor(roomFloor);
        this->roomFullNumber = this->roomFloor*RoomNumberGenerator::maxRoomsOnFloor+ // typical formula for room numbering
                               this->roomNumber;
        this->requiredAccessLevel = GreenAccess;
        std::cout << this->ToString() << " has built\n"+std::string(80,'-')+"\n";
    }

    // GETTERS SETTERS
    AccessLevel GetRequiredAccessLevel()
    {
        return requiredAccessLevel;
    }
    int GetRoomNumber() const
    {
        return roomFullNumber;
    }
    // END GETTERS SETTERS

    std::string ToString()
    {
        std::string typeName = Utils::TypeNameToHumanString(typeid(*this).name());
        return typeName+" #"+std::to_string(this->roomFullNumber);
    }
};
inline bool operator==(const Room& lhs, const Room& rhs){ return lhs.GetRoomNumber() == rhs.GetRoomNumber(); }
inline bool operator!=(const Room& lhs, const Room& rhs){ return !operator==(lhs,rhs);}
inline bool operator< (const Room& lhs, const Room& rhs){ return lhs.GetRoomNumber() < rhs.GetRoomNumber(); }

#endif /* ROOM */
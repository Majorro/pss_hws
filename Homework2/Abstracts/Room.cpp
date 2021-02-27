#ifndef ROOM
#define ROOM

#include"../Utils/RoomNumberCounter.cpp"

//do not instantinate this!!!!!!(can't make true abstract because c++)
class Room
{
protected:
    AccessLevel requiredAccessLevel;
    virtual void IamAbstract(){};

private:
    const int lowestFloor = RoomNumberCounter::lowestFloor,
              highestFloor = RoomNumberCounter::highestFloor;
    int roomFullNumber, roomNumber, roomFloor;
    
public:
    Room(int roomFloor) // requiredAccessLevel should be initialized in children constructors
    {
        if(roomFloor < lowestFloor || roomFloor > highestFloor)
            throw std::invalid_argument("Invalid room floor was given");
        this->roomFloor = roomFloor;
        this->roomNumber = RoomNumberCounter::GetNextRoomOnFloor(roomFloor);
        this->roomFullNumber = this->roomFloor*RoomNumberCounter::maxRoomsOnFloor+
                               this->roomNumber;
        this->requiredAccessLevel = GreenAccess;
        std::cout << this->ToString() << " was built\n";
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

#include"../Rooms/Cabinet.cpp"
#include"../Rooms/ClassRoom.cpp"
#include"../Rooms/ConferenceRoom.cpp"
#include"../Rooms/DirectorCabinet.cpp"
#include"../Rooms/LectureRoom.cpp"

#endif /* ROOM */
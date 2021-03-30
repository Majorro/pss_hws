// #define DEBUG

#include"Abstracts/Room.cpp"
#include"Abstracts/User.cpp"
#include"Rooms/Cabinet.cpp"
#include"Rooms/ClassRoom.cpp"
#include"Rooms/ConferenceRoom.cpp"
#include"Rooms/DirectorCabinet.cpp"
#include"Rooms/LectureRoom.cpp"
#include"Users/Admin.cpp"
#include"Users/Director.cpp"
#include"Users/LabEmployee.cpp"
#include"Users/Professor.cpp"
#include"Users/Student.cpp"
#include"Users/Guest.cpp"

int main()
{
#ifdef DEBUG
    freopen("Homework2/out.txt", "w", stdout);
#endif

    Director director("Kirill", "Semenikhin", 33);
    Admin admin("Aaron", "Aaronov", 20);
    Professor professor("Nikolay", "Shilov", 48, DM);
    LabEmployee le("agafon", "agafonov", 24, Robotics);
    Student student("albert", "akhmukhametov", 18, 1);
    Guest guest("aziz", "azizov", 25);

    Cabinet cabinet(1);
    ClassRoom classRoom(1);
    ConferenceRoom conferenceRoom1(1);
    ConferenceRoom conferenceRoom2(2);
    DirectorCabinet directorCabinet(5);
    LectureRoom lectureRoom(1);

    // You can't create second director user or director cabinet object
    // it will throw exception
    // Director director2("a", "a", 5);
    // DirectorCabinet(1);

    admin.TakePrivilegeFromUser(student, cabinet);

    // User with level less than roomlevel can't access it
    professor.RequestAccessToRoom(directorCabinet); // rejected

    // Admin can change access level of users
    admin.SetUserAccessLevel(professor, directorCabinet.GetRequiredAccessLevel());
    professor.RequestAccessToRoom(directorCabinet); // accessed
    
    // Also admin can give and take access privileges on exact rooms to users
    student.RequestAccessToRoom(cabinet); // rejected
    admin.GivePrivilegeToUser(student, cabinet);
    student.RequestAccessToRoom(cabinet); // accessed
    admin.TakePrivilegeFromUser(student, cabinet);
    student.RequestAccessToRoom(cabinet); // rejected
    // All rooms objects are "immutable" so set of privileges will work properly

    // Guests can only access lecture rooms and conference ones which are on the 1st floor
    guest.RequestAccessToRoom(lectureRoom);
    guest.RequestAccessToRoom(conferenceRoom1);
    guest.RequestAccessToRoom(conferenceRoom2);
    guest.RequestAccessToRoom(cabinet);

    // if emergent situation, then all doors are opened
    Room::isEmergency = 1;
    guest.RequestAccessToRoom(cabinet);
    le.RequestAccessToRoom(directorCabinet);
    return 0;
}
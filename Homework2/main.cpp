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

int main()
{
#ifdef DEBUG
    freopen("Homework2/out.txt", "w", stdout);
#endif

    Director director("Kirill", "Semenikhin", 33);
    Admin admin1("Aaron", "Aaronov", 20);
    Admin admin2("Avraam", "Avraamov", 25);
    Professor nikolay("Nikolay", "Shilov", 48, DM);
    Professor eugene("Eugene", "Zouev", 50, PSS);
    Professor frolov("Andrey", "Frolov", 34, DM);
    Professor manuel("Manuel", "Mazzara", 35, TCS);
    LabEmployee agafon("agafon", "agafonov", 24, Robotics);
    LabEmployee azat("azat", "azatov", 32, Robotics);
    LabEmployee ayrat("ayrat", "ayratov", 28, BioInformatics);
    LabEmployee alexander("alexander", "alexandrov", 29, BioInformatics);
    LabEmployee alim("alim", "alimov", 44, InfoSec);
    LabEmployee albert("albert", "albertov", 27, InfoSec);
    LabEmployee anar("anar", "anarov", 18, SoftEngineering);
    LabEmployee angel("angel", "angelov", 150, SoftEngineering);
    Student albert2("albert", "akhmukhametov", 18, 1);
    Student andrey("andrey", "plekhov", 19, 1);
    Student daler("daler", "zakirov", 19, 1);
    Student sandiman("andrey", "sandimirov", 18, 1);
    Student marat("vadim", "makarov", 19, 1);
    Student arseniy("arseniy", "levochkin", 19, 1);
    Student vagif("vagif", "khalilov", 18, 1);
    Student anfim("anfim", "anfimov", 20, 2);
    Student arman("arman", "armanov", 21, 2);
    Student arslan("arslan", "arslanov", 20, 2);
    Student arhip("arhip", "arhipov", 22, 3);
    Student askhat("askhat", "askhatov", 22, 3);
    Student abram("abram", "abramov", 23, 3);
    Student agap("agap", "agapov", 24, 4);
    Student adam("adam", "adamov", 24, 4);
    Student aziz("aziz", "azizov", 25, 4);

    Cabinet cabinet(1);
    ClassRoom classRoom(1);
    ConferenceRoom conferenceRoom(1);
    DirectorCabinet directorCabinet(5);
    LectureRoom lectureRoom(1);

    // You can't create second director user or director cabinet object
    // it will throw exception
    // Director director2("a", "a", 5);
    // DirectorCabinet(1);

    admin2.TakePrivilegeFromUser(andrey, cabinet);

    // User with level less than roomlevel can't access it
    nikolay.RequestAccessToRoom(directorCabinet); // rejected

    // Admin can change access level of users
    admin1.SetUserAccessLevel(nikolay, directorCabinet.GetRequiredAccessLevel());
    nikolay.RequestAccessToRoom(directorCabinet); // accessed
    
    // Also admin can give and take access privileges on exact rooms to users
    andrey.RequestAccessToRoom(cabinet); // rejected
    admin1.GivePrivilegeToUser(andrey, cabinet);
    andrey.RequestAccessToRoom(cabinet); // accessed
    admin2.TakePrivilegeFromUser(andrey, cabinet);
    andrey.RequestAccessToRoom(cabinet); // rejected
    // All rooms objects are "immutable" so set of privileges will work properly

    /* 
        Project isn't ideal, but I've tried to catch all buggy places, and make everything encapsulated and data-secure.
        However, I had to add some kostyls and allowances like creation Room object, pseudo-singleton
        director things and so on. On the other hand, there's some automated features like convertions to string
        or room number generation. I'd recommend to check everything in Abstracts/ and Utils/, also Users/Admin and maybe Users/Director,
        because they're the most ungeneric files in project, all remaining files mostly similar.
        Also, header files are pretty useless in this case(homework:)) and spend a lot of time(I've already written a lot of redundant code-_-),
        but if it had been a real project, I'd necessarily have added them.
    */ 
    return 0;
}
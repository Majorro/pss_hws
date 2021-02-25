#ifndef ADMIN
#define ADMIN

#include<iostream>
#include<string>

#include"../Abstracts/Room.cpp"
#include"../Abstracts/User.cpp"

class Admin : public User
{
public:
    Admin(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        this->accessLevel = AdminAccess;
    }

    // GETTERS SETTERS
    // END GETTERS SETTERS

    // ADMIN INTERACTION COSTYLS
    void SetAccessLevelToUser(User& user, AccessLevel accessLevel)
    {
        user.SetAccessLevel(*this, accessLevel);
    }

    void AddPrivilegeToUser(User& user, Room room)
    {
        user.AddPrivilege(*this, room);
    }

    void TakePrivilegeFromUser(User& user, Room room)
    {
        user.TakePrivilege(*this, room);
    }
    // END ADMIN INTERACTION COSTYLS

    bool IsAdmin() override
    {
        return 1;
    }
};

#endif /* ADMIN */
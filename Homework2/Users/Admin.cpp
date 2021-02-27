#ifndef ADMIN
#define ADMIN

#include<string>
#include"../Abstracts/User.cpp"
#include"../Abstracts/Room.cpp"
#include"../Utils/AccessLevel.cpp"

class Admin : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    
public:
    Admin(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        this->accessLevel = AdminAccess;
    }

    // ADMIN INTERACTION COSTYLS
    void SetUserAccessLevel(User& user, AccessLevel accessLevel)
    {
        user.SetAccessLevel(*this, accessLevel);
    }

    void GivePrivilegeToUser(User& user, Room& room)
    {
        user.AddPrivilege(*this, room);
    }

    void TakePrivilegeFromUser(User& user, Room& room)
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
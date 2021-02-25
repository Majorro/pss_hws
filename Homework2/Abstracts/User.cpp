#ifndef USER
#define USER

#include<string>
#include<set>

class Admin;

class User
{
protected:
    AccessLevel accessLevel;
private:
    std::string name, surname; // TODO: add checkers and formatters
    int age;
    std::set<Room> privileges; // specific rooms which can be opened by exact user
public:
    User(std::string name, std::string surname, int age) // in children constructors requiredAccessLevel should be initialized
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    // GETTERS SETTERS
    virtual std::string GetName()
    {
        return name;
    }
    virtual std::string GetSurname()
    {
        return surname;
    }
    virtual int GetAge()
    {
        return age;
    }
    virtual AccessLevel GetAccessLevel()
    {
        return accessLevel;
    }
    virtual std::set<Room> GetPrivileges()
    {
        return privileges;
    }
    // END GETTERS SETTERS

    // ADMIN INTERACTION COSTYLS
    void SetAccessLevel(Admin& admin, AccessLevel accessLevel)
    {
        this->accessLevel = accessLevel;
    }
    void AddPrivilege(Admin& admin, Room room)
    {
        privileges.insert(room);
    }
    void TakePrivilege(Admin& admin, Room room)
    {
        try
        {
            privileges.erase(room);
        }
        catch(...)
        {
            std::cout << "User "+this->name+" "+this->surname+" has no privelege on room №" << room.GetRoomNumber() << '\n'
                      << "Nothing changed\n";
        }
    }
    // END ADMIN INTERACTION COSTYLS

    bool HasAccessToRoom(Room& room){ return this->accessLevel >= room.GetRequiredAccessLevel(); }

    bool requestAccessToRoom(Room& room)
    {
        if(this->HasAccessToRoom(room))
        {
            std::cout << "Room successfully opened!\n";
            return 1;
        }
        else
        {
            std::cout << "Room is still closed, required access level is"
                      << room.GetRequiredAccessLevel() << '\n';
            return 0;
        }
    }

    bool HasPrivilege(Room room)
    {
        return privileges.find(room) != privileges.end();
    }

    virtual bool IsAdmin()
    {
        return 0;
    }
};

#include"../Users/Admin.cpp"
// #include"../Users/Director.cpp"
// #include"../Users/LabEmployee.cpp"
// #include"../Users/Professor.cpp"
// #include"../Users/Student.cpp"

#endif /* USER */
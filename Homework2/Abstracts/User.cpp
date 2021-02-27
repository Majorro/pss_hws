#ifndef USER
#define USER

class Admin;



class User
{
protected:
    AccessLevel accessLevel;
    virtual void IamAbstract()=0;
    
private:
    std::string name, surname;
    int age;
    std::set<Room> privileges; // specific rooms which can be opened by exact user
    void FormatName(std::string& name)
    {
        if(name.empty())
            throw std::invalid_argument("Empty argument was given");
        name[0] = std::toupper(name[0]);
        std::transform(name.begin()+1, name.end(), name.begin()+1, [](char c){ return std::tolower(c); });
    }

public:
    User(std::string name, std::string surname, int age) // accessLevel should be initialized in children constructors 
    {
        if(age<0||age>150)
            throw std::invalid_argument("Wrong age was given to user");
        if(name.empty() || surname.empty())
            throw std::invalid_argument("Empty name or surname was given");

        FormatName(name); FormatName(surname);
        this->name = name;
        this->surname = surname;
        this->age = age;
        
        this->accessLevel = GreenAccess;
        std::cout << this->ToString()+" was added\n";
    }

    // GETTERS SETTERS
    std::string GetName()
    {
        return name;
    }
    std::string GetSurname()
    {
        return surname;
    }
    int GetAge()
    {
        return age;
    }
    AccessLevel GetAccessLevel()
    {
        return accessLevel;
    }
    std::set<Room> GetPrivileges()
    {
        return privileges;
    }
    // END GETTERS SETTERS

    // ADMIN INTERACTION COSTYLS
    void SetAccessLevel(Admin& admin, AccessLevel accessLevel)
    {
        std::cout << this->name+" "+this->surname+"'s access level was successfully changed from " <<
                  this->accessLevel << " to " << accessLevel << '\n';
        this->accessLevel = accessLevel;
    }
    void AddPrivilege(Admin& admin, Room& room)
    {
        privileges.insert(room);
        std::cout << this->ToString()+" got privelege on room №" << room.GetRoomNumber() << '\n'; //got or has got?
    }
    void TakePrivilege(Admin& admin, Room& room)
    {
        try
        {
            privileges.erase(room);
            std::cout << this->ToString()+" lost privelege on room №" << room.GetRoomNumber() << '\n';
        }
        catch(...)
        {
            std::cout << this->ToString()+" has no privelege on room №" << room.GetRoomNumber() << '\n'
                      << "Nothing changed\n";
        }
    }
    // END ADMIN INTERACTION COSTYLS

    bool HasAccessToRoom(Room& room){ return this->accessLevel >= room.GetRequiredAccessLevel(); }

    bool RequestAccessToRoom(Room& room)
    {
        std::cout << this->ToString()+" is trying to open "+room.ToString() << '\n';
        for(int i = 0; i < 3; ++i) // illusion of working
        {
            std::cout << ".";
            sleep(1);
        }
        std::cout << '\n';
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

    bool HasPrivilege(Room& room)
    {
        return privileges.find(room) != privileges.end();
    }

    std::string ToString()
    {
        std::string typeName = Utils::TypeNameToHumanString(typeid(*this).name());
        return typeName+" "+this->name+" "+this->surname;
    }

    virtual bool IsAdmin()
    {
        return 0;
    }
};

#include"../Users/Admin.cpp"
#include"../Users/Director.cpp"
#include"../Users/LabEmployee.cpp"
#include"../Users/Professor.cpp"
#include"../Users/Student.cpp"

#endif /* USER */
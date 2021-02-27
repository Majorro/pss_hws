#ifndef USER
#define USER

#include<iostream>
#include<set>
#include<string>
#include<unistd.h>
#include<algorithm>
#include"../Utils/AccessLevel.cpp"
#include"../Utils/Utils.cpp"
#include"../Abstracts/Room.cpp"

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
    void FormatName(std::string& name) // name is one's name) converts to Udddd
    {
        if(name.empty())
            throw std::invalid_argument("Argument cannot be empty");
        name[0] = std::toupper(name[0]);
        std::transform(name.begin()+1, name.end(), name.begin()+1, [](char c){ return std::tolower(c); });
    }

public:
    User(std::string name, std::string surname, int age) // accessLevel should be initialized in children constructors 
    {
        if(age<0||age>150)
            throw std::invalid_argument("Wrong age was given to user");
        if(name.empty() || surname.empty())
            throw std::invalid_argument("Name and surname cannot be empty");
        for(auto c : name)
            if(!isalpha(c))
                std::invalid_argument("Name should contain only letters");
        for(auto c : surname)
            if(!isalpha(c))
                std::invalid_argument("Surname should contain only letters");                
        FormatName(name); FormatName(surname);
        this->name = name;
        this->surname = surname;
        this->age = age;
        
        this->accessLevel = GreenAccess;
        std::cout << this->ToString()+" was added\n"+std::string(80,'-')+"\n";
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
    void SetAccessLevel(Admin& admin, AccessLevel accessLevel) // admin object parameter like "key", which lets change this user's access level
    {
        std::cout << this->name+" "+this->surname+"'s access level has successfully changed from " <<
                  this->accessLevel << " to " << accessLevel << "\n"+std::string(80,'-')+"\n";
        this->accessLevel = accessLevel;
    }
    void AddPrivilege(Admin& admin, Room& room)
    {
        privileges.insert(room);
        std::cout << this->ToString()+" has gotten privilege on room #" << room.GetRoomNumber() << "\n"+std::string(80,'-')+"\n"; //got or has gotten?
    }
    void TakePrivilege(Admin& admin, Room& room)
    {
        if(privileges.erase(room))
            std::cout << this->ToString()+" has lost privilege on room #" << room.GetRoomNumber() << "\n"+std::string(80,'-')+"\n";
        else
        {
            std::cout << this->ToString()+" has no privilege on room #" << room.GetRoomNumber() << '\n'
                      << "Nothing has changed\n"+std::string(80,'-')+"\n";
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
            std::cout << "Room has successfully opened!\n"+std::string(80,'-')+"\n";
            return 1;
        }
        else if(this->privileges.find(room) != this->privileges.end())
        {
            std::cout << this->ToString()+" has privilege on this room\n";
            std::cout << "Room has successfully opened!\n"+std::string(80,'-')+"\n";
            return 1;
        }
        else
        {
            std::cout << "Room is still closed, required access level is "
                      << room.GetRequiredAccessLevel() << "\n"+std::string(80,'-')+"\n";
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

#endif /* USER */
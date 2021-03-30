#ifndef GUEST
#define GUEST

#include<string>
#include"../Abstracts/User.cpp"

class Guest : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    
public:
    Guest(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        this->accessLevel = BlueAccess;
    }

    // GETTERS SETTERS
    // END GETTERS SETTERS
};

#endif /* GUEST */
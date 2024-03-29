#ifndef DIRECTOR
#define DIRECTOR

#include<string>
#include<iostream>
#include"../Abstracts/User.cpp"

class Director : public User // TODO: think how to make more bug-secure
{
private:
    void IamAbstract() override {}; //legendary costyl
    static bool isCreated;

public:

    Director(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        if(isCreated)
            throw std::logic_error("Director has already added");
        else
        {
            this->accessLevel = FullAccess;
            isCreated = 1;
        }
    }

    static bool IsAdded()
    {
        return Director::isCreated;
    }
};

bool Director::isCreated = 0;

#endif /* DIRECTOR */
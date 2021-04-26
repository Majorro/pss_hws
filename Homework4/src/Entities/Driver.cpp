#pragma once

#include<vector>
#include"AppUser.cpp"
#include"Car.cpp"

struct Driver : public AppUser
{
    std::vector<Car*> Cars;
    bool IsWorking;
    bool IsInRide;

    Driver() : AppUser()
    {}
    Driver(std::string name, std::string login, std::string password)
        : AppUser(name, login, password)
    {}
};


#pragma once

#include<set>
#include"AppUser.cpp"
#include"../Enums/PaymentMethod.cpp"
#include"Address.cpp"

struct Passenger : public AppUser
{
    std::set<PaymentMethod> PaymentMethods;
    std::set<Address> PinnedAddresses;

    Passenger() : AppUser()
    {}
    Passenger(std::string name, std::string login, std::string password)
        : AppUser(name, login, password)
    {}
};

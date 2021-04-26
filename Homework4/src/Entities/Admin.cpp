#pragma once

#include<string>
#include"SystemUser.cpp"

struct Admin : public SystemUser
{
    Admin() : SystemUser()
    {}
    Admin(std::string login, std::string password)
        : SystemUser(login, password)
    {}
};

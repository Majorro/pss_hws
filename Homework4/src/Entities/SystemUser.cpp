#pragma once

#include<string>
#include"Entity.cpp"

struct SystemUser : public Entity
{
    std::string Login;
    std::string Password;
    
    SystemUser() : Entity()
    {}
    SystemUser(std::string login, std::string password)
        : Entity()
    {
        Login = login;
        Password = password;
    }
};
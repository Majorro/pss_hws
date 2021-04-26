#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"SystemUser.cpp"
#include"Order.cpp"

struct AppUser : public SystemUser
{
    std::string Name;
    double Rating;
    int RatedCnt;
    std::vector<Order*> OrderHistory;
    
    AppUser() : SystemUser()
    {}
    AppUser(std::string name, std::string login, std::string password)
        : SystemUser(login, password)
    {
        Name = name;
        Rating = 0.;
        RatedCnt = 0;
    }

    void UpdateRating(int rating)
    {
        if(rating < 1 || rating > 5)
        {
            throw std::out_of_range("The given rating must be in range [1,5].");
        }

        Rating = ((Rating*(double)RatedCnt)+rating)/(RatedCnt++);
    }
};
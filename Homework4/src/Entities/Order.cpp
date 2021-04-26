#pragma once

#include"Entity.cpp"
#include"Address.cpp"

struct Order : public Entity
{
    int Hours;
    int Minutes;
    Address From;
    Address To;

    Order() : Entity()
    {}
    Order(int hours, int minutes, Address from, Address to)
        : Entity()
    {
        Hours = hours;
        Minutes = minutes;
        From = from;
        To = to;
    }
};


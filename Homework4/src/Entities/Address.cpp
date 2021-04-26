#pragma once

#include"Entity.cpp"

struct Address : public Entity
{
    int X;
    int Y;

    Address() : Entity()
    {}
    Address(int x, int y)
        : Entity()
    {
        X = x;
        Y = y;
    }
};


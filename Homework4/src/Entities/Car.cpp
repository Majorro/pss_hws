#pragma once

#include<string>
#include"Entity.cpp"
#include"../Enums/CarType.cpp"
#include"../Enums/Color.cpp"
#include"Address.cpp"

struct Car : public Entity
{
    std::string Model;
    CarType Type;
    Address CurrentAddress;
    Color CarColor;
    std::string Number;
    int FreeBottleOfWater;

    Car() : Entity()
    {}
    Car(std::string model, CarType type, Address currentAddress, Color carColor, std::string number)
        : Entity()
    {
        Model = model;
        Type = type;
        CurrentAddress = currentAddress;
        CarColor = carColor;
        Number = number;
        FreeBottleOfWater = 10;
    }

    void ParkRightInFrontOfTheEntrance()
    {}
};

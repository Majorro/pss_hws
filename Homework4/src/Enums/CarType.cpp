#pragma once

#include<ostream>

enum CarType
{
    Economy,
    Comfort,
    ComfortPlus,
    Business
};

std::ostream& operator<<(std::ostream& out, const CarType carType)
{
    switch (carType)
    {
    case CarType::Economy:
        out << "Economy";
        break;
    
    case CarType::Comfort:
        out << "Comfort";
        break;

    case CarType::ComfortPlus:
        out << "ComfortPlus";
        break;

    case CarType::Business:
        out << "Business";
        break;
    }
    return out;
}

#pragma once

#include<ostream>

enum Color
{
    Black,
    White,
    Red,
    Green,
    Blue
};

std::ostream& operator<<(std::ostream& out, const Color color)
{
    switch (color)
    {
    case Color::Black:
        out << "Black";
        break;
    
    case Color::White:
        out << "White";
        break;

    case Color::Red:
        out << "Red";
        break;

    case Color::Green:
        out << "Green";
        break;

    case Color::Blue:
        out << "Blue";
        break;
    }
    return out;
}

#ifndef ACCESS_LEVEL
#define ACCESS_LEVEL

#include<ostream>

enum AccessLevel
{
    GreenAccess,
    YellowAccess,
    RedAccess,
    FullAccess, //==Admin
    AdminAccess=3
};

std::ostream &operator<<(std::ostream &out, const AccessLevel accessLevel)
{
    switch (accessLevel)
    {
        case GreenAccess:
            out << "Green";
            break;
        case YellowAccess:
            out << "Yellow";
            break;
        case RedAccess:
            out << "Red";
            break;
        case FullAccess:
            out << "Full";
            break;
    }
    return out;
}
#endif /* ACCESS_LEVEL */
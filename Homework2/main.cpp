#define DEBUG

#include<iostream>
#include<fstream>

#include"Utils/AccessLevel.cpp"
#include"Abstracts/Room.cpp"
#include"Abstracts/User.cpp"

int main()
{
#ifdef DEBUG
    freopen("Homework2/out.txt", "w", stdout);
#endif
    
    Admin a = Admin("adad", "asd", 123);
    Admin b = Admin("aad", "as", 124);
    Admin c = Admin("dad", "ad", 125);
    std::cout << a.GetAccessLevel() << std::endl;
    std::cout << b.GetAccessLevel() << std::endl;
    std::cout << c.GetAccessLevel() << std::endl;
    b.SetAccessLevel(a, GreenAccess);
    std::cout << a.GetAccessLevel() << std::endl;
    std::cout << b.GetAccessLevel() << std::endl;
    std::cout << c.GetAccessLevel() << std::endl;

    return 0;
}
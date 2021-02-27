#define DEBUG // TODO: add real things to children
              // TODO: add headers to all classes
              // TODO: distribute includings among cpps
              // TODO: add samples
              // TODO: add docs
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<set>
#include<typeinfo>
#include<unistd.h>

#include"Utils/Utils.cpp"
#include"Utils/AccessLevel.cpp"
#include"Abstracts/Room.cpp" // all children included
#include"Abstracts/User.cpp" // all children included

int main()
{
#ifdef DEBUG
    freopen("Homework2/out.txt", "w", stdout);
#endif
    Admin a("adad", "asd", 123);
    Director b("aad", "as", 124);
    DirectorCabinet c(1);
    b.RequestAccessToRoom(c);
    std::cout << '\n';
    // std::cout << b.ToString() << std::endl;
    // std::cout << c.ToString() << std::endl;
    return 0;
    // std::cout << a.GetAccessLevel() << std::endl;
    // std::cout << b.GetAccessLevel() << std::endl;
    // std::cout << c.GetAccessLevel() << std::endl;
    // b.SetAccessLevel(a, GreenAccess);
    // std::cout << a.GetAccessLevel() << std::endl;
    // std::cout << b.GetAccessLevel() << std::endl;
    // std::cout << c.GetAccessLevel() << std::endl;

    return 0;
}
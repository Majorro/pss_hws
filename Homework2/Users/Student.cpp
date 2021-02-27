#ifndef STUDENT
#define STUDENT

class Student : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    
public:
    Student(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        this->accessLevel = YellowAccess;
    }

    // GETTERS SETTERS
    // END GETTERS SETTERS
};

#endif /* STUDENT */
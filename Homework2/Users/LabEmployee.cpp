#ifndef LAB_EMPLOYEE
#define LAB_EMPLOYEE

class LabEmployee : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    
public:
    LabEmployee(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        this->accessLevel = GreenAccess;
    }

    // GETTERS SETTERS
    // END GETTERS SETTERS
};

#endif /* LAB_EMPLOYEE */
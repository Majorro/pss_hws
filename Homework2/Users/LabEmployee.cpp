#ifndef LAB_EMPLOYEE
#define LAB_EMPLOYEE

#include<string>
#include"../Abstracts/User.cpp"

enum Specialization
{
    BioInformatics,
    Robotics,
    InfoSec,
    SoftEngineering
};

class LabEmployee : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    Specialization specialization;
    
public:
    LabEmployee(std::string name, std::string surname, int age, Specialization specialization)
    : User(name, surname, age)
    {
        this->accessLevel = GreenAccess;
        this->specialization = specialization;
    }

    // GETTERS SETTERS
    Specialization GetSpecialization()
    {
        return this->specialization;
    }
    // END GETTERS SETTERS
};

#endif /* LAB_EMPLOYEE */
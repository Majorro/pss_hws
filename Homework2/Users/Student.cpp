#ifndef STUDENT
#define STUDENT

#include<iostream>
#include<string>
#include"../Abstracts/User.cpp"

class Student : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    int studyingYear;
    
public:
    Student(std::string name, std::string surname, int age, int studyingYear)
    : User(name, surname, age)
    {
        if(studyingYear < 1 || studyingYear > 4)
            throw std::invalid_argument("Bachelor students can be only 1st,2nd,3rd or 4th year");
        this->accessLevel = YellowAccess;
        this->studyingYear = studyingYear;
    }

    // GETTERS SETTERS
    int GetStudyingYear()
    {
        return this->studyingYear;
    }
    // END GETTERS SETTERS
};

#endif /* STUDENT */
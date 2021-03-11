#ifndef PROFESSOR
#define PROFESSOR

#include<string>
#include"../Abstracts/User.cpp"

enum Subject
{
    PSS,
    DSA,
    EAGLA,
    EAP,
    Calculus,
    TCS,
    Phylosophy,
    DM
};

class Professor : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
    Subject teachingSubject;

public:
    Professor(std::string name, std::string surname, int age, Subject subject)
    : User(name, surname, age)
    {
        this->accessLevel = RedAccess;
        this->teachingSubject = subject;
    }

    // GETTERS SETTERS
    Subject GetTeachingSubject()
    {
        return this->teachingSubject;
    }
    // END GETTERS SETTERS
};

#endif /* PROFESSOR */
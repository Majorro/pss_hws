#ifndef PROFESSOR
#define PROFESSOR

class Professor : public User
{
private:
    void IamAbstract() override {}; //legendary costyl
public:
    Professor(std::string name, std::string surname, int age)
    : User(name, surname, age)
    {
        this->accessLevel = RedAccess;
    }

    // GETTERS SETTERS
    // END GETTERS SETTERS
};

#endif /* PROFESSOR */
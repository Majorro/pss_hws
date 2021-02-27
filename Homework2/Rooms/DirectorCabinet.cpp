#ifndef DIRECTOR_CABINET
#define DIRECTOR_CABINET

class DirectorCabinet : public Room // TODO: add restrictions on creating(pseudo-singleton)
{
private:
    void IamAbstract() override {}; //legendary costyl
    static bool isCreated;
public:
    DirectorCabinet(int roomFloor)
    : Room(roomFloor)
    {
        if(isCreated)
            throw std::logic_error("Director cabined has already built");
        else
        {
            this->requiredAccessLevel = FullAccess;
            isCreated = 1;
        }
    }

    // GETTERS SETTERS
    // END GETTERS SETTERS

    bool IsAdded()
    {
        return DirectorCabinet::isCreated;
    }
};
bool DirectorCabinet::isCreated = 0;

#endif /* DIRECTOR_CABINET */
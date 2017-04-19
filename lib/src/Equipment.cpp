#include "Equipment.hpp"

int Equipment::autoID = 1;

Equipment::Equipment()
{
    ++autoID;
}

int Equipment::getClassID()
{
    return classID;
}

void Equipment::setClassID( int classID )
{
    this->classID = classID;
}

std::string Equipment::getID()
{
    return ID;
}

#include<string>

#include "meshanimation.h"

meshanimation::meshanimation()
{
    _name="";

    _id=-1;
}


meshanimation::meshanimation(std::string name, int id)
{
    _name=name;

    _id=id;

}

#ifndef MAINBONE_H
#define MAINBONE_H
#include "mesh/animation/join.h"
#include "mesh/animation/bone.h"

class mainbone : public bone
{
public:
    mainbone();

    mainbone(join*,join*);

    mainbone(join*,join*,int);
};

#endif // MAINBONE_H

#ifndef MESHFRAME_H
#define MESHFRAME_H
#include <vector>
#include "actionvertex.h"
#include "meshframe.h"

using namespace std;
class meshframe
{
public:
    meshframe();
    meshframe(int,int);
private:
    int _idani;
    int _idframe;

    vector<actionvertex> _actions;
    meshframe* _next;

};

#endif // MESHFRAME_H

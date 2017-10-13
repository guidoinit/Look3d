#include "mesh/action.h"
#include "vertexlist.h"
#include "actionvertex.h"

actionvertex::actionvertex()

{
    action();
    _list=NULL;
}
actionvertex::actionvertex(vertexlist* _l)

{
    action();
    _list=_l;
}

actionvertex::actionvertex(int no,int nf)

{
    action(no,nf);
    _list=NULL;

}



actionvertex::~actionvertex()
{
    delete _list;
}

void actionvertex::setlist(vertexlist *_l)
{
    _list=_l;

}
vertexlist * actionvertex::getlist()
{
    return (_list);
}

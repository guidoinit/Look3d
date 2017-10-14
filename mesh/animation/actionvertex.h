#ifndef ACTIONVERTEX_H
#define ACTIONVERTEX_H
#include <QOpenGLFunctions>

#include "vertexlist.h"
#include "mesh/action.h"


class actionvertex:public action
{

public:

        actionvertex();
        actionvertex(vertexlist* );
        actionvertex(int,int);
        ~actionvertex();



        void setlist(vertexlist *_l);


        vertexlist* getlist();


        actionvertex ( const actionvertex &obj )
        {
            action((action&)obj);
            _list=obj._list;


        }

        actionvertex& operator=( const actionvertex &obj )
        {
            action((action&)obj);

            _list=obj._list;

            return (*this);

        }


private:


        vertexlist *_list;

        //numero dell'oggetto a cui  riferita l'azione

};

#endif // ACTIONVERTEX_H

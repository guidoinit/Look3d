#ifndef LOCX_VERTEX_H
#define LOCX_VERTEX_H
#include "baseframe_vertex.h"

class locx_vertex:public baseframe_vertex
{
private:
        float _x;
public:
        locx_vertex(int fstart,int fend, float x);
        locx_vertex(void);
        ~locx_vertex(void);
//	virtual void Serialize(CArchive &ar);

        float get();
        void set(float);


        locx_vertex(const locx_vertex& loc)
        {
                baseframe_vertex((baseframe_vertex&)loc);
                _x=loc._x;
        }
        locx_vertex operator=(locx_vertex& loc)
        {
                baseframe_vertex((baseframe_vertex&)loc);
                _x=loc._x;

                return *this;
        }
};

#endif // LOCX_VERTEX_H

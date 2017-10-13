#ifndef LOCY_VERTEX_H
#define LOCY_VERTEX_H
#include "baseframe_vertex.h"

class locy_vertex:public baseframe_vertex
{
private:
        float _y;
public:
        locy_vertex(int fstart,int fend, float x);
        locy_vertex(void);
        ~locy_vertex(void);
//	virtual void Serialize(CArchive &ar);

        float get();
        void set(float);


        locy_vertex(const locy_vertex& loc)
        {
                baseframe_vertex((baseframe_vertex&)loc);
                _y=loc._y;
        }
        locy_vertex operator=(locy_vertex& loc)
        {
                baseframe_vertex((baseframe_vertex&)loc);
                _y=loc._y;

                return *this;
        }
};

#endif // LOCY_VERTEX_H

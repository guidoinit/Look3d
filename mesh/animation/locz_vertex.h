#ifndef LOCZ_VERTEX_H
#define LOCZ_VERTEX_H
#include "baseframe_vertex.h"

class locz_vertex:public baseframe_vertex
{
private:
        float _z;
public:
        locz_vertex(int fstart,int fend, float z);
        locz_vertex(void);
        ~locz_vertex(void);
//	virtual void Serialize(CArchive &ar);

        float get();
        void set(float);


        locz_vertex(const locz_vertex& loc)
        {
                baseframe_vertex((baseframe_vertex&)loc);
                _z=loc._z;
        }
        locz_vertex operator=(locz_vertex& loc)
        {
                baseframe_vertex((baseframe_vertex&)loc);
                _z=loc._z;

                return *this;
        }
};

#endif // LOCZ_VERTEX_H

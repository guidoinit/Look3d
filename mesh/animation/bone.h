#ifndef BONE_H
#define BONE_H
#include "l3d_include.h"
#include "mesh/l3d_vertex.h"
#include "mesh/l3d_line.h"
#include "mesh/l3d_face3.h"
#include "mesh/l3d_face4.h"
#include "mesh/l3d_mesh.h"

#include "mesh/vbo/l3d_bufferobject.h"
#include "mesh/vbo/l3d_vertexbufferobject.h"

#include "scene/sceneenum.h"
#include <list>
#include "join.h"
using namespace l3d;
using namespace l3d::vertex3f;
using namespace l3d::edge;
using namespace l3d::face3;
using namespace l3d::face4;
using namespace l3d::mesh;
using namespace l3d::material;


using namespace std;

using namespace l3d::mesh;

class bone
{
public:
    bone();
    bone(join*,join*);

    bone(join*,join*,int);

    void addnext(bone *,int);

    void setbox(bbox *);

    void setid(int);
    void setid(bone *,int id);

    //void draw(bone*,object3d*,object3d*);
    void draw_select();

    bool find(bone *,int);

    bone * get(bone *,int id);


private:
    join * _first;
    join * _second;

    list<bone*> _next;
    bbox * _box;

    int _id;
};

#endif // BONE_H

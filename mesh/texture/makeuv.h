#ifndef MAKEUV_H
#define MAKEUV_H
#include "./mesh/texture/vertexuv.h""
#include "./mesh/object3dinclude.h"

enum ALG_UV
{
    poligonal=0,
    poligonalx,
    poligonaly,
    poligonalz

};

class makeuv
{
public:
    makeuv();
    makeuv(object3d * obj);
    makeuv(object3d * obj,ALG_UV alg);

    void selalgoritm(ALG_UV alg);
    void setobj(object3d *);

    void poligonal(ALG_UV alg);
    void poligonal(ALG_UV alg,float val);

    ~makeuv();
private:
    object3d * m_obj;
    ALG_UV m_alg;
    float m_fpol;
};

#endif // MAKEUV_H

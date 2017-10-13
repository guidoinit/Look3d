#ifndef L3D_LIST_H
#define L3D_LIST_H
namespace l3d
{
typedef struct _l3d_list_int
{
    l3d_uint info;
    _l3d_list_int * next;

    void set(l3d_uint val)
    {
        info=val;
    }
    l3d_uint get()
    {
        return (info);
    }

    _l3d_list_int *getnext()
    {
        return (next);
    }

}l3d_list_int,*pl3d_list_int;
}

#endif // L3D_LIST_H

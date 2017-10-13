#ifndef MODIFIERMIRROR_H
#define MODIFIERMIRROR_H
#include <string>


using namespace std;
class modifiermirror
{
public:
    modifiermirror();
    modifiermirror(object3d );
    modifiermirror(object3d *);
private:
    object3d* _meshto;
    object3d _meshto2;
protected:
};

#endif // MODIFIERMIRROR_H

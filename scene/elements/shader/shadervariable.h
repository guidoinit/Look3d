#ifndef SHADERVARIABLE_H
#define SHADERVARIABLE_H

enum ShaderVariableType
{
        vinteger=1,
        vchar =2,
        vfloat=3,
        vvector2=4,
        vvector3=5,
        vvector4=6,
        vvectornf=7,
        vmatrix=8
};
class shadervariable
{
private:
        char * _name;
        void * _val;
        void * _min;
        void * _max;
        void * _step;
        GLuint _location;
        ShaderVariableType _type;
        int rmat;
        int cmat;
        int _nvector1;
        int _nvector2;
        bool _bminmax;
public:
        shadervariable(void);
        shadervariable(char *name,unsigned int var_size);
        shadervariable(char *name,ShaderVariableType type);
        ~shadervariable(void);

        shadervariable (const shadervariable& var)
        {
                _type=var._type;
                _name=var._name;
                _val=var._val;
                _location=var._location;
                _min=var._min;
                _max=var._max;
                _step=var._step;
                rmat=var.rmat;
                cmat=var.cmat;

        }
        void set_vectorn(int nv1,int nv2);
        void set_minmax(void* min,void* max,void * step);
        void set_location (GLuint prog);
        void set_value (void *val);
        void add_value(void * value);
        void *get_value();
        void Update();
};

#endif // SHADERVARIABLE_H

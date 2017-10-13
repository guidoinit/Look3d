#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

using namespace std;

class variable
{
public:
    variable();

    variable(string );
    virtual ~variable();
    void SetTipo(string);
    void SetName(string);
    void * Get (void);
    void Set (void*);
    variable ( const variable &var )
    {
            data=var.data;
            tipo=var.tipo;
            nome=var.nome;
    }
    variable& operator=( const variable &var )
    {
            data=var.data;
            tipo=var.tipo;
            nome=var.nome;
            return (*this);
    }
private:
    void * data;
    string nome;
    string tipo;
};

#endif // VARIABLE_H

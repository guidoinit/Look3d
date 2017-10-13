#ifndef ISTRUCTION_H
#define ISTRUCTION_H

#include <vector>
#include "variable.h"


class istruction
{
public:
    istruction();
    ~istruction();

    vector <variable> variabili;
    variable valret;


    istruction ( const istruction &var )
    {
            int x;
            for(x=0; x < var.variabili.size();x++)
                    variabili[x]=var.variabili[x];
    }

    istruction& operator=( const istruction &var )
    {
            //data=var.data;
            //tipo=var.tipo;
            int x;
            for(x=0; x < var.variabili.size();x++)
                    variabili[x]=var.variabili[x];
            return (*this);
    }
};

#endif // ISTRUCTION_H

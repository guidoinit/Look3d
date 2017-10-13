#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include "variable.h"
#include "action.h"
#include "istruction.h"

class functionp
{
public:
    functionp();

    functionp(string,variable,string);

    virtual ~functionp();
    string key;
    string nome;
    variable tipo;

    std::vector <action>azione;
    std::vector <action> parametri;
    std::vector <variable> variabili;
    std::vector <istruction>istruzioni;
    functionp ( const functionp &fun )
    {
            int x;

            key=fun.key;
            nome=fun.nome;
            tipo=fun.tipo;

            for(x=0; x< fun.parametri.size();x++)
                    parametri[x]=fun.parametri[x];
            for(x=0; x< fun.variabili.size();x++)
                    variabili[x]=fun.variabili[x];
            for(x=0; x< fun.istruzioni.size();x++)
                    istruzioni[x]=fun.istruzioni[x];



    }

    functionp& operator=( const functionp &fun )
    {
            int x;

            key=fun.key;
            nome=fun.nome;
            tipo=fun.tipo;

            for(x=0; x< fun.parametri.size();x++)
                    parametri[x]=fun.parametri[x];
            for(x=0; x< fun.variabili.size();x++)
                    variabili[x]=fun.variabili[x];
            for(x=0; x< fun.istruzioni.size();x++)
                    istruzioni[x]=fun.istruzioni[x];

            return *this;


    }
};

#endif // FUNCTION_H

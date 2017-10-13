#ifndef MODULE_H
#define MODULE_H

#include "variable.h"
#include "function.h"
#include <vector>

class module
{
public:
    module();

    module(const module& mod)
    {
        variabili.clear();
        for(int ix=0; ix < mod.variabili.size(); ix++)
            variabili.push_back(mod.variabili[ix]);
        funzioni.clear();
        for(int ix=0; ix < mod.funzioni.size(); ix++)
            funzioni.push_back(mod.funzioni[ix]);

    }
    module& operator=( const module &mod )
    {
        variabili.clear();
        for(int ix=0; ix < mod.variabili.size(); ix++)
            variabili.push_back(mod.variabili[ix]);
        funzioni.clear();
        for(int ix=0; ix < mod.funzioni.size(); ix++)
            funzioni.push_back(mod.funzioni[ix]);

        return *this;
    }

    ~module();
    std::vector<variable> variabili;
    std::vector<functionp> funzioni;
};

#endif // MODULE_H

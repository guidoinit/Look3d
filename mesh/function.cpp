#include <vector>
#include "variable.h"
#include "action.h"
#include "istruction.h"

#include "function.h"




functionp::functionp()
{
}
functionp::functionp(string nome,variable tipo,string key)
{

        this->nome=nome;
        this->tipo=tipo;
        this->key=key;

}



functionp::~functionp()
{
}

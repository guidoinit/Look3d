#include <string>

#include "stdlib.h"
#include "variable.h"



variable::variable()
{
}
variable::variable(string tipo)
{
        if(tipo.compare("int"))
        {
                data=::malloc(sizeof(int));
        }

}

variable::~variable()
{
}

void *variable::Get()
{
        return (data);
}
void variable::Set(void *nd)
{
        data=nd;
}
void variable::SetTipo(string tipo)
{
        this->tipo=tipo;
}
void variable::SetName(string name)
{
        this->nome=name;
}

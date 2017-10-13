#ifndef LIGHTMODEL_H
#define LIGHTMODEL_H



class lightmodel
{
public:
    lightmodel();
    void set();
    float m_ambient[4];
    float m_local_viewer;
    float m_two_side;

};

#endif // LIGHTMODEL_H

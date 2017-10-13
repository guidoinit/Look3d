#ifndef ANIMATIONMANAGER_STATE_H
#define ANIMATIONMANAGER_STATE_H
#include "scene/sceneenum.h"
class animationmanager_state
{
public:
    animationmanager_state();

    int m_iframe;
    int m_ianiselect;
    int m_iplay;
    int m_iscalexyz;
    int m_irotatexyz;

    bool m_bplay;
    bool m_moveobj[3];
    bool m_bmove;
    bool m_bShift;
    bool m_bismove;
    bool m_bisrotate;
    bool m_bisscale;
    SCENE::ModeDraw m_mode;

};

#endif // ANIMATIONMANAGER_STATE_H

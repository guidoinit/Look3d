#pragma once
#include "sceneenum.h"

class SceneProperty
{
public:
	SceneProperty(void);
	~SceneProperty(void);
        SCENE::SceneType _scenetype;
        SCENE::ModeDocument _modedocument;
        SCENE::ModeEdit _modeedit;
        SCENE::ModeDraw _modedraw;
};


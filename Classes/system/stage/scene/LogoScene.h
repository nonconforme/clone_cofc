//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef LogoScene_h
#define LogoScene_h
#include "cocos2d.h"
#include "BaseScene.h"
class LogoScene : public BaseScene {
   public:
    static const int SCENE_ID = 1;
    LogoScene();
    virtual ~LogoScene();
    cocos2d::Scene* create() override;
};
#endif
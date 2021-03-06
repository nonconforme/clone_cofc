//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef DestroyEffectBehaviour_h
#define DestroyEffectBehaviour_h
// cocos2d
#include "cocos2d.h"
// behaviour
#include "BaseBehaviour.h"
#include "OrnamentProperty.h"
class DestroyEffectBehaviour : public BaseBehaviour {
   public:
    DestroyEffectBehaviour(BaseProperty* ornamentProperty);
    virtual ~DestroyEffectBehaviour();
    void onCreate(cocos2d::Layer* layer, Position position) override;
   private:
    float const BASIC_SCALE = 0.2f;
    float effectScale;
};
#endif

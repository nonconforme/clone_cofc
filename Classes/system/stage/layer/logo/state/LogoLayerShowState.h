//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

#ifndef LogoLayerShowState_h
#define LogoLayerShowState_h

// layer
#include "LogoLayer.h"

// state
#include "FiniteState.h"

class LogoLayerShowState : public FiniteState<LogoLayer> {
   public:
    LogoLayerShowState();
    virtual ~LogoLayerShowState();
    void create() override;
    void update(float delta) override;
};
#endif

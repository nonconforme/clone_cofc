//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef MortarTouchEndState_h
#define MortarTouchEndState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "MortarBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
// asset
#include "AnimatorAsset.h"
class MortarBehaviour;
class MortarTouchEndState : public FiniteState<MortarBehaviour> {
   public:
    MortarTouchEndState();
    virtual ~MortarTouchEndState();
    void create(Parameter* parameter);
   private:
    AnimatorAsset* asset;
};
#endif

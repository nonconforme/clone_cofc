//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef TurretDamageState_h
#define TurretDamageState_h
// stl
#include <vector>
// state
#include "FiniteState.h"
// behaviour
#include "TurretBehaviour.h"
// route
#include "BaseRouteSearch.h"
// frame
#include "TimeLine.h"
#include "Parameter.h"
#include "BaseStrategy.h"
class TurretBehaviour;
class TurretDamageState : public FiniteState<TurretBehaviour> {
   public:
    TurretDamageState();
    virtual ~TurretDamageState();
    void create(Parameter* parameter) override;
   private:
    BaseStrategy* damageStrategy;
};
#endif

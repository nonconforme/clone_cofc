//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef GoblinMoveState_h
#define GoblinMoveState_h
// state
#include "FiniteState.h"
#include "UnitMoveState.h"
// behaviour
#include "GoblinBehaviour.h"
class GoblinBehaviour;
class GoblinMoveState : public FiniteState<GoblinBehaviour>, UnitMoveState<GoblinBehaviour> {
   public:
    GoblinMoveState();
    virtual ~GoblinMoveState();
    void create() override;
    void update(float delta) override;
   protected:
    GeographicNode* findGoalNode(GeographicNode* startNode) override;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef BattleStatusStrategy_h
#define BattleStatusStrategy_h
// service
#include "BaseStrategy.h"
class BattleStatusStrategy : public BaseStrategy {
   public:
    BattleStatusStrategy();
    virtual ~BattleStatusStrategy();
    Response get(Parameter* parameter = NULL) override;
};
#endif

//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================

// service
#include "BarrierService.h"
#include "BarrierDestroyStrategy.h"
#include "BarrierCreateStrategy.h"
#include "BarrierDamageStrategy.h"

BarrierService::BarrierService() {
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("create", new BarrierCreateStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("damage", new BarrierDamageStrategy()));
    this->strategyMap.insert(std::map<std::string, BaseStrategy*>::value_type("destroy", new BarrierDestroyStrategy()));
}

BarrierService::~BarrierService() {}
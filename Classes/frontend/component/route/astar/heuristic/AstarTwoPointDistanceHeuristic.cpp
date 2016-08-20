//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "AstarTwoPointDistanceHeuristic.h"
#include "Distance.h"
AstarTwoPointDistanceHeuristic::AstarTwoPointDistanceHeuristic() {}
AstarTwoPointDistanceHeuristic::~AstarTwoPointDistanceHeuristic() {}
int AstarTwoPointDistanceHeuristic::getEstimateDistance() {
    int distanceOfNextToGoal = Distance::create(this->start->address, this->goal->address);
    return distanceOfNextToGoal;
}
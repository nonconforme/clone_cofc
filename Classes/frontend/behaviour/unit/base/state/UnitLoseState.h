//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitLoseState_h
#define UnitLoseState_h
template <class T>
class UnitLoseState {
   public:
    UnitLoseState();
    virtual ~UnitLoseState();
    void changeDirection(T* owner);
};
#endif

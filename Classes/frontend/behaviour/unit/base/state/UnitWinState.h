//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitWinState_h
#define UnitWinState_h
template <class T>
class UnitWinState {
   public:
    UnitWinState();
    virtual ~UnitWinState();
    void changeDirection(T* owner);
};
#endif

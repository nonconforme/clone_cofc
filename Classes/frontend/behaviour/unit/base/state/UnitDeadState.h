//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#ifndef UnitDeadState_h
#define UnitDeadState_h
template <class T>
class UnitDeadState {
   public:
    UnitDeadState();
    virtual ~UnitDeadState();
   protected:
    void dead(T* owner);
};
#endif

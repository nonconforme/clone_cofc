//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "UICommand.h"
UICommand::UICommand() {}
UICommand::~UICommand() {}
void UICommand::execute(BaseBehaviour* behaviour, float delta) { behaviour->onUpdate(delta); }

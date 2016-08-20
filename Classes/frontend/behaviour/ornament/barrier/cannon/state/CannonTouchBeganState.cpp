//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
#include "CannonTouchBeganState.h"
// asset
#include "TextureAsset.h"
// geography
#include "GeographicGateway.h"
#include "GeographicNode.h"
#include "GeographicDepth.h"
// notify
#include "Notifier.h"
#include "NotifyMessage.h"
// utility
#include "Degree.h"
#include "Figure.h"
#include "Vector2D.h"
#include "Random.h"
#include "Alpha.h"
using namespace cocos2d;
CannonTouchBeganState::CannonTouchBeganState() {}
CannonTouchBeganState::~CannonTouchBeganState() {}
void CannonTouchBeganState::create(Parameter* parameter) {
    Vec2 pos = parameter->get<Vec2>("touchPosition");
    bool reset = parameter->get<bool>("reset");
    GeographicGateway* gateway = GeographicGateway::getInstance();
    GeographicNode* node = NULL;
    if (false != reset) {
        node = this->owner->getGeographicNode();
    } else {
        node = gateway->findByPosition(pos);
    }
    this->owner->clearGeographicNodeVector();
    if (NULL != node) {
        Vec2 pos = node->position;
        Parameter parameter;
        std::vector<int> idVector;
        idVector.push_back(node->geographicId);
        parameter.set<std::vector<int>>("parameter", idVector);
        Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Node);
        Notifier::getInstance()->notify(NotifyMessage::Route_Search_Test_Viewer_Start, &parameter);
        GLubyte alpha = Alpha::HALF_ALPHA;
        AnimatorAsset* anime = (AnimatorAsset*)this->owner->getAsset("anime");
        anime->transform(pos, (OrnamentProperty*)this->owner->getProperty());
        anime->transform(GeographicDepth::ORNAMENT_TOUCH_DEPTH);
        anime->transform(alpha);
        TextureAsset* texture = (TextureAsset*)this->owner->getAsset("texture");
        texture->transform(node, GeographicDepth::ORNAMENT_TOUCH_DEPTH - 1);
        texture->transform(alpha);
    }
    return;
}

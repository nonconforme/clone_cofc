//======================================================================
// Project Name    : cofcofc
//
// Copyright © 2016 U-CREATES. All rights reserved.
//
// This source code is the property of U-CREATES.
// If such findings are accepted at any time.
// We hope the tips and helpful in developing.
//======================================================================
// behaviour
#include "MortarBehaviour.h"
#include "BehaviourIdGenerator.h"
// peroperty
#include "OrnamentProperty.h"
// asset
#include "AnimatorAsset.h"
#include "SoundEffectAsset.h"
// notify
#include "Notifier.h"
// geographic
#include "GeographicDepth.h"
#include "Parameter.h"
#include "ServiceGateway.h"
#include "BarrierBehaviourType.h"
using namespace cocos2d;
MortarBehaviour::MortarBehaviour(GeographicNode* geographicNode) {
    int id = BehaviourIdGenerator::getInstance()->getId();
    this->asset->add("anime", new AnimatorAsset("csb/animation/barrier/mortar", id));
    this->geographicNode = geographicNode;
    this->property = new OrnamentProperty("mortar", id, "attack", 2, 1, 2);
    this->stateMachine = new FiniteStateMachine<MortarBehaviour>(this);
    this->stateMachine->add("attack", new MortarAttackState(id));
    this->stateMachine->add("damage", new MortarDamageState());
    this->stateMachine->add("destroy", new MortarDestroyState());
    this->stateMachine->add("pause", new MortarPauseState());
    this->stateMachine->add("touchBegan", new MortarTouchBeganState());
    this->stateMachine->add("touchEnd", new MortarTouchEndState());
    this->stateMachine->stop();
    Notifier::getInstance()->add(this, this->property);
    Parameter parameter;
    parameter.set<int>("barrierId", id);
    parameter.set<int>("barrierType", BarrierBehaviourType::Mortar);
    Response res = ServiceGateway::getInstance()->request("service://barrier/create")->update(&parameter);
    if (ServiceStatus::SUCCESS != res.getStatus()) {
        CCLOGERROR("service faild %s, %s, %d", __FILE__, __FUNCTION__, __LINE__);
    }
    res.clear();
}
MortarBehaviour::~MortarBehaviour() { Notifier::getInstance()->erase(this->property->getId()); }
void MortarBehaviour::onCreate(Layer* layer) {
    OrnamentProperty* oproperty = (OrnamentProperty*)this->property;
    int depth = this->geographicNode->depth + GeographicDepth::BARRIER_DEPTH_RELATIVE_TO_NODE * oproperty->getAddressScale()->x;
    this->onCreate(layer, depth);
}
void MortarBehaviour::onCreate(Layer* layer, int depth) {
    Position position = Position(this->geographicNode->position, depth);
    this->onCreate(layer, position);
    return;
}
void MortarBehaviour::onCreate(Layer* layer, Position position) {
    this->layer = layer;
    if (NULL != this->geographicNode) {
        GeographicGateway* gateway = GeographicGateway::getInstance();
        std::vector<GeographicNode*> nodeVector = gateway->find2x2ByAddress(this->geographicNode->address);
        this->setGeographicNodeVector(nodeVector);
    }
    this->lifeGuage->onCreate(layer, position.zorder);
    AnimatorAsset* anime = (AnimatorAsset*)this->getAsset("anime");
    anime->pause();
    anime->transform(position, (OrnamentProperty*)this->property);
    anime->addLayer(layer, position.zorder);
    this->stateMachine->change("pause");
    this->stateMachine->play();
    return;
}
void MortarBehaviour::onUpdate(float delta) {
    this->lifeGuage->onUpdate(delta);
    this->stateMachine->update(delta);
}
void MortarBehaviour::onNotify(NotifyMessage notifyMessage, Parameter* parameter) {
    if (NULL == parameter) {
        return;
    }
    int barrierId = parameter->get<int>("barrierId");
    if (this->property->getId() != barrierId) {
        return;
    }
    if (notifyMessage == NotifyMessage::Behaviour_Barrier_Destroy) {
        this->stateMachine->change("destroy", true);
    } else if (notifyMessage == NotifyMessage::Behaviour_Barrier_Damage) {
        this->stateMachine->change("damage", parameter);
    } else if (notifyMessage == NotifyMessage::Behaviour_Barrier_Mortar_Atack) {
        this->stateMachine->change("attack");
    } else if (notifyMessage == NotifyMessage::Behaviour_Barrier_Mortar_Pause) {
        this->stateMachine->change("pause");
    } else if (notifyMessage == Behaviour_Barrier_Touch_Began) {
        this->stateMachine->change("touchBegan", parameter);
    } else if (notifyMessage == Behaviour_Barrier_Touch_End) {
        this->stateMachine->change("touchEnd", parameter);
    }
    this->stateMachine->play();
}
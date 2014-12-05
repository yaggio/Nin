//
//  OpScene.cpp
//  Nin
//
//  Created by gamagama on 2014/12/04.
//
//

#include "OpScene.h"
#include "MapScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;

Scene* OpScene::createScene()
{
  auto scene = Scene::create();
  auto layer = OpScene::create();
  scene->addChild(layer);

  return scene;
}

bool OpScene::init()
{
  if ( !Layer::init() ) return false;

  //Welcome Message
  auto windowSize = Director::getInstance()->getWinSize();
  node = CSLoader::getInstance()->createNodeFromProtocolBuffers("OpScene.csb");
  this->addChild(node);
  
  auto btn_skip = dynamic_cast<Button*>(node->getChildByName("btn_skip"));
  btn_skip->addTouchEventListener(this, toucheventselector(OpScene::pushSkip));
  
  return true;
}

void OpScene::pushSkip(Ref *sender, TouchEventType type)
{
  auto btn = sender;
  MenuItem* menuItem = (MenuItem*)sender;
  log("click tag:%i", menuItem->getTag());
  Director::getInstance()->replaceScene(TransitionFade::create(1.0f, MapScene::createScene(), Color3B::WHITE));

}

//
//  MapScene.cpp
//  Nin
//
//  Created by gamagama on 2014/12/05.
//
//

#include "MapScene.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;

Scene* MapScene::createScene()
{
  auto scene = Scene::create();
  auto layer = MapScene::create();
  scene->addChild(layer);

  return scene;
}

bool MapScene::init()
{
  if ( !Layer::init() ) return false;

  //Welcome Message
  auto windowSize = Director::getInstance()->getWinSize();
  auto label = LabelTTF::create("MapScene", "Arial", 24);
  label->setPosition(windowSize.width / 2, windowSize.height / 2);
  this->addChild(label);
 
  return true;
}
